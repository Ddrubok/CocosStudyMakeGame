#include "UI_Buttons.h"

std::vector<std::string> UI_Buttons::GetEnumNames()
{
    std::vector<std::string> EnumStrings(GameObjectss::Count);

    for (int i = 0; i < (int)GameObjectss::Count; i++)
    {
        EnumStrings[i] = EnumToString((GameObjectss)i);
    }
    return EnumStrings;
}
