/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }


	
    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}

	//{//乱数の初期化
	     //rand(time(nullptr));

		//for (int i = 0; i < 5; i++)
		//{
		//	sprite[i] = Sprite::create("ebi.png");
		//	this->addChild(sprite[i]);
		//	//テクスチャファイル名を指定して、スプライトを作成
		//	
		//}
	    sprite = Sprite::create("ebi.png");
	//	//sprite = Sprite::create("sample01.png");
		//sceneグラフにつなぐ
		this->addChild(sprite);
		sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0));
		sprite->setScale(0.2f, 0.2f);

		MoveTo*action1 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));
		JumpTo*action2 = JumpTo::create(0.5f, Vec2(100.0f, 100.0f), 100.0f, 1);
		RepeatForever*action3 = RepeatForever::create(action1);
		//TintTo*action3 = TintTo::create(2.0f, Color3B(255, 255, 0));
		//Spawn*action4 = Spawn::create(action2, action3, nullptr);
		Sequence*action4 = Sequence::create(action1, action3, nullptr);
		DelayTime*action6 = DelayTime::create(3);
		ToggleVisibility*action7 = ToggleVisibility::create();
		//Repeat*action2 = Repeat::create(action1, 8);
		sprite->runAction(action4);


	//	MoveBy*action1 = MoveBy::create(1.0f, Vec2(300, 300));
	//	EaseBackInOut* action2 = EaseBackInOut::create(action1);
	//	sprite->runAction(action2);
	//}

	//{
	//	sprite2 = Sprite::create("snake.png");
	//	//sprite = Sprite::create("sample01.png");
	//	//sceneグラフにつなぐ
	//	this->addChild(sprite2);
	//	sprite2->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0));
	//	sprite2->setScale(0.2f, 0.2f);

	//	MoveBy*action1 = MoveBy::create(1.0f, Vec2(-300, -300));
	//	EaseBackInOut* action2 = EaseBackInOut::create(action1);
	//	sprite2->runAction(action2);
	//}

	//ScaleTo* action1 = ScaleTo::create(3.0f, 5.0f);
	//JumpTo* action1 = JumpTo::create(1.5f, Vec2(200, 100), 500.0f, 3);
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(500, 500);
	conf.controlPoint_2 = Vec2(500, 100);
	conf.endPosition = Vec2(200, 100);
	BezierTo* action1 = BezierTo::create(3.0f, conf);*/
	//Blink* action1 = Blink::create(2.0, 4);
	//SkewTo* action1 = SkewTo::create(3.0f, 3.0f, 3.0f);


	//sprite->setScale(3.0f, 3.0f);
	//sprite->setPosition(Vec2(1130, 620));
	//f,
	//sprite->setColor(Color3B(255, 255, 255));
	//sprite->setOpacity(255);

	//画像の左下が(0,0)
	//画像の右上が(1,0)
	//基準点を指定する
	//sprite->setAnchorPoint(Vec2(1.0f, 0.0f));

	//sprite->setRotation(45.0f);

	//sprite->setFlippedX(true);
	//sprite->setTextureRect(Rect(302, 53, 460, 600));

	//sprite->setTextureRect(Rect(0, 0, 32, 40));

	//Updateを有効にする
	//this->scheduleUpdate();

	//counter = 0;

	//どちらに移動中か0←123
	//state = 0;


    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

void HelloWorld::update(float delta)
{

}
