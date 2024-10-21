#include "Managers.h"
#include "GameManager.h"
//#include "DataManager.h"
//#include "ResourceManager.h"
//#include "SoundManager.h"
//#include "UIManager.h"
//#include "ObjectManager.h"

Manager* Manager::s_instance = nullptr;

Manager* Manager::getInstance() {
    if (s_instance == nullptr) {
        s_instance = new Manager();
        s_instance->init();
    }
    return s_instance;
}

GameManager* Manager::getGameManager()
{
    return _game;
}

void Manager::init() {
    // 각 매니저 초기화
   _game = new GameManager();
   /* _data = new DataManager();
    _resource = new ResourceManager();
    _sound = new SoundManager();
    _ui = new UIManager();
    _object = new ObjectManager();*/
}

Manager::~Manager() {
    delete _game;
  /*  delete _data;
    delete _resource;
    delete _sound;
    delete _ui;
    delete _object;*/
}
