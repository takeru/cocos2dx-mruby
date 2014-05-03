//
//  CCMrubyEngine.cpp
//  CocosMruby
//
//  Created by admin on 13/09/17.
//
//

#include "CCMrubyEngine.h"
#include "mruby/mruby.h"
#include "mruby/mruby/array.h"
#include "mruby/mruby/class.h"
#include "mruby/mruby/compile.h"
#include "mruby/mruby/string.h"
#include "mruby/mruby/variable.h"
#include "mruby/mruby/error.h"
#include "MrubyCocos2dx.h"
#include "MrubyCocos2dx_WebSocket.h"
#include "MrubyCocosDenshion.h"
#include "MrubyBox2D.h"
#include "MrubyCocos2dx_Extensions.h"
#include "CCSwipeGestureRecognizer.h"

extern mrb_value _wrap_CCTouch(mrb_state *mrb, const cocos2d::CCTouch* ptr);
extern mrb_value _wrap_CCObject(mrb_state *mrb, const cocos2d::CCObject* ptr);
extern mrb_value _wrap_CCNode(mrb_state *mrb, const cocos2d::CCNode* ptr);
extern mrb_value _wrap_CCSwipe(mrb_state *mrb, const CCSwipe* ptr);

static const char* getBaseName(const char* fullpath) {
  int len = strlen(fullpath);
  for (int i = len - 1; --i >= 0; ) {
    if (fullpath[i] == '/')
      return &fullpath[i + 1];
  }
  return fullpath;
}

static struct RClass* getMrubyCocos2dxClassPtr(mrb_state *mrb, const char* className) {
  RClass* mod = mrb_module_get(mrb, "Cocos2dx");
  return mrb_class_get_under(mrb, mod, className);
}

static mrb_value getMrubyCocos2dxClassValue(mrb_state *mrb, const char* className) {
  return mrb_obj_value(getMrubyCocos2dxClassPtr(mrb, className));
}

int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc) {
  mrb_value man = getMrubyCocos2dxClassValue(mrb, "HandleManager");
  mrb_value result = mrb_funcall(mrb, man, "register", 1, proc);
  return mrb_fixnum(result);
}

mrb_value getRegisteredProc(mrb_state *mrb, int id) {
  mrb_value man = getMrubyCocos2dxClassValue(mrb, "HandleManager");
  mrb_value proc = mrb_funcall(mrb, man, "getProc", 1, mrb_fixnum_value(id));
  return proc;
}

NS_CC_BEGIN

static const char HelperFunctions[] =
"module Cocos2dx\n"
"  class HandleManager\n"
"    @@counter = 0\n"
"    @@proc2id = {}\n"
"    @@id2proc = {}\n"

"    def self.register(proc)\n"
"      if @@proc2id.has_key?(proc)\n"
"        return @@proc2id[proc]\n"
"      end\n"
"      id = (@@counter += 1)\n"
"      @@id2proc[id] = proc\n"
"      @@proc2id[proc] = id\n"
"      return id\n"
"    end\n"

"    def self.getProc(id)\n"
"      return @@id2proc[id]\n"
"    end\n"
"  end\n"
"  class Callback\n"
"    @@remove_script_object = nil\n"
"    def self.remove_script_object(&proc)\n"
"      @@remove_script_object = proc\n"
"    end\n"
"    def self._remove_script_object(obj)\n"
"      @@remove_script_object.call(obj) if @@remove_script_object\n"
"    end\n"

"    @@uncaught_exception = proc{|e,bt| puts \"UncaughtException: #{([e.inspect]+e.backtrace).join(\"\\n  \")}\" }\n"
"    def self.uncaught_exception(&proc)\n"
"      @@uncaught_exception = proc\n"
"    end\n"
"    def self._uncaught_exception(e,bt)\n"
"      @@uncaught_exception.call(e,bt) if @@uncaught_exception\n"
"    end\n"

"    @@before_shutdown = nil\n"
"    def self.before_shutdown(&proc)\n"
"      @@before_shutdown = proc\n"
"    end\n"
"    def self._before_shutdown\n"
"      @@before_shutdown.call if @@before_shutdown\n"
"    end\n"

"  end\n"
"end\n";

