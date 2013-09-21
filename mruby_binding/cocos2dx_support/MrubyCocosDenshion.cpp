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
  RClass* mod = mrb_class_get(mrb, "CocosDenshion");
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
// SimpleAudioEngine

static mrb_value SimpleAudioEngine_sharedEngine(mrb_state *mrb, mrb_value self) {

  
  SimpleAudioEngine* retval = SimpleAudioEngine::sharedEngine();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "SimpleAudioEngine"));
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

static mrb_value SimpleAudioEngine_playEffect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
    instance->playEffect(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    bool p1 = get_bool(args[1]);
    SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
    instance->playEffect(p0, p1);
    return mrb_nil_value();
  } else {
    // TODO: raise exception.
    return mrb_nil_value();
  }
}

static mrb_value SimpleAudioEngine_stopEffect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  unsigned int p0 = get_int(args[0]);
  SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
  instance->stopEffect(p0);
  return mrb_nil_value();
}

static mrb_value SimpleAudioEngine_stopAllEffects(mrb_state *mrb, mrb_value self) {

  SimpleAudioEngine* instance = static_cast<SimpleAudioEngine*>(DATA_PTR(self));
  instance->stopAllEffects();
  return mrb_nil_value();
}

static void installSimpleAudioEngine(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "SimpleAudioEngine", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedEngine", SimpleAudioEngine_sharedEngine, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "playBackgroundMusic", SimpleAudioEngine_playBackgroundMusic, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "preloadEffect", SimpleAudioEngine_preloadEffect, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "playEffect", SimpleAudioEngine_playEffect, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "stopEffect", SimpleAudioEngine_stopEffect, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "stopAllEffects", SimpleAudioEngine_stopAllEffects, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

void installMrubyCocosDenshion(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "CocosDenshion");
  installSimpleAudioEngine(mrb, mod);
}
