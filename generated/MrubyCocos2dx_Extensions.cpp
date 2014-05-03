#include "mruby/mruby.h"
#include "cocos2d.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);

#include "CCSwipeGestureRecognizer.h"

USING_NS_CC;

class CCSwipeGestureRecognizerForScript : public CCSwipeGestureRecognizer
{
public:
    CREATE_FUNC(CCSwipeGestureRecognizerForScript);
    void setHandler(int nHandler);
    void didRecognizeGesture(CCObject * obj);
    int _nHandler = -1;
};

void CCSwipeGestureRecognizerForScript::setHandler(int nHandler)
{
    _nHandler = nHandler;
    this->setTarget(this, callfuncO_selector(CCSwipeGestureRecognizerForScript::didRecognizeGesture));
}

void CCSwipeGestureRecognizerForScript::didRecognizeGesture(CCObject * obj)
{
    CCSwipe* swipe = (CCSwipe*)obj;
    CCArray* pArrayArgs = CCArray::createWithCapacity(1);
    pArrayArgs->addObject(swipe);
    CCScriptEngineManager::sharedManager()->getScriptEngine()->executeEventWithArgs(_nHandler, pArrayArgs);
}

mrb_value _wrap_CCPoint(mrb_state *mrb, const CCPoint* ptr);


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
// CCGestureRecognizer
static void _dfree_CCGestureRecognizer(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_CCGestureRecognizer = { "CCGestureRecognizer", _dfree_CCGestureRecognizer };
mrb_value _wrap_CCGestureRecognizer(mrb_state *mrb, const CCGestureRecognizer* ptr) {
  struct RClass* tc = getClass(mrb, "CCGestureRecognizer");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCGestureRecognizer, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCGestureRecognizer;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCGestureRecognizer_setCancelsTouchesInView(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCGestureRecognizer* instance = static_cast<CCGestureRecognizer*>(DATA_PTR(self));
  instance->setCancelsTouchesInView(p0);
  return mrb_nil_value();
}

static void installCCGestureRecognizer(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCLayer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCGestureRecognizer", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "setCancelsTouchesInView", CCGestureRecognizer_setCancelsTouchesInView, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSwipe
static void _dfree_CCSwipe(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_CCSwipe = { "CCSwipe", _dfree_CCSwipe };
mrb_value _wrap_CCSwipe(mrb_state *mrb, const CCSwipe* ptr) {
  struct RClass* tc = getClass(mrb, "CCSwipe");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSwipe, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSwipe;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSwipe_direction(mrb_state *mrb, mrb_value self) {
  CCSwipe* instance = static_cast<CCSwipe*>(DATA_PTR(self));
  return mrb_fixnum_value((int)instance->direction);
}

static mrb_value CCSwipe_set_direction(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCSwipe* instance = static_cast<CCSwipe*>(DATA_PTR(self));
  instance->direction = (CCSwipeGestureRecognizerDirection)mrb_fixnum(o);
  return mrb_nil_value();
}

static mrb_value CCSwipe_location(mrb_state *mrb, mrb_value self) {
  CCSwipe* instance = static_cast<CCSwipe*>(DATA_PTR(self));
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(instance->location));
}

static mrb_value CCSwipe_set_location(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCSwipe* instance = static_cast<CCSwipe*>(DATA_PTR(self));
  instance->location = *static_cast<CCPoint*>(DATA_PTR(o));
  return mrb_nil_value();
}

static void installCCSwipe(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSwipe", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "direction", CCSwipe_direction, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "direction=", CCSwipe_set_direction, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "location", CCSwipe_location, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "location=", CCSwipe_set_location, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCSwipeGestureRecognizer
static void _dfree_CCSwipeGestureRecognizer(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_CCSwipeGestureRecognizer = { "CCSwipeGestureRecognizer", _dfree_CCSwipeGestureRecognizer };
mrb_value _wrap_CCSwipeGestureRecognizer(mrb_state *mrb, const CCSwipeGestureRecognizer* ptr) {
  struct RClass* tc = getClass(mrb, "CCSwipeGestureRecognizer");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSwipeGestureRecognizer, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSwipeGestureRecognizer;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSwipeGestureRecognizer_setDirection(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  int p0 = get_int(args[0]);
  CCSwipeGestureRecognizer* instance = static_cast<CCSwipeGestureRecognizer*>(DATA_PTR(self));
  instance->setDirection(p0);
  return mrb_nil_value();
}

static void installCCSwipeGestureRecognizer(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCGestureRecognizer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSwipeGestureRecognizer", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "setDirection", CCSwipeGestureRecognizer_setDirection, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSwipeGestureRecognizerForScript
static void _dfree_CCSwipeGestureRecognizerForScript(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_CCSwipeGestureRecognizerForScript = { "CCSwipeGestureRecognizerForScript", _dfree_CCSwipeGestureRecognizerForScript };
mrb_value _wrap_CCSwipeGestureRecognizerForScript(mrb_state *mrb, const CCSwipeGestureRecognizerForScript* ptr) {
  struct RClass* tc = getClass(mrb, "CCSwipeGestureRecognizerForScript");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSwipeGestureRecognizerForScript, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSwipeGestureRecognizerForScript;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSwipeGestureRecognizerForScript_create(mrb_state *mrb, mrb_value self) {

  
  CCSwipeGestureRecognizerForScript* retval = CCSwipeGestureRecognizerForScript::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSwipeGestureRecognizerForScript(mrb, retval));
}

static mrb_value CCSwipeGestureRecognizerForScript_setHandler(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  CCSwipeGestureRecognizerForScript* instance = static_cast<CCSwipeGestureRecognizerForScript*>(DATA_PTR(self));
  instance->setHandler(blockHandler);
  return mrb_nil_value();
}

static void installCCSwipeGestureRecognizerForScript(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCSwipeGestureRecognizer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSwipeGestureRecognizerForScript", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCSwipeGestureRecognizerForScript_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setHandler", CCSwipeGestureRecognizerForScript_setHandler, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

void installMrubyCocos2dx_Extensions(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Cocos2dx");
  mrb_define_const(mrb, mod, "KSwipeGestureRecognizerDirectionRight", mrb_fixnum_value(kSwipeGestureRecognizerDirectionRight));
  mrb_define_const(mrb, mod, "KSwipeGestureRecognizerDirectionLeft", mrb_fixnum_value(kSwipeGestureRecognizerDirectionLeft));
  mrb_define_const(mrb, mod, "KSwipeGestureRecognizerDirectionUp", mrb_fixnum_value(kSwipeGestureRecognizerDirectionUp));
  mrb_define_const(mrb, mod, "KSwipeGestureRecognizerDirectionDown", mrb_fixnum_value(kSwipeGestureRecognizerDirectionDown));
  installCCGestureRecognizer(mrb, mod);
  installCCSwipe(mrb, mod);
  installCCSwipeGestureRecognizer(mrb, mod);
  installCCSwipeGestureRecognizerForScript(mrb, mod);
}
