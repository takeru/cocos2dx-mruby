#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "mruby/mruby.h"
#include "mruby/mruby/array.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);

using namespace cocos2d;

typedef ccColor3B CcColor3B;
typedef ccColor4F CcColor4F;

template <class T>
mrb_value wrap(mrb_state *mrb, T* ptr, const char* type);
mrb_value wrap_Cocos2dx_CCTouch(mrb_state *mrb, CCTouch* ptr) {
  return wrap(mrb, ptr, "CCTouch");
}
mrb_value wrap_Cocos2dx_CCObject(mrb_state *mrb, CCObject* ptr) {
  return wrap(mrb, ptr, "CCObject");
}
mrb_value wrap_Cocos2dx_CCNode(mrb_state *mrb, CCNode* ptr) {
  return wrap(mrb, ptr, "CCNode");
}


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
  RClass* mod = mrb_module_get(mrb, "Cocos2dx");
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
// CcColor3B

static mrb_value CcColor3B_r(mrb_state *mrb, mrb_value self) {
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->r);
}

static mrb_value CcColor3B_set_r(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  instance->r = get_int(o);
  return mrb_nil_value();
}

static mrb_value CcColor3B_g(mrb_state *mrb, mrb_value self) {
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->g);
}

static mrb_value CcColor3B_set_g(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  instance->g = get_int(o);
  return mrb_nil_value();
}

static mrb_value CcColor3B_b(mrb_state *mrb, mrb_value self) {
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->b);
}

static mrb_value CcColor3B_set_b(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor3B* instance = static_cast<CcColor3B*>(DATA_PTR(self));
  instance->b = get_int(o);
  return mrb_nil_value();
}

static void installCcColor3B(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcColor3B", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "r", CcColor3B_r, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "r=", CcColor3B_set_r, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "g", CcColor3B_g, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "g=", CcColor3B_set_g, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "b", CcColor3B_b, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "b=", CcColor3B_set_b, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CcColor4F

static mrb_value CcColor4F_r(mrb_state *mrb, mrb_value self) {
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->r);
}

static mrb_value CcColor4F_set_r(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  instance->r = get_float(o);
  return mrb_nil_value();
}

static mrb_value CcColor4F_g(mrb_state *mrb, mrb_value self) {
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->g);
}

static mrb_value CcColor4F_set_g(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  instance->g = get_float(o);
  return mrb_nil_value();
}

static mrb_value CcColor4F_b(mrb_state *mrb, mrb_value self) {
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->b);
}

static mrb_value CcColor4F_set_b(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  instance->b = get_float(o);
  return mrb_nil_value();
}

static mrb_value CcColor4F_a(mrb_state *mrb, mrb_value self) {
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->a);
}

static mrb_value CcColor4F_set_a(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CcColor4F* instance = static_cast<CcColor4F*>(DATA_PTR(self));
  instance->a = get_float(o);
  return mrb_nil_value();
}

static void installCcColor4F(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcColor4F", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "r", CcColor4F_r, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "r=", CcColor4F_set_r, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "g", CcColor4F_g, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "g=", CcColor4F_set_g, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "b", CcColor4F_b, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "b=", CcColor4F_set_b, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "a", CcColor4F_a, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "a=", CcColor4F_set_a, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCPoint

static mrb_value CCPoint___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCPoint* retval = new CCPoint();
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCPoint* retval = new CCPoint(p0, p1);
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
    
    CCPoint* retval = new CCPoint(p0);
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *static_cast<CCSize*>(DATA_PTR(args[0]));
    
    CCPoint* retval = new CCPoint(p0);
    DATA_PTR(self) = retval; return self;
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCPoint#__ctor");
    return mrb_nil_value();
  }
}

static mrb_value CCPoint_x(mrb_state *mrb, mrb_value self) {
  CCPoint* instance = static_cast<CCPoint*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->x);
}

static mrb_value CCPoint_set_x(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCPoint* instance = static_cast<CCPoint*>(DATA_PTR(self));
  instance->x = get_float(o);
  return mrb_nil_value();
}

static mrb_value CCPoint_y(mrb_state *mrb, mrb_value self) {
  CCPoint* instance = static_cast<CCPoint*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->y);
}

static mrb_value CCPoint_set_y(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCPoint* instance = static_cast<CCPoint*>(DATA_PTR(self));
  instance->y = get_float(o);
  return mrb_nil_value();
}

static void installCCPoint(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCPoint", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCPoint___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "x", CCPoint_x, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "x=", CCPoint_set_x, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "y", CCPoint_y, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "y=", CCPoint_set_y, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCSize

static mrb_value CCSize___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSize* retval = new CCSize();
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCSize* retval = new CCSize(p0, p1);
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
    
    CCSize* retval = new CCSize(p0);
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *static_cast<CCSize*>(DATA_PTR(args[0]));
    
    CCSize* retval = new CCSize(p0);
    DATA_PTR(self) = retval; return self;
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSize#__ctor");
    return mrb_nil_value();
  }
}

static mrb_value CCSize_width(mrb_state *mrb, mrb_value self) {
  CCSize* instance = static_cast<CCSize*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->width);
}

static mrb_value CCSize_set_width(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCSize* instance = static_cast<CCSize*>(DATA_PTR(self));
  instance->width = get_float(o);
  return mrb_nil_value();
}

