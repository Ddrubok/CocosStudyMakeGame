#include "UI_ButtonTest.h"
#include "cocos2d.h"
#include "Managers.h"
#include "GameManager.h"

bool UI_ButtonTest::init()
{
    if (_init) {
        return false;
    }
    // �̺�Ʈ �ڵ鷯 ���
   /* Manager::getInstance()->getGameManager()->removeOnEquipmentTapChanged(this);
    Manager::getInstance()->getGameManager()->addEquipmentTapChangedListener()*/
    return true;
    
}

void UI_ButtonTest::setItemType(ItemType itemType)
{
    _itemType = itemType;
}


