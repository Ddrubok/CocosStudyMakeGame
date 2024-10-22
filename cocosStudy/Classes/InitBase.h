#include "cocos2d.h"

class InitBase : public cocos2d::Node {
protected:
    bool _init = false;
    bool _start = false;

public:
    virtual bool Init() {
        if (_init)
            return false;

        _init = true;
        return true;
    }
    virtual bool onInit() {
        return Init();
    }

    virtual bool init() override {
        if (!Node::init()) {
            return false;
        }
        onInit();

        return true;
    }

    void update(float delta) {
    }

    // CREAT_FUNC 매크로를 사용하여 객체 생성
    CREATE_FUNC(InitBase);
};
