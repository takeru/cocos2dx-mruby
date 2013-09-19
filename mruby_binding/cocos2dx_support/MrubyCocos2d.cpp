#include "cocos2d.h"
#include "mruby.h"

extern int registerProc(mrb_state *mrb, mrb_value proc);

using namespace cocos2d;

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
  mrb_sym sym = mrb_intern_cstr(mrb, "Cocos2d");
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
    // TODO: raise exception.
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
    // TODO: raise exception.
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
    // TODO: raise exception.
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

static void installCCRect(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCRect", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "initialize", CCRect___ctor, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "origin", CCRect_origin, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "origin=", CCRect_set_origin, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "size", CCRect_size, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "size=", CCRect_set_size, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCObject

static void installCCObject(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCObject", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCArray

static mrb_value CCArray_create(mrb_state *mrb, mrb_value self) {

  
  CCArray* retval = CCArray::create();
  return wrap(mrb, retval, "CCArray");
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
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCObject");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCAction", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCActionInterval

static void installCCActionInterval(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCAction");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCActionInterval", parent);
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
    // TODO: raise exception.
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
  } else {
    // TODO: raise exception.
    return mrb_nil_value();
  }
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

static void installCCNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCNode", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "setPosition", CCNode_setPosition, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setPositionX", CCNode_setPositionX, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPositionX", CCNode_getPositionX, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setPositionY", CCNode_setPositionY, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPositionY", CCNode_getPositionY, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getPosition", CCNode_getPosition, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addChild", CCNode_addChild, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "runAction", CCNode_runAction, MRB_ARGS_ANY());
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
  return wrap(mrb, retval, "CCTextureCache");
}

static mrb_value CCTextureCache_addImage(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  const char* p0 = mrb_string_value_ptr(mrb, args[0]);
  CCTextureCache* instance = static_cast<CCTextureCache*>(DATA_PTR(self));
  CCTexture2D* retval = instance->addImage(p0);
  return wrap(mrb, retval, "CCTexture2D");
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
  return wrap(mrb, retval, "CCSpriteFrame");
}

static mrb_value CCSpriteFrame_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCTexture2D* p0 = static_cast<CCTexture2D*>(DATA_PTR(args[0]));
  const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
  
  CCSpriteFrame* retval = CCSpriteFrame::createWithTexture(p0, p1);
  return wrap(mrb, retval, "CCSpriteFrame");
}

static void installCCSpriteFrame(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCObject");
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
  return wrap(mrb, retval, "CCAnimation");
}

static void installCCAnimation(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCObject");
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
  return wrap(mrb, retval, "CCAnimate");
}

static void installCCAnimate(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCActionInterval");
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
  return wrap(mrb, retval, "CCRepeatForever");
}

static void installCCRepeatForever(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCActionInterval");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCRepeatForever", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCRepeatForever_create, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCSprite

static mrb_value CCSprite_create(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  if (arg_count == 0) {
  
    
    CCSprite* retval = CCSprite::create();
    return wrap(mrb, retval, "CCSprite");
  } else if (arg_count == 1) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    
    CCSprite* retval = CCSprite::create(p0);
    return wrap(mrb, retval, "CCSprite");
  } else if (arg_count == 2) {
    const char* p0 = mrb_string_value_ptr(mrb, args[0]);
    const CCRect& p1 = *static_cast<CCRect*>(DATA_PTR(args[1]));
    
    CCSprite* retval = CCSprite::create(p0, p1);
    return wrap(mrb, retval, "CCSprite");
  } else {
    // TODO: raise exception.
    return mrb_nil_value();
  }
}

static mrb_value CCSprite_createWithSpriteFrame(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCSpriteFrame* p0 = static_cast<CCSpriteFrame*>(DATA_PTR(args[0]));
  
  CCSprite* retval = CCSprite::createWithSpriteFrame(p0);
  return wrap(mrb, retval, "CCSprite");
}

