#include "UI_Base.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class UI_Buttons : public UI_Base {
public:
    enum GameObjectss {
        ButtonImage,
        Count
    };

private:
    cocos2d::Node* _resources;
    cocos2d::ui::Button* _tapButton;
    cocos2d::Label* _textLabel;

public:
    virtual bool init() override {
        if (_init) {
            return false;
        }

        // UI ��� ���ε�
        BindObjects("GameObjectss"); // Enum �̸��� ���ڿ��� ����

        _resources = GetObject((int)GameObjectss::ButtonImage);
        _tapButton = dynamic_cast<cocos2d::ui::Button*>(_resources);
        _textLabel = dynamic_cast<cocos2d::Label*>(_resources->getChildByName("Text")); // �ؽ�Ʈ ����� �̸��� ���

        // �̺�Ʈ ���ε�
        BindEvent(_tapButton, CC_CALLBACK_2(UI_Buttons::OnPointerDown, this), 0); // 0�� Click �̺�Ʈ ����

        return true;
    }

    void TextColorChange(const cocos2d::Color4B& color) {
        _textLabel->setTextColor(color);
    }

    void TapImageColorChange(const cocos2d::Color3B& color) {
        _tapButton->setColor(color);
    }

    virtual void TapOn() {
        TextColorChange(cocos2d::Color4B::WHITE);
        TapImageColorChange(cocos2d::Color3B(22, 96, 131)); // #166083�� RGB ��
    }

    virtual void TapOff() {
        TextColorChange(cocos2d::Color4B::BLACK);
        TapImageColorChange(cocos2d::Color3B::WHITE);
    }

    virtual void OnPointerDown(cocos2d::Touch* touch, cocos2d::Event* event) {
        // ��ư Ŭ�� �� ������ ���⿡ ����
        CCLOG("Button Tapped!");
    }

    CREATE_FUNC(UI_Buttons);

    // UI_Base��(��) ���� ��ӵ�
    std::vector<std::string> GetEnumNames() override;

    std::string EnumToString(GameObjectss obj) {
        switch (obj) {
        case GameObjectss::ButtonImage: return "ButtonImage";
        default: return "Unknown";
        }
    }
};
