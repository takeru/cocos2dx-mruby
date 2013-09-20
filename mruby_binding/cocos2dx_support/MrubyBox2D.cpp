#include "Box2D.h"

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

static mrb_value getMrubyCocos2dClassValue(mrb_state *mrb, const char* className) {
  mrb_sym sym = mrb_intern_cstr(mrb, "Box2D");
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
  DATA_PTR(instance) = (void*)ptr;
  return instance;
}

////////////////////////////////////////////////////////////////
// b2Vec2

static mrb_value b2Vec2___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    b2Vec2* retval = new b2Vec2();
    DATA_PTR(self) = retval; return self;
  } else if (arg_count == 2) {
    float p0 = get_float(args[0]);
    float p1 = get_float(args[1]);
    
    b2Vec2* retval = new b2Vec2(p0, p1);
    DATA_PTR(self) = retval; return self;
  } else {
    // TODO: raise exception.
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
  mrb_define_method(mrb, tc, "Set", b2Vec2_Set, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2Shape

static void installb2Shape(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Shape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// b2EdgeShape

static mrb_value b2EdgeShape___ctor(mrb_state *mrb, mrb_value self) {

  
  b2EdgeShape* retval = new b2EdgeShape();
  DATA_PTR(self) = retval; return self;
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
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "b2Shape");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2EdgeShape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2EdgeShape___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "Set", b2EdgeShape_Set, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2PolygonShape

static mrb_value b2PolygonShape___ctor(mrb_state *mrb, mrb_value self) {

  
  b2PolygonShape* retval = new b2PolygonShape();
  DATA_PTR(self) = retval; return self;
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
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "b2Shape");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2PolygonShape", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2PolygonShape___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "SetAsBox", b2PolygonShape_SetAsBox, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2FixtureDef

static mrb_value b2FixtureDef___ctor(mrb_state *mrb, mrb_value self) {

  
  b2FixtureDef* retval = new b2FixtureDef();
  DATA_PTR(self) = retval; return self;
}

static mrb_value b2FixtureDef_shape(mrb_state *mrb, mrb_value self) {
  b2FixtureDef* instance = static_cast<b2FixtureDef*>(DATA_PTR(self));
  return (instance->shape == NULL ? mrb_nil_value() : wrap(mrb, instance->shape, "B2Shape"));
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

static void installb2Fixture(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Fixture", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// b2BodyDef

static mrb_value b2BodyDef___ctor(mrb_state *mrb, mrb_value self) {

  
  b2BodyDef* retval = new b2BodyDef();
  DATA_PTR(self) = retval; return self;
}

static mrb_value b2BodyDef_type(mrb_state *mrb, mrb_value self) {
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(b2BodyType))) b2BodyType(instance->type), "B2BodyType");
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
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(instance->position), "B2Vec2");
}

static mrb_value b2BodyDef_set_position(mrb_state *mrb, mrb_value self) {
  mrb_value o;
  mrb_get_args(mrb, "o", &o);
  b2BodyDef* instance = static_cast<b2BodyDef*>(DATA_PTR(self));
  instance->position = *static_cast<b2Vec2*>(DATA_PTR(o));
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
}

////////////////////////////////////////////////////////////////
// b2Body

static mrb_value b2Body_CreateFixture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 1) {
    const b2FixtureDef* p0 = static_cast<b2FixtureDef*>(DATA_PTR(args[0]));
    b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
    b2Fixture* retval = instance->CreateFixture(p0);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "B2Fixture"));
  } else if (arg_count == 2) {
    const b2Shape* p0 = static_cast<b2Shape*>(DATA_PTR(args[0]));
    float p1 = get_float(args[1]);
    b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
    b2Fixture* retval = instance->CreateFixture(p0, p1);
    return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "B2Fixture"));
  } else {
    // TODO: raise exception.
    return mrb_nil_value();
  }
}

static mrb_value b2Body_GetNext(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  b2Body* retval = instance->GetNext();
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "B2Body"));
}

static mrb_value b2Body_GetUserData(mrb_state *mrb, mrb_value self) {

  b2Body* instance = static_cast<b2Body*>(DATA_PTR(self));
  void* retval = instance->GetUserData();
  return (retval == NULL ? mrb_nil_value() : mrb_voidp_value(mrb, retval));
}

static void installb2Body(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2Body", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "CreateFixture", b2Body_CreateFixture, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "GetNext", b2Body_GetNext, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "GetUserData", b2Body_GetUserData, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// b2World

static mrb_value b2World___ctor(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  b2Vec2 p0 = *static_cast<b2Vec2*>(DATA_PTR(args[0]));
  
  b2World* retval = new b2World(p0);
  DATA_PTR(self) = retval; return self;
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
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "B2Body"));
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
  return (retval == NULL ? mrb_nil_value() : wrap(mrb, retval, "B2Body"));
}

static void installb2World(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "B2World", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", b2World___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "SetAllowSleeping", b2World_SetAllowSleeping, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "SetContinuousPhysics", b2World_SetContinuousPhysics, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "CreateBody", b2World_CreateBody, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "Step", b2World_Step, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "GetBodyList", b2World_GetBodyList, MRB_ARGS_ANY());
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
  return wrap(mrb, new(mrb_malloc(mrb, sizeof(b2Vec2))) b2Vec2(retval), "B2Vec2");
}

void installMrubyBox2D(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Box2D");
  mrb_define_const(mrb, mod, "B2_staticBody", mrb_fixnum_value(b2_staticBody));
  mrb_define_const(mrb, mod, "B2_kinematicBody", mrb_fixnum_value(b2_kinematicBody));
  mrb_define_const(mrb, mod, "B2_dynamicBody", mrb_fixnum_value(b2_dynamicBody));
  mrb_define_method(mrb, mod, "b2Vec2", b2Vec2__, MRB_ARGS_ANY());
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