////////////////////////////////////////////////////////////////
// Misc.
static mrb_value _mrb_cclog(mrb_state *mrb, mrb_value self) {
    mrb_value* args;
    int n;
    mrb_get_args(mrb, "*", &args, &n);
    for (int i = 0; i < n; ++i) {
        mrb_value s = mrb_funcall(mrb, args[i], "to_s", 0);
        CCLOG("%s", RSTRING_PTR(s));
    }
    return mrb_nil_value();
}

static mrb_value _mrb_puts(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int n;
  mrb_get_args(mrb, "*", &args, &n);
  for (int i = 0; i < n; ++i) {
    mrb_value s = mrb_funcall(mrb, args[i], "to_s", 0);
    printf("%s\n", RSTRING_PTR(s));
  }
  return mrb_nil_value();
}

static mrb_value _mrb_p(mrb_state *mrb, mrb_value self) {
    mrb_value* args;
    int n;
    mrb_get_args(mrb, "*", &args, &n);
    for (int i = 0; i < n; ++i) {
        mrb_value s = mrb_funcall(mrb, args[i], "inspect", 0);
        printf("%s\n", RSTRING_PTR(s));
    }
    return mrb_nil_value();
}

static bool _dumpException(mrb_state *mrb) {
    if (!mrb->exc)
        return FALSE;

    mrb_value exc = mrb_obj_value(mrb->exc);
    mrb_value backtrace = mrb_exc_backtrace(mrb, exc);
    mrb_value s = mrb_funcall(mrb, exc, "inspect", 0);
    printf("Uncaught Exception: %s\n", RSTRING_PTR(s));
    for (mrb_int n = mrb_ary_len(mrb, backtrace), i = 0; i < n; ++i) {
        mrb_value v = mrb_ary_ref(mrb, backtrace, i);
        printf("  %s\n", RSTRING_PTR(v));
    }
    mrb->exc = NULL;
    return TRUE;
}

static bool checkUncaughtException(mrb_state *mrb) {
    if (!mrb->exc)
        return FALSE;

    int arena = mrb_gc_arena_save(mrb);
    mrb_value exc = mrb_obj_value(mrb->exc);
    mrb_value backtrace = mrb_exc_backtrace(mrb, exc);
    mrb->exc = NULL;
    mrb_value cb = getMrubyCocos2dxClassValue(mrb, "Callback");
    mrb_funcall(mrb, cb, "_uncaught_exception", 2, exc, backtrace);
    _dumpException(mrb);
    mrb_gc_arena_restore(mrb, arena);
    return TRUE;
}

CCMrubyEngine* CCMrubyEngine::m_defaultEngine = NULL;

CCMrubyEngine* CCMrubyEngine::defaultEngine(void)
{
  if (!m_defaultEngine)
  {
    m_defaultEngine = new CCMrubyEngine();
    m_defaultEngine->init();
  }
  return m_defaultEngine;
}

CCMrubyEngine::~CCMrubyEngine()
{
  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value cb  = getMrubyCocos2dxClassValue(m_mrb, "Callback");
  mrb_funcall(m_mrb, cb, "_before_shutdown", 0);
  checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);

  mrb_close(m_mrb);
  m_defaultEngine = NULL;
}

CCMrubyEngine::CCMrubyEngine(void)
{
}

bool CCMrubyEngine::init(void)
{
  m_mrb = mrb_open();

  // Installs general functions.
  mrb_define_method(m_mrb, m_mrb->kernel_module, "cclog", _mrb_cclog, MRB_ARGS_ANY());
  mrb_define_method(m_mrb, m_mrb->kernel_module, "puts",  _mrb_puts,  MRB_ARGS_ANY());
  mrb_define_method(m_mrb, m_mrb->kernel_module, "p",     _mrb_p,     MRB_ARGS_ANY());

  // Installs cocos2d classes.
  installMrubyCocos2dx(m_mrb);
  installMrubyCocos2dx_WebSocket(m_mrb);
  installMrubyCocos2dx_Extensions(m_mrb);
  installMrubyCocosDenshion(m_mrb);
  installMrubyBox2D(m_mrb);

  // Installs helper functions.
  // This line must be after installing mruby bindings,
  // because it creates new module for `Cocos2d'.
  mrb_load_string(m_mrb, HelperFunctions);

  return true;
}

