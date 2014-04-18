#include "WebSocket.h"
#include "mruby/mruby.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);
USING_NS_CC_EXT;

// TODO release WebSocket object.

#include "mruby/mruby.h"
#include "mruby/mruby/class.h"
#include "mruby/mruby/data.h"
#include "mruby/mruby/string.h"
#include "mruby/mruby/variable.h"
#include <new>
#include <assert.h>

static void dummy(mrb_state *mrb, void *ptr) {
  //printf("dummy called\n");
}

// TODO: Use different data type for each class.
static struct mrb_data_type dummy_type = { "Dummy", dummy };

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
  RClass* mod = mrb_module_get(mrb, "Cocos2d");
  return mrb_class_get_under(mrb, mod, className);
}

template <class T>
mrb_value wrap(mrb_state *mrb, T* ptr, const char* type) {
  struct RClass* tc = getClass(mrb, type);
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &dummy_type, NULL));
  DATA_TYPE(instance) = &dummy_type;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

////////////////////////////////////////////////////////////////
// WebSocket

static mrb_value WebSocket___ctor(mrb_state *mrb, mrb_value self) {

  
  WebSocket* retval = new WebSocket();
  DATA_PTR(self) = retval; return self;
}

static mrb_value WebSocket_init(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  const std::string& p0 = std::string(mrb_string_value_ptr(mrb, args[0]));
  WebSocket* instance = static_cast<WebSocket*>(DATA_PTR(self));
  bool retval = instance->init(blockHandler, p0);
  return mrb_bool_value(retval);
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
  mrb_define_method(mrb, tc, "init", WebSocket_init, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "send", WebSocket_send, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "close", WebSocket_close, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

void installMrubyCocos2d_WebSocket(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Cocos2d");
  installWebSocket(mrb, mod);
}
