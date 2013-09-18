#include "MrubyCocos2d.h"
#include "cocos2d.h"
#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/compile.h"
#include "mruby/data.h"
#include "mruby/hash.h"
#include "mruby/string.h"
#include "mruby/variable.h"
#include "mrubybind.h"

using namespace cocos2d;

static void ccobject_free(mrb_state *mrb, void *ptr) {
  CCObject* object = static_cast<CCObject*>(ptr);
  object->retain();
}

static void dummy(mrb_state *mrb, void *ptr) {
  //CCDirector* hoge = static_cast<CCDirector*>(ptr);
  //delete hoge;
  
  // The object must be shared object, so we don't have to free it.
}

static struct mrb_data_type ccpoint_type = { "CCPoint", dummy };
static struct mrb_data_type ccsize_type = { "CCSize", dummy };
static struct mrb_data_type ccrect_type = { "CCRect", dummy };
static struct mrb_data_type ccarray_type = { "CCArray", dummy };
static struct mrb_data_type ccspriteframe_type = { "CCSpriteFrame", ccobject_free };
static struct mrb_data_type ccsprite_type = { "CCSprite", ccobject_free };
static struct mrb_data_type cctexture2d_type = { "CCTexture2d", ccobject_free };
static struct mrb_data_type cctexturecache_type = { "CCTextureCache", dummy };
static struct mrb_data_type ccanimation_type = { "CCAnimation", ccobject_free };
static struct mrb_data_type ccanimate_type = { "CCAnimate", ccobject_free };
static struct mrb_data_type ccrepeatforever_type = { "CCRepeatForever", ccobject_free };
static struct mrb_data_type cclayer_type = { "CCLayer", ccobject_free };
static struct mrb_data_type ccscene_type = { "CCScene", ccobject_free };
static struct mrb_data_type ccscheduler_type = { "CCScheduler", dummy };
static struct mrb_data_type ccdirector_type = { "CCDirector", dummy };

static mrb_value getMrubyCocos2dClassValue(mrb_state *mrb, const char* className) {
  mrb_sym sym = mrb_intern_cstr(mrb, "Cocos2d");
  mrb_value mod = mrb_const_get(mrb, mrb_obj_value(mrb->kernel_module), sym);
  mrb_value klass = mrb_iv_get(mrb, mod, mrb_intern_cstr(mrb, className));
  return klass;
}

static struct RClass* getMrubyCocos2dClassPtr(mrb_state *mrb, const char* className) {
  return mrb_class_ptr(getMrubyCocos2dClassValue(mrb, className));
}

int registerProc(mrb_state *mrb, mrb_value proc) {
  mrb_value man = getMrubyCocos2dClassValue(mrb, "HandleManager");
  mrb_value result = mrb_funcall(mrb, man, "register", 1, proc);
  return mrb_fixnum(result);
}

mrb_value getRegisteredProc(mrb_state *mrb, int id) {
  mrb_value man = getMrubyCocos2dClassValue(mrb, "HandleManager");
  mrb_value proc = mrb_funcall(mrb, man, "getProc", 1, mrb_fixnum_value(id));
  return proc;
}

CCArray a;

////////////////////////////////////////////////////////////////
// CCPoint

static mrb_value ccpoint_wrap(mrb_state *mrb, struct RClass *tc, CCPoint* point) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccpoint_type, point));
}

static mrb_value ccpointmake(mrb_state *mrb, mrb_value self) {
  mrb_float x, y;
  mrb_get_args(mrb, "ff", &x, &y);
  
  struct RClass* tc = getMrubyCocos2dClassPtr(mrb, "CCPoint");
  
  CCPoint* pPoint = new CCPoint(x, y);
  return ccpoint_wrap(mrb, tc, pPoint);
}

static mrb_value ccpoint_x(mrb_state *mrb, mrb_value self) {
  CCPoint* point = static_cast<CCPoint*>(DATA_PTR(self));
  return mrb_float_value(mrb, point->x);
}