static mrb_value CCSize_height(mrb_state *mrb, mrb_value self) {
  CCSize* instance = static_cast<CCSize*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->height);
}

static mrb_value CCSize_set_height(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCSize* instance = static_cast<CCSize*>(DATA_PTR(self));
  instance->height = get_float(o);
  return mrb_nil_value();
}

static void installCCSize(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSize", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCSize___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "width", CCSize_width, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "width=", CCSize_set_width, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "height", CCSize_height, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "height=", CCSize_set_height, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCRect

static mrb_value CCRect___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCRect* retval = new CCRect();
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 4) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    float p2 = get_float(args[2]);
    float p3 = get_float(args[3]);
    
    CCRect* retval = new CCRect(p0, p1, p2, p3);
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCRect& p0 = *static_cast<CCRect*>(DATA_PTR(args[0]));
    
    CCRect* retval = new CCRect(p0);
    DATA_PTR(self) = retval; return self;
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCRect#__ctor");
    return mrb_nil_value();
  }
}

static mrb_value CCRect_origin(mrb_state *mrb, mrb_value self) {
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(instance->origin), "CCPoint");
}

static mrb_value CCRect_set_origin(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  instance->origin = *static_cast<CCPoint*>(DATA_PTR(o));
  return mrb_nil_value();
}

static mrb_value CCRect_size(mrb_state *mrb, mrb_value self) {
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(instance->size), "CCSize");
}

static mrb_value CCRect_set_size(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  instance->size = *static_cast<CCSize*>(DATA_PTR(o));
  return mrb_nil_value();
}

static mrb_value CCRect_containsPoint(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  bool retval = instance->containsPoint(p0);
  return mrb_bool_value(retval);
}

static mrb_value CCRect_intersectsRect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCRect& p0 = *static_cast<CCRect*>(DATA_PTR(args[0]));
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  bool retval = instance->intersectsRect(p0);
  return mrb_bool_value(retval);
}

static void installCCRect(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCRect", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCRect___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "origin", CCRect_origin, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "origin=", CCRect_set_origin, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "size", CCRect_size, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "size=", CCRect_set_size, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "containsPoint", CCRect_containsPoint, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "intersectsRect", CCRect_intersectsRect, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCObject

static mrb_value CCObject_release(mrb_state *mrb, mrb_value self) {

  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  instance->release();
  return mrb_nil_value();
}

static mrb_value CCObject_autorelease(mrb_state *mrb, mrb_value self) {

  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  CCObject* retval = instance->autorelease();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCObject"));
}

static mrb_value CCObject_retainCount(mrb_state *mrb, mrb_value self) {

  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  unsigned int retval = instance->retainCount();
  return mrb_fixnum_value(retval);
}

static mrb_value CCObject_m_nLuaID(mrb_state *mrb, mrb_value self) {
  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->m_nLuaID);
}

static mrb_value CCObject_set_m_nLuaID(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  instance->m_nLuaID = get_int(o);
  return mrb_nil_value();
}

static mrb_value CCObject_m_uID(mrb_state *mrb, mrb_value self) {
  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->m_uID);
}

static mrb_value CCObject_set_m_uID(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  instance->m_uID = get_int(o);
  return mrb_nil_value();
}

static mrb_value CCObject_dataptr(mrb_state *mrb, mrb_value self) {
  return mrb_fixnum_value((int)DATA_PTR(self));
}