static void installCCSprite(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCSprite_create, MRB_ARGS_ANY());
  mrb_define_class_method(mrb, tc, "createWithSpriteFrame", CCSprite_createWithSpriteFrame, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCLayer

static mrb_value CCLayer_create(mrb_state *mrb, mrb_value self) {

  
  CCLayer* retval = CCLayer::create();
  return wrap(mrb, retval, "CCLayer");
}

static mrb_value CCLayer_registerScriptTouchHandler(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_value block;
  mrb_get_args(mrb, "*&", &args, &arg_count, &block);
  if (arg_count == 0) {
    int blockHandler = registerProc(mrb, block);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler);
    return mrb_nil_value();
  } else if (arg_count == 1) {
    int blockHandler = registerProc(mrb, block);
    bool p0 = get_bool(args[0]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0);
    return mrb_nil_value();
  } else if (arg_count == 2) {
    int blockHandler = registerProc(mrb, block);
    bool p0 = get_bool(args[0]);
    int p1 = get_int(args[1]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0, p1);
    return mrb_nil_value();
  } else if (arg_count == 3) {
    int blockHandler = registerProc(mrb, block);
    bool p0 = get_bool(args[0]);
    int p1 = get_int(args[1]);
    bool p2 = get_bool(args[2]);
    CCLayer* instance = static_cast<CCLayer*>(DATA_PTR(self));
    instance->registerScriptTouchHandler(blockHandler, p0, p1, p2);
    return mrb_nil_value();
  } else {
    // TODO: raise exception.
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

static void installCCLayer(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCNode");
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCLayer", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", CCLayer_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "registerScriptTouchHandler", CCLayer_registerScriptTouchHandler, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "setTouchEnabled", CCLayer_setTouchEnabled, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCScene

static mrb_value CCScene_create(mrb_state *mrb, mrb_value self) {

  
  CCScene* retval = CCScene::create();
  return wrap(mrb, retval, "CCScene");
}

static void installCCScene(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = getMrubyCocos2dClassPtr(mrb, "CCNode");
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
  int blockHandler = registerProc(mrb, block);
  float p0 = get_float(args[0]);
  bool p1 = get_bool(args[1]);
  CCScheduler* instance = static_cast<CCScheduler*>(DATA_PTR(self));
  int retval = instance->scheduleScriptFunc(blockHandler, p0, p1);
  return mrb_fixnum_value(retval);
}

static void installCCScheduler(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCScheduler", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "scheduleScriptFunc", CCScheduler_scheduleScriptFunc, MRB_ARGS_ANY());
}

////////////////////////////////////////////////////////////////
// CCDirector

static mrb_value CCDirector_sharedDirector(mrb_state *mrb, mrb_value self) {

  
  CCDirector* retval = CCDirector::sharedDirector();
  return wrap(mrb, retval, "CCDirector");
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

static mrb_value CCDirector_runWithScene(mrb_state *mrb, mrb_value self) {
  mrb_value* args;
  int arg_count;
  mrb_get_args(mrb, "*", &args, &arg_count);
  CCScene* p0 = static_cast<CCScene*>(DATA_PTR(args[0]));
  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  instance->runWithScene(p0);
  return mrb_nil_value();
}

static mrb_value CCDirector_getScheduler(mrb_state *mrb, mrb_value self) {

  CCDirector* instance = static_cast<CCDirector*>(DATA_PTR(self));
  CCScheduler* retval = instance->getScheduler();
  return wrap(mrb, retval, "CCScheduler");
}

static void installCCDirector(mrb_state *mrb, struct RClass *mod) {
  struct RClass* parent = mrb->object_class;
  struct RClass* tc = mrb_define_class_under(mrb, mod, "CCDirector", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedDirector", CCDirector_sharedDirector, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getVisibleOrigin", CCDirector_getVisibleOrigin, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getVisibleSize", CCDirector_getVisibleSize, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "runWithScene", CCDirector_runWithScene, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "getScheduler", CCDirector_getScheduler, MRB_ARGS_ANY());
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

void installMrubyCocos2d(mrb_state *mrb) {
  struct RClass* mod = mrb_define_module(mrb, "Cocos2d");
  mrb_define_const(mrb, mod, "CCTOUCHBEGAN", mrb_fixnum_value(CCTOUCHBEGAN));
  mrb_define_const(mrb, mod, "CCTOUCHMOVED", mrb_fixnum_value(CCTOUCHMOVED));
  mrb_define_const(mrb, mod, "CCTOUCHENDED", mrb_fixnum_value(CCTOUCHENDED));
  mrb_define_const(mrb, mod, "CCTOUCHCANCELLED", mrb_fixnum_value(CCTOUCHCANCELLED));
  mrb_define_const(mrb, mod, "kCCNodeOnEnter", mrb_fixnum_value(kCCNodeOnEnter));
  mrb_define_const(mrb, mod, "kCCNodeOnExit", mrb_fixnum_value(kCCNodeOnExit));
  mrb_define_const(mrb, mod, "kCCNodeOnEnterTransitionDidFinish", mrb_fixnum_value(kCCNodeOnEnterTransitionDidFinish));
  mrb_define_const(mrb, mod, "kCCNodeOnExitTransitionDidStart", mrb_fixnum_value(kCCNodeOnExitTransitionDidStart));
  mrb_define_const(mrb, mod, "kCCNodeOnCleanup", mrb_fixnum_value(kCCNodeOnCleanup));
  mrb_define_method(mrb, mod, "CCPointMake", CCPointMake__, MRB_ARGS_ANY());
  mrb_define_method(mrb, mod, "CCSizeMake", CCSizeMake__, MRB_ARGS_ANY());
  mrb_define_method(mrb, mod, "CCRectMake", CCRectMake__, MRB_ARGS_ANY());
  installCCPoint(mrb, mod);
  installCCSize(mrb, mod);
  installCCRect(mrb, mod);
  installCCObject(mrb, mod);
  installCCArray(mrb, mod);
  installCCAction(mrb, mod);
  installCCActionInterval(mrb, mod);
  installCCNode(mrb, mod);
  installCCTexture2D(mrb, mod);
  installCCTextureCache(mrb, mod);
  installCCSpriteFrame(mrb, mod);
  installCCAnimation(mrb, mod);
  installCCAnimate(mrb, mod);
  installCCRepeatForever(mrb, mod);
  installCCSprite(mrb, mod);
  installCCLayer(mrb, mod);
  installCCScene(mrb, mod);
  installCCScheduler(mrb, mod);
  installCCDirector(mrb, mod);
}