static mrb_value ccpoint_y(mrb_state *mrb, mrb_value self) {
  CCPoint* point = static_cast<CCPoint*>(DATA_PTR(self));
  return mrb_float_value(mrb, point->x);
}

static void installCCPoint(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCPoint", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "x", ccpoint_x, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "y", ccpoint_x, MRB_ARGS_NONE());
}

////////////////////////////////////////////////////////////////
// CCSize

static mrb_value ccsize_wrap(mrb_state *mrb, struct RClass *tc, CCSize* size) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccsize_type, size));
}

static mrb_value ccsizemake(mrb_state *mrb, mrb_value self) {
  mrb_float w, h;
  mrb_get_args(mrb, "ff", &w, &h);

  struct RClass* tc = getMrubyCocos2dClassPtr(mrb, "CCSize");
  
  CCSize* pSize = new CCSize(w, h);
  return ccsize_wrap(mrb, tc, pSize);
}

static mrb_value ccsize_width(mrb_state *mrb, mrb_value self) {
  CCSize* size = static_cast<CCSize*>(DATA_PTR(self));
  return mrb_float_value(mrb, size->width);
}

static mrb_value ccsize_height(mrb_state *mrb, mrb_value self) {
  CCSize* size = static_cast<CCSize*>(DATA_PTR(self));
  return mrb_float_value(mrb, size->height);
}

static void installCCSize(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCSize", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "width", ccsize_width, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "height", ccsize_height, MRB_ARGS_NONE());
}

////////////////////////////////////////////////////////////////
// CCRect

static mrb_value ccrectmake(mrb_state *mrb, mrb_value self) {
  mrb_float x, y, w, h;
  mrb_get_args(mrb, "ffff", &x, &y, &w, &h);
  
  struct RClass* tc = getMrubyCocos2dClassPtr(mrb, "CCRect");
  
  CCRect* pRect = new CCRect(x, y, w, h);
  struct RData* data = Data_Wrap_Struct(mrb, tc, &ccrect_type, pRect);
  return mrb_obj_value(data);
}

static void installCCRect(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCRect", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCArray

static mrb_value ccarray_wrap(mrb_state *mrb, struct RClass *tc, CCArray* array) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccarray_type, array));
}

static mrb_value ccarray_create(mrb_state *mrb, mrb_value self) {
  struct RClass* tc = getMrubyCocos2dClassPtr(mrb, "CCArray");
  CCArray* array = new CCArray();
  return ccarray_wrap(mrb, tc, array);
}

static mrb_value ccarray_addObject(mrb_state *mrb, mrb_value self) {
  CCArray* array = static_cast<CCArray*>(DATA_PTR(self));
  mrb_value object;
  mrb_get_args(mrb, "o", &object);
  // TODO: Type check.
  CCObject* pObject = static_cast<CCObject*>(DATA_PTR(object));
  array->addObject(pObject);
  return mrb_nil_value();
}

