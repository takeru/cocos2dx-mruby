//
//  CCMrubyEngine.h
//  CocosMruby
//
//  Created by admin on 13/09/17.
//
//

#ifndef __CC_MRUBY_ENGINE_H__
#define __CC_MRUBY_ENGINE_H__

#include "cocos2d.h"
#include "mruby.h"

NS_CC_BEGIN

const ccScriptType kScriptTypeMruby = (ccScriptType) 314;

class CCMrubyEngine : public CCScriptEngineProtocol
{
public:
  static CCMrubyEngine* defaultEngine(void);
  virtual ~CCMrubyEngine(void);
  
  virtual ccScriptType getScriptType() { return kScriptTypeMruby; };
  
  /** Remove script object. */
  virtual void removeScriptObjectByCCObject(CCObject* pObj);

  /** Execute script code contained in the given string. */
  virtual int executeString(const char* codes);

  /** Execute a script file. */
  virtual int executeScriptFile(const char* filename);

  /** Execute a scripted global function. */
  virtual int executeGlobalFunction(const char* functionName);

  /**
   @brief Execute a node event function
   @param pNode which node produce this event
   @param nAction kCCNodeOnEnter,kCCNodeOnExit,kCCMenuItemActivated,kCCNodeOnEnterTransitionDidFinish,kCCNodeOnExitTransitionDidStart
   @return The integer value returned from the script function.
   */
  virtual int executeNodeEvent(CCNode* pNode, int nAction);
  
  virtual int executeMenuItemEvent(CCMenuItem* pMenuItem);
  /** Execute a notification event function */
  virtual int executeNotificationEvent(CCNotificationCenter* pNotificationCenter, const char* pszName);
  
  /** execute a callfun event */
  virtual int executeCallFuncActionEvent(CCCallFunc* pAction, CCObject* pTarget = NULL);
  /** execute a schedule function */
  virtual int executeSchedule(int nHandler, float dt, CCNode* pNode = NULL);
  
  /** functions for executing touch event */
  virtual int executeLayerTouchesEvent(CCLayer* pLayer, int eventType, CCSet *pTouches);
  virtual int executeLayerTouchEvent(CCLayer* pLayer, int eventType, CCTouch *pTouch);
  
  /** functions for keypad event */
  virtual int executeLayerKeypadEvent(CCLayer* pLayer, int eventType);
  
  /** execute a accelerometer event */
  virtual int executeAccelerometerEvent(CCLayer* pLayer, CCAcceleration* pAccelerationValue);
  
  /** function for common event */
  virtual int executeEvent(int nHandler, const char* pEventName, CCObject* pEventSource = NULL, const char* pEventSourceClassName = NULL);
  
  /** called by CCAssert to allow scripting engine to handle failed assertions
   * @return true if the assert was handled by the script engine, false otherwise.
   */
  virtual bool handleAssert(const char *msg);
  
private:
  CCMrubyEngine(void);
  bool init(void);

  static CCMrubyEngine* m_defaultEngine;

  mrb_state* m_mrb;
};

NS_CC_END

#endif // __CC_MRUBY_ENGINE_H__
