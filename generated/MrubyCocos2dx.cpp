#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "mruby/mruby.h"
#include "mruby/mruby/array.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);

using namespace cocos2d;

typedef ccColor3B CcColor3B;
typedef ccColor4F CcColor4F;


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
// CcColor3B
static void _dfree_CcColor3B(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CcColor3B\n");
}
static struct mrb_data_type _mrb_data_type_CcColor3B = { "CcColor3B", _dfree_CcColor3B };
mrb_value _wrap_CcColor3B(mrb_state *mrb, const CcColor3B* ptr) {
  struct RClass* tc = getClass(mrb, "CcColor3B");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CcColor3B, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CcColor3B;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
static void _dfree_CcColor4F(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CcColor4F\n");
}
static struct mrb_data_type _mrb_data_type_CcColor4F = { "CcColor4F", _dfree_CcColor4F };
mrb_value _wrap_CcColor4F(mrb_state *mrb, const CcColor4F* ptr) {
  struct RClass* tc = getClass(mrb, "CcColor4F");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CcColor4F, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CcColor4F;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
static void _dfree_CCPoint(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCPoint\n");
}
static struct mrb_data_type _mrb_data_type_CCPoint = { "CCPoint", _dfree_CCPoint };
mrb_value _wrap_CCPoint(mrb_state *mrb, const CCPoint* ptr) {
  struct RClass* tc = getClass(mrb, "CCPoint");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCPoint, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCPoint;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCPoint___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCPoint* retval = /*TODO delete*/new CCPoint();
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCPoint* retval = /*TODO delete*/new CCPoint(p0, p1);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
    
    CCPoint* retval = /*TODO delete*/new CCPoint(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *static_cast<CCSize*>(DATA_PTR(args[0]));
    
    CCPoint* retval = /*TODO delete*/new CCPoint(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
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
static void _dfree_CCSize(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSize\n");
}
static struct mrb_data_type _mrb_data_type_CCSize = { "CCSize", _dfree_CCSize };
mrb_value _wrap_CCSize(mrb_state *mrb, const CCSize* ptr) {
  struct RClass* tc = getClass(mrb, "CCSize");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSize, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSize;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSize___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSize* retval = /*TODO delete*/new CCSize();
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCSize* retval = /*TODO delete*/new CCSize(p0, p1);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
    
    CCSize* retval = /*TODO delete*/new CCSize(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *static_cast<CCSize*>(DATA_PTR(args[0]));
    
    CCSize* retval = /*TODO delete*/new CCSize(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
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
static void _dfree_CCRect(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCRect\n");
}
static struct mrb_data_type _mrb_data_type_CCRect = { "CCRect", _dfree_CCRect };
mrb_value _wrap_CCRect(mrb_state *mrb, const CCRect* ptr) {
  struct RClass* tc = getClass(mrb, "CCRect");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCRect, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCRect;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCRect___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCRect* retval = /*TODO delete*/new CCRect();
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 4) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    float p2 = get_float(args[2]);
    float p3 = get_float(args[3]);
    
    CCRect* retval = /*TODO delete*/new CCRect(p0, p1, p2, p3);
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCRect& p0 = *static_cast<CCRect*>(DATA_PTR(args[0]));
    
    CCRect* retval = /*TODO delete*/new CCRect(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCRect#__ctor");
    return mrb_nil_value();
  }
}

static mrb_value CCRect_origin(mrb_state *mrb, mrb_value self) {
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(instance->origin));
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
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(instance->size));
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
// ccBlendFunc
static void _dfree_ccBlendFunc(mrb_state *mrb, void *ptr) {
  // printf("_dfree_ccBlendFunc\n");
}
static struct mrb_data_type _mrb_data_type_ccBlendFunc = { "ccBlendFunc", _dfree_ccBlendFunc };
mrb_value _wrap_ccBlendFunc(mrb_state *mrb, const ccBlendFunc* ptr) {
  struct RClass* tc = getClass(mrb, "CcBlendFunc");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_ccBlendFunc, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_ccBlendFunc;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installccBlendFunc(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcBlendFunc", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCObject
static void _dfree_CCObject(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCObject\n");
}
static struct mrb_data_type _mrb_data_type_CCObject = { "CCObject", _dfree_CCObject };
mrb_value _wrap_CCObject(mrb_state *mrb, const CCObject* ptr) {
  struct RClass* tc = getClass(mrb, "CCObject");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCObject, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCObject;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCObject_release(mrb_state *mrb, mrb_value self) {

  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  instance->release();
  return mrb_nil_value();
}

static mrb_value CCObject_autorelease(mrb_state *mrb, mrb_value self) {

  CCObject* instance = static_cast<CCObject*>(DATA_PTR(self));
  CCObject* retval = instance->autorelease();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCObject(mrb, retval));
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
}

////////////////////////////////////////////////////////////////
// CCArray
static void _dfree_CCArray(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCArray\n");
}
static struct mrb_data_type _mrb_data_type_CCArray = { "CCArray", _dfree_CCArray };
mrb_value _wrap_CCArray(mrb_state *mrb, const CCArray* ptr) {
  struct RClass* tc = getClass(mrb, "CCArray");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCArray, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCArray;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCArray_create(mrb_state *mrb, mrb_value self) {

  
  CCArray* retval = CCArray::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCArray(mrb, retval));
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
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCArray", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCArray_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addObject", CCArray_addObject, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCAction
static void _dfree_CCAction(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCAction\n");
}
static struct mrb_data_type _mrb_data_type_CCAction = { "CCAction", _dfree_CCAction };
mrb_value _wrap_CCAction(mrb_state *mrb, const CCAction* ptr) {
  struct RClass* tc = getClass(mrb, "CCAction");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCAction, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCAction;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCFiniteTimeAction
static void _dfree_CCFiniteTimeAction(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCFiniteTimeAction\n");
}
static struct mrb_data_type _mrb_data_type_CCFiniteTimeAction = { "CCFiniteTimeAction", _dfree_CCFiniteTimeAction };
mrb_value _wrap_CCFiniteTimeAction(mrb_state *mrb, const CCFiniteTimeAction* ptr) {
  struct RClass* tc = getClass(mrb, "CCFiniteTimeAction");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCFiniteTimeAction, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCFiniteTimeAction;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCFiniteTimeAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCFiniteTimeAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInterval
static void _dfree_CCActionInterval(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCActionInterval\n");
}
static struct mrb_data_type _mrb_data_type_CCActionInterval = { "CCActionInterval", _dfree_CCActionInterval };
mrb_value _wrap_CCActionInterval(mrb_state *mrb, const CCActionInterval* ptr) {
  struct RClass* tc = getClass(mrb, "CCActionInterval");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCActionInterval, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCActionInterval;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCActionInterval(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInterval", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInstant
static void _dfree_CCActionInstant(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCActionInstant\n");
}
static struct mrb_data_type _mrb_data_type_CCActionInstant = { "CCActionInstant", _dfree_CCActionInstant };
mrb_value _wrap_CCActionInstant(mrb_state *mrb, const CCActionInstant* ptr) {
  struct RClass* tc = getClass(mrb, "CCActionInstant");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCActionInstant, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCActionInstant;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCActionInstant(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInstant", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCNode
static void _dfree_CCNode(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCNode\n");
}
static struct mrb_data_type _mrb_data_type_CCNode = { "CCNode", _dfree_CCNode };
mrb_value _wrap_CCNode(mrb_state *mrb, const CCNode* ptr) {
  struct RClass* tc = getClass(mrb, "CCNode");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCNode, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCNode;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
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
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
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
  return (retval == NULL ? mrb_nil_value() : _wrap_CCNode(mrb, retval));
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
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
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
  return _wrap_CCRect(mrb, new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(retval));
}

static mrb_value CCNode_convertTouchToNodeSpace(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTouch* p0 = static_cast<CCTouch*>(DATA_PTR(args[0]));
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCPoint retval = instance->convertTouchToNodeSpace(p0);
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
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
  return (retval == NULL ? mrb_nil_value() : _wrap_CCObject(mrb, retval));
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
static void _dfree_CCNodeRGBA(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCNodeRGBA\n");
}
static struct mrb_data_type _mrb_data_type_CCNodeRGBA = { "CCNodeRGBA", _dfree_CCNodeRGBA };
mrb_value _wrap_CCNodeRGBA(mrb_state *mrb, const CCNodeRGBA* ptr) {
  struct RClass* tc = getClass(mrb, "CCNodeRGBA");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCNodeRGBA, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCNodeRGBA;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
static void _dfree_CCTexture2D(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCTexture2D\n");
}
static struct mrb_data_type _mrb_data_type_CCTexture2D = { "CCTexture2D", _dfree_CCTexture2D };
mrb_value _wrap_CCTexture2D(mrb_state *mrb, const CCTexture2D* ptr) {
  struct RClass* tc = getClass(mrb, "CCTexture2D");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCTexture2D, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCTexture2D;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCTexture2D(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTexture2D", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCTextureCache
static void _dfree_CCTextureCache(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCTextureCache\n");
}
static struct mrb_data_type _mrb_data_type_CCTextureCache = { "CCTextureCache", _dfree_CCTextureCache };
mrb_value _wrap_CCTextureCache(mrb_state *mrb, const CCTextureCache* ptr) {
  struct RClass* tc = getClass(mrb, "CCTextureCache");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCTextureCache, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCTextureCache;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCTextureCache_sharedTextureCache(mrb_state *mrb, mrb_value self) {

  
  CCTextureCache* retval = CCTextureCache::sharedTextureCache();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCTextureCache(mrb, retval));
}

static mrb_value CCTextureCache_addImage(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCTextureCache* instance = static_cast<CCTextureCache*>(DATA_PTR(self));
  CCTexture2D* retval = instance->addImage(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCTexture2D(mrb, retval));
}

static void installCCTextureCache(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTextureCache", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedTextureCache", CCTextureCache_sharedTextureCache, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addImage", CCTextureCache_addImage, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpriteFrame
static void _dfree_CCSpriteFrame(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSpriteFrame\n");
}
static struct mrb_data_type _mrb_data_type_CCSpriteFrame = { "CCSpriteFrame", _dfree_CCSpriteFrame };
mrb_value _wrap_CCSpriteFrame(mrb_state *mrb, const CCSpriteFrame* ptr) {
  struct RClass* tc = getClass(mrb, "CCSpriteFrame");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSpriteFrame, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSpriteFrame;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSpriteFrame_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
  
  CCSpriteFrame* retval = CCSpriteFrame::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSpriteFrame(mrb, retval));
}

static mrb_value CCSpriteFrame_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
  const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
  
  CCSpriteFrame* retval = CCSpriteFrame::createWithTexture(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSpriteFrame(mrb, retval));
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
static void _dfree_CCAnimation(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCAnimation\n");
}
static struct mrb_data_type _mrb_data_type_CCAnimation = { "CCAnimation", _dfree_CCAnimation };
mrb_value _wrap_CCAnimation(mrb_state *mrb, const CCAnimation* ptr) {
  struct RClass* tc = getClass(mrb, "CCAnimation");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCAnimation, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCAnimation;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCAnimation_createWithSpriteFrames(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCArray* p0 = static_cast<CCArray*>(DATA_PTR(args[0]));
  float p1 = get_float(args[1]);
  
  CCAnimation* retval = CCAnimation::createWithSpriteFrames(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCAnimation(mrb, retval));
}

static void installCCAnimation(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAnimation", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithSpriteFrames", CCAnimation_createWithSpriteFrames, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCAnimate
static void _dfree_CCAnimate(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCAnimate\n");
}
static struct mrb_data_type _mrb_data_type_CCAnimate = { "CCAnimate", _dfree_CCAnimate };
mrb_value _wrap_CCAnimate(mrb_state *mrb, const CCAnimate* ptr) {
  struct RClass* tc = getClass(mrb, "CCAnimate");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCAnimate, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCAnimate;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCAnimate_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCAnimation* p0 = static_cast<CCAnimation*>(DATA_PTR(args[0]));
  
  CCAnimate* retval = CCAnimate::create(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCAnimate(mrb, retval));
}

static void installCCAnimate(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAnimate", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCAnimate_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCRepeatForever
static void _dfree_CCRepeatForever(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCRepeatForever\n");
}
static struct mrb_data_type _mrb_data_type_CCRepeatForever = { "CCRepeatForever", _dfree_CCRepeatForever };
mrb_value _wrap_CCRepeatForever(mrb_state *mrb, const CCRepeatForever* ptr) {
  struct RClass* tc = getClass(mrb, "CCRepeatForever");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCRepeatForever, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCRepeatForever;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCRepeatForever_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCActionInterval* p0 = static_cast<CCActionInterval*>(DATA_PTR(args[0]));
  
  CCRepeatForever* retval = CCRepeatForever::create(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCRepeatForever(mrb, retval));
}

static void installCCRepeatForever(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCRepeatForever", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCRepeatForever_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCScaleTo
static void _dfree_CCScaleTo(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCScaleTo\n");
}
static struct mrb_data_type _mrb_data_type_CCScaleTo = { "CCScaleTo", _dfree_CCScaleTo };
mrb_value _wrap_CCScaleTo(mrb_state *mrb, const CCScaleTo* ptr) {
  struct RClass* tc = getClass(mrb, "CCScaleTo");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCScaleTo, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCScaleTo;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCScaleTo_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCScaleTo* retval = CCScaleTo::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCScaleTo(mrb, retval));
}

static void installCCScaleTo(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScaleTo", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCScaleTo_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMoveBy
static void _dfree_CCMoveBy(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMoveBy\n");
}
static struct mrb_data_type _mrb_data_type_CCMoveBy = { "CCMoveBy", _dfree_CCMoveBy };
mrb_value _wrap_CCMoveBy(mrb_state *mrb, const CCMoveBy* ptr) {
  struct RClass* tc = getClass(mrb, "CCMoveBy");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMoveBy, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMoveBy;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCMoveBy_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *static_cast<CCPoint*>(DATA_PTR(args[1]));
  
  CCMoveBy* retval = CCMoveBy::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMoveBy(mrb, retval));
}

static void installCCMoveBy(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMoveBy", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMoveBy_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMoveTo
static void _dfree_CCMoveTo(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMoveTo\n");
}
static struct mrb_data_type _mrb_data_type_CCMoveTo = { "CCMoveTo", _dfree_CCMoveTo };
mrb_value _wrap_CCMoveTo(mrb_state *mrb, const CCMoveTo* ptr) {
  struct RClass* tc = getClass(mrb, "CCMoveTo");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMoveTo, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMoveTo;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCMoveTo_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *static_cast<CCPoint*>(DATA_PTR(args[1]));
  
  CCMoveTo* retval = CCMoveTo::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMoveTo(mrb, retval));
}

static void installCCMoveTo(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMoveBy");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMoveTo", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMoveTo_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCCallFunc
static void _dfree_CCCallFunc(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCCallFunc\n");
}
static struct mrb_data_type _mrb_data_type_CCCallFunc = { "CCCallFunc", _dfree_CCCallFunc };
mrb_value _wrap_CCCallFunc(mrb_state *mrb, const CCCallFunc* ptr) {
  struct RClass* tc = getClass(mrb, "CCCallFunc");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCCallFunc, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCCallFunc;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCCallFunc_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  int blockHandler = registerProc(mrb, self, block);
  
  CCCallFunc* retval = CCCallFunc::create(blockHandler);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCCallFunc(mrb, retval));
}

static void installCCCallFunc(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInstant");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCCallFunc", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCCallFunc_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSequence
static void _dfree_CCSequence(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSequence\n");
}
static struct mrb_data_type _mrb_data_type_CCSequence = { "CCSequence", _dfree_CCSequence };
mrb_value _wrap_CCSequence(mrb_state *mrb, const CCSequence* ptr) {
  struct RClass* tc = getClass(mrb, "CCSequence");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSequence, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSequence;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSequence_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[0]));
  CCFiniteTimeAction* p1 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[1]));
  
  CCActionInterval* retval = CCSequence::createWithTwoActions(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCActionInterval(mrb, retval));
}

static void installCCSequence(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSequence", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithTwoActions", CCSequence_createWithTwoActions, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpawn
static void _dfree_CCSpawn(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSpawn\n");
}
static struct mrb_data_type _mrb_data_type_CCSpawn = { "CCSpawn", _dfree_CCSpawn };
mrb_value _wrap_CCSpawn(mrb_state *mrb, const CCSpawn* ptr) {
  struct RClass* tc = getClass(mrb, "CCSpawn");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSpawn, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSpawn;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSpawn_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[0]));
  CCFiniteTimeAction* p1 = static_cast<CCFiniteTimeAction*>(DATA_PTR(args[1]));
  
  CCActionInterval* retval = CCSpawn::createWithTwoActions(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCActionInterval(mrb, retval));
}

static void installCCSpawn(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSpawn", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithTwoActions", CCSpawn_createWithTwoActions, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSprite
static void _dfree_CCSprite(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSprite\n");
}
static struct mrb_data_type _mrb_data_type_CCSprite = { "CCSprite", _dfree_CCSprite };
mrb_value _wrap_CCSprite(mrb_state *mrb, const CCSprite* ptr) {
  struct RClass* tc = getClass(mrb, "CCSprite");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSprite, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSprite;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSprite_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSprite* retval = CCSprite::create();
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    
    CCSprite* retval = CCSprite::create(p0);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    
    CCSprite* retval = CCSprite::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
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
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
}

static mrb_value CCSprite_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    
    CCSprite* retval = CCSprite::createWithTexture(p0);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else if (arg_count == 2) {
    CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    
    CCSprite* retval = CCSprite::createWithTexture(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSprite#createWithTexture");
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
  mrb_define_method(mrb, tc, "setTextureRect", CCSprite_setTextureRect, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSpriteBatchNode
static void _dfree_CCSpriteBatchNode(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCSpriteBatchNode\n");
}
static struct mrb_data_type _mrb_data_type_CCSpriteBatchNode = { "CCSpriteBatchNode", _dfree_CCSpriteBatchNode };
mrb_value _wrap_CCSpriteBatchNode(mrb_state *mrb, const CCSpriteBatchNode* ptr) {
  struct RClass* tc = getClass(mrb, "CCSpriteBatchNode");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCSpriteBatchNode, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCSpriteBatchNode;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCSpriteBatchNode_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    unsigned int p1 = get_int(args[1]);
    
    CCSpriteBatchNode* retval = CCSpriteBatchNode::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSpriteBatchNode(mrb, retval));
  } else if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    
    CCSpriteBatchNode* retval = CCSpriteBatchNode::create(p0);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSpriteBatchNode(mrb, retval));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCSpriteBatchNode#create");
    return mrb_nil_value();
  }
}

static mrb_value CCSpriteBatchNode_getTexture(mrb_state *mrb, mrb_value self) {

  CCSpriteBatchNode* instance = static_cast<CCSpriteBatchNode*>(DATA_PTR(self));
  CCTexture2D* retval = instance->getTexture();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCTexture2D(mrb, retval));
}

static void installCCSpriteBatchNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSpriteBatchNode", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCSpriteBatchNode_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getTexture", CCSpriteBatchNode_getTexture, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLabelTTF
static void _dfree_CCLabelTTF(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCLabelTTF\n");
}
static struct mrb_data_type _mrb_data_type_CCLabelTTF = { "CCLabelTTF", _dfree_CCLabelTTF };
mrb_value _wrap_CCLabelTTF(mrb_state *mrb, const CCLabelTTF* ptr) {
  struct RClass* tc = getClass(mrb, "CCLabelTTF");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCLabelTTF, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCLabelTTF;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCLabelTTF_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 3) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    
    CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelTTF(mrb, retval));
  } else if (arg_count == 5) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    const CCSize& p3 = *static_cast<CCSize*>(DATA_PTR(args[3]));
    CCTextAlignment p4 = (CCTextAlignment)mrb_fixnum(args[4]);
    
    CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2, p3, p4);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelTTF(mrb, retval));
  } else if (arg_count == 6) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    const CCSize& p3 = *static_cast<CCSize*>(DATA_PTR(args[3]));
    CCTextAlignment p4 = (CCTextAlignment)mrb_fixnum(args[4]);
    CCVerticalTextAlignment p5 = (CCVerticalTextAlignment)mrb_fixnum(args[5]);
    
    CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2, p3, p4, p5);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelTTF(mrb, retval));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "CCLabelTTF#create");
    return mrb_nil_value();
  }
}

static mrb_value CCLabelTTF_setString(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCLabelTTF* instance = static_cast<CCLabelTTF*>(DATA_PTR(self));
  instance->setString(p0);
  return mrb_nil_value();
}

static void installCCLabelTTF(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCSprite");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLabelTTF", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCLabelTTF_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setString", CCLabelTTF_setString, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLabelBMFont
static void _dfree_CCLabelBMFont(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCLabelBMFont\n");
}
static struct mrb_data_type _mrb_data_type_CCLabelBMFont = { "CCLabelBMFont", _dfree_CCLabelBMFont };
mrb_value _wrap_CCLabelBMFont(mrb_state *mrb, const CCLabelBMFont* ptr) {
  struct RClass* tc = getClass(mrb, "CCLabelBMFont");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCLabelBMFont, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCLabelBMFont;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCLabelBMFont_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 3) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    
    CCLabelBMFont* retval = CCLabelBMFont::create(p0, p1, p2);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelBMFont(mrb, retval));
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    
    CCLabelBMFont* retval = CCLabelBMFont::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelBMFont(mrb, retval));
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
static void _dfree_CCDrawNode(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCDrawNode\n");
}
static struct mrb_data_type _mrb_data_type_CCDrawNode = { "CCDrawNode", _dfree_CCDrawNode };
mrb_value _wrap_CCDrawNode(mrb_state *mrb, const CCDrawNode* ptr) {
  struct RClass* tc = getClass(mrb, "CCDrawNode");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCDrawNode, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCDrawNode;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCDrawNode_create(mrb_state *mrb, mrb_value self) {

  
  CCDrawNode* retval = CCDrawNode::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCDrawNode(mrb, retval));
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
  delete[] p0;
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
  return _wrap_ccBlendFunc(mrb, new(mrb_malloc(mrb, sizeof(ccBlendFunc))) ccBlendFunc(retval));
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
static void _dfree_CCLayer(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCLayer\n");
}
static struct mrb_data_type _mrb_data_type_CCLayer = { "CCLayer", _dfree_CCLayer };
mrb_value _wrap_CCLayer(mrb_state *mrb, const CCLayer* ptr) {
  struct RClass* tc = getClass(mrb, "CCLayer");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCLayer, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCLayer;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCLayer_create(mrb_state *mrb, mrb_value self) {

  
  CCLayer* retval = CCLayer::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCLayer(mrb, retval));
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
  mrb_define_class_method(mrb, tc, "create", CCLayer_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "registerScriptTouchHandler", CCLayer_registerScriptTouchHandler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTouchEnabled", CCLayer_setTouchEnabled, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAccelerometerEnabled", CCLayer_setAccelerometerEnabled, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTouchMode", CCLayer_setTouchMode, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLayerRGBA
static void _dfree_CCLayerRGBA(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCLayerRGBA\n");
}
static struct mrb_data_type _mrb_data_type_CCLayerRGBA = { "CCLayerRGBA", _dfree_CCLayerRGBA };
mrb_value _wrap_CCLayerRGBA(mrb_state *mrb, const CCLayerRGBA* ptr) {
  struct RClass* tc = getClass(mrb, "CCLayerRGBA");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCLayerRGBA, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCLayerRGBA;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCLayerRGBA(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCLayer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLayerRGBA", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCScene
static void _dfree_CCScene(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCScene\n");
}
static struct mrb_data_type _mrb_data_type_CCScene = { "CCScene", _dfree_CCScene };
mrb_value _wrap_CCScene(mrb_state *mrb, const CCScene* ptr) {
  struct RClass* tc = getClass(mrb, "CCScene");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCScene, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCScene;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCScene_create(mrb_state *mrb, mrb_value self) {

  
  CCScene* retval = CCScene::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCScene(mrb, retval));
}

static void installCCScene(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScene", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCScene_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCScheduler
static void _dfree_CCScheduler(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCScheduler\n");
}
static struct mrb_data_type _mrb_data_type_CCScheduler = { "CCScheduler", _dfree_CCScheduler };
mrb_value _wrap_CCScheduler(mrb_state *mrb, const CCScheduler* ptr) {
  struct RClass* tc = getClass(mrb, "CCScheduler");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCScheduler, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCScheduler;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScheduler", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "scheduleScriptFunc", CCScheduler_scheduleScriptFunc, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "unscheduleScriptEntry", CCScheduler_unscheduleScriptEntry, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCDirector
static void _dfree_CCDirector(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCDirector\n");
}
static struct mrb_data_type _mrb_data_type_CCDirector = { "CCDirector", _dfree_CCDirector };
mrb_value _wrap_CCDirector(mrb_state *mrb, const CCDirector* ptr) {
  struct RClass* tc = getClass(mrb, "CCDirector");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCDirector, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCDirector;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCDirector_sharedDirector(mrb_state *mrb, mrb_value self) {

  
  CCDirector* retval = CCDirector::sharedDirector();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCDirector(mrb, retval));
}

static mrb_value CCDirector_getWinSize(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCSize retval = instance->getWinSize();
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
}

static mrb_value CCDirector_getVisibleOrigin(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCPoint retval = instance->getVisibleOrigin();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCDirector_getVisibleSize(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCSize retval = instance->getVisibleSize();
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
}

static mrb_value CCDirector_convertToGL(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *static_cast<CCPoint*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCPoint retval = instance->convertToGL(p0);
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
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
  return (retval == NULL ? mrb_nil_value() : _wrap_CCScheduler(mrb, retval));
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
  struct RClass* parent = getClass(mrb, "CCObject");
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
static void _dfree_CCEGLView(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCEGLView\n");
}
static struct mrb_data_type _mrb_data_type_CCEGLView = { "CCEGLView", _dfree_CCEGLView };
mrb_value _wrap_CCEGLView(mrb_state *mrb, const CCEGLView* ptr) {
  struct RClass* tc = getClass(mrb, "CCEGLView");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCEGLView, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCEGLView;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCEGLView_sharedOpenGLView(mrb_state *mrb, mrb_value self) {

  
  CCEGLView* retval = CCEGLView::sharedOpenGLView();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCEGLView(mrb, retval));
}

static mrb_value CCEGLView_getDesignResolutionSize(mrb_state *mrb, mrb_value self) {

  CCEGLView* instance = static_cast<CCEGLView*>(DATA_PTR(self));
  const CCSize& retval = instance->getDesignResolutionSize();
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
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
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
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
static void _dfree_CCFileUtils(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCFileUtils\n");
}
static struct mrb_data_type _mrb_data_type_CCFileUtils = { "CCFileUtils", _dfree_CCFileUtils };
mrb_value _wrap_CCFileUtils(mrb_state *mrb, const CCFileUtils* ptr) {
  struct RClass* tc = getClass(mrb, "CCFileUtils");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCFileUtils, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCFileUtils;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCFileUtils_sharedFileUtils(mrb_state *mrb, mrb_value self) {

  
  CCFileUtils* retval = CCFileUtils::sharedFileUtils();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCFileUtils(mrb, retval));
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
static void _dfree_CCMenuItem(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenuItem\n");
}
static struct mrb_data_type _mrb_data_type_CCMenuItem = { "CCMenuItem", _dfree_CCMenuItem };
mrb_value _wrap_CCMenuItem(mrb_state *mrb, const CCMenuItem* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenuItem");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenuItem, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenuItem;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

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
static void _dfree_CCMenuItemSprite(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenuItemSprite\n");
}
static struct mrb_data_type _mrb_data_type_CCMenuItemSprite = { "CCMenuItemSprite", _dfree_CCMenuItemSprite };
mrb_value _wrap_CCMenuItemSprite(mrb_state *mrb, const CCMenuItemSprite* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenuItemSprite");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenuItemSprite, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenuItemSprite;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCMenuItemSprite(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemImage
static void _dfree_CCMenuItemImage(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenuItemImage\n");
}
static struct mrb_data_type _mrb_data_type_CCMenuItemImage = { "CCMenuItemImage", _dfree_CCMenuItemImage };
mrb_value _wrap_CCMenuItemImage(mrb_state *mrb, const CCMenuItemImage* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenuItemImage");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenuItemImage, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenuItemImage;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCMenuItemImage_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const char* p1 = mrb_string_value_ptr(mrb, args[1]);
  
  CCMenuItemImage* retval = CCMenuItemImage::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenuItemImage(mrb, retval));
}

static void installCCMenuItemImage(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItemSprite");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemImage", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenuItemImage_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenuItemLabel
static void _dfree_CCMenuItemLabel(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenuItemLabel\n");
}
static struct mrb_data_type _mrb_data_type_CCMenuItemLabel = { "CCMenuItemLabel", _dfree_CCMenuItemLabel };
mrb_value _wrap_CCMenuItemLabel(mrb_state *mrb, const CCMenuItemLabel* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenuItemLabel");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenuItemLabel, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenuItemLabel;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installCCMenuItemLabel(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemLabel", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemFont
static void _dfree_CCMenuItemFont(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenuItemFont\n");
}
static struct mrb_data_type _mrb_data_type_CCMenuItemFont = { "CCMenuItemFont", _dfree_CCMenuItemFont };
mrb_value _wrap_CCMenuItemFont(mrb_state *mrb, const CCMenuItemFont* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenuItemFont");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenuItemFont, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenuItemFont;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCMenuItemFont_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  
  CCMenuItemFont* retval = CCMenuItemFont::create(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenuItemFont(mrb, retval));
}

static void installCCMenuItemFont(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItemLabel");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemFont", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenuItemFont_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenu
static void _dfree_CCMenu(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCMenu\n");
}
static struct mrb_data_type _mrb_data_type_CCMenu = { "CCMenu", _dfree_CCMenu };
mrb_value _wrap_CCMenu(mrb_state *mrb, const CCMenu* ptr) {
  struct RClass* tc = getClass(mrb, "CCMenu");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCMenu, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCMenu;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCMenu_create(mrb_state *mrb, mrb_value self) {

  
  CCMenu* retval = CCMenu::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenu(mrb, retval));
}

static mrb_value CCMenu_createWithItem(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCMenuItem* p0 = static_cast<CCMenuItem*>(DATA_PTR(args[0]));
  
  CCMenu* retval = CCMenu::createWithItem(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenu(mrb, retval));
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
static void _dfree_CCTouch(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCTouch\n");
}
static struct mrb_data_type _mrb_data_type_CCTouch = { "CCTouch", _dfree_CCTouch };
mrb_value _wrap_CCTouch(mrb_state *mrb, const CCTouch* ptr) {
  struct RClass* tc = getClass(mrb, "CCTouch");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCTouch, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCTouch;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCTouch_getLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getLocation();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getPreviousLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getPreviousLocation();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getStartLocation(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getStartLocation();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getDelta(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getDelta();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getLocationInView();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getPreviousLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getPreviousLocationInView();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCTouch_getStartLocationInView(mrb_state *mrb, mrb_value self) {

  CCTouch* instance = static_cast<CCTouch*>(DATA_PTR(self));
  CCPoint retval = instance->getStartLocationInView();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
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
static void _dfree_CCUserDefault(mrb_state *mrb, void *ptr) {
  // printf("_dfree_CCUserDefault\n");
}
static struct mrb_data_type _mrb_data_type_CCUserDefault = { "CCUserDefault", _dfree_CCUserDefault };
mrb_value _wrap_CCUserDefault(mrb_state *mrb, const CCUserDefault* ptr) {
  struct RClass* tc = getClass(mrb, "CCUserDefault");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_CCUserDefault, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_CCUserDefault;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value CCUserDefault_sharedUserDefault(mrb_state *mrb, mrb_value self) {

  
  CCUserDefault* retval = CCUserDefault::sharedUserDefault();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCUserDefault(mrb, retval));
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
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value ccp__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCPoint retval = ccp(p0, p1);
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCSizeMake__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  CCSize retval = CCSizeMake(p0, p1);
  return _wrap_CCSize(mrb, new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(retval));
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
  return _wrap_CCRect(mrb, new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(retval));
}

static mrb_value ccc3__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  unsigned char p0 = get_int(args[0]);
  unsigned char p1 = get_int(args[1]);
  unsigned char p2 = get_int(args[2]);
  
  CcColor3B retval = ccc3(p0, p1, p2);
  return _wrap_CcColor3B(mrb, new(mrb_malloc(mrb, sizeof(CcColor3B))) CcColor3B(retval));
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
  return _wrap_CcColor4F(mrb, new(mrb_malloc(mrb, sizeof(CcColor4F))) CcColor4F(retval));
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
  mrb_define_const(mrb, mod, "KCCTextAlignmentLeft", mrb_fixnum_value(kCCTextAlignmentLeft));
  mrb_define_const(mrb, mod, "KCCTextAlignmentCenter", mrb_fixnum_value(kCCTextAlignmentCenter));
  mrb_define_const(mrb, mod, "KCCTextAlignmentRight", mrb_fixnum_value(kCCTextAlignmentRight));
  mrb_define_const(mrb, mod, "KCCVerticalTextAlignmentTop", mrb_fixnum_value(kCCVerticalTextAlignmentTop));
  mrb_define_const(mrb, mod, "KCCVerticalTextAlignmentCenter", mrb_fixnum_value(kCCVerticalTextAlignmentCenter));
  mrb_define_const(mrb, mod, "KCCVerticalTextAlignmentBottom", mrb_fixnum_value(kCCVerticalTextAlignmentBottom));
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
  installccBlendFunc(mrb, mod);
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
