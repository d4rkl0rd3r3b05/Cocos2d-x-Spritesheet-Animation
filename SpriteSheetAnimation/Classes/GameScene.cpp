#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScreen::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScreen::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    glClearColor(1.0,1.0,1.0,1.0);
    
    auto visibleRect = Director::getInstance()->getVisibleSize();
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("pigleBoy.plist", "pigleBoy.png");
    
    auto pigleBoySprite = Sprite::create();
    pigleBoySprite->setPosition(visibleOrigin.x, visibleOrigin.y+visibleRect.height/2);
    pigleBoySprite->runAction(moving());
    this->addChild(pigleBoySprite);
    
    auto moveAnimation = MoveTo::create(15*0.3, Point(visibleOrigin.x+visibleRect.width - 60,visibleOrigin.y+visibleRect.height/2));
    auto repositionAnimation = Place::create(Point(visibleOrigin.x, visibleOrigin.y+visibleRect.height/2));
    pigleBoySprite->runAction(RepeatForever::create(Sequence::create(moveAnimation,repositionAnimation, NULL)));
     
    
    
    return true;
}

RepeatForever* GameScreen::moving()
{
    int numFrame = 19;
    
    cocos2d::Vector<cocos2d::SpriteFrame *> frames;
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    
    for (int i = 2; i < numFrame; i++) {
        if (i==11 || i==13) {
            continue;
        }
        __String *spriteFrameName = __String::createWithFormat("images/pigle_boy_%02d.png",i);
        SpriteFrame *frame = frameCache->getSpriteFrameByName(spriteFrameName->getCString());
        frames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames, 0.3);
    Animate *animate = Animate::create(animation);
    
    
    RepeatForever *repeat = RepeatForever::create(animate);
    return repeat;
}