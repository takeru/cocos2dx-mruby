#include <string>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "mruby/mruby.h"
#include "mruby/mruby/array.h"

extern int registerProc(mrb_state *mrb, mrb_value self, mrb_value proc);

using namespace cocos2d;

static CCSize* get_CCSize(mrb_state *mrb, mrb_value v);
static CCTouch* get_CCTouch(mrb_state *mrb, mrb_value v);


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
// ccColor3B
static void _dfree_ccColor3B(mrb_state *mrb, void *ptr) {
  ((ccColor3B*)ptr)->~ccColor3B(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_ccColor3B = { "ccColor3B", _dfree_ccColor3B };
mrb_value _wrap_ccColor3B(mrb_state *mrb, const ccColor3B* ptr) {
  struct RClass* tc = getClass(mrb, "CcColor3B");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_ccColor3B, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_ccColor3B;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}
ccColor3B* get_ccColor3B(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CcColor3B");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<ccColor3B*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is ccColor3B.");
    return NULL;
  }
}

static mrb_value ccColor3B_r(mrb_state *mrb, mrb_value self) {
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->r);
}

static mrb_value ccColor3B_set_r(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  instance->r = get_int(o);
  return mrb_nil_value();
}

static mrb_value ccColor3B_g(mrb_state *mrb, mrb_value self) {
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->g);
}

static mrb_value ccColor3B_set_g(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  instance->g = get_int(o);
  return mrb_nil_value();
}

static mrb_value ccColor3B_b(mrb_state *mrb, mrb_value self) {
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->b);
}

static mrb_value ccColor3B_set_b(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor3B* instance = static_cast<ccColor3B*>(DATA_PTR(self));
  instance->b = get_int(o);
  return mrb_nil_value();
}

static void installccColor3B(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcColor3B", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "r", ccColor3B_r, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "r=", ccColor3B_set_r, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "g", ccColor3B_g, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "g=", ccColor3B_set_g, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "b", ccColor3B_b, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "b=", ccColor3B_set_b, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// ccColor4F
static void _dfree_ccColor4F(mrb_state *mrb, void *ptr) {
  ((ccColor4F*)ptr)->~ccColor4F(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_ccColor4F = { "ccColor4F", _dfree_ccColor4F };
mrb_value _wrap_ccColor4F(mrb_state *mrb, const ccColor4F* ptr) {
  struct RClass* tc = getClass(mrb, "CcColor4F");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_ccColor4F, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_ccColor4F;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}
ccColor4F* get_ccColor4F(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CcColor4F");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<ccColor4F*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is ccColor4F.");
    return NULL;
  }
}

static mrb_value ccColor4F_r(mrb_state *mrb, mrb_value self) {
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->r);
}

static mrb_value ccColor4F_set_r(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  instance->r = get_float(o);
  return mrb_nil_value();
}

static mrb_value ccColor4F_g(mrb_state *mrb, mrb_value self) {
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->g);
}

static mrb_value ccColor4F_set_g(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  instance->g = get_float(o);
  return mrb_nil_value();
}

static mrb_value ccColor4F_b(mrb_state *mrb, mrb_value self) {
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->b);
}

static mrb_value ccColor4F_set_b(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  instance->b = get_float(o);
  return mrb_nil_value();
}

static mrb_value ccColor4F_a(mrb_state *mrb, mrb_value self) {
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->a);
}

static mrb_value ccColor4F_set_a(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccColor4F* instance = static_cast<ccColor4F*>(DATA_PTR(self));
  instance->a = get_float(o);
  return mrb_nil_value();
}

static void installccColor4F(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcColor4F", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "r", ccColor4F_r, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "r=", ccColor4F_set_r, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "g", ccColor4F_g, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "g=", ccColor4F_set_g, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "b", ccColor4F_b, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "b=", ccColor4F_set_b, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "a", ccColor4F_a, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "a=", ccColor4F_set_a, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// ccBlendFunc
static void _dfree_ccBlendFunc(mrb_state *mrb, void *ptr) {
  ((ccBlendFunc*)ptr)->~ccBlendFunc(); mrb_free(mrb, ptr);
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
ccBlendFunc* get_ccBlendFunc(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CcBlendFunc");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<ccBlendFunc*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is ccBlendFunc.");
    return NULL;
  }
}

