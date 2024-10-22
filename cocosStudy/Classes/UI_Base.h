#include "cocos2d.h"
#include "InitBase.h"
#include <unordered_map>
#include <typeindex>
#include <vector>

class UI_Base : public InitBase {
protected:
	std::unordered_map<std::type_index, std::vector<cocos2d::Node*>> _objects;

	template <typename T>
	void Bind(const std::string& typeName) {
		std::vector<std::string> names = GetEnumNames(); // Enum 이름을 문자열로 추가하세요.
		std::vector<cocos2d::Node*> objects(names.size());
		_objects[typeid(T)] = objects;

		for (size_t i = 0; i < names.size(); ++i) {
			objects[i] = this->getChildByName(names[i]); // 자식 노드 찾기
			if (!objects[i]) {
				CCLOG("Failed to bind(%s)", names[i].c_str());
			}
		}
	}

public:
	void BindObjects(const std::string& typeName = "Object") { Bind<cocos2d::Node>(typeName); }
	void BindImages(const std::string& typeName = "Image") { Bind<cocos2d::Sprite>(typeName); } // Cocos2d-x에서 이미지 사용
	void BindButtons(const std::string& typeName = "Button") { Bind<cocos2d::MenuItem>(typeName); } // Cocos2d-x에서 버튼 사용

	virtual std::vector<std::string> GetEnumNames() = 0; // 순수 가상 함수

	

	template <typename T>
	T* Get(size_t idx) {
		auto it = _objects.find(std::type_index(typeid(T)));
		if (it == _objects.end()) return nullptr;

		return dynamic_cast<T*>(it->second[idx]); // 타입 캐스팅
	}

	cocos2d::Node* GetObject(size_t idx) { return Get<cocos2d::Node>(idx); }
	cocos2d::Sprite* GetImage(size_t idx) { return Get<cocos2d::Sprite>(idx); }
	cocos2d::MenuItem* GetButton(size_t idx) { return Get<cocos2d::MenuItem>(idx); }

	// 이벤트 바인딩 메서드
	static void BindEvent(cocos2d::Node* node, std::function<void(cocos2d::Touch*, cocos2d::Event*)> action, int eventType) {
		auto listener = cocos2d::EventListenerTouchOneByOne::create();

		listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			if (action) action(touch, event);
			return true; // 터치 이벤트를 처리했다고 표시
			};

		listener->onTouchMoved = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			// 추가적인 동작을 여기에 정의할 수 있습니다.
			};

		listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			// 추가적인 동작을 여기에 정의할 수 있습니다.
			};

		// 이벤트 리스너를 노드에 추가
		cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);
	}
};
