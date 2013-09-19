class TestScene
  include Cocos2d

  def initialize
    visibleSize = CCDirector.sharedDirector().getVisibleSize()
    origin = CCDirector.sharedDirector().getVisibleOrigin()

    sceneGame = CCScene.create()
    sceneGame.addChild(createLayerFarm(visibleSize, origin))

    CCDirector.sharedDirector().runWithScene(sceneGame)
  end

  def createLayerFarm(visibleSize, origin)
    @layerFarm = CCLayer.create()

    bg = CCSprite.create("farm.jpg")
    bg.setPosition(origin.x + visibleSize.width / 2 + 80, origin.y + visibleSize.height / 2)
    @layerFarm.addChild(bg)

    # add land sprite
    4.times do |i|
      2.times do |j|
        spriteLand = CCSprite.create("land.png")
        spriteLand.setPosition(200 + j * 180 - i % 2 * 90, 10 + i * 95 / 2)
        @layerFarm.addChild(spriteLand)
      end
    end

    # add crop
    frameCrop = CCSpriteFrame.create("crop.png", CCRectMake(0, 0, 105, 95))
    4.times do |i|
      2.times do |j|
        spriteCrop = CCSprite.createWithSpriteFrame(frameCrop)
        spriteCrop.setPosition(10 + 200 + j * 180 - i % 2 * 90, 30 + 10 + i * 95 / 2)
        @layerFarm.addChild(spriteCrop)
      end
    end

    # add moving dog
    spriteDog = creatDog(visibleSize, origin)
    @layerFarm.addChild(spriteDog)

    # handing touch events
    @touchBeginPoint = nil

    @layerFarm.registerScriptTouchHandler do |eventType, x, y|
      if eventType == CCTOUCHBEGAN
        onTouchBegan(x, y)
      elsif eventType == CCTOUCHMOVED
        onTouchMoved(x, y)
      else  # ENDED or CANCELLED
        onTouchEnded(x, y)
      end
    end
    @layerFarm.setTouchEnabled(true)

    return @layerFarm
  end

  def creatDog(visibleSize, origin)
    frameWidth = 105
    frameHeight = 95

    # create dog animate
    textureDog = CCTextureCache.sharedTextureCache().addImage("dog.png")
    rect = CCRectMake(0, 0, frameWidth, frameHeight)
    frame0 = CCSpriteFrame.createWithTexture(textureDog, rect)
    rect = CCRectMake(frameWidth, 0, frameWidth, frameHeight)
    frame1 = CCSpriteFrame.createWithTexture(textureDog, rect)

    spriteDog = CCSprite.createWithSpriteFrame(frame0)
    @spriteDogIsPaused = false
    spriteDog.setPosition(origin.x, origin.y + visibleSize.height / 4 * 3)

    animFrames = CCArray.create()

    animFrames.addObject(frame0)
    animFrames.addObject(frame1)

    animation = CCAnimation.createWithSpriteFrames(animFrames, 0.5)
    animate = CCAnimate.create(animation)
    spriteDog.runAction(CCRepeatForever.create(animate))

    # moving dog at every frame
    CCDirector.sharedDirector().getScheduler().scheduleScriptFunc(0, false) do
      unless @spriteDogIsPaused
        x = spriteDog.getPositionX()
        if x > origin.x + visibleSize.width
          x = origin.x
        else
          x = x + 1
        end

        spriteDog.setPositionX(x)
      end
    end

    return spriteDog
  end

  def onTouchBegan(x, y)
    puts("onTouchBegan: #{x}, #{y}")
    @touchBeginPoint = {:x => x, :y => y}
    @spriteDogIsPaused = true
    # CCTOUCHBEGAN event must return true
    return true
  end

  def onTouchMoved(x, y)
    puts("onTouchMoved: #{x}, #{y}")
    if @touchBeginPoint
      pos = @layerFarm.getPosition()
      @layerFarm.setPosition(pos.x + x - @touchBeginPoint[:x], pos.y + y - @touchBeginPoint[:y])
      @touchBeginPoint = {:x => x, :y => y}
    end
  end

  def onTouchEnded(x, y)
    puts("onTouchEnded: #{x}, #{y}")
    @touchBeginPoint = nil
    @spriteDogIsPaused = false
  end
end

TestScene.new