static mrb_value ccBlendFunc_src(mrb_state *mrb, mrb_value self) {
  ccBlendFunc* instance = static_cast<ccBlendFunc*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->src);
}

static mrb_value ccBlendFunc_set_src(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccBlendFunc* instance = static_cast<ccBlendFunc*>(DATA_PTR(self));
  instance->src = get_int(o);
  return mrb_nil_value();
}

static mrb_value ccBlendFunc_dst(mrb_state *mrb, mrb_value self) {
  ccBlendFunc* instance = static_cast<ccBlendFunc*>(DATA_PTR(self));
  return mrb_fixnum_value(instance->dst);
}

static mrb_value ccBlendFunc_set_dst(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  ccBlendFunc* instance = static_cast<ccBlendFunc*>(DATA_PTR(self));
  instance->dst = get_int(o);
  return mrb_nil_value();
}

static void installccBlendFunc(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CcBlendFunc", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "src", ccBlendFunc_src, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "src=", ccBlendFunc_set_src, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "dst", ccBlendFunc_dst, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "dst=", ccBlendFunc_set_dst, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCPoint
static void _dfree_CCPoint(mrb_state *mrb, void *ptr) {
  ((CCPoint*)ptr)->~CCPoint(); mrb_free(mrb, ptr);
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
CCPoint* get_CCPoint(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCPoint");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCPoint*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCPoint.");
    return NULL;
  }
}

static mrb_value CCPoint___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCPoint* retval = new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint();
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCPoint* retval = new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(p0, p1);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
    
    CCPoint* retval = new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *get_CCSize(mrb, args[0]);
    
    CCPoint* retval = new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCPoint; DATA_PTR(self) = retval; return self;
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCPoint#__ctor Wrong count of arguments.");
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
  ((CCSize*)ptr)->~CCSize(); mrb_free(mrb, ptr);
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
CCSize* get_CCSize(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSize");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSize*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSize.");
    return NULL;
  }
}

static mrb_value CCSize___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSize* retval = new(mrb_malloc(mrb, sizeof(CCSize))) CCSize();
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    CCSize* retval = new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(p0, p1);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
    
    CCSize* retval = new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCSize& p0 = *get_CCSize(mrb, args[0]);
    
    CCSize* retval = new(mrb_malloc(mrb, sizeof(CCSize))) CCSize(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCSize; DATA_PTR(self) = retval; return self;
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCSize#__ctor Wrong count of arguments.");
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
  ((CCRect*)ptr)->~CCRect(); mrb_free(mrb, ptr);
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
CCRect* get_CCRect(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCRect");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCRect*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCRect.");
    return NULL;
  }
}

static mrb_value CCRect___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCRect* retval = new(mrb_malloc(mrb, sizeof(CCRect))) CCRect();
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 4) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    float p2 = get_float(args[2]);
    float p3 = get_float(args[3]);
    
    CCRect* retval = new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(p0, p1, p2, p3);
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 1) {
    const CCRect& p0 = *get_CCRect(mrb, args[0]);
    
    CCRect* retval = new(mrb_malloc(mrb, sizeof(CCRect))) CCRect(p0);
    DATA_TYPE(self) = &_mrb_data_type_CCRect; DATA_PTR(self) = retval; return self;
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCRect#__ctor Wrong count of arguments.");
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
  instance->origin = *get_CCPoint(mrb, o);
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
  instance->size = *get_CCSize(mrb, o);
  return mrb_nil_value();
}

static mrb_value CCRect_containsPoint(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  CCRect* instance = static_cast<CCRect*>(DATA_PTR(self));
  bool retval = instance->containsPoint(p0);
  return mrb_bool_value(retval);
}

