#include "UIHelper.h"

USING_NS_CC;

MenuItemFont* UIHelper::createButton(const std::string& title, const ccMenuCallback& callback, const Vec2& position) {
    auto button = MenuItemFont::create(title, callback);
    button->setPosition(position);
    return button;
}

Label* UIHelper::createLabel(const std::string& text, const std::string& fontName, float fontSize, const Vec2& position) {
    auto label = Label::createWithSystemFont(text, fontName, fontSize);
    label->setPosition(position);
    return label;
}

Sprite* UIHelper::createSprite(const std::string& filename, const Vec2& position) {
    auto sprite = Sprite::create(filename);
    sprite->setPosition(position);
    return sprite;
}

cocos2d::ui::EditBox* UIHelper::createTextField(const std::string& placeholder, const cocos2d::Size& size,
    const std::string& backgroundImage,
    const cocos2d::Vec2& position) {
    auto background = cocos2d::ui::Scale9Sprite::create(backgroundImage);

    auto editBox = cocos2d::ui::EditBox::create(size, background);

    editBox->setPlaceHolder(placeholder.c_str());
    editBox->setFontColor(cocos2d::Color3B::BLACK);
    editBox->setMaxLength(20);
    editBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);

    editBox->setPosition(position);

    return editBox;
}