static void installCCArray(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCArray", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccarray_create, MRB_ARGS_ANY());
  mrb_define_method(mrb, tc, "addObject", ccarray_addObject, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCNode

static mrb_value ccnode_addChild(mrb_state *mrb, mrb_value self) {
  CCNode* node = static_cast<CCNode*>(DATA_PTR(self));
  mrb_value object;
  mrb_get_args(mrb, "o", &object);
  //CCNode* child = static_cast<CCNode*>(mrb_get_datatype(mrb, object, &ccnode_type));
  CCNode* child = static_cast<CCNode*>(DATA_PTR(object));
  node->addChild(child);
  return mrb_nil_value();
}

static mrb_value ccnode_setPosition(mrb_state *mrb, mrb_value self) {
  CCNode* node = static_cast<CCNode*>(DATA_PTR(self));
  mrb_float x, y;
  mrb_get_args(mrb, "ff", &x, &y);
  node->setPosition(x, y);
  return mrb_nil_value();
}

static mrb_value ccnode_getPosition(mrb_state *mrb, mrb_value self) {
  CCNode* node = static_cast<CCNode*>(DATA_PTR(self));
  const CCPoint& pos = node->getPosition();
  mrb_value array = mrb_ary_new_capa(mrb, 2);
  mrb_ary_push(mrb, array, mrb_float_value(mrb, pos.x));
  mrb_ary_push(mrb, array, mrb_float_value(mrb, pos.y));
  return array;
}

static mrb_value ccnode_runAction(mrb_state *mrb, mrb_value self) {
  CCNode* node = static_cast<CCNode*>(DATA_PTR(self));
  mrb_value action;
  mrb_get_args(mrb, "o", &action);
  // TODO: Type check.
  CCAction* pAction = static_cast<CCAction*>(DATA_PTR(action));
  node->runAction(pAction);
  return mrb_nil_value();
}

static struct RClass* installCCNode(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCNode", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "addChild", ccnode_addChild, MRB_ARGS_REQ(1));
  //mrb_define_method(mrb, tc, "setPosition", ccnode_setPosition, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, tc, "getPosition", ccnode_getPosition, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "runAction", ccnode_runAction, MRB_ARGS_REQ(1));
  
  mrubybind::MrubyBind b(mrb, mod);
  b.bind_class_method("CCNode", "setPosition", (void (CCNode::*)(float, float))&CCNode::setPosition);
  b.bind_class_method("CCNode", "setPositionX", &CCNode::setPositionX);
  return tc;
}

////////////////////////////////////////////////////////////////
// CCSpriteFrame

static mrb_value ccspriteframe_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccspriteframe_type, NULL));
}

static mrb_value ccspriteframe_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccspriteframe_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccspriteframe_type;
  DATA_PTR(instance) = NULL;
  
  const char* fileName;
  int len;
  mrb_value rect;
  mrb_get_args(mrb, "so", &fileName, &len, &rect);
  CCRect* prect = static_cast<CCRect*>(mrb_data_get_ptr(mrb, rect, &ccrect_type));
  
  CCSpriteFrame* spriteFrame = CCSpriteFrame::create(fileName, *prect);
  DATA_PTR(instance) = spriteFrame;
  return instance;
}

static mrb_value ccspriteframe_createWithTexture(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccspriteframe_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccspriteframe_type;
  DATA_PTR(instance) = NULL;
  
  mrb_value tex2d;
  mrb_value rect;
  mrb_get_args(mrb, "oo", &tex2d, &rect);
  CCTexture2D* ptex2d = static_cast<CCTexture2D*>(mrb_data_get_ptr(mrb, tex2d, &cctexture2d_type));
  CCRect* prect = static_cast<CCRect*>(mrb_data_get_ptr(mrb, rect, &ccrect_type));
  CCSpriteFrame* spriteFrame = CCSpriteFrame::createWithTexture(ptex2d, *prect);
  
  DATA_PTR(instance) = spriteFrame;
  return instance;
}

static void installCCSpriteFrame(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCSpriteFrame", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccspriteframe_create, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, tc, "createWithTexture", ccspriteframe_createWithTexture, MRB_ARGS_REQ(2));
}

////////////////////////////////////////////////////////////////
// CCSprite

static mrb_value ccsprite_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccsprite_type, NULL));
}

static mrb_value ccsprite_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccsprite_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccsprite_type;
  DATA_PTR(instance) = NULL;
  
  CCSprite* sprite = NULL;
  mrb_value fileName;
  mrb_value rect;
  int n = mrb_get_args(mrb, "|oo", &fileName, &rect);
  switch (n) {
    case 0:
      sprite = CCSprite::create();
      break;
    case 1:
      sprite = CCSprite::create(RSTRING_PTR(fileName));
      break;
    case 2:
      CCLOGERROR("Not implemented");
      break;
    default:
      CCLOGERROR("Illegal arg count");
      break;
  }
  
  DATA_PTR(instance) = sprite;
  return instance;
}

