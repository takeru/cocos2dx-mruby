cocos2dx-mruby
==============

mruby binding for Cocos2d-x(2.2.2)

Working in progress, very limited classes and methods are implemented.

How to use
----------
* ./create_project.py -project HelloRuby -package com.example.helloruby -language cpp
* Install MRuby.framework. https://github.com/carsonmcdonald/ios-ruby-embedded
* (Run rake to re-generate stab files.)
* Add *.cpp,h files to your project.
 * mruby_binding/cocos2dx_support/*.cpp,h
 * generated/*.cpp,h
* Put .rb script file into Resources.
* Use CCMrubyEngine and start mruby script using `executeScriptFile()`

```c++
#include "CCMrubyEngine.h"

  CCMrubyEngine* pEngine = CCMrubyEngine::defaultEngine();
  CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

  std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("hello.rb");
  pEngine->executeScriptFile(path.c_str());
```

Example
-------

https://github.com/takeru/NyanGameRuby
