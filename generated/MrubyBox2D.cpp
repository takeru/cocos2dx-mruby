#include "Box2D.h"

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
  RClass* mod = mrb_module_get(mrb, "Box2D");
  return mrb_class_get_under(mrb, mod, className);
}


////////////////////////////////////////////////////////////////
// b2Vec2
static void _dfree_b2Vec2(mrb_state *mrb, void *ptr) {
  ((b2Vec2*)ptr)->~b2Vec2(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2Vec2 = { "b2Vec2", _dfree_b2Vec2 };
mrb_value _wrap_b2Vec2(mrb_state *mrb, const b2Vec2* ptr) {
  struct RClass* tc = getClass(mrb, "B2Vec2");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2Vec2, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2Vec2;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2Vec2___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    b2Vec2* retval = new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2();
    DATA_TYPE(self) = &_mrb_data_type_b2Vec2; DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    b2Vec2* retval = new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(p0, p1);
    DATA_TYPE(self) = &_mrb_data_type_b2Vec2; DATA_PTR(self) = retval; return self;
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "b2Vec2#__ctor");
    return mrb_nil_value();
  }
}

static mrb_value b2Vec2_x(mrb_state *mrb, mrb_value self) {
  b2Vec2* instance = static_cast<b2Vec2*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->x);
}

static mrb_value b2Vec2_set_x(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2Vec2* instance = static_cast<b2Vec2*>(DATA_PTR(self));
  instance->x = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2Vec2_y(mrb_state *mrb, mrb_value self) {
  b2Vec2* instance = static_cast<b2Vec2*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->y);
}

