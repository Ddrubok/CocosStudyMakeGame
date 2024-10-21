#ifndef __INPUT_HELPER_H__
#define __INPUT_HELPER_H__

#include "cocos2d.h"

class InputHelper {
public:
    static InputHelper* getInstance();

    void init(cocos2d::Node* targetNode);

    // 터치 관련 콜백
    void setTouchBeganCallback(const std::function<bool(cocos2d::Touch*, cocos2d::Event*)>& callback);
    void setTouchMovedCallback(const std::function<void(cocos2d::Touch*, cocos2d::Event*)>& callback);
    void setTouchEndedCallback(const std::function<void(cocos2d::Touch*, cocos2d::Event*)>& callback);

    // 마우스 관련 콜백
    void setMouseDownCallback(const std::function<void(cocos2d::EventMouse*)>& callback);
    void setMouseMoveCallback(const std::function<void(cocos2d::EventMouse*)>& callback);
    void setMouseUpCallback(const std::function<void(cocos2d::EventMouse*)>& callback);

    // 키보드 관련 콜백
    void setKeyPressedCallback(const std::function<void(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*)>& callback);
    void setKeyReleasedCallback(const std::function<void(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*)>& callback);

private:
    InputHelper() = default;
    ~InputHelper() = default;

    cocos2d::EventListenerTouchOneByOne* touchListener;
    cocos2d::EventListenerMouse* mouseListener;
    cocos2d::EventListenerKeyboard* keyboardListener;
};

#endif // __INPUT_HELPER_H__