/** Remove script object. */
void CCMrubyEngine::removeScriptObjectByCCObject(CCObject* pObj)
{
  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value obj = _wrap_CCObject(m_mrb, pObj);
  mrb_value cb  = getMrubyCocos2dxClassValue(m_mrb, "Callback");
  mrb_funcall(m_mrb, cb, "_remove_script_object", 1, obj);
  checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
}

int CCMrubyEngine::executeString(const char* codes)
{
  int arena = mrb_gc_arena_save(m_mrb);
  if(executeWithDebugInfo){
    mrbc_context *cxt = mrbc_context_new(m_mrb);
    mrbc_filename(m_mrb, cxt, getBaseName("*main*"));
    mrb_load_string_cxt(m_mrb, codes, cxt);
    mrbc_context_free(m_mrb, cxt);
  }else{
    // No debug info.
    mrb_load_string(m_mrb, codes);
  }
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeScriptFile(const char* filename)
{
  std::string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);

  int arena = mrb_gc_arena_save(m_mrb);
  if(executeWithDebugInfo){
    mrbc_context *cxt = mrbc_context_new(m_mrb);
    mrbc_filename(m_mrb, cxt, getBaseName(filename));
    FILE* fp = fopen(fullpath.c_str(), "rb");
    mrb_load_file_cxt(m_mrb, fp, cxt);
    fclose(fp);
    mrbc_context_free(m_mrb, cxt);
  }else{
    // No debug info.
    FILE* fp = fopen(fullpath.c_str(), "rb");
    mrb_load_file(m_mrb, fp);
    fclose(fp);
  }
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);

  return !exc;
}

int CCMrubyEngine::executeGlobalFunction(const char* functionName)
{
  int arena = mrb_gc_arena_save(m_mrb);
  mrb_funcall(m_mrb, mrb_top_self(m_mrb), functionName, 0);
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeNodeEvent(CCNode* pNode, int nAction)
{
  int nHandler = pNode->getScriptHandler();
  if (!nHandler) return 0;

  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_value node = _wrap_CCNode(m_mrb, pNode);

  mrb_funcall(m_mrb, proc, "call", 2, node, mrb_fixnum_value(nAction));
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeMenuItemEvent(CCMenuItem* pMenuItem)
{
  int nHandler = pMenuItem->getScriptTapHandler();
  if (!nHandler) return 0;

  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value block = getRegisteredProc(m_mrb, nHandler);
  mrb_yield(m_mrb, block, mrb_nil_value());
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeNotificationEvent(CCNotificationCenter* pNotificationCenter, const char* pszName)
{
  CCLOGERROR("CCMrubyEngine::executeNotificationEvent has not implemented: %p, %s", pNotificationCenter, pszName);
  return 0;
}

int CCMrubyEngine::executeCallFuncActionEvent(CCCallFunc* pAction, CCObject* pTarget)
{
  int nHandler = pAction->getScriptHandler();
  if (!nHandler) return 0;

  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_yield(m_mrb, proc, mrb_nil_value());
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeSchedule(int nHandler, float dt, CCNode* pNode)
{
  if (!nHandler) return FALSE;

  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value block = getRegisteredProc(m_mrb, nHandler);
  mrb_value node = _wrap_CCNode(m_mrb, pNode);
  mrb_funcall(m_mrb, block, "call", 2, mrb_float_value(m_mrb, dt), node);
  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  return !exc;
}

int CCMrubyEngine::executeLayerTouchesEvent(CCLayer* pLayer, int eventType, CCSet *pTouches)
{
    CCTouchScriptHandlerEntry* pScriptHandlerEntry = pLayer->getScriptTouchHandlerEntry();
    if (!pScriptHandlerEntry) return FALSE;
    int nHandler = pScriptHandlerEntry->getHandler();
    if (!nHandler) return FALSE;

    int arena = mrb_gc_arena_save(m_mrb);
    mrb_value proc = getRegisteredProc(m_mrb, nHandler);
    mrb_value args[2];
    args[0] = mrb_fixnum_value(eventType);
    mrb_value array = mrb_ary_new(m_mrb);
    for(CCSetIterator it=pTouches->begin(); it!=pTouches->end(); it++){
        CCTouch* pTouch = (CCTouch*)(*it);
        mrb_value touch = _wrap_CCTouch(m_mrb, pTouch);
        mrb_ary_push(m_mrb, array, touch);
    }
    args[1] = array;
    mrb_value ret = mrb_yield_argv(m_mrb, proc, 2, args);

    bool exc = checkUncaughtException(m_mrb);
    mrb_gc_arena_restore(m_mrb, arena);
    if(exc){ return 0; }
    
    return mrb_bool(ret) ? 1 : 0;
}

int CCMrubyEngine::executeLayerTouchEvent(CCLayer* pLayer, int eventType, CCTouch *pTouch)
{
  CCTouchScriptHandlerEntry* pScriptHandlerEntry = pLayer->getScriptTouchHandlerEntry();
  if (!pScriptHandlerEntry) return FALSE;
  int nHandler = pScriptHandlerEntry->getHandler();
  if (!nHandler) return FALSE;

  int arena = mrb_gc_arena_save(m_mrb);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_value args[2];
  args[0] = mrb_fixnum_value(eventType);
  args[1] = _wrap_CCTouch(m_mrb, pTouch);
  mrb_value ret = mrb_yield_argv(m_mrb, proc, 2, args);

  bool exc = checkUncaughtException(m_mrb);
  mrb_gc_arena_restore(m_mrb, arena);
  if(exc){ return 0; }

  return mrb_bool(ret) ? 1 : 0;
}

int CCMrubyEngine::executeLayerKeypadEvent(CCLayer* pLayer, int eventType)
{
  CCLOGERROR("CCMrubyEngine::executeLayerKeypadEvent has not implemented: %p, %d", pLayer, eventType);
  return 0;
}

int CCMrubyEngine::executeAccelerometerEvent(CCLayer* pLayer, CCAcceleration* pAccelerationValue)
{
  CCLOGERROR("CCMrubyEngine::executeAccelerometerEvent has not implemented: %p, %p", pLayer, pAccelerationValue);
  return 0;
}

int CCMrubyEngine::executeEvent(int nHandler, const char* pEventName, CCObject* pEventSource, const char* pEventSourceClassName)
{
  CCLOGERROR("CCMrubyEngine::executeEvent has not implemented: %d, %s, %p, %s", nHandler, pEventName, pEventSource, pEventSourceClassName);
  return 0;
}

int CCMrubyEngine::executeEventWithArgs(int nHandler, CCArray* pArgs)
{
    if (!nHandler) return FALSE;
    
    int arena = mrb_gc_arena_save(m_mrb);
    mrb_value block = getRegisteredProc(m_mrb, nHandler);

    mrb_value* args = new mrb_value[pArgs->count()];
    for(int i=0; i<pArgs->count(); i++){
        CCObject* arg = pArgs->objectAtIndex(i);
        if(CCString* s = dynamic_cast<CCString*>(arg)){
            args[i] = mrb_str_buf_new(m_mrb, s->length());
            mrb_str_buf_cat(m_mrb, args[i], s->getCString(), s->length());
        }else if(CCInteger* cci = dynamic_cast<CCInteger*>(arg)){
            args[i] = mrb_fixnum_value(cci->getValue());
        }else if(CCSwipe* obj = dynamic_cast<CCSwipe*>(arg)){
            args[i] = _wrap_CCSwipe(m_mrb, obj);
        }else if(CCNode* obj = dynamic_cast<CCNode*>(arg)){
            args[i] = _wrap_CCNode(m_mrb, obj);
        }else if(CCObject* obj = dynamic_cast<CCObject*>(arg)){
            args[i] = _wrap_CCObject(m_mrb, obj);
        }else{
            args[i] = mrb_nil_value();
        }
    }
    mrb_funcall_argv(m_mrb, block, mrb_intern_cstr(m_mrb,"call"), pArgs->count(), args);
    delete[] args;

    bool exc = checkUncaughtException(m_mrb);
    mrb_gc_arena_restore(m_mrb, arena);
    return !exc;
}

/** called by CCAssert to allow scripting engine to handle failed assertions
 * @return true if the assert was handled by the script engine, false otherwise.
 */
bool CCMrubyEngine::handleAssert(const char *msg)
{
  CCLOGERROR("CCMrubyEngine::handleAssert has not implemented: %s", msg);
  return 0;
}

bool CCMrubyEngine::parseConfig(ConfigType type, const std::string& str)
{
    return false;
}

NS_CC_END