static mrb_value b2Vec2_set_y(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2Vec2* instance = static_cast<b2Vec2*>(DATA_PTR(self));
  instance->y = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2Vec2_Set(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  b2Vec2* instance = static_cast<b2Vec2*>(DATA_PTR(self));
  instance->Set(p0, p1);
  return mrb_nil_value();
}

static void installb2Vec2(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Vec2", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2Vec2___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "x", b2Vec2_x, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "x=", b2Vec2_set_x, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "y", b2Vec2_y, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "y=", b2Vec2_set_y, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "set", b2Vec2_Set, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2Shape
static void _dfree_b2Shape(mrb_state *mrb, void *ptr) {
  ((b2Shape*)ptr)->~b2Shape(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2Shape = { "b2Shape", _dfree_b2Shape };
mrb_value _wrap_b2Shape(mrb_state *mrb, const b2Shape* ptr) {
  struct RClass* tc = getClass(mrb, "B2Shape");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2Shape, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2Shape;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installb2Shape(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Shape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// b2EdgeShape
static void _dfree_b2EdgeShape(mrb_state *mrb, void *ptr) {
  ((b2EdgeShape*)ptr)->~b2EdgeShape(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2EdgeShape = { "b2EdgeShape", _dfree_b2EdgeShape };
mrb_value _wrap_b2EdgeShape(mrb_state *mrb, const b2EdgeShape* ptr) {
  struct RClass* tc = getClass(mrb, "B2EdgeShape");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2EdgeShape, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2EdgeShape;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2EdgeShape___ctor(mrb_state *mrb, mrb_value self) {

  
  b2EdgeShape* retval = new(mrb_malloc(mrb, sizeof(b2EdgeShape))) b2EdgeShape();
  DATA_TYPE(self) = &_mrb_data_type_b2EdgeShape; DATA_PTR(self) = retval; return self;
}

static mrb_value b2EdgeShape_Set(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const b2Vec2& p0 = *static_cast<b2Vec2*>(DATA_PTR(args[0]));
  const b2Vec2& p1 = *static_cast<b2Vec2*>(DATA_PTR(args[1]));
  b2EdgeShape* instance = static_cast<b2EdgeShape*>(DATA_PTR(self));
  instance->Set(p0, p1);
  return mrb_nil_value();
}

static void installb2EdgeShape(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "B2Shape");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2EdgeShape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2EdgeShape___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "set", b2EdgeShape_Set, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2PolygonShape
static void _dfree_b2PolygonShape(mrb_state *mrb, void *ptr) {
  ((b2PolygonShape*)ptr)->~b2PolygonShape(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2PolygonShape = { "b2PolygonShape", _dfree_b2PolygonShape };
mrb_value _wrap_b2PolygonShape(mrb_state *mrb, const b2PolygonShape* ptr) {
  struct RClass* tc = getClass(mrb, "B2PolygonShape");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2PolygonShape, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2PolygonShape;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2PolygonShape___ctor(mrb_state *mrb, mrb_value self) {

  
  b2PolygonShape* retval = new(mrb_malloc(mrb, sizeof(b2PolygonShape))) b2PolygonShape();
  DATA_TYPE(self) = &_mrb_data_type_b2PolygonShape; DATA_PTR(self) = retval; return self;
}

static mrb_value b2PolygonShape_SetAsBox(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  b2PolygonShape* instance = static_cast<b2PolygonShape*>(DATA_PTR(self));
  instance->SetAsBox(p0, p1);
  return mrb_nil_value();
}

static void installb2PolygonShape(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getClass(mrb, "B2Shape");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2PolygonShape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2PolygonShape___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAsBox", b2PolygonShape_SetAsBox, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2FixtureDef
static void _dfree_b2FixtureDef(mrb_state *mrb, void *ptr) {
  ((b2FixtureDef*)ptr)->~b2FixtureDef(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2FixtureDef = { "b2FixtureDef", _dfree_b2FixtureDef };
mrb_value _wrap_b2FixtureDef(mrb_state *mrb, const b2FixtureDef* ptr) {
  struct RClass* tc = getClass(mrb, "B2FixtureDef");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2FixtureDef, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2FixtureDef;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2FixtureDef___ctor(mrb_state *mrb, mrb_value self) {

  
  b2FixtureDef* retval = new(mrb_malloc(mrb, sizeof(b2FixtureDef))) b2FixtureDef();
  DATA_TYPE(self) = &_mrb_data_type_b2FixtureDef; DATA_PTR(self) = retval; return self;
}

static mrb_value b2FixtureDef_shape(mrb_state *mrb, mrb_value self) {
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  return (instance->shape == NULL ? mrb_nil_value() : _wrap_b2Shape(mrb, instance->shape));
}

static mrb_value b2FixtureDef_set_shape(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  instance->shape = static_cast<b2Shape*>(DATA_PTR(o));
  return mrb_nil_value();
}

static mrb_value b2FixtureDef_friction(mrb_state *mrb, mrb_value self) {
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->friction);
}

static mrb_value b2FixtureDef_set_friction(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  instance->friction = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2FixtureDef_restitution(mrb_state *mrb, mrb_value self) {
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->restitution);
}

static mrb_value b2FixtureDef_set_restitution(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  instance->restitution = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2FixtureDef_density(mrb_state *mrb, mrb_value self) {
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->density);
}

static mrb_value b2FixtureDef_set_density(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  instance->density = get_float(o);
  return mrb_nil_value();
}

static void installb2FixtureDef(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2FixtureDef", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2FixtureDef___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "shape", b2FixtureDef_shape, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "shape=", b2FixtureDef_set_shape, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "friction", b2FixtureDef_friction, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "friction=", b2FixtureDef_set_friction, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "restitution", b2FixtureDef_restitution, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "restitution=", b2FixtureDef_set_restitution, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "density", b2FixtureDef_density, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "density=", b2FixtureDef_set_density, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// b2Fixture
static void _dfree_b2Fixture(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_b2Fixture = { "b2Fixture", _dfree_b2Fixture };
mrb_value _wrap_b2Fixture(mrb_state *mrb, const b2Fixture* ptr) {
  struct RClass* tc = getClass(mrb, "B2Fixture");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2Fixture, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2Fixture;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static void installb2Fixture(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Fixture", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// b2BodyDef
static void _dfree_b2BodyDef(mrb_state *mrb, void *ptr) {
  ((b2BodyDef*)ptr)->~b2BodyDef(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2BodyDef = { "b2BodyDef", _dfree_b2BodyDef };
mrb_value _wrap_b2BodyDef(mrb_state *mrb, const b2BodyDef* ptr) {
  struct RClass* tc = getClass(mrb, "B2BodyDef");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2BodyDef, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2BodyDef;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2BodyDef___ctor(mrb_state *mrb, mrb_value self) {

  
  b2BodyDef* retval = new(mrb_malloc(mrb, sizeof(b2BodyDef))) b2BodyDef();
  DATA_TYPE(self) = &_mrb_data_type_b2BodyDef; DATA_PTR(self) = retval; return self;
}

static mrb_value b2BodyDef_type(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return mrb_fixnum_value((int)instance->type);
}

static mrb_value b2BodyDef_set_type(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->type = (b2BodyType)mrb_fixnum(o);
  return mrb_nil_value();
}

static mrb_value b2BodyDef_position(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return _wrap_b2Vec2(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(instance->position));
}

static mrb_value b2BodyDef_set_position(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->position = *static_cast<b2Vec2*>(DATA_PTR(o));
  return mrb_nil_value();
}

static mrb_value b2BodyDef_angle(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->angle);
}

static mrb_value b2BodyDef_set_angle(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->angle = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2BodyDef_linearVelocity(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return _wrap_b2Vec2(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(instance->linearVelocity));
}

static mrb_value b2BodyDef_set_linearVelocity(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->linearVelocity = *static_cast<b2Vec2*>(DATA_PTR(o));
  return mrb_nil_value();
}

static mrb_value b2BodyDef_angularVelocity(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->angularVelocity);
}

static mrb_value b2BodyDef_set_angularVelocity(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->angularVelocity = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2BodyDef_linearDamping(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->linearDamping);
}

static mrb_value b2BodyDef_set_linearDamping(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->linearDamping = get_float(o);
  return mrb_nil_value();
}

static mrb_value b2BodyDef_angularDamping(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return mrb_float_value(mrb, instance->angularDamping);
}

static mrb_value b2BodyDef_set_angularDamping(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->angularDamping = get_float(o);
  return mrb_nil_value();
}

static void installb2BodyDef(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2BodyDef", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2BodyDef___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "type", b2BodyDef_type, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "type=", b2BodyDef_set_type, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "position", b2BodyDef_position, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "position=", b2BodyDef_set_position, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "angle", b2BodyDef_angle, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "angle=", b2BodyDef_set_angle, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "linearVelocity", b2BodyDef_linearVelocity, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "linearVelocity=", b2BodyDef_set_linearVelocity, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "angularVelocity", b2BodyDef_angularVelocity, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "angularVelocity=", b2BodyDef_set_angularVelocity, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "linearDamping", b2BodyDef_linearDamping, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "linearDamping=", b2BodyDef_set_linearDamping, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "angularDamping", b2BodyDef_angularDamping, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "angularDamping=", b2BodyDef_set_angularDamping, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// b2Body
static void _dfree_b2Body(mrb_state *mrb, void *ptr) {
  //nop
}
static struct mrb_data_type _mrb_data_type_b2Body = { "b2Body", _dfree_b2Body };
mrb_value _wrap_b2Body(mrb_state *mrb, const b2Body* ptr) {
  struct RClass* tc = getClass(mrb, "B2Body");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2Body, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2Body;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2Body_CreateFixture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const b2FixtureDef* p0 = static_cast<b2FixtureDef*>(DATA_PTR(args[0]));
    b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
    b2Fixture* retval = instance->CreateFixture(p0);
    return (retval == NULL ? mrb_nil_value() : _wrap_b2Fixture(mrb, retval));
  } else if (arg_count == 2) {
    const b2Shape* p0 = static_cast<b2Shape*>(DATA_PTR(args[0]));
    float p1 = get_float(args[1]);
    b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
    b2Fixture* retval = instance->CreateFixture(p0, p1);
    return (retval == NULL ? mrb_nil_value() : _wrap_b2Fixture(mrb, retval));
  } else {

    mrb_raise(mrb, mrb_class_get(mrb, "ArgumentError"), "b2Body#CreateFixture");
    return mrb_nil_value();
  }
}

static mrb_value b2Body_DestroyFixture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  b2Fixture* p0 = static_cast<b2Fixture*>(DATA_PTR(args[0]));
  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  instance->DestroyFixture(p0);
  return mrb_nil_value();
}

static mrb_value b2Body_GetNext(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  b2Body* retval = instance->GetNext();
  return (retval == NULL ? mrb_nil_value() : _wrap_b2Body(mrb, retval));
}

static mrb_value b2Body_GetUserData(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  void* retval = instance->GetUserData();
  return (retval == NULL ? mrb_nil_value() : mrb_voidp_value(mrb, retval));
}

static mrb_value b2Body_SetTransform(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const b2Vec2& p0 = *static_cast<b2Vec2*>(DATA_PTR(args[0]));
  float p1 = get_float(args[1]);
  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  instance->SetTransform(p0, p1);
  return mrb_nil_value();
}

static mrb_value b2Body_GetPosition(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  const b2Vec2& retval = instance->GetPosition();
  return _wrap_b2Vec2(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(retval));
}

static mrb_value b2Body_GetAngle(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  float retval = instance->GetAngle();
  return mrb_float_value(mrb, retval);
}

static mrb_value b2Body_SetLinearVelocity(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const b2Vec2& p0 = *static_cast<b2Vec2*>(DATA_PTR(args[0]));
  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  instance->SetLinearVelocity(p0);
  return mrb_nil_value();
}

static mrb_value b2Body_GetLinearVelocity(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  b2Vec2 retval = instance->GetLinearVelocity();
  return _wrap_b2Vec2(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(retval));
}

static mrb_value b2Body_SetAngularVelocity(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  instance->SetAngularVelocity(p0);
  return mrb_nil_value();
}

static mrb_value b2Body_GetAngularVelocity(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  float retval = instance->GetAngularVelocity();
  return mrb_float_value(mrb, retval);
}

static void installb2Body(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Body", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "createFixture", b2Body_CreateFixture, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "destroyFixture", b2Body_DestroyFixture, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getNext", b2Body_GetNext, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getUserData", b2Body_GetUserData, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTransform", b2Body_SetTransform, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPosition", b2Body_GetPosition, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getAngle", b2Body_GetAngle, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setLinearVelocity", b2Body_SetLinearVelocity, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getLinearVelocity", b2Body_GetLinearVelocity, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAngularVelocity", b2Body_SetAngularVelocity, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getAngularVelocity", b2Body_GetAngularVelocity, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2World
static void _dfree_b2World(mrb_state *mrb, void *ptr) {
  ((b2World*)ptr)->~b2World(); mrb_free(mrb, ptr);
}
static struct mrb_data_type _mrb_data_type_b2World = { "b2World", _dfree_b2World };
mrb_value _wrap_b2World(mrb_state *mrb, const b2World* ptr) {
  struct RClass* tc = getClass(mrb, "B2World");
  assert(tc != NULL);
  mrb_value instance = mrb_obj_value(Data_Wrap_Struct(mrb, tc, &_mrb_data_type_b2World, NULL));
  DATA_TYPE(instance) = &_mrb_data_type_b2World;
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

static mrb_value b2World___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  b2Vec2 p0 = *static_cast<b2Vec2*>(DATA_PTR(args[0]));
  
  b2World* retval = new(mrb_malloc(mrb, sizeof(b2World))) b2World(p0);
  DATA_TYPE(self) = &_mrb_data_type_b2World; DATA_PTR(self) = retval; return self;
}

static mrb_value b2World_SetAllowSleeping(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  instance->SetAllowSleeping(p0);
  return mrb_nil_value();
}

static mrb_value b2World_SetContinuousPhysics(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  bool p0 = get_bool(args[0]);
  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  instance->SetContinuousPhysics(p0);
  return mrb_nil_value();
}

static mrb_value b2World_CreateBody(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const b2BodyDef* p0 = static_cast<b2BodyDef*>(DATA_PTR(args[0]));
  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  b2Body* retval = instance->CreateBody(p0);
  return (retval == NULL ? mrb_nil_value() : _wrap_b2Body(mrb, retval));
}

static mrb_value b2World_DestroyBody(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  b2Body* p0 = static_cast<b2Body*>(DATA_PTR(args[0]));
  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  instance->DestroyBody(p0);
  return mrb_nil_value();
}

static mrb_value b2World_Step(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  int p1 = get_int(args[1]);
  int p2 = get_int(args[2]);
  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  instance->Step(p0, p1, p2);
  return mrb_nil_value();
}

static mrb_value b2World_GetBodyList(mrb_state *mrb, mrb_value self) {

  b2World* instance = static_cast<b2World*>(DATA_PTR(self));
  b2Body* retval = instance->GetBodyList();
  return (retval == NULL ? mrb_nil_value() : _wrap_b2Body(mrb, retval));
}

static void installb2World(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2World", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2World___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setAllowSleeping", b2World_SetAllowSleeping, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setContinuousPhysics", b2World_SetContinuousPhysics, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "createBody", b2World_CreateBody, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "destroyBody", b2World_DestroyBody, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "step", b2World_Step, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getBodyList", b2World_GetBodyList, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// Functions.

static mrb_value b2Vec2__(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  float p0 = get_float(args[0]);
  float p1 = get_float(args[1]);
  
  b2Vec2 retval = b2Vec2(p0, p1);
  return _wrap_b2Vec2(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(retval));
}

void installMrubyBox2D(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Box2D");
  mrb_define_const(mrb, mod, "B2_staticBody", mrb_fixnum_value(b2_staticBody));
  mrb_define_const(mrb, mod, "B2_kinematicBody", mrb_fixnum_value(b2_kinematicBody));
  mrb_define_const(mrb, mod, "B2_dynamicBody", mrb_fixnum_value(b2_dynamicBody));
  mrb_define_module_function(mrb, mod, "b2Vec2", b2Vec2__, MRB_ARGS_ANY());
  installb2Vec2(mrb, mod);
  installb2Shape(mrb, mod);
  installb2EdgeShape(mrb, mod);
  installb2PolygonShape(mrb, mod);
  installb2FixtureDef(mrb, mod);
  installb2Fixture(mrb, mod);
  installb2BodyDef(mrb, mod);
  installb2Body(mrb, mod);
  installb2World(mrb, mod);
}
