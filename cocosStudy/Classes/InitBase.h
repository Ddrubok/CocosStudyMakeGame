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

    // CREAT_FUNC ��ũ�θ� ����Ͽ� ��ü ����
    CREATE_FUNC(InitBase);
};
