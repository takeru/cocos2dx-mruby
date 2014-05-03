#include "WebSocket.h"
#include "mruby/mruby.h"
#include <string>
#include "cocos2d.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);
USING_NS_CC;

namespace cocos2dmruby {
class WebSocket :
  public cocos2d::extension::WebSocket,
  public cocos2d::extension::WebSocket::Delegate
{
private:
    int _nHandler = -1;
public:
    static WebSocket* create(int nHandler, const std::string& url);
    void onOpen(cocos2d::extension::WebSocket* ws);
    void onMessage(cocos2d::extension::WebSocket* ws, const cocos2d::extension::WebSocket::Data& data);
    void onClose(cocos2d::extension::WebSocket* ws);
    void onError(cocos2d::extension::WebSocket* ws, const cocos2d::extension::WebSocket::ErrorCode& error);
};

WebSocket* WebSocket::create(int nHandler, const std::string& url)
{
    WebSocket* ws = new WebSocket();
    ws->init(*ws, url, NULL);
    ws->_nHandler = nHandler;
    return ws;
}

void WebSocket::onOpen(cocos2d::extension::WebSocket* ws)
{
    CCArray* pArrayArgs = CCArray::createWithCapacity(1);
    pArrayArgs->addObject(CCString::create("open"));
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeEventWithArgs(_nHandler, pArrayArgs);
}

void WebSocket::onMessage(cocos2d::extension::WebSocket* ws, const cocos2d::extension::WebSocket::Data& data)
{
    CCArray* pArrayArgs = CCArray::createWithCapacity(2);
    pArrayArgs->addObject(CCString::create("message"));
    pArrayArgs->addObject(CCString::createWithData((unsigned char*)data.bytes, data.len));
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeEventWithArgs(_nHandler, pArrayArgs);
}

void WebSocket::onClose(cocos2d::extension::WebSocket* ws)
{
    CCArray* pArrayArgs = CCArray::createWithCapacity(1);
    pArrayArgs->addObject(CCString::create("close"));
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeEventWithArgs(_nHandler, pArrayArgs);
    CC_SAFE_DELETE(ws);
}

void WebSocket::onError(cocos2d::extension::WebSocket* ws, const cocos2d::extension::WebSocket::ErrorCode& error)
{
    CCArray* pArrayArgs = CCArray::createWithCapacity(2);
    pArrayArgs->addObject(CCString::create("error"));
    pArrayArgs->addObject(CCInteger::create(error));
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeEventWithArgs(_nHandler, pArrayArgs);
}

}// end of namespace cocos2dmruby.
using namespace cocos2dmruby;

#include "mruby/mruby.h"
#include "mruby/mruby/class.h"
#include "mruby/mruby/data.h"
#include "mruby/mruby/string.h"
#include "mruby/mruby/variable.h"
#include <new>
#include <assert.h>

static bool get_bool(mrb_value x) {
  return mrb_bool(x);
}

static int get_int(mrb_value x) {
  if (mrb_fixnum_p(x)) {
    return mrb_fixnum(x);
  } else if (mrb_float_p(x)) {
    return mrb_float(x);
  } else {
    return 0;
  }
}

static float get_float(mrb_value x) {
  if (mrb_fixnum_p(x)) {
    return mrb_fixnum(x);
  } else if (mrb_float_p(x)) {
    return mrb_float(x);
  } else {
    return 0;
  }
}

static struct RClass* getClass(mrb_state *mrb, const char* className) {
  RClass* mod = mrb_module_get(mrb, "Cocos2dx");
  return mrb_class_get_under(mrb, mod, className);
}


////////////////////////////////////////////////////////////////
// WebSocket
static void _dfree_WebSocket(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_WebSocket = { "WebSocket", _dfree_WebSocket };
mrb_value _wrap_WebSocket(mrb_state *mrb, const WebSocket* ptr) {
  struct RClass* tc = getClass(mrb, "WebSocket");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_WebSocket, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_WebSocket;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value WebSocket___ctor(mrb_state *mrb, mrb_value self) {

  
  WebSocket* retval = new(mrb_malloc(mrb, sizeof(WebSocket))) WebSocket();
  DATA_TYPE(self) = &_mrb_data_type_WebSocket; DATA_PTR(self) = retval; return self;
}

static mrb_value WebSocket_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  const std::string& p0 = std::string(mrb_string_value_ptr(mrb, args[0]));
  
  WebSocket* retval = WebSocket::create(blockHandler, p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_WebSocket(mrb, retval));
}

static mrb_value WebSocket_send(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const std::string& p0 = std::string(mrb_string_value_ptr(mrb, args[0]));
  WebSocket* instance = static_cast<WebSocket*>(DATA_PTR(self));
  instance->send(p0);
  return mrb_nil_value();
}

static mrb_value WebSocket_close(mrb_state *mrb, mrb_value self) {

  WebSocket* instance = static_cast<WebSocket*>(DATA_PTR(self));
  instance->close();
  return mrb_nil_value();
}

static void installWebSocket(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "WebSocket", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", WebSocket___ctor, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "create", WebSocket_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "send", WebSocket_send, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "close", WebSocket_close, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

void installMrubyCocos2dx_WebSocket(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Cocos2dx");
  installWebSocket(mrb, mod);
}
