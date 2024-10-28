#include "cocos2d.h"
#include "ui/CocosGUI.h"

class UI_CustomButtons : public cocos2d::ui::Button {
public:
    // 생성자: 기본값으로 버튼을 설정
    UI_CustomButtons() {
        // 기본 버튼 스타일 설정
        this->setTitleText("Default Button");
        this->setTitleFontSize(24);
        this->setTitleColor(cocos2d::Color3B::WHITE);
        this->setContentSize(cocos2d::Size(200, 50)); // 기본 크기
        this->setPosition(cocos2d::Vec2(100, 100)); // 기본 위치
       // this->addClickEventListener(CC_CALLBACK_2(UI_CustomButtons::onButtonClicked));
    }

    // 설정을 통해 버튼을 구성하는 메서드
    void configureButton(const std::string& title, const cocos2d::Color3B& titleColor,
        const cocos2d::Color3B& backgroundColor, const cocos2d::Size& size,
        const std::function<void(cocos2d::Ref*)>& callback) {
        this->setTitleText(title);
        this->setTitleColor(titleColor);
        this->setContentSize(size);
        this->addClickEventListener(callback);
    }

private:
    // 버튼 클릭 이벤트 핸들러
    void onButtonClicked(cocos2d::Ref* sender) {
        CCLOG("Button clicked: %s", this->getTitleText().c_str());
        // 기본 클릭 이벤트 처리
    }
};