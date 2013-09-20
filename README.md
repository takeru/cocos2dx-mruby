cocos2dx-mruby
==============

mruby binding for Cocos2d-x

Working in progress, very limited classes and methods are implemented.


How to use
----------

* Create cocos2d-x project.
* Put source files under mruby_binding into libs/ directory in the project.
* Add header include paths for
  * mruby_binding/include
* For Xcode, set Target > Build Settings > Search Paths > Always Search User Paths to NO.
* Use CCMrubyEngine and start mruby script using `executeScriptFile()`

```c++
#include "CCMrubyEngine.h"

  CCMrubyEngine* pEngine = CCMrubyEngine::defaultEngine();
  CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
  
  std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("hello.rb");
  pEngine->executeScriptFile(path.c_str());
```


Exampe
------

* Please see [hello.rb](https://github.com/ktaobo/cocos2dx-mruby/blob/master/example/Resources/hello.rb)
* Add Classes/* and Resources/* to the according paths
* Run.