static mrb_value CCRect_intersectsRect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCRect& p0 = *get_CCRect(mrb, args[0]);
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
static void _dfree_CCObject(mrb_state *mrb, void *ptr) {
  //nop
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
CCObject* get_CCObject(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCObject");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCObject*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCObject.");
    return NULL;
  }
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
  //nop
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
CCArray* get_CCArray(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCArray");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCArray*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCArray.");
    return NULL;
  }
}

static mrb_value CCArray_create(mrb_state *mrb, mrb_value self) {

  
  CCArray* retval = CCArray::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCArray(mrb, retval));
}

static mrb_value CCArray_addObject(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCObject* p0 = get_CCObject(mrb, args[0]);
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
  //nop
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
CCAction* get_CCAction(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCAction");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCAction*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCAction.");
    return NULL;
  }
}

static void installCCAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCFiniteTimeAction
static void _dfree_CCFiniteTimeAction(mrb_state *mrb, void *ptr) {
  //nop
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
CCFiniteTimeAction* get_CCFiniteTimeAction(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCFiniteTimeAction");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCFiniteTimeAction*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCFiniteTimeAction.");
    return NULL;
  }
}

static void installCCFiniteTimeAction(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCFiniteTimeAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInterval
static void _dfree_CCActionInterval(mrb_state *mrb, void *ptr) {
  //nop
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
CCActionInterval* get_CCActionInterval(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCActionInterval");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCActionInterval*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCActionInterval.");
    return NULL;
  }
}

static void installCCActionInterval(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInterval", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInstant
static void _dfree_CCActionInstant(mrb_state *mrb, void *ptr) {
  //nop
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
CCActionInstant* get_CCActionInstant(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCActionInstant");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCActionInstant*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCActionInstant.");
    return NULL;
  }
}

static void installCCActionInstant(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCFiniteTimeAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInstant", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCNode
static void _dfree_CCNode(mrb_state *mrb, void *ptr) {
  //nop
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
CCNode* get_CCNode(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCNode");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCNode*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCNode.");
    return NULL;
  }
}

static mrb_value CCNode_setPosition(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCNode#setPosition Wrong count of arguments.");
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
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setAnchorPoint(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getAnchorPoint(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  const CCPoint& retval = instance->getAnchorPoint();
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCNode_setScale(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  instance->setScale(p0);
  return mrb_nil_value();
}

static mrb_value CCNode_getScale(mrb_state *mrb, mrb_value self) {

  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  float retval = instance->getScale();
  return mrb_float_value(mrb, retval);
}

static mrb_value CCNode_addChild(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCNode* p0 = get_CCNode(mrb, args[0]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    CCNode* p0 = get_CCNode(mrb, args[0]);
    int p1 = get_int(args[1]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0, p1);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    CCNode* p0 = get_CCNode(mrb, args[0]);
    int p1 = get_int(args[1]);
    int p2 = get_int(args[2]);
    CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
    instance->addChild(p0, p1, p2);
    return mrb_nil_value();
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCNode#addChild Wrong count of arguments.");
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
  CCAction* p0 = get_CCAction(mrb, args[0]);
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
  CCTouch* p0 = get_CCTouch(mrb, args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCPoint retval = instance->convertTouchToNodeSpace(p0);
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCNode_convertToNodeSpace(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  CCNode* instance = static_cast<CCNode*>(DATA_PTR(self));
  CCPoint retval = instance->convertToNodeSpace(p0);
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
  CCObject* p0 = get_CCObject(mrb, args[0]);
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
  mrb_define_method(mrb, tc, "setScale", CCNode_setScale, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getScale", CCNode_getScale, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addChild", CCNode_addChild, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getChildByTag", CCNode_getChildByTag, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "runAction", CCNode_runAction, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getContentSize", CCNode_getContentSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setVisible", CCNode_setVisible, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "scheduleUpdate", CCNode_scheduleUpdate, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "scheduleUpdateWithPriorityLua", CCNode_scheduleUpdateWithPriorityLua, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "boundingBox", CCNode_boundingBox, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "convertTouchToNodeSpace", CCNode_convertTouchToNodeSpace, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "convertToNodeSpace", CCNode_convertToNodeSpace, MRB_ARGS_ANY());
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
  //nop
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
CCNodeRGBA* get_CCNodeRGBA(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCNodeRGBA");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCNodeRGBA*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCNodeRGBA.");
    return NULL;
  }
}

static mrb_value CCNodeRGBA_setColor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const ccColor3B& p0 = *get_ccColor3B(mrb, args[0]);
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
  //nop
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
CCTexture2D* get_CCTexture2D(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCTexture2D");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCTexture2D*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCTexture2D.");
    return NULL;
  }
}

static void installCCTexture2D(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCTexture2D", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCTextureCache
static void _dfree_CCTextureCache(mrb_state *mrb, void *ptr) {
  //nop
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
CCTextureCache* get_CCTextureCache(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCTextureCache");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCTextureCache*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCTextureCache.");
    return NULL;
  }
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
  //nop
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
CCSpriteFrame* get_CCSpriteFrame(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSpriteFrame");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSpriteFrame*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSpriteFrame.");
    return NULL;
  }
}

static mrb_value CCSpriteFrame_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const CCRect& p1 = *get_CCRect(mrb, args[1]);
  
  CCSpriteFrame* retval = CCSpriteFrame::create(p0, p1);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSpriteFrame(mrb, retval));
}

static mrb_value CCSpriteFrame_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTexture2D* p0 = get_CCTexture2D(mrb, args[0]);
  const CCRect& p1 = *get_CCRect(mrb, args[1]);
  
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
  //nop
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
CCAnimation* get_CCAnimation(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCAnimation");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCAnimation*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCAnimation.");
    return NULL;
  }
}

