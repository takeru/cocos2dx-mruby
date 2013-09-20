#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/data.h"
#include "mruby/string.h"
#include "mruby/variable.h"
#include <new>
#include <assert.h>

static void dummy(mrb_state *mrb, void *ptr) {
  //printf("dummy called\n");
}

// TODO: Use different data type for each class.
static struct mrb_data_type dummy_type = { "Dummy", dummy };

static float get_bool(mrb_value x) {
  return mrb_bool(x);
}

static float get_int(mrb_value x) {
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

static mrb_value getMrubyCocos2dClassValue(mrb_state *mrb, const char* className) {
  mrb_sym sym = mrb_intern_cstr(mrb, "CocosDenshion");
  mrb_value mod = mrb_const_get(mrb, mrb_obj_value(mrb->kernel_module), sym);
  mrb_value klass = mrb_iv_get(mrb, mod, mrb_intern_cstr(mrb, className));
  return klass;
}

static struct RClass* getMrubyCocos2dClassPtr(mrb_state *mrb, const char* className) {
  return mrb_class_ptr(getMrubyCocos2dClassValue(mrb, className));
}

template <class T>
mrb_value wrap(mrb_state *mrb, T* ptr, const char* type) {
  struct RClass* tc = getMrubyCocos2dClassPtr(mrb, type);
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &dummy_type, NULL));
  DATA_TYPE(instance) = &dummy_type;
  DATA_PTR(instance) = ptr;
  return instance;
}

////////////////////////////////////////////////////////////////
// SimpleAudioEngine

static mrb_value SimpleAudioEngine_sharedEngine(mrb_state *mrb, mrb_value self) {

  
  SimpleAudioEngine* retval = SimpleAudioEngine::sharedEngine();
  return wrap(mrb, retval, "SimpleAudioEngine");
}

static mrb_value SimpleAudioEngine_playBackgroundMusic(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
    instance->playBackgroundMusic(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    bool p1 = get_bool(args[1]);
    SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
    instance->playBackgroundMusic(p0, p1);
    return mrb_nil_value();
  } else {
    // TODO: raise exception.
    return mrb_nil_value();
  }
}

static mrb_value SimpleAudioEngine_preloadEffect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
  instance->preloadEffect(p0);
  return mrb_nil_value();
}

static void installSimpleAudioEngine(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "SimpleAudioEngine", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedEngine", SimpleAudioEngine_sharedEngine, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "playBackgroundMusic", SimpleAudioEngine_playBackgroundMusic, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "preloadEffect", SimpleAudioEngine_preloadEffect, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

void installMrubyCocosDenshion(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "CocosDenshion");
  installSimpleAudioEngine(mrb, mod);
}
