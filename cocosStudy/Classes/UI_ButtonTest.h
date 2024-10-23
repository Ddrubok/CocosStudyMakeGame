#include "UI_Buttons.h"
#include "ui/CocosGUI.h"
#include "Managers.h"
#include "GameManager.h"


class MenuItemImage;
class UI_ButtonTest : public UI_Buttons {
protected:
    ItemType _itemType; // 아이템 타입

    MenuItemImage* Image;

public:
    virtual bool init() override;

    void HandleOnEquipmentTapChanged(ItemType itemType) {
        if (itemType == _itemType) {
            TapOn();
        }
        else {
            TapOff();
        }
    }

    virtual void TapOn() override {
        TapImageColorChange(cocos2d::Color3B(12, 47, 67)); // #0C2F43
    }

    virtual void TapOff() override {
        TapImageColorChange(cocos2d::Color3B(18, 93, 137)); // #125D89
    }

    virtual void OnPointerDown(cocos2d::Touch* touch, cocos2d::Event* event) override {
        CCLOG("%d 버튼", static_cast<int>(_itemType)); // 아이템 타입을 출력
        Manager::getInstance()->getGameManager()->setEquipmentTap(_itemType);
    }

    void setItemType(ItemType itemType);

    CREATE_FUNC(UI_ButtonTest);
};
