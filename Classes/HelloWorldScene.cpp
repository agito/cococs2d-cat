#include "HelloWorldScene.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
		
	
	auto itemAddButton = MenuItemImage::create(
											   "twitter.png",
											   "twitter.png",
											   CC_CALLBACK_0(HelloWorld::addCat, this));
	
	itemAddButton->setPosition(Point(100,200));
	auto itemAddButtonMenu = Menu::create(itemAddButton, NULL);
	itemAddButtonMenu->setPosition(Point::ZERO);
	this->addChild(itemAddButtonMenu, 2);
	
	
	
	Sprite *enemy = Sprite::create("dribbble.png");
	enemy->setPosition(Point(800, 300 ));
	
	this->addChild(enemy);
	
	
	
	this->scheduleUpdate();
    
    return true;
}


void HelloWorld::addCat()
{
	log("HelloWorld::addCat()");
	
	
	Sprite *cat = Sprite::create( "dropbox.png" );
	cat->setPosition(Point(200, 400) );
	this->addChild(cat);
	
	MoveTo *action = MoveTo::create(3, Point(900,rand() % 800 + 100 ) );
	CallFuncN *acitionDone = CallFuncN::create(this, callfuncN_selector(HelloWorld::actionDone));
	Sequence *sequence = Sequence::create(action, acitionDone, NULL);
	
	cat->runAction(sequence);
	cats.pushBack(cat);

}



void HelloWorld::update(float dt)
{
//	log("1");
}


void HelloWorld::actionDone(Node *sender)
{
	Sprite *sprite = (Sprite *)sender;
	this->removeChild(sprite, true);
	cats.erase(cats.find(sprite));
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
