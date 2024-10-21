#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"
#include <functional>
#include <array>

enum class ItemType {
    Weapon,
    Armor,
    Shield,
    None,
};

enum class GameTap {
    Resources,
    Battle,
    Equipment,
};

class GameManager {
public:
    using GoldChangedCallback = std::function<void(uint64_t)>;
    using SaveGoldChangedCallback = std::function<void(double)>;
    using CharacterAttackChangedCallback = std::function<void(uint64_t)>;
    using CharacterHPChangedCallback = std::function<void(uint64_t)>;
    using CharacterShieldChangedCallback = std::function<void(uint64_t)>;
    using CharacterBattlePowerChangedCallback = std::function<void(uint64_t)>;
    using GameTapChangedCallback = std::function<void(GameTap)>;
    using EquipmentTapChangedCallback = std::function<void(ItemType)>;

    GameManager();
    ~GameManager();

    // Gold
    void setGold(uint64_t amount);
    uint64_t getGold() const;
    bool canBuy(uint64_t amount);
    void addGoldChangedListener(GoldChangedCallback callback);

    // Save Gold
    void setSaveGold(double amount);
    double getSaveGold() const;
    void addSaveGoldChangedListener(SaveGoldChangedCallback callback);

    // Character Attack
    void setCharacterAttack(uint64_t amount);
    uint64_t getCharacterAttack() const;
    void addCharacterAttackChangedListener(CharacterAttackChangedCallback callback);

    // Character HP
    void setCharacterHP(uint64_t amount);
    uint64_t getCharacterHP() const;
    void addCharacterHPChangedListener(CharacterHPChangedCallback callback);

    // Character Shield
    void setCharacterShield(uint64_t amount);
    uint64_t getCharacterShield() const;
    void addCharacterShieldChangedListener(CharacterShieldChangedCallback callback);

    // Character Battle Power
    uint64_t getCharacterBattlePower() const;

    // Game Tap
    void setGameTap(GameTap tap);
    GameTap getGameTap() const;
    void addGameTapChangedListener(GameTapChangedCallback callback);

    // Equipment Tap
    void setEquipmentTap(ItemType type);
    ItemType getEquipmentTap() const;
    void addEquipmentTapChangedListener(EquipmentTapChangedCallback callback);

private:
    void calculateBattlePower();

    uint64_t _gold = 0;
    double _saveGold = 0.0;
    uint64_t _characterAttack = 0;
    uint64_t _characterHP = 0;
    uint64_t _characterShield = 0;
    uint64_t _characterBattlePower = 0;

    GameTap _gameTap = GameTap::Resources;
    ItemType _equipmentTap = ItemType::Weapon;

    std::vector<GoldChangedCallback> _goldChangedListeners;
    std::vector<SaveGoldChangedCallback> _saveGoldChangedListeners;
    std::vector<CharacterAttackChangedCallback> _characterAttackChangedListeners;
    std::vector<CharacterHPChangedCallback> _characterHPChangedListeners;
    std::vector<CharacterShieldChangedCallback> _characterShieldChangedListeners;
    std::vector<GameTapChangedCallback> _gameTapChangedListeners;
    std::vector<EquipmentTapChangedCallback> _equipmentTapChangedListeners;
};

#endif // __GAME_MANAGER_H__