static mrb_value ccsprite_createWithSpriteFrame(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccsprite_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccsprite_type;
  DATA_PTR(instance) = NULL;
  
  mrb_value spriteFrame;
  mrb_get_args(mrb, "o", &spriteFrame);
  CCSpriteFrame* pSpriteFrame = static_cast<CCSpriteFrame*>(mrb_data_get_ptr(mrb, spriteFrame, &ccspriteframe_type));
  CCSprite* sprite = CCSprite::createWithSpriteFrame(pSpriteFrame);
  
  DATA_PTR(instance) = sprite;
  return instance;
}

static void installCCSprite(mrb_state *mrb, struct RClass* mod, struct RClass* parent) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCSprite", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccsprite_create, MRB_ARGS_NONE() | MRB_ARGS_OPT(2));
  mrb_define_class_method(mrb, tc, "createWithSpriteFrame", ccsprite_createWithSpriteFrame, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCTexture2D

static mrb_value cctexture2d_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &cctexture2d_type, NULL));
}

static void installCCTexture2D(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCTexture2D", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
}

////////////////////////////////////////////////////////////////
// CCTextureCache

static mrb_value cctexturecache_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &cctexturecache_type, NULL));
}

static mrb_value cctexturecache_sharedTextureCache(mrb_state *mrb, mrb_value self) {
  mrb_value instance = cctexturecache_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &cctexturecache_type;
  DATA_PTR(instance) = NULL;
  
  CCTextureCache* textureCache = CCTextureCache::sharedTextureCache();
  DATA_PTR(instance) = textureCache;
  return instance;
}

static mrb_value cctexturecache_addImage(mrb_state *mrb, mrb_value self) {
  CCTextureCache* textureCache = static_cast<CCTextureCache*>(DATA_PTR(self));
  const char* fileimage;
  int len;
  mrb_get_args(mrb, "s", &fileimage, &len);
  CCTexture2D* texture2d = textureCache->addImage(fileimage);
  mrb_value tex_value = cctexture2d_wrap(mrb, getMrubyCocos2dClassPtr(mrb, "CCTexture2D"));
  DATA_PTR(tex_value) = texture2d;
  return tex_value;
}

static void installCCTextureCache(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCTextureCache", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedTextureCache", cctexturecache_sharedTextureCache, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "addImage", cctexturecache_addImage, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCAnimation

static mrb_value ccanimation_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccanimation_type, NULL));
}

static mrb_value ccanimation_createWithSpriteFrames(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccanimation_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccanimation_type;
  DATA_PTR(instance) = NULL;

  mrb_value array;
  mrb_float delay = 0;
  mrb_get_args(mrb, "o|f", &array, &delay);
  CCArray* pArray = static_cast<CCArray*>(mrb_data_get_ptr(mrb, array, &ccarray_type));
  
  CCAnimation* animation = CCAnimation::createWithSpriteFrames(pArray, delay);
  DATA_PTR(instance) = animation;
  return instance;
}

static void installCCAnimation(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCAnimation", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "createWithSpriteFrames", ccanimation_createWithSpriteFrames, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCAnimate

static mrb_value ccanimate_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccanimate_type, NULL));
}

static mrb_value ccanimate_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccanimate_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccanimate_type;
  DATA_PTR(instance) = NULL;
  
  mrb_value animation;
  mrb_get_args(mrb, "o", &animation);
  CCAnimation* pAnimation = static_cast<CCAnimation*>(mrb_data_get_ptr(mrb, animation, &ccanimation_type));
  
  CCAnimate* animate = CCAnimate::create(pAnimation);
  DATA_PTR(instance) = animate;
  return instance;
}

static void installCCAnimate(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCAnimate", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccanimate_create, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCRepeatForever

static mrb_value ccrepeatforever_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccrepeatforever_type, NULL));
}

static mrb_value ccrepeatforever_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccrepeatforever_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccrepeatforever_type;
  DATA_PTR(instance) = NULL;
  
  mrb_value action;
  mrb_get_args(mrb, "o", &action);
  // TODO: Type check.
  CCActionInterval* pAction = static_cast<CCActionInterval*>(DATA_PTR(action));
  
  CCRepeatForever* repeatforever = CCRepeatForever::create(pAction);
  DATA_PTR(instance) = repeatforever;
  return instance;
}

static void installCCRepeatForever(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCRepeatForever", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccrepeatforever_create, MRB_ARGS_REQ(1));
}

////////////////////////////////////////////////////////////////
// CCLayer

static mrb_value cclayer_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &cclayer_type, NULL));
}

static mrb_value cclayer_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = cclayer_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &cclayer_type;
  DATA_PTR(instance) = NULL;
  
  CCLayer* layer = CCLayer::create();
  DATA_PTR(instance) = layer;
  return instance;
}

static mrb_value cclayer_registerScriptTouchHandler(mrb_state *mrb, mrb_value self) {
  CCLayer* layer = static_cast<CCLayer*>(DATA_PTR(self));
  
  mrb_value block;
  bool bIsMultiTouches = false;
  int nPriority = INT_MIN;
  bool bSwallowsTouches = false;
  
  mrb_get_args(mrb, "|bib&", &bIsMultiTouches, &nPriority, &bSwallowsTouches, &block);
  int blockHandler = registerProc(mrb, block);
  layer->registerScriptTouchHandler(blockHandler, bIsMultiTouches, nPriority, bSwallowsTouches);
  return mrb_nil_value();
}

static mrb_value cclayer_setTouchEnabled(mrb_state *mrb, mrb_value self) {
  CCLayer* layer = static_cast<CCLayer*>(DATA_PTR(self));
  bool value;
  mrb_get_args(mrb, "b", &value);
  layer->setTouchEnabled(value);
  return mrb_nil_value();
}

static void installCCLayer(mrb_state *mrb, struct RClass *mod, struct RClass *parent) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCLayer", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", cclayer_create, ARGS_NONE());
  mrb_define_method(mrb, tc, "registerScriptTouchHandler", cclayer_registerScriptTouchHandler, MRB_ARGS_OPT(3) | MRB_ARGS_BLOCK());
  mrb_define_method(mrb, tc, "setTouchEnabled", cclayer_setTouchEnabled, MRB_ARGS_REQ(1));

  mrubybind::MrubyBind b(mrb, mod);
  b.bind_class_method("CCNode", "setTouchEnabled", &CCLayer::setTouchEnabled);
}

////////////////////////////////////////////////////////////////
// CCScene

static void ccscene_free(mrb_state *mrb, void *ptr) {
  CCScene* scene = static_cast<CCScene*>(ptr);
  scene->retain();
}

static mrb_value ccscene_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccscene_type, NULL));
}

static mrb_value ccscene_create(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccscene_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccscene_type;
  DATA_PTR(instance) = NULL;
  
  CCScene* scene = CCScene::create();
  DATA_PTR(instance) = scene;
  return instance;
}

static void installCCScene(mrb_state *mrb, struct RClass *mod, struct RClass *parent) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCScene", parent);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "create", ccscene_create, MRB_ARGS_NONE());
}

////////////////////////////////////////////////////////////////
// CCScheduler

static mrb_value ccscheduler_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccscheduler_type, NULL));
}

static mrb_value ccscheduler_scheduleScriptFunc(mrb_state *mrb, mrb_value self) {
  CCScheduler* scheduler = static_cast<CCScheduler*>(DATA_PTR(self));
  mrb_float interval = 0;
  mrb_bool paused = false;
  mrb_value block;
  mrb_get_args(mrb, "fb&", &interval, &paused, &block);
  int nHandler = registerProc(mrb, block);
  scheduler->scheduleScriptFunc(nHandler, interval, paused);
  return mrb_nil_value();
}

static void installCCScheduler(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCScheduler", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_method(mrb, tc, "scheduleScriptFunc", ccscheduler_scheduleScriptFunc, MRB_ARGS_NONE());
}

////////////////////////////////////////////////////////////////
// CCDirector

static mrb_value ccdirector_wrap(mrb_state *mrb, struct RClass *tc) {
  return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &ccdirector_type, NULL));
}

