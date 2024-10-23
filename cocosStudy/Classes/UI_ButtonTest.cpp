#include "UI_ButtonTest.h"
#include "cocos2d.h"
#include "Managers.h"
#include "GameManager.h"

bool UI_ButtonTest::init()
{
    if (_init) {
        return false;
    }
    // 이벤트 핸들러 등록
   /* Manager::getInstance()->getGameManager()->removeOnEquipmentTapChanged(this);
    Manager::getInstance()->getGameManager()->addEquipmentTapChangedListener()*/
    return true;
    
}

void UI_ButtonTest::setItemType(ItemType itemType)
{
    _itemType = itemType;
}