static mrb_value CCAnimation_createWithSpriteFrames(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCArray* p0 = get_CCArray(mrb, args[0]);
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
  //nop
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
CCAnimate* get_CCAnimate(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCAnimate");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCAnimate*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCAnimate.");
    return NULL;
  }
}

static mrb_value CCAnimate_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCAnimation* p0 = get_CCAnimation(mrb, args[0]);
  
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
  //nop
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
CCRepeatForever* get_CCRepeatForever(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCRepeatForever");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCRepeatForever*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCRepeatForever.");
    return NULL;
  }
}

static mrb_value CCRepeatForever_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCActionInterval* p0 = get_CCActionInterval(mrb, args[0]);
  
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
  //nop
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
CCScaleTo* get_CCScaleTo(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCScaleTo");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCScaleTo*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCScaleTo.");
    return NULL;
  }
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
  //nop
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
CCMoveBy* get_CCMoveBy(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMoveBy");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMoveBy*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMoveBy.");
    return NULL;
  }
}

static mrb_value CCMoveBy_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *get_CCPoint(mrb, args[1]);
  
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
  //nop
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
CCMoveTo* get_CCMoveTo(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMoveTo");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMoveTo*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMoveTo.");
    return NULL;
  }
}

static mrb_value CCMoveTo_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  const CCPoint& p1 = *get_CCPoint(mrb, args[1]);
  
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
  //nop
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
CCCallFunc* get_CCCallFunc(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCCallFunc");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCCallFunc*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCCallFunc.");
    return NULL;
  }
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
  //nop
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
CCSequence* get_CCSequence(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSequence");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSequence*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSequence.");
    return NULL;
  }
}

static mrb_value CCSequence_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = get_CCFiniteTimeAction(mrb, args[0]);
  CCFiniteTimeAction* p1 = get_CCFiniteTimeAction(mrb, args[1]);
  
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
  //nop
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
CCSpawn* get_CCSpawn(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSpawn");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSpawn*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSpawn.");
    return NULL;
  }
}

static mrb_value CCSpawn_createWithTwoActions(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCFiniteTimeAction* p0 = get_CCFiniteTimeAction(mrb, args[0]);
  CCFiniteTimeAction* p1 = get_CCFiniteTimeAction(mrb, args[1]);
  
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
  //nop
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
CCSprite* get_CCSprite(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSprite");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSprite*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSprite.");
    return NULL;
  }
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
    const CCRect& p1 = *get_CCRect(mrb, args[1]);
    
    CCSprite* retval = CCSprite::create(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCSprite#create Wrong count of arguments.");
    return mrb_nil_value();
  }
}