static void installCCObject(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCObject", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "release", CCObject_release, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "autorelease", CCObject_autorelease, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "retainCount", CCObject_retainCount, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "m_nLuaID", CCObject_m_nLuaID, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "m_nLuaID=", CCObject_set_m_nLuaID, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "m_uID", CCObject_m_uID, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "m_uID=", CCObject_set_m_uID, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "dataptr", CCObject_dataptr, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCArray

static mrb_value CCArray_create(mrb_state *mrb, mrb_value self) {

  
  CCArray* retval = CCArray::create();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCArray"));
}

static mrb_value CCArray_addObject(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCObject* p0 = static_cast<CCObject*>(DATA_PTR(args[0]));
  CCArray* instance = static_cast<CCArray*>(DATA_PTR(self));
  instance->addObject(p0);
  return mrb_nil_value();
}

static void installCCArray(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCArray", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCArray_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addObject", CCArray_addObject, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCAction

static void installCCAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCFiniteTimeAction

static void installCCFiniteTimeAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCFiniteTimeAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInterval

static void installCCActionInterval(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInterval", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInstant

static void installCCActionInstant(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInstant", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCNode

static mrb_value CCNode_setPosition(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->setPosition(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->setPosition(p0, p1);
    return mrb_nil_value();
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCNode#setPosition");
    return mrb_nil_value();
  }
}

static mrb_value CCNode_setPositionX(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setPositionX(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getPositionX(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  float retval = instance->getPositionX();
  return mrb_float_value(mrb, retval);
}

static mrb_value CCNode_setPositionY(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setPositionY(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getPositionY(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  float retval = instance->getPositionY();
  return mrb_float_value(mrb, retval);
}

static mrb_value CCNode_getPosition(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  const CCPoint& retval = instance->getPosition();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCNode_setRotation(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setRotation(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getRotation(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  float retval = instance->getRotation();
  return mrb_float_value(mrb, retval);
}

static mrb_value CCNode_setAnchorPoint(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setAnchorPoint(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getAnchorPoint(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  const CCPoint& retval = instance->getAnchorPoint();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCNode_addChild(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCNode* p0 = static_cast<CCNode*>(DATA_PTR(args[0]));
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    CCNode* p0 = static_cast<CCNode*>(DATA_PTR(args[0]));
    int p1 = get_int(args[1]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0, p1);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    CCNode* p0 = static_cast<CCNode*>(DATA_PTR(args[0]));
    int p1 = get_int(args[1]);
    int p2 = get_int(args[2]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0, p1, p2);
    return mrb_nil_value();
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCNode#addChild");
    return mrb_nil_value();
  }
}

static mrb_value CCNode_getChildByTag(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  int p0 = get_int(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCNode* retval = instance->getChildByTag(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCNode"));
}

static mrb_value CCNode_runAction(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCAction* p0 = static_cast<CCAction*>(DATA_PTR(args[0]));
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->runAction(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getContentSize(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  const CCSize& retval = instance->getContentSize();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static mrb_value CCNode_setVisible(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setVisible(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_scheduleUpdate(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->scheduleUpdate();
  return mrb_nil_value();
}

static mrb_value CCNode_scheduleUpdateWithPriorityLua(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  int p0 = get_int(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->scheduleUpdateWithPriorityLua(blockHandler, p0);
  return mrb_nil_value();
}

static mrb_value CCNode_boundingBox(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCRect retval = instance->boundingBox();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(retval), "CCRect");
}

static mrb_value CCNode_convertTouchToNodeSpace(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTouch* p0 = static_cast<CCTouch*>(DATA_PTR(args[0]));
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCPoint retval = instance->convertTouchToNodeSpace(p0);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCNode_getTag(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  int retval = instance->getTag();
  return mrb_fixnum_value(retval);
}

static mrb_value CCNode_setTag(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  int p0 = get_int(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setTag(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getZOrder(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  int retval = instance->getZOrder();
  return mrb_fixnum_value(retval);
}

static mrb_value CCNode_setZOrder(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  int p0 = get_int(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setZOrder(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getUserObject(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCObject* retval = instance->getUserObject();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCObject"));
}

static mrb_value CCNode_setUserObject(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCObject* p0 = static_cast<CCObject*>(DATA_PTR(args[0]));
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setUserObject(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_removeFromParentAndCleanup(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->removeFromParentAndCleanup(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_registerScriptHandler(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->registerScriptHandler(blockHandler);
  return mrb_nil_value();
}

static mrb_value CCNode_unregisterScriptHandler(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->unregisterScriptHandler();
  return mrb_nil_value();
}

static mrb_value CCNode_getScriptHandler(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  int retval = instance->getScriptHandler();
  return mrb_fixnum_value(retval);
}

static void installCCNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCNode", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "setPosition", CCNode_setPosition, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setPositionX", CCNode_setPositionX, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPositionX", CCNode_getPositionX, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setPositionY", CCNode_setPositionY, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPositionY", CCNode_getPositionY, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPosition", CCNode_getPosition, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setRotation", CCNode_setRotation, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getRotation", CCNode_getRotation, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAnchorPoint", CCNode_setAnchorPoint, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getAnchorPoint", CCNode_getAnchorPoint, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addChild", CCNode_addChild, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getChildByTag", CCNode_getChildByTag, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "runAction", CCNode_runAction, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getContentSize", CCNode_getContentSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setVisible", CCNode_setVisible, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "scheduleUpdate", CCNode_scheduleUpdate, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "scheduleUpdateWithPriorityLua", CCNode_scheduleUpdateWithPriorityLua, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "boundingBox", CCNode_boundingBox, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "convertTouchToNodeSpace", CCNode_convertTouchToNodeSpace, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getTag", CCNode_getTag, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTag", CCNode_setTag, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getZOrder", CCNode_getZOrder, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setZOrder", CCNode_setZOrder, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getUserObject", CCNode_getUserObject, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setUserObject", CCNode_setUserObject, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "removeFromParentAndCleanup", CCNode_removeFromParentAndCleanup, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "registerScriptHandler", CCNode_registerScriptHandler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "unregisterScriptHandler", CCNode_unregisterScriptHandler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getScriptHandler", CCNode_getScriptHandler, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCNodeRGBA

static mrb_value CCNodeRGBA_setColor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CcColor3B& p0 = *static_cast<CcColor3B*>(DATA_PTR(args[0]));
  CCNodeRGBA* instance = static_cast<CCNodeRGBA*>(DATA_PTR(self));
  instance->setColor(p0);
  return mrb_nil_value();
}

static void installCCNodeRGBA(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCNodeRGBA", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "setColor", CCNodeRGBA_setColor, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCTexture2D

static void installCCTexture2D(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTexture2D", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCTextureCache

static mrb_value CCTextureCache_sharedTextureCache(mrb_state *mrb, mrb_value self) {

  
  CCTextureCache* retval = CCTextureCache::sharedTextureCache();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCTextureCache"));
}

static mrb_value CCTextureCache_addImage(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCTextureCache* instance = static_cast<CCTextureCache*>(DATA_PTR(self));
  CCTexture2D* retval = instance->addImage(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCTexture2D"));
}

static void installCCTextureCache(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTextureCache", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedTextureCache", CCTextureCache_sharedTextureCache, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addImage", CCTextureCache_addImage, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpriteFrame

static mrb_value CCSpriteFrame_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
  
  CCSpriteFrame* retval = CCSpriteFrame::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSpriteFrame"));
}

static mrb_value CCSpriteFrame_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
  const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
  
  CCSpriteFrame* retval = CCSpriteFrame::createWithTexture(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSpriteFrame"));
}

static void installCCSpriteFrame(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSpriteFrame", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCSpriteFrame_create, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "createWithTexture", CCSpriteFrame_createWithTexture, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCAnimation

static mrb_value CCAnimation_createWithSpriteFrames(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCArray* p0 = static_cast<CCArray*>(DATA_PTR(args[0]));
  float p1 = get_float(args[1]);
  
  CCAnimation* retval = CCAnimation::createWithSpriteFrames(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCAnimation"));
}

static void installCCAnimation(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAnimation", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithSpriteFrames", CCAnimation_createWithSpriteFrames, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCAnimate

static mrb_value CCAnimate_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCAnimation* p0 = static_cast<CCAnimation*>(DATA_PTR(args[0]));
  
  CCAnimate* retval = CCAnimate::create(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCAnimate"));
}

static void installCCAnimate(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAnimate", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCAnimate_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCRepeatForever

static mrb_value CCRepeatForever_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCActionInterval* p0 = static_cast<CCActionInterval*>(DATA_PTR(args[0]));
  
  CCRepeatForever* retval = CCRepeatForever::create(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCRepeatForever"));
}

static void installCCRepeatForever(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCRepeatForever", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCRepeatForever_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCScaleTo

static mrb_value CCScaleTo_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCScaleTo* retval = CCScaleTo::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCScaleTo"));
}

static void installCCScaleTo(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScaleTo", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCScaleTo_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMoveBy

static mrb_value CCMoveBy_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *static_cast<CCPoint*>(DATA_PTR(args[1]));
  
  CCMoveBy* retval = CCMoveBy::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMoveBy"));
}

static void installCCMoveBy(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMoveBy", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMoveBy_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMoveTo

static mrb_value CCMoveTo_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *static_cast<CCPoint*>(DATA_PTR(args[1]));
  
  CCMoveTo* retval = CCMoveTo::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMoveTo"));
}

static void installCCMoveTo(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMoveBy");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMoveTo", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMoveTo_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCCallFunc

static mrb_value CCCallFunc_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  
  CCCallFunc* retval = CCCallFunc::create(blockHandler);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCCallFunc"));
}

static void installCCCallFunc(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInstant");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCCallFunc", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCCallFunc_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSequence

static mrb_value CCSequence_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[0]));
  CCFiniteTimeAction* p1 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[1]));
  
  CCActionInterval* retval = CCSequence::createWithTwoActions(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCActionInterval"));
}

static void installCCSequence(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSequence", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithTwoActions", CCSequence_createWithTwoActions, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpawn

static mrb_value CCSpawn_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[0]));
  CCFiniteTimeAction* p1 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[1]));
  
  CCActionInterval* retval = CCSpawn::createWithTwoActions(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCActionInterval"));
}

static void installCCSpawn(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSpawn", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithTwoActions", CCSpawn_createWithTwoActions, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSprite

static mrb_value CCSprite_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSprite* retval = CCSprite::create();
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
  } else if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    
    CCSprite* retval = CCSprite::create(p0);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    
    CCSprite* retval = CCSprite::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSprite#create");
    return mrb_nil_value();
  }
}

static mrb_value CCSprite_createWithSpriteFrame(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCSpriteFrame* p0 = static_cast<CCSpriteFrame*>(DATA_PTR(args[0]));
  
  CCSprite* retval = CCSprite::createWithSpriteFrame(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
}

static mrb_value CCSprite_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    
    CCSprite* retval = CCSprite::createWithTexture(p0);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
  } else if (arg_count == 2) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    
    CCSprite* retval = CCSprite::createWithTexture(p0, p1);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSprite"));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSprite#createWithTexture");
    return mrb_nil_value();
  }
}

static mrb_value CCSprite___ctor(mrb_state *mrb, mrb_value self) {

  
  CCSprite* retval = new CCSprite();
  DATA_PTR(self) = retval; return self;
}

static mrb_value CCSprite_initWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->initWithTexture(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->initWithTexture(p0, p1);
    return mrb_nil_value();
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSprite#initWithTexture");
    return mrb_nil_value();
  }
}

static mrb_value CCSprite_setTextureRect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const CCRect& p0 = *static_cast<CCRect*>(DATA_PTR(args[0]));
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->setTextureRect(p0);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    const CCRect& p0 = *static_cast<CCRect*>(DATA_PTR(args[0]));
    bool p1 = get_bool(args[1]);
    const CCSize& p2 = *static_cast<CCSize*>(DATA_PTR(args[2]));
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->setTextureRect(p0, p1, p2);
    return mrb_nil_value();
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSprite#setTextureRect");
    return mrb_nil_value();
  }
}

static void installCCSprite(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNodeRGBA");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCSprite_create, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "createWithSpriteFrame", CCSprite_createWithSpriteFrame, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "createWithTexture", CCSprite_createWithTexture, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "initialize", CCSprite___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "initWithTexture", CCSprite_initWithTexture, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTextureRect", CCSprite_setTextureRect, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpriteBatchNode

static mrb_value CCSpriteBatchNode___ctor(mrb_state *mrb, mrb_value self) {

  
  CCSpriteBatchNode* retval = new CCSpriteBatchNode();
  DATA_PTR(self) = retval; return self;
}

static mrb_value CCSpriteBatchNode_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    unsigned int p1 = get_int(args[1]);
    
    CCSpriteBatchNode* retval = CCSpriteBatchNode::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSpriteBatchNode"));
  } else if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    
    CCSpriteBatchNode* retval = CCSpriteBatchNode::create(p0);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCSpriteBatchNode"));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSpriteBatchNode#create");
    return mrb_nil_value();
  }
}

static mrb_value CCSpriteBatchNode_getTexture(mrb_state *mrb, mrb_value self) {

  CCSpriteBatchNode* instance = static_cast<CCSpriteBatchNode*>(DATA_PTR(self));
  CCTexture2D* retval = instance->getTexture();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCTexture2D"));
}

static void installCCSpriteBatchNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSpriteBatchNode", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCSpriteBatchNode___ctor, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "create", CCSpriteBatchNode_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getTexture", CCSpriteBatchNode_getTexture, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLabelTTF

static mrb_value CCLabelTTF_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const char* p1 = mrb_string_value_ptr(mrb, args[1]);
  float p2 = get_float(args[2]);
  
  CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCLabelTTF"));
}

static void installCCLabelTTF(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCSprite");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLabelTTF", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCLabelTTF_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLabelBMFont

static mrb_value CCLabelBMFont_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 3) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    
    CCLabelBMFont* retval = CCLabelBMFont::create(p0, p1, p2);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCLabelBMFont"));
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    
    CCLabelBMFont* retval = CCLabelBMFont::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCLabelBMFont"));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCLabelBMFont#create");
    return mrb_nil_value();
  }
}

static mrb_value CCLabelBMFont_setString(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCLabelBMFont* instance = static_cast<CCLabelBMFont*>(DATA_PTR(self));
  instance->setString(p0);
  return mrb_nil_value();
}

static void installCCLabelBMFont(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCSpriteBatchNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLabelBMFont", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCLabelBMFont_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setString", CCLabelBMFont_setString, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCDrawNode

static mrb_value CCDrawNode_create(mrb_state *mrb, mrb_value self) {

  
  CCDrawNode* retval = CCDrawNode::create();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCDrawNode"));
}

static mrb_value CCDrawNode_drawDot(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  float p1 = get_float(args[1]);
  const ccColor4F& p2 = *static_cast<ccColor4F*>(DATA_PTR(args[2]));
  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->drawDot(p0, p1, p2);
  return mrb_nil_value();
}

static mrb_value CCDrawNode_drawSegment(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  const CCPoint& p1 = *static_cast<CCPoint*>(DATA_PTR(args[1]));
  float p2 = get_float(args[2]);
  const ccColor4F& p3 = *static_cast<ccColor4F*>(DATA_PTR(args[3]));
  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->drawSegment(p0, p1, p2, p3);
  return mrb_nil_value();
}

static mrb_value CCDrawNode_drawPolygon(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  mrb_value array = args[0];
  unsigned int p1 = mrb_ary_ptr(array)->len;
  CCPoint* p0 = new CCPoint[p1];
  for(int i=0; i<p1; i++){
    CCPoint* p = static_cast<CCPoint*>(DATA_PTR(mrb_ary_ref(mrb,array,i)));
    p0[i] = *p;
  }
  const ccColor4F& p2 = *static_cast<ccColor4F*>(DATA_PTR(args[1]));
  float p3 = get_float(args[2]);
  const ccColor4F& p4 = *static_cast<ccColor4F*>(DATA_PTR(args[3]));
  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->drawPolygon(p0, p1, p2, p3, p4);
  delete p0;
  return mrb_nil_value();
}

static mrb_value CCDrawNode_clear(mrb_state *mrb, mrb_value self) {

  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->clear();
  return mrb_nil_value();
}

static mrb_value CCDrawNode_getBlendFunc(mrb_state *mrb, mrb_value self) {

  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  ccBlendFunc retval = instance->getBlendFunc();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(ccBlendFunc))) ccBlendFunc(retval), "CcBlendFunc");
}

static mrb_value CCDrawNode_setBlendFunc(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const ccBlendFunc& p0 = *static_cast<ccBlendFunc*>(DATA_PTR(args[0]));
  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->setBlendFunc(p0);
  return mrb_nil_value();
}

static void installCCDrawNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCDrawNode", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCDrawNode_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "drawDot", CCDrawNode_drawDot, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "drawSegment", CCDrawNode_drawSegment, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "drawPolygon", CCDrawNode_drawPolygon, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "clear", CCDrawNode_clear, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getBlendFunc", CCDrawNode_getBlendFunc, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setBlendFunc", CCDrawNode_setBlendFunc, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLayer

static mrb_value CCLayer___ctor(mrb_state *mrb, mrb_value self) {

  
  CCLayer* retval = new CCLayer();
  DATA_PTR(self) = retval; return self;
}

static mrb_value CCLayer_create(mrb_state *mrb, mrb_value self) {

  
  CCLayer* retval = CCLayer::create();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCLayer"));
}

static mrb_value CCLayer_registerScriptTouchHandler(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  if (arg_count == 0) {
    int blockHandler = registerProc(mrb, self, block);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler);
    return mrb_nil_value();
  } else if (arg_count == 1) {
    int blockHandler = registerProc(mrb, self, block);
    bool p0 = get_bool(args[0]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    int blockHandler = registerProc(mrb, self, block);
    bool p0 = get_bool(args[0]);
    int p1 = get_int(args[1]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0, p1);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    int blockHandler = registerProc(mrb, self, block);
    bool p0 = get_bool(args[0]);
    int p1 = get_int(args[1]);
    bool p2 = get_bool(args[2]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0, p1, p2);
    return mrb_nil_value();
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCLayer#registerScriptTouchHandler");
    return mrb_nil_value();
  }
}

static mrb_value CCLayer_setTouchEnabled(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
  instance->setTouchEnabled(p0);
  return mrb_nil_value();
}

static mrb_value CCLayer_setAccelerometerEnabled(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
  instance->setAccelerometerEnabled(p0);
  return mrb_nil_value();
}

static mrb_value CCLayer_setTouchMode(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  ccTouchesMode p0 = (ccTouchesMode)mrb_fixnum(args[0]);
  CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
  instance->setTouchMode(p0);
  return mrb_nil_value();
}

static void installCCLayer(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLayer", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCLayer___ctor, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "create", CCLayer_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "registerScriptTouchHandler", CCLayer_registerScriptTouchHandler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTouchEnabled", CCLayer_setTouchEnabled, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAccelerometerEnabled", CCLayer_setAccelerometerEnabled, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTouchMode", CCLayer_setTouchMode, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLayerRGBA

static void installCCLayerRGBA(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCLayer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLayerRGBA", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCScene

static mrb_value CCScene_create(mrb_state *mrb, mrb_value self) {

  
  CCScene* retval = CCScene::create();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCScene"));
}

static void installCCScene(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScene", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCScene_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCScheduler

static mrb_value CCScheduler_scheduleScriptFunc(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  float p0 = get_float(args[0]);
  bool p1 = get_bool(args[1]);
  CCScheduler* instance = static_cast<CCScheduler*>(DATA_PTR(self));
  unsigned int retval = instance->scheduleScriptFunc(blockHandler, p0, p1);
  return mrb_fixnum_value(retval);
}

static mrb_value CCScheduler_unscheduleScriptEntry(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  unsigned int p0 = get_int(args[0]);
  CCScheduler* instance = static_cast<CCScheduler*>(DATA_PTR(self));
  instance->unscheduleScriptEntry(p0);
  return mrb_nil_value();
}

static void installCCScheduler(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScheduler", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "scheduleScriptFunc", CCScheduler_scheduleScriptFunc, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "unscheduleScriptEntry", CCScheduler_unscheduleScriptEntry, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCDirector

static mrb_value CCDirector_sharedDirector(mrb_state *mrb, mrb_value self) {

  
  CCDirector* retval = CCDirector::sharedDirector();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCDirector"));
}

static mrb_value CCDirector_getWinSize(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCSize retval = instance->getWinSize();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static mrb_value CCDirector_getVisibleOrigin(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCPoint retval = instance->getVisibleOrigin();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCDirector_getVisibleSize(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCSize retval = instance->getVisibleSize();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static mrb_value CCDirector_convertToGL(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCPoint retval = instance->convertToGL(p0);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCDirector_runWithScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = static_cast<CCScene*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->runWithScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_replaceScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = static_cast<CCScene*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->replaceScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_pushScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = static_cast<CCScene*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->pushScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_getScheduler(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCScheduler* retval = instance->getScheduler();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCScheduler"));
}

static mrb_value CCDirector_setContentScaleFactor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->setContentScaleFactor(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_setDisplayStats(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->setDisplayStats(p0);
  return mrb_nil_value();
}

static void installCCDirector(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCDirector", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedDirector", CCDirector_sharedDirector, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getWinSize", CCDirector_getWinSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getVisibleOrigin", CCDirector_getVisibleOrigin, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getVisibleSize", CCDirector_getVisibleSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "convertToGL", CCDirector_convertToGL, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "runWithScene", CCDirector_runWithScene, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "replaceScene", CCDirector_replaceScene, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "pushScene", CCDirector_pushScene, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getScheduler", CCDirector_getScheduler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setContentScaleFactor", CCDirector_setContentScaleFactor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setDisplayStats", CCDirector_setDisplayStats, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCEGLView

static mrb_value CCEGLView_sharedOpenGLView(mrb_state *mrb, mrb_value self) {

  
  CCEGLView* retval = CCEGLView::sharedOpenGLView();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCEGLView"));
}

static mrb_value CCEGLView_getDesignResolutionSize(mrb_state *mrb, mrb_value self) {

  CCEGLView* instance = static_cast<CCEGLView*>(DATA_PTR(self));
  const CCSize& retval = instance->getDesignResolutionSize();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static mrb_value CCEGLView_setDesignResolutionSize(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  ResolutionPolicy p2 = (ResolutionPolicy)mrb_fixnum(args[2]);
  CCEGLView* instance = static_cast<CCEGLView*>(DATA_PTR(self));
  instance->setDesignResolutionSize(p0, p1, p2);
  return mrb_nil_value();
}

static mrb_value CCEGLView_getFrameSize(mrb_state *mrb, mrb_value self) {

  CCEGLView* instance = static_cast<CCEGLView*>(DATA_PTR(self));
  const CCSize& retval = instance->getFrameSize();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static void installCCEGLView(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCEGLView", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedOpenGLView", CCEGLView_sharedOpenGLView, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getDesignResolutionSize", CCEGLView_getDesignResolutionSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setDesignResolutionSize", CCEGLView_setDesignResolutionSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getFrameSize", CCEGLView_getFrameSize, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCFileUtils

static mrb_value CCFileUtils_sharedFileUtils(mrb_state *mrb, mrb_value self) {

  
  CCFileUtils* retval = CCFileUtils::sharedFileUtils();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCFileUtils"));
}

static mrb_value CCFileUtils_fullPathForFilename(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  std::string retval = instance->fullPathForFilename(p0);
  return mrb_str_new(mrb, retval.c_str(), retval.size());
}

static void installCCFileUtils(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCFileUtils", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedFileUtils", CCFileUtils_sharedFileUtils, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "fullPathForFilename", CCFileUtils_fullPathForFilename, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenuItem

static mrb_value CCMenuItem_registerScriptTapHandler(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  CCMenuItem* instance = static_cast<CCMenuItem*>(DATA_PTR(self));
  instance->registerScriptTapHandler(blockHandler);
  return mrb_nil_value();
}

static void installCCMenuItem(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNodeRGBA");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItem", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "registerScriptTapHandler", CCMenuItem_registerScriptTapHandler, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenuItemSprite

static void installCCMenuItemSprite(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemImage

static mrb_value CCMenuItemImage_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const char* p1 = mrb_string_value_ptr(mrb, args[1]);
  
  CCMenuItemImage* retval = CCMenuItemImage::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMenuItemImage"));
}

static void installCCMenuItemImage(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItemSprite");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemImage", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenuItemImage_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenuItemLabel

static void installCCMenuItemLabel(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemLabel", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemFont

static mrb_value CCMenuItemFont_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  
  CCMenuItemFont* retval = CCMenuItemFont::create(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMenuItemFont"));
}

static void installCCMenuItemFont(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItemLabel");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemFont", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenuItemFont_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenu

static mrb_value CCMenu_create(mrb_state *mrb, mrb_value self) {

  
  CCMenu* retval = CCMenu::create();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMenu"));
}

static mrb_value CCMenu_createWithItem(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCMenuItem* p0 = static_cast<CCMenuItem*>(DATA_PTR(args[0]));
  
  CCMenu* retval = CCMenu::createWithItem(p0);
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCMenu"));
}

static void installCCMenu(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCLayerRGBA");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenu", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenu_create, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "createWithItem", CCMenu_createWithItem, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCTouch

static mrb_value CCTouch_getLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getLocation();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getPreviousLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getPreviousLocation();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getStartLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getStartLocation();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getDelta(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getDelta();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getLocationInView();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getPreviousLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getPreviousLocationInView();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getStartLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getStartLocationInView();
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCTouch_getID(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  int retval = instance->getID();
  return mrb_fixnum_value(retval);
}

static void installCCTouch(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTouch", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "getLocation", CCTouch_getLocation, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPreviousLocation", CCTouch_getPreviousLocation, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getStartLocation", CCTouch_getStartLocation, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getDelta", CCTouch_getDelta, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getLocationInView", CCTouch_getLocationInView, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPreviousLocationInView", CCTouch_getPreviousLocationInView, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getStartLocationInView", CCTouch_getStartLocationInView, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getID", CCTouch_getID, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCUserDefault

static mrb_value CCUserDefault_sharedUserDefault(mrb_state *mrb, mrb_value self) {

  
  CCUserDefault* retval = CCUserDefault::sharedUserDefault();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "CCUserDefault"));
}

static mrb_value CCUserDefault_getIntegerForKey(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  int p1 = get_int(args[1]);
  CCUserDefault* instance = static_cast<CCUserDefault*>(DATA_PTR(self));
  int retval = instance->getIntegerForKey(p0, p1);
  return mrb_fixnum_value(retval);
}

static mrb_value CCUserDefault_setIntegerForKey(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  int p1 = get_int(args[1]);
  CCUserDefault* instance = static_cast<CCUserDefault*>(DATA_PTR(self));
  instance->setIntegerForKey(p0, p1);
  return mrb_nil_value();
}

static void installCCUserDefault(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCUserDefault", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedUserDefault", CCUserDefault_sharedUserDefault, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getIntegerForKey", CCUserDefault_getIntegerForKey, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setIntegerForKey", CCUserDefault_setIntegerForKey, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

static mrb_value CCPointMake__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCPoint retval = CCPointMake(p0, p1);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value ccp__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCPoint retval = ccp(p0, p1);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval), "CCPoint");
}

static mrb_value CCSizeMake__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCSize retval = CCSizeMake(p0, p1);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval), "CCSize");
}

static mrb_value CCRectMake__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  float p2 = get_float(args[2]);
  float p3 = get_float(args[3]);
  
  CCRect retval = CCRectMake(p0, p1, p2, p3);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(retval), "CCRect");
}

static mrb_value ccc3__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  unsigned char p0 = get_int(args[0]);
  unsigned char p1 = get_int(args[1]);
  unsigned char p2 = get_int(args[2]);
  
  CcColor3B retval = ccc3(p0, p1, p2);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CcColor3B))) CcColor3B(retval), "CcColor3B");
}

static mrb_value CCRANDOM_0_1__(mrb_state *mrb, mrb_value self) {

  
  float retval = CCRANDOM_0_1();
  return mrb_float_value(mrb, retval);
}

static mrb_value ccc4f__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  float p2 = get_float(args[2]);
  float p3 = get_float(args[3]);
  
  CcColor4F retval = ccc4f(p0, p1, p2, p3);
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(CcColor4F))) CcColor4F(retval), "CcColor4F");
}

void installMrubyCocos2dx(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Cocos2dx");
  mrb_define_const(mrb, mod, "CCTOUCHBEGAN", mrb_fixnum_value(CCTOUCHBEGAN));
  mrb_define_const(mrb, mod, "CCTOUCHMOVED", mrb_fixnum_value(CCTOUCHMOVED));
  mrb_define_const(mrb, mod, "CCTOUCHENDED", mrb_fixnum_value(CCTOUCHENDED));
  mrb_define_const(mrb, mod, "CCTOUCHCANCELLED", mrb_fixnum_value(CCTOUCHCANCELLED));
  mrb_define_const(mrb, mod, "KCCNodeOnEnter", mrb_fixnum_value(kCCNodeOnEnter));
  mrb_define_const(mrb, mod, "KCCNodeOnExit", mrb_fixnum_value(kCCNodeOnExit));
  mrb_define_const(mrb, mod, "KCCNodeOnEnterTransitionDidFinish", mrb_fixnum_value(kCCNodeOnEnterTransitionDidFinish));
  mrb_define_const(mrb, mod, "KCCNodeOnExitTransitionDidStart", mrb_fixnum_value(kCCNodeOnExitTransitionDidStart));
  mrb_define_const(mrb, mod, "KCCNodeOnCleanup", mrb_fixnum_value(kCCNodeOnCleanup));
  mrb_define_const(mrb, mod, "KCCTouchesAllAtOnce", mrb_fixnum_value(kCCTouchesAllAtOnce));
  mrb_define_const(mrb, mod, "KCCTouchesOneByOne", mrb_fixnum_value(kCCTouchesOneByOne));
  mrb_define_const(mrb, mod, "KResolutionExactFit", mrb_fixnum_value(kResolutionExactFit));
  mrb_define_const(mrb, mod, "KResolutionNoBorder", mrb_fixnum_value(kResolutionNoBorder));
  mrb_define_const(mrb, mod, "KResolutionShowAll", mrb_fixnum_value(kResolutionShowAll));
  mrb_define_const(mrb, mod, "KResolutionFixedHeight", mrb_fixnum_value(kResolutionFixedHeight));
  mrb_define_const(mrb, mod, "KResolutionFixedWidth", mrb_fixnum_value(kResolutionFixedWidth));
  mrb_define_const(mrb, mod, "KResolutionUnKnown", mrb_fixnum_value(kResolutionUnKnown));
  mrb_define_module_function(mrb, mod, "cCPointMake", CCPointMake__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "ccp", ccp__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "cCSizeMake", CCSizeMake__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "cCRectMake", CCRectMake__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "ccc3", ccc3__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "cCRANDOM_0_1", CCRANDOM_0_1__, MRB_ARGS_ANY());
  mrb_define_module_function(mrb, mod, "ccc4f", ccc4f__, MRB_ARGS_ANY());
  installCcColor3B(mrb, mod);
  installCcColor4F(mrb, mod);
  installCCPoint(mrb, mod);
  installCCSize(mrb, mod);
  installCCRect(mrb, mod);
  installCCObject(mrb, mod);
  installCCArray(mrb, mod);
  installCCAction(mrb, mod);
  installCCFiniteTimeAction(mrb, mod);
  installCCActionInterval(mrb, mod);
  installCCActionInstant(mrb, mod);
  installCCNode(mrb, mod);
  installCCNodeRGBA(mrb, mod);
  installCCTexture2D(mrb, mod);
  installCCTextureCache(mrb, mod);
  installCCSpriteFrame(mrb, mod);
  installCCAnimation(mrb, mod);
  installCCAnimate(mrb, mod);
  installCCRepeatForever(mrb, mod);
  installCCScaleTo(mrb, mod);
  installCCMoveBy(mrb, mod);
  installCCMoveTo(mrb, mod);
  installCCCallFunc(mrb, mod);
  installCCSequence(mrb, mod);
  installCCSpawn(mrb, mod);
  installCCSprite(mrb, mod);
  installCCSpriteBatchNode(mrb, mod);
  installCCLabelTTF(mrb, mod);
  installCCLabelBMFont(mrb, mod);
  installCCDrawNode(mrb, mod);
  installCCLayer(mrb, mod);
  installCCLayerRGBA(mrb, mod);
  installCCScene(mrb, mod);
  installCCScheduler(mrb, mod);
  installCCDirector(mrb, mod);
  installCCEGLView(mrb, mod);
  installCCFileUtils(mrb, mod);
  installCCMenuItem(mrb, mod);
  installCCMenuItemSprite(mrb, mod);
  installCCMenuItemImage(mrb, mod);
  installCCMenuItemLabel(mrb, mod);
  installCCMenuItemFont(mrb, mod);
  installCCMenu(mrb, mod);
  installCCTouch(mrb, mod);
  installCCUserDefault(mrb, mod);
}
