#include "GameManager.h"

GameManager::GameManager() {}

GameManager::~GameManager() {}

void GameManager::setGold(uint64_t amount) {
    _gold = amount;
    for (const auto& listener : _goldChangedListeners) {
        listener(_gold);
    }
}

uint64_t GameManager::getGold() const {
    return _gold;
}

bool GameManager::canBuy(uint64_t amount) {
    if (_gold >= amount) {
        setGold(_gold - amount);
        return true;
    }
    return false;
}

void GameManager::addGoldChangedListener(GoldChangedCallback callback) {
    _goldChangedListeners.push_back(callback);
}

void GameManager::setSaveGold(double amount) {
    _saveGold = amount;
    for (const auto& listener : _saveGoldChangedListeners) {
        listener(_saveGold);
    }
}

double GameManager::getSaveGold() const {
    return _saveGold;
}

void GameManager::addSaveGoldChangedListener(SaveGoldChangedCallback callback) {
    _saveGoldChangedListeners.push_back(callback);
}

void GameManager::setCharacterAttack(uint64_t amount) {
    _characterAttack = amount;
    calculateBattlePower();
    for (const auto& listener : _characterAttackChangedListeners) {
        listener(_characterAttack);
    }
}

uint64_t GameManager::getCharacterAttack() const {
    return _characterAttack;
}

void GameManager::addCharacterAttackChangedListener(CharacterAttackChangedCallback callback) {
    _characterAttackChangedListeners.push_back(callback);
}

void GameManager::setCharacterHP(uint64_t amount) {
    _characterHP = amount;
    calculateBattlePower();
    for (const auto& listener : _characterHPChangedListeners) {
        listener(_characterHP);
    }
}

uint64_t GameManager::getCharacterHP() const {
    return _characterHP;
}

void GameManager::addCharacterHPChangedListener(CharacterHPChangedCallback callback) {
    _characterHPChangedListeners.push_back(callback);
}

void GameManager::setCharacterShield(uint64_t amount) {
    _characterShield = amount;
    calculateBattlePower();
    for (const auto& listener : _characterShieldChangedListeners) {
        listener(_characterShield);
    }
}

uint64_t GameManager::getCharacterShield() const {
    return _characterShield;
}

void GameManager::addCharacterShieldChangedListener(CharacterShieldChangedCallback callback) {
    _characterShieldChangedListeners.push_back(callback);
}

uint64_t GameManager::getCharacterBattlePower() const {
    return _characterBattlePower;
}

void GameManager::calculateBattlePower() {
    _characterBattlePower = _characterAttack + _characterHP + _characterShield;
}

void GameManager::setGameTap(GameTap tap) {
    _gameTap = tap;
    for (const auto& listener : _gameTapChangedListeners) {
        listener(_gameTap);
    }
}

GameTap GameManager::getGameTap() const {
    return _gameTap;
}

void GameManager::addGameTapChangedListener(GameTapChangedCallback callback) {
    _gameTapChangedListeners.push_back(callback);
}

void GameManager::setEquipmentTap(ItemType type) {
    _equipmentTap = type;
    for (const auto& listener : _equipmentTapChangedListeners) {
        listener(_equipmentTap);
    }
}

ItemType GameManager::getEquipmentTap() const {
    return _equipmentTap;
}

void GameManager::addEquipmentTapChangedListener(EquipmentTapChangedCallback callback) {
    _equipmentTapChangedListeners.push_back(callback);
}
