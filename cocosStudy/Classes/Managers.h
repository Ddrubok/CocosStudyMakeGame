#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "cocos2d.h"

class GameManager;
//class DataManager;
//class ResourceManager;
//class SoundManager;
//class UIManager;
//class ObjectManager;

class Manager {
public:
    static Manager* getInstance();

    // Getter ¸Ş¼­µå
    GameManager* getGameManager();
   /* DataManager* getDataManager() { return _data; }
    ResourceManager* getResourceManager() { return _resource; }
    SoundManager* getSoundManager() { return _sound; }
    UIManager* getUIManager() { return _ui; }
    ObjectManager* getObjectManager() { return _object; }*/

    

private:
    Manager() = default;
    ~Manager();

   
    void init();
    static Manager* s_instance;

    GameManager* _game;
   /* DataManager* _data;
    ResourceManager* _resource;
    SoundManager* _sound;
    UIManager* _ui;
    ObjectManager* _object;*/
};

#endif // __MANAGER_H__