static mrb_value CCSprite_createWithSpriteFrame(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCSpriteFrame* p0 = get_CCSpriteFrame(mrb, args[0]);
  
  CCSprite* retval = CCSprite::createWithSpriteFrame(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
}

static mrb_value CCSprite_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    CCTexture2D* p0 = get_CCTexture2D(mrb, args[0]);
    
    CCSprite* retval = CCSprite::createWithTexture(p0);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else if (arg_count == 2) {
    CCTexture2D* p0 = get_CCTexture2D(mrb, args[0]);
    const CCRect& p1 = *get_CCRect(mrb, args[1]);
    
    CCSprite* retval = CCSprite::createWithTexture(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCSprite(mrb, retval));
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCSprite#createWithTexture Wrong count of arguments.");
    return mrb_nil_value();
  }
}

static mrb_value CCSprite_setTextureRect(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const CCRect& p0 = *get_CCRect(mrb, args[0]);
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->setTextureRect(p0);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    const CCRect& p0 = *get_CCRect(mrb, args[0]);
    bool p1 = get_bool(args[1]);
    const CCSize& p2 = *get_CCSize(mrb, args[2]);
    CCSprite* instance = static_cast<CCSprite*>(DATA_PTR(self));
    instance->setTextureRect(p0, p1, p2);
    return mrb_nil_value();
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCSprite#setTextureRect Wrong count of arguments.");
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
  //nop
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
CCSpriteBatchNode* get_CCSpriteBatchNode(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCSpriteBatchNode");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCSpriteBatchNode*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCSpriteBatchNode.");
    return NULL;
  }
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCSpriteBatchNode#create Wrong count of arguments.");
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
  //nop
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
CCLabelTTF* get_CCLabelTTF(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCLabelTTF");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCLabelTTF*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCLabelTTF.");
    return NULL;
  }
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
    const CCSize& p3 = *get_CCSize(mrb, args[3]);
    CCTextAlignment p4 = (CCTextAlignment)mrb_fixnum(args[4]);
    
    CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2, p3, p4);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelTTF(mrb, retval));
  } else if (arg_count == 6) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const char* p1 = mrb_string_value_ptr(mrb, args[1]);
    float p2 = get_float(args[2]);
    const CCSize& p3 = *get_CCSize(mrb, args[3]);
    CCTextAlignment p4 = (CCTextAlignment)mrb_fixnum(args[4]);
    CCVerticalTextAlignment p5 = (CCVerticalTextAlignment)mrb_fixnum(args[5]);
    
    CCLabelTTF* retval = CCLabelTTF::create(p0, p1, p2, p3, p4, p5);
    return (retval == NULL ? mrb_nil_value() : _wrap_CCLabelTTF(mrb, retval));
  } else {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCLabelTTF#create Wrong count of arguments.");
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
  //nop
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
CCLabelBMFont* get_CCLabelBMFont(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCLabelBMFont");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCLabelBMFont*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCLabelBMFont.");
    return NULL;
  }
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCLabelBMFont#create Wrong count of arguments.");
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
  //nop
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
CCDrawNode* get_CCDrawNode(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCDrawNode");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCDrawNode*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCDrawNode.");
    return NULL;
  }
}

static mrb_value CCDrawNode_create(mrb_state *mrb, mrb_value self) {

  
  CCDrawNode* retval = CCDrawNode::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCDrawNode(mrb, retval));
}

static mrb_value CCDrawNode_drawDot(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  float p1 = get_float(args[1]);
  const ccColor4F& p2 = *get_ccColor4F(mrb, args[2]);
  CCDrawNode* instance = static_cast<CCDrawNode*>(DATA_PTR(self));
  instance->drawDot(p0, p1, p2);
  return mrb_nil_value();
}

