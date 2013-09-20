class PhysicsSprite < Cocos2d::CCSprite
  def initialize
    super
    @pBody = nil
  end
  
  def setPhysicsBody(body)
    @pBody = body;
  end
  
  def isDirty
    true
  end

  def nodeToParentTransform
    pos  = @pBody.GetPosition
    
    x = pos.x * PTM_RATIO
    y = pos.y * PTM_RATIO
    
    if isIgnoreAnchorPointForPosition
      x += obAnchorPointInPoints.x
      y += obAnchorPointInPoints.y
    end
      
    # Make matrix
    radians = @pBody.GetAngle
    c = cosf(radians);
    s = sinf(radians);
      
    if !obAnchorPointInPoints.equals(CCPointZero)
      x += c*-obAnchorPointInPoints.x + -s*-obAnchorPointInPoints.y
      y += s*-obAnchorPointInPoints.x + c*-obAnchorPointInPoints.y
    end
        
    # Rot, Translate Matrix
    sTransform = CCAffineTransformMake( c,  s,
                                       -s,  c,
                                        x,  y)
        
    return sTransform;
  end
end

class HelloWorld < Cocos2d::CCLayer
  include Cocos2d
  include Box2D

  PTM_RATIO = 32
  KTagParentNode = 1

  def initialize
    super
    setTouchEnabled(true)
    registerScriptTouchHandler do |eventType, x, y|
      if eventType == CCTOUCHENDED
        addNewSpriteAtPosition(x, y)
      end
    end
    setAccelerometerEnabled(true)

    s = CCDirector.sharedDirector.getWinSize
    initPhysics

    parent = CCSpriteBatchNode.create("blocks.png", 100)
    @pSpriteTexture = parent.getTexture
    
    addChild(parent, 0, KTagParentNode)

    label = CCLabelTTF.create("Tap screen", "Marker Felt", 32)
    addChild(label, 0)
    label.setColor(ccc3(0,0,255))
    label.setPosition(ccp(s.width/2, s.height-50))

    scheduleUpdateWithPriorityLua(0) do |dt|
      update(dt)
    end
  end

  def initPhysics
    s = CCDirector.sharedDirector.getWinSize

    gravity = B2Vec2.new
    gravity.Set(0.0, -10.0)
    @world = B2World.new(gravity)
    
    # Do we want to let bodies sleep?
    @world.SetAllowSleeping(true)
    
    @world.SetContinuousPhysics(true)
    
    #     m_debugDraw = new GLESDebugDraw( PTM_RATIO );
    #     @world.SetDebugDraw(m_debugDraw);
    
    #flags = 0
    #flags += B2Draw.e_shapeBit
    #        flags += b2Draw::e_jointBit;
    #        flags += b2Draw::e_aabbBit;
    #        flags += b2Draw::e_pairBit;
    #        flags += b2Draw::e_centerOfMassBit;
    #m_debugDraw->SetFlags(flags);
    
    
    # Define the ground body.
    groundBodyDef = B2BodyDef.new
    groundBodyDef.position.Set(0, 0)  # bottom-left corner
    
    # Call the body factory which allocates memory for the ground body
    # from a pool and creates the ground box shape (also from a pool).
    # The body is also added to the world.
    groundBody = @world.CreateBody(groundBodyDef)
    
    # Define the ground box shape.
    groundBox = B2EdgeShape.new
    
    # bottom
    
    groundBox.Set(b2Vec2(0,0), b2Vec2(s.width/PTM_RATIO,0))
    groundBody.CreateFixture(groundBox, 0)
    
    # top
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO))
    groundBody.CreateFixture(groundBox, 0)
    
    # left
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody.CreateFixture(groundBox,0);
    
    # right
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody.CreateFixture(groundBox,0);
  end
  
  def addNewSpriteAtPosition(x, y)
    puts("Add sprite #{x},#{y}")
    parent = getChildByTag(KTagParentNode)
    
    # We have a 64x64 sprite sheet with 4 different 32x32 images.  The following code is
    # just randomly picking one of the images
    idx = (CCRANDOM_0_1() > 0.5 ? 0 : 1)
    idy = (CCRANDOM_0_1() > 0.5 ? 0 : 1)
    sprite = PhysicsSprite.new
    sprite.initWithTexture(@pSpriteTexture, CCRectMake(32 * idx, 32 * idy, 32, 32))
    sprite.autorelease
    
    parent.addChild(sprite)
    
    sprite.setPosition(CCPointMake(x, y))
    
    # Define the dynamic body.
    # Set up a 1m squared box in the physics world
    bodyDef = B2BodyDef.new
    bodyDef.type = B2_dynamicBody
    bodyDef.position.Set(x / PTM_RATIO, y / PTM_RATIO)
    
    body = @world.CreateBody(bodyDef)
    
    # Define another box shape for our dynamic body.
    dynamicBox = B2PolygonShape.new
    dynamicBox.SetAsBox(0.5, 0.5)  #These are mid points for our 1m box
    
    # Define the dynamic body fixture.
    fixtureDef = B2FixtureDef.new
    fixtureDef.shape = dynamicBox
    fixtureDef.density = 1.0
    fixtureDef.friction = 0.3
    body.CreateFixture(fixtureDef)
    
    #sprite.setPhysicsBody(body)
  end
  
  def update(dt)
    #It is recommended that a fixed time step is used with Box2D for stability
    #of the simulation, however, we are using a variable time step here.
    #You need to make an informed choice, the following URL is useful
    #http://gafferongames.com/game-physics/fix-your-timestep/
    
    velocityIterations = 8
    positionIterations = 1
    
    # Instruct the world to perform a single step of simulation. It is
    # generally best to keep the time step and iterations fixed.
    @world.Step(dt, velocityIterations, positionIterations)
    
    #Iterate over the bodies in the physics world
    b = @world.GetBodyList
    while b
      ud = b.GetUserData
      if ud
        #Synchronize the AtlasSprites position and rotation with the corresponding body
        myActor = ud  # CCSprite(ud)
        myActor.setPosition(CCPointMake(b.GetPosition.x * PTM_RATIO, b.GetPosition.y * PTM_RATIO))
        myActor.setRotation(-1 * CC_RADIANS_TO_DEGREES(b.GetAngle))
      end
      b = b.GetNext()
    end
  end

  def self.scene
    scene = CCScene.create
    layer = HelloWorld.new
    scene.addChild(layer)
    layer.release
    return scene
  end
end

Cocos2d::CCDirector.sharedDirector.runWithScene(HelloWorld.scene)
