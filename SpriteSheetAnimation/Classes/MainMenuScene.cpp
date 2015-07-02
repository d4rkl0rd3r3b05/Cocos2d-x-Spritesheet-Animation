#include "MainMenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleRect = Director::getInstance()->getVisibleSize();
    auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundSprite = Sprite::create("main_bg.png");
    backgroundSprite->setPosition(visibleOrigin.x+(visibleRect.width/2),visibleOrigin.y+(visibleRect.height/2));
    
    backgroundSprite->setScaleX(Director::getInstance()->getWinSize().width/backgroundSprite->getContentSize().width);
    backgroundSprite->setScaleY(Director::getInstance()->getWinSize().height/backgroundSprite->getContentSize().height);
    this->addChild(backgroundSprite, -1);
    
    auto playMenuItem = MenuItemImage::create("main_button_play_a.png", "main_button_play_a.png", CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    
    auto mainMenu = Menu::create(playMenuItem, NULL);
    mainMenu->alignItemsVerticallyWithPadding(Director::getInstance()->getVisibleSize().height/4);
    
    this->addChild(mainMenu);

    return true;
}

void MainMenu::GoToGameScene(Ref *pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
}
