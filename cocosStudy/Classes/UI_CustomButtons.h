#include "cocos2d.h"
#include "ui/CocosGUI.h"

class UI_CustomButtons : public cocos2d::ui::Button {
public:
    // ������: �⺻������ ��ư�� ����
    UI_CustomButtons() {
        // �⺻ ��ư ��Ÿ�� ����
        this->setTitleText("Default Button");
        this->setTitleFontSize(24);
        this->setTitleColor(cocos2d::Color3B::WHITE);
        this->setContentSize(cocos2d::Size(200, 50)); // �⺻ ũ��
        this->setPosition(cocos2d::Vec2(100, 100)); // �⺻ ��ġ
       // this->addClickEventListener(CC_CALLBACK_2(UI_CustomButtons::onButtonClicked));
    }

    // ������ ���� ��ư�� �����ϴ� �޼���
    void configureButton(const std::string& title, const cocos2d::Color3B& titleColor,
        const cocos2d::Color3B& backgroundColor, const cocos2d::Size& size,
        const std::function<void(cocos2d::Ref*)>& callback) {
        this->setTitleText(title);
        this->setTitleColor(titleColor);
        this->setContentSize(size);
        this->addClickEventListener(callback);
    }

private:
    // ��ư Ŭ�� �̺�Ʈ �ڵ鷯
    void onButtonClicked(cocos2d::Ref* sender) {
        CCLOG("Button clicked: %s", this->getTitleText().c_str());
        // �⺻ Ŭ�� �̺�Ʈ ó��
    }
};