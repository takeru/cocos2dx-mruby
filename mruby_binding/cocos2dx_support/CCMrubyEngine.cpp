//
//  CCMrubyEngine.cpp
//  CocosMruby
//
//  Created by admin on 13/09/17.
//
//

#include "CCMrubyEngine.h"
#include "mruby.h"
#include "mruby/array.h"
#include "mruby/compile.h"
#include "mruby/string.h"

NS_CC_BEGIN

static const char HelperFunctions[] =
"module Cocos2d\n"
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
"end\n";

////////////////////////////////////////////////////////////////
// Misc.
static mrb_value _mrb_puts(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int n;
  mrb_get_args(mrb, "*", &args, &n);
  for (int i = 0; i < n; ++i) {
    mrb_value s = mrb_funcall(mrb, args[i], "to_s", 0);
    CCLOG("%s", RSTRING_PTR(s));
  }
  return mrb_nil_value();
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
  mrb_define_method(m_mrb, m_mrb->kernel_module, "cclog", _mrb_puts, MRB_ARGS_ANY());
  mrb_define_method(m_mrb, m_mrb->kernel_module, "puts", _mrb_puts, MRB_ARGS_ANY());
  mrb_define_method(m_mrb, m_mrb->kernel_module, "p", _mrb_puts, MRB_ARGS_ANY());

  // Installs cocos2d classes.
  installMrubyCocos2dBindings(m_mrb);
  
  // Installs helper functions.
  // This line must be after installing mruby bindings,
  // because it creates new module for `Cocos2d'.
  mrb_load_string(m_mrb, HelperFunctions);
  
  return true;
}

/** Remove script object. */
void CCMrubyEngine::removeScriptObjectByCCObject(CCObject* pObj)
{
  CCLOGERROR("CCRubyEngine::removeScriptObjectByCCObject has not implemented: %p", pObj);
}

int CCMrubyEngine::executeString(const char* codes)
{
  mrb_load_string(m_mrb, codes);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeScriptFile(const char* filename)
{
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    CCLOGERROR("Can't open %s", filename);
    return FALSE;
  }

  mrb_load_file(m_mrb, fp);
  fclose(fp);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeGlobalFunction(const char* functionName)
{
  mrb_funcall(m_mrb, mrb_top_self(m_mrb), functionName, 0);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeNodeEvent(CCNode* pNode, int nAction)
{
  int nHandler = pNode->getScriptHandler();
  if (!nHandler) return 0;
  
  int areana = mrb_gc_arena_save(m_mrb);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_funcall(m_mrb, proc, "call", 1, mrb_fixnum_value(nAction));
  mrb_gc_arena_restore(m_mrb, areana);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeMenuItemEvent(CCMenuItem* pMenuItem)
{
  CCLOGERROR("CCRubyEngine::executeMenuItemEvent has not implemented: %p", pMenuItem);
  return 0;
}

int CCMrubyEngine::executeNotificationEvent(CCNotificationCenter* pNotificationCenter, const char* pszName)
{
  CCLOGERROR("CCRubyEngine::executeNotificationEvent has not implemented: %p, %s", pNotificationCenter, pszName);
  return 0;
}

int CCMrubyEngine::executeCallFuncActionEvent(CCCallFunc* pAction, CCObject* pTarget)
{
  CCLOGERROR("CCRubyEngine::executeCallFuncActionEvent has not implemented: %p, %p", pAction, pTarget);
  return 0;
}

int CCMrubyEngine::executeSchedule(int nHandler, float dt, CCNode* pNode)
{
  if (!nHandler) return FALSE;

  int areana = mrb_gc_arena_save(m_mrb);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_funcall(m_mrb, proc, "call", 1, mrb_float_value(m_mrb, dt));
  mrb_gc_arena_restore(m_mrb, areana);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeLayerTouchesEvent(CCLayer* pLayer, int eventType, CCSet *pTouches)
{
  CCLOGERROR("CCRubyEngine::executeLayerTouchesEvent has not implemented: %p, %d, %p", pLayer, eventType, pTouches);
  return 0;
}

int CCMrubyEngine::executeLayerTouchEvent(CCLayer* pLayer, int eventType, CCTouch *pTouch)
{
  CCTouchScriptHandlerEntry* pScriptHandlerEntry = pLayer->getScriptTouchHandlerEntry();
  if (!pScriptHandlerEntry) return FALSE;
  int nHandler = pScriptHandlerEntry->getHandler();
  if (!nHandler) return FALSE;
  
  int areana = mrb_gc_arena_save(m_mrb);
  const CCPoint pt = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
  mrb_value x = mrb_float_value(m_mrb, pt.x);
  mrb_value y = mrb_float_value(m_mrb, pt.y);
  mrb_value proc = getRegisteredProc(m_mrb, nHandler);
  mrb_funcall(m_mrb, proc, "call", 3, mrb_fixnum_value(eventType), x, y);
  mrb_gc_arena_restore(m_mrb, areana);
  if (m_mrb->exc) {
    mrb_p(m_mrb, mrb_obj_value(m_mrb->exc));
    return FALSE;
  }
  return TRUE;
}

int CCMrubyEngine::executeLayerKeypadEvent(CCLayer* pLayer, int eventType)
{
  CCLOGERROR("CCRubyEngine::executeLayerKeypadEvent has not implemented: %p, %d", pLayer, eventType);
  return 0;
}

int CCMrubyEngine::executeAccelerometerEvent(CCLayer* pLayer, CCAcceleration* pAccelerationValue)
{
  CCLOGERROR("CCRubyEngine::executeAccelerometerEvent has not implemented: %p, %p", pLayer, pAccelerationValue);
  return 0;
}

int CCMrubyEngine::executeEvent(int nHandler, const char* pEventName, CCObject* pEventSource, const char* pEventSourceClassName)
{
  CCLOGERROR("CCRubyEngine::executeEvent has not implemented: %d, %s, %p, %s", nHandler, pEventName, pEventSource, pEventSourceClassName);
  return 0;
}


/** called by CCAssert to allow scripting engine to handle failed assertions
 * @return true if the assert was handled by the script engine, false otherwise.
 */
bool CCMrubyEngine::handleAssert(const char *msg)
{
  CCLOGERROR("CCRubyEngine::handleAssert has not implemented: %s", msg);
  return 0;
}

NS_CC_END