static mrb_value CCDrawNode_drawSegment(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  const CCPoint& p1 = *get_CCPoint(mrb, args[1]);
  float p2 = get_float(args[2]);
  const ccColor4F& p3 = *get_ccColor4F(mrb, args[3]);
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
  const ccBlendFunc& p0 = *get_ccBlendFunc(mrb, args[0]);
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
  //nop
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
CCLayer* get_CCLayer(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCLayer");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCLayer*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCLayer.");
    return NULL;
  }
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
    mrb_raise(mrb, E_ARGUMENT_ERROR, "CCLayer#registerScriptTouchHandler Wrong count of arguments.");
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
  //nop
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
CCLayerRGBA* get_CCLayerRGBA(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCLayerRGBA");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCLayerRGBA*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCLayerRGBA.");
    return NULL;
  }
}

static void installCCLayerRGBA(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCLayer");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLayerRGBA", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCScene
static void _dfree_CCScene(mrb_state *mrb, void *ptr) {
  //nop
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
CCScene* get_CCScene(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCScene");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCScene*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCScene.");
    return NULL;
  }
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
  //nop
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
CCScheduler* get_CCScheduler(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCScheduler");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCScheduler*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCScheduler.");
    return NULL;
  }
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
  //nop
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
CCDirector* get_CCDirector(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCDirector");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCDirector*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCDirector.");
    return NULL;
  }
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
  const CCPoint& p0 = *get_CCPoint(mrb, args[0]);
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCPoint retval = instance->convertToGL(p0);
  return _wrap_CCPoint(mrb, new(mrb_malloc(mrb, sizeof(CCPoint))) CCPoint(retval));
}

static mrb_value CCDirector_runWithScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = get_CCScene(mrb, args[0]);
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->runWithScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_replaceScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = get_CCScene(mrb, args[0]);
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->replaceScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_pushScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = get_CCScene(mrb, args[0]);
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
  //nop
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
CCEGLView* get_CCEGLView(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCEGLView");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCEGLView*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCEGLView.");
    return NULL;
  }
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
  //nop
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
CCFileUtils* get_CCFileUtils(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCFileUtils");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCFileUtils*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCFileUtils.");
    return NULL;
  }
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

static mrb_value CCFileUtils_fullPathFromRelativeFile(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  const char* p1 = mrb_string_value_ptr(mrb, args[1]);
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  const char* retval = instance->fullPathFromRelativeFile(p0, p1);
  return mrb_str_new_cstr(mrb, retval);
}

static mrb_value CCFileUtils_addSearchPath(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  instance->addSearchPath(p0);
  return mrb_nil_value();
}

static mrb_value CCFileUtils_removeSearchPath(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  instance->removeSearchPath(p0);
  return mrb_nil_value();
}

static mrb_value CCFileUtils_removeAllPaths(mrb_state *mrb, mrb_value self) {

  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  instance->removeAllPaths();
  return mrb_nil_value();
}

static mrb_value CCFileUtils_getSearchPaths(mrb_state *mrb, mrb_value self) {
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  const std::vector<std::string>& retval = instance->getSearchPaths();
  mrb_value array = mrb_ary_new(mrb);
  for(auto s:retval){
    mrb_value v = mrb_str_new(mrb, s.c_str(), s.size());
    mrb_ary_push(mrb, array, v);
  }
  return array;
}

static mrb_value CCFileUtils_isFileExist(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const std::string& p0 = std::string(mrb_string_value_ptr(mrb, args[0]));
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  bool retval = instance->isFileExist(p0);
  return mrb_bool_value(retval);
}

static mrb_value CCFileUtils_isAbsolutePath(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const std::string& p0 = std::string(mrb_string_value_ptr(mrb, args[0]));
  CCFileUtils* instance = static_cast<CCFileUtils*>(DATA_PTR(self));
  bool retval = instance->isAbsolutePath(p0);
  return mrb_bool_value(retval);
}

