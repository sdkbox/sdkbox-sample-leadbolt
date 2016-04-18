
#include "HelloWorldScene.h"
#include "PluginLeadBolt/PluginLeadBolt.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    CCLOG("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu()
{
    sdkbox::PluginLeadBolt::setListener(this);

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("cache ad", "sans", 24), [](Ref*){
        CCLOG("cache ad");
        sdkbox::PluginLeadBolt::loadModuleToCache("inapp");
    }));

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("show ad", "sans", 24), [](Ref*){
        CCLOG("show ad");
        if (sdkbox::PluginLeadBolt::isAdReady("inapp")) {
            sdkbox::PluginLeadBolt::loadModule("inapp");
        } else {
            CCLOG("leadbolt ad is not ready");
        }
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}


void HelloWorld::onModuleLoaded(const std::string& placement)
{
    CCLOG("onModuleLoaded: %s", placement.c_str());
}

void HelloWorld::onModuleClosed(const std::string& placement)
{
    CCLOG("onModuleClosed: %s", placement.c_str());
}

void HelloWorld::onModuleClicked(const std::string& placement)
{
    CCLOG("onModuleClicked: %s", placement.c_str());
}

void HelloWorld::onModuleCached(const std::string& placement)
{
    CCLOG("onModuleCached: %s", placement.c_str());
}

void HelloWorld::onModuleFailed(const std::string& placement, const std::string& error, bool iscached)
{
    CCLOG("onModuleFailed: %s, err: %s, iscached: %s", placement.c_str(), error.c_str(), iscached ? "YES" : "NO");
}

void HelloWorld::onMediaFinished(bool viewCompleted)
{
    CCLOG("onMediaFinished: %s", viewCompleted ? "YES" : "NO");
}

