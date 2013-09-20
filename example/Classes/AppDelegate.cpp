//
//  CocosMrubyAppDelegate.cpp
//  CocosMruby
//
//  Created by ktaobo on 13/09/17.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CCMrubyEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
  // initialize director
  CCDirector *pDirector = CCDirector::sharedDirector();
  pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
  
  // turn on display FPS
  pDirector->setDisplayStats(true);
  
  // set FPS. the default value is 1.0/60 if you don't call this
  pDirector->setAnimationInterval(1.0 / 60);
  
  // register mruby engine
  CCMrubyEngine* pEngine = CCMrubyEngine::defaultEngine();
  CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
  
  const char* scriptFileName = "hello.rb";
  //const char* scriptFileName = "box2dsample.rb";
  std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(scriptFileName);
  pEngine->executeScriptFile(path.c_str());
  
  return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
