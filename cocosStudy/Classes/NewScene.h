#pragma once
#include "cocos2d.h"

class NewScene : public cocos2d::Scene
{
   
    virtual bool init();
    CREATE_FUNC(NewScene);
public:
    static cocos2d::Scene* createScene();
};