static mrb_value ccdirector_sharedDirector(mrb_state *mrb, mrb_value self) {
  mrb_value instance = ccdirector_wrap(mrb, mrb_class_ptr(self));
  DATA_TYPE(instance) = &ccdirector_type;
  DATA_PTR(instance) = NULL;
  
  CCDirector* director = CCDirector::sharedDirector();
  DATA_PTR(instance) = director;
  return instance;
}

static mrb_value ccdirector_getVisibleOrigin(mrb_state *mrb, mrb_value self) {
  CCDirector* director = static_cast<CCDirector*>(DATA_PTR(self));
  const CCPoint& origin = director->getVisibleOrigin();
  // TODO: Confirm memory leak.
  CCPoint* clone = new CCPoint(origin);
  return ccpoint_wrap(mrb, getMrubyCocos2dClassPtr(mrb, "CCPoint"), clone);
}

static mrb_value ccdirector_getVisibleSize(mrb_state *mrb, mrb_value self) {
  CCDirector* director = static_cast<CCDirector*>(DATA_PTR(self));
  const CCSize& size = director->getVisibleSize();
  // TODO: Confirm memory leak.
  CCSize* clone = new CCSize(size);
  return ccsize_wrap(mrb, getMrubyCocos2dClassPtr(mrb, "CCSize"), clone);
}

static mrb_value ccdirector_runWithScene(mrb_state *mrb, mrb_value self) {
  CCDirector* director = static_cast<CCDirector*>(DATA_PTR(self));
  mrb_value sceneObject;
  mrb_get_args(mrb, "o", &sceneObject);
  CCScene* scene = static_cast<CCScene*>(mrb_get_datatype(mrb, sceneObject, &ccscene_type));
  if (scene == NULL)
    return mrb_nil_value();
  director->runWithScene(scene);
  return mrb_nil_value();
}

static mrb_value ccdirector_getScheduler(mrb_state *mrb, mrb_value self) {
  CCDirector* director = static_cast<CCDirector*>(DATA_PTR(self));
  mrb_value scheduler = ccscheduler_wrap(mrb, getMrubyCocos2dClassPtr(mrb, "CCScheduler"));
  DATA_PTR(scheduler) = director->getScheduler();
  return scheduler;
}

static void installCCDirector(mrb_state *mrb, struct RClass *mod) {
  struct RClass *tc = mrb_define_class_under(mrb, mod, "CCDirector", mrb->object_class);
  MRB_SET_INSTANCE_TT(tc, MRB_TT_DATA);
  mrb_define_class_method(mrb, tc, "sharedDirector", ccdirector_sharedDirector, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "getVisibleOrigin", ccdirector_getVisibleOrigin, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "getVisibleSize", ccdirector_getVisibleSize, MRB_ARGS_NONE());
  mrb_define_method(mrb, tc, "runWithScene", ccdirector_runWithScene, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, tc, "getScheduler", ccdirector_getScheduler, MRB_ARGS_NONE());
}

////////////////////////////////////////////////////////////////
void installMrubyCocos2dBindings(mrb_state *mrb) {
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

  mrb_define_method(mrb, mod, "CCPointMake", ccpointmake, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, mod, "CCSizeMake", ccsizemake, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, mod, "CCRectMake", ccrectmake, MRB_ARGS_REQ(4));

  installCCPoint(mrb, mod);
  installCCSize(mrb, mod);
  installCCRect(mrb, mod);
  installCCArray(mrb, mod);
  struct RClass* ccnodeClass = installCCNode(mrb, mod);
  installCCSpriteFrame(mrb, mod);
  installCCSprite(mrb, mod, ccnodeClass);
  installCCTexture2D(mrb, mod);
  installCCTextureCache(mrb, mod);
  installCCAnimation(mrb, mod);
  installCCAnimate(mrb, mod);
  installCCRepeatForever(mrb, mod);
  installCCLayer(mrb, mod, ccnodeClass);
  installCCScene(mrb, mod, ccnodeClass);
  installCCScheduler(mrb, mod);
  installCCDirector(mrb, mod);
}
