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
#include "Managers.h"
#include "GameManager.h"

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

uint64_t gold = 1000;


bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
        return false;

    


    auto label = cocos2d::Label::createWithTTF("Gold: 0", "fonts/Marker Felt.ttf", 24);
    label->setPosition(cocos2d::Vec2(640, 600)); // 적절한 위치 설정
    this->addChild(label);

    Manager::getInstance()->getGameManager()->addGoldChangedListener([label](uint64_t gold) {
        // Gold가 변경될 때 라벨 업데이트
        label->setString(cocos2d::StringUtils::format("Gold: %llu", gold));
        CCLOG("Gold changed: %llu", gold);
        });

    Manager::getInstance()->getGameManager()->setGold(gold);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem2 = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem2 == nullptr ||
        closeItem2->getContentSize().width <= 0 ||
        closeItem2->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem2->getContentSize().width / 2;
        float y = origin.y + closeItem2->getContentSize().height / 2;
        closeItem2->setPosition(Vec2(640, 360));
        closeItem2->setScale(2.0f);
    }

    // create menu, it's an autorelease object
    auto menu2 = Menu::create(closeItem2, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    gold -= 10;
    Manager::getInstance()->getGameManager()->setGold(gold);
}