static void installCCFileUtils(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCFileUtils", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedFileUtils", CCFileUtils_sharedFileUtils, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "fullPathForFilename", CCFileUtils_fullPathForFilename, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "fullPathFromRelativeFile", CCFileUtils_fullPathFromRelativeFile, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addSearchPath", CCFileUtils_addSearchPath, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "removeSearchPath", CCFileUtils_removeSearchPath, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "removeAllPaths", CCFileUtils_removeAllPaths, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getSearchPaths", CCFileUtils_getSearchPaths, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "isFileExist", CCFileUtils_isFileExist, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "isAbsolutePath", CCFileUtils_isAbsolutePath, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenuItem
static void _dfree_CCMenuItem(mrb_state *mrb, void *ptr) {
  //nop
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
CCMenuItem* get_CCMenuItem(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenuItem");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenuItem*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenuItem.");
    return NULL;
  }
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
  //nop
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
CCMenuItemSprite* get_CCMenuItemSprite(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenuItemSprite");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenuItemSprite*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenuItemSprite.");
    return NULL;
  }
}

static void installCCMenuItemSprite(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemImage
static void _dfree_CCMenuItemImage(mrb_state *mrb, void *ptr) {
  //nop
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
CCMenuItemImage* get_CCMenuItemImage(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenuItemImage");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenuItemImage*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenuItemImage.");
    return NULL;
  }
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
  //nop
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
CCMenuItemLabel* get_CCMenuItemLabel(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenuItemLabel");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenuItemLabel*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenuItemLabel.");
    return NULL;
  }
}

static void installCCMenuItemLabel(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItem");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemLabel", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCMenuItemFont
static void _dfree_CCMenuItemFont(mrb_state *mrb, void *ptr) {
  //nop
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
CCMenuItemFont* get_CCMenuItemFont(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenuItemFont");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenuItemFont*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenuItemFont.");
    return NULL;
  }
}

static mrb_value CCMenuItemFont_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  
  CCMenuItemFont* retval = CCMenuItemFont::create(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenuItemFont(mrb, retval));
}

static mrb_value CCMenuItemFont_setFontSizeObj(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  unsigned int p0 = get_int(args[0]);
  CCMenuItemFont* instance = static_cast<CCMenuItemFont*>(DATA_PTR(self));
  instance->setFontSizeObj(p0);
  return mrb_nil_value();
}

static void installCCMenuItemFont(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "CCMenuItemLabel");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCMenuItemFont", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCMenuItemFont_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setFontSizeObj", CCMenuItemFont_setFontSizeObj, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCMenu
static void _dfree_CCMenu(mrb_state *mrb, void *ptr) {
  //nop
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
CCMenu* get_CCMenu(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCMenu");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCMenu*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCMenu.");
    return NULL;
  }
}

static mrb_value CCMenu_create(mrb_state *mrb, mrb_value self) {

  
  CCMenu* retval = CCMenu::create();
  return (retval == NULL ? mrb_nil_value() : _wrap_CCMenu(mrb, retval));
}

static mrb_value CCMenu_createWithItem(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCMenuItem* p0 = get_CCMenuItem(mrb, args[0]);
  
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
  //nop
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
CCTouch* get_CCTouch(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCTouch");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCTouch*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCTouch.");
    return NULL;
  }
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
  //nop
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
CCUserDefault* get_CCUserDefault(mrb_state *mrb, mrb_value v)
{
  struct RClass *c = getClass(mrb, "CCUserDefault");
  if(mrb_obj_is_kind_of(mrb, v, c)){
    return static_cast<CCUserDefault*>(DATA_PTR(v));
  }else{
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Wrong type for argument. required class is CCUserDefault.");
    return NULL;
  }
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
  
  ccColor3B retval = ccc3(p0, p1, p2);
  return _wrap_ccColor3B(mrb, new(mrb_malloc(mrb, sizeof(ccColor3B))) ccColor3B(retval));
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
  
  ccColor4F retval = ccc4f(p0, p1, p2, p3);
  return _wrap_ccColor4F(mrb, new(mrb_malloc(mrb, sizeof(ccColor4F))) ccColor4F(retval));
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
  installccColor3B(mrb, mod);
  installccColor4F(mrb, mod);
  installccBlendFunc(mrb, mod);
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
