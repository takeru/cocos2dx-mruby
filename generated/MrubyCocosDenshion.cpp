#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

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
  RClass* mod = mrb_module_get(mrb, "CocosDenshion");
  return mrb_class_get_under(mrb, mod, className);
}


////////////////////////////////////////////////////////////////
// SimpleAudioEngine
static void _dfree_SimpleAudioEngine(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_SimpleAudioEngine = { "SimpleAudioEngine", _dfree_SimpleAudioEngine };
mrb_value _wrap_SimpleAudioEngine(mrb_state *mrb, const SimpleAudioEngine* ptr) {
  struct RClass* tc = getClass(mrb, "SimpleAudioEngine");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_SimpleAudioEngine, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_SimpleAudioEngine;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}
SimpleAudioEngine* get_SimpleAudioEngine(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "SimpleAudioEngine");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<SimpleAudioEngine*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is SimpleAudioEngine.");
    return NULL;
  }
}

static mrb_value SimpleAudioEngine_sharedEngine(mrb_state *mrb, mrb_value self) {

  
  SimpleAudioEngine* retval = SimpleAudioEngine::sharedEngine();
  return (retval == NULL ? mrb_nil_value() : _wrap_SimpleAudioEngine(mrb, retval));
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "SimpleAudioEngine#playBackgroundMusic Wrong count of arguments.");
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "SimpleAudioEngine#playEffect Wrong count of arguments.");
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
