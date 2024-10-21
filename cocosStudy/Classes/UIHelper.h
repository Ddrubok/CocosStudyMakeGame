#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h" // ui 네임스페이스 포함

class EditBox;
class UIHelper {
public:
    // 버튼 생성
    static cocos2d::MenuItemFont* createButton(const std::string& title, const cocos2d::ccMenuCallback& callback, const cocos2d::Vec2& position);

    // 레이블 생성
    static cocos2d::Label* createLabel(const std::string& text, const std::string& fontName, float fontSize, const cocos2d::Vec2& position);

    // 스프라이트 생성
    static cocos2d::Sprite* createSprite(const std::string& filename, const cocos2d::Vec2& position);

    // 입력 필드 생성
    static cocos2d::ui::EditBox* createTextField(const std::string& placeholder, const cocos2d::Size& size,
        const std::string& backgroundImage,
        const cocos2d::Vec2& position);
};