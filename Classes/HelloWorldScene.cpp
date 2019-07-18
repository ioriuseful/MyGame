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
#include "AudioEngine.h"

USING_NS_CC;
//using namespace experimental;

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
	if (!Scene::init())
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
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	//if (label == nullptr)
	//{
	//    problemLoading("'fonts/Marker Felt.ttf'");
	//}
	//else
	//{
	//    // position the label on the center of the screen
	//    label->setPosition(Vec2(origin.x + visibleSize.width/2,
	//                            origin.y + visibleSize.height - label->getContentSize().height));

	//    // add the label as a child to this layer
	//    this->addChild(label, 1);
	//}



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


	//	//テクスチャファイル名を指定して、スプライトを作成

	sprite = Sprite::create("20592.png");
	mario = 0;

	Sprite*spr = Sprite::create("1.png");


	// 対象の画像の読み取り(読み捨て用)

	spr->setTextureRect(Rect(0, 0, 16, 20));

	spr->setPosition(Vec2(570.0f, 130.0f));
	spr->setScale(2.0f, 2.0f);
	this->addChild(spr);


	//sceneグラフにつなぐ
	this->addChild(sprite);
	sprite->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0));
	sprite->setScale(2.2f, 2.2f);
	this->addChild(spr);
	CallFunc* callFunc = CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction2, this, "1.png"));


	//指定時間待つ
	DelayTime*delay = DelayTime::create(3.0f);
	//連続アクション
	//Sequence*seq = Sequence::create(delay, callFunc, nullptr);

	
	experimental::AudioEngine::play2d("11.mp3", true);
	experimental::AudioEngine::play2d("Coin.mp3", true);
	//this->runAction(seq);

	audioID = experimental::AudioEngine::play2d("Coin.mp3", true);

	MoveTo*action1 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));
	//spr->runAction(action1);
	JumpTo*action2 = JumpTo::create(1.0f, Vec2(570.0f, 130.0f), 100.0f, 1);
	spr->runAction(action2);
	spr->setTextureRect(Rect(62, 0, 16, 20));

	JumpTo*action3 = JumpTo::create(1.0f, Vec2(570.0f, 130.0f), 100.0f, 30);


	spr->runAction(action3);
	//RepeatForever*action3 = RepeatForever::create(action1);
	////TintTo*action3 = TintTo::create(2.0f, Color3B(255, 255, 0));
	////Spawn*action4 = Spawn::create(action2, action3, nullptr);
	//Sequence*action4 = Sequence::create(action1, action3, nullptr);
	//DelayTime*action6 = DelayTime::create(3);
	//ToggleVisibility*action7 = ToggleVisibility::create();
	////Repeat*action2 = Repeat::create(action1, 8);
	//sprite->runAction(action4);


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
	this->scheduleUpdate();



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
	Sprite*spr = Sprite::create("1.png");
	timer = 0;
	timer++;
	if (timer < 10) {
		spr->setTextureRect(Rect(0, 0, 16, 20));
	}
	else if (timer < 20) {
		spr->setTextureRect(Rect(22, 0, 16, 20));
	}
	else if (timer < 30) {
		spr->setTextureRect(Rect(40, 0, 16, 20));
	}
	if (timer > 30)
	{
		timer = 0;
	}
	counters--;
	if (counters <= 0)
	{
		// 割り振られたオーディオIDを指定して止める
		//experimental::AudioEngine::pause(audioID);
		//experimental::AudioEngine::stopAll();
		//experimental::AudioEngine::play2d("Hollow Crown.mp3", true);
		//counters = 100000000;
	}

}

// 任意の自作メンバ関数
void HelloWorld::myFunction()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Sprite*spr = Sprite::create("1.png");
	spr->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0));
	spr->setScale(2.0f, 2.0f);
	this->addChild(spr);
	experimental::AudioEngine::play2d("Coin.wav", true);
}

// 任意の自作メンバ関数
void HelloWorld::myFunction2(std::string filename)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Sprite*spr = Sprite::create(filename);
	spr->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0));
	spr->setScale(2.0f, 2.0f);
	this->addChild(spr);

	experimental::AudioEngine::stopAll();
	experimental::AudioEngine::play2d("8bit08.mp3", true);
}

// 任意の自作メンバ関数
void HelloWorld::myFunction3()
{
	experimental::AudioEngine::stopAll();
	experimental::AudioEngine::play2d("Coin.mp3", true);
	experimental::AudioEngine::play2d("8bit08.mp3", true);
}
