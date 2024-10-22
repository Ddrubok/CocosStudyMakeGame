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
		std::vector<std::string> names = GetEnumNames(); // Enum �̸��� ���ڿ��� �߰��ϼ���.
		std::vector<cocos2d::Node*> objects(names.size());
		_objects[typeid(T)] = objects;

		for (size_t i = 0; i < names.size(); ++i) {
			objects[i] = this->getChildByName(names[i]); // �ڽ� ��� ã��
			if (!objects[i]) {
				CCLOG("Failed to bind(%s)", names[i].c_str());
			}
		}
	}

public:
	void BindObjects(const std::string& typeName = "Object") { Bind<cocos2d::Node>(typeName); }
	void BindImages(const std::string& typeName = "Image") { Bind<cocos2d::Sprite>(typeName); } // Cocos2d-x���� �̹��� ���
	void BindButtons(const std::string& typeName = "Button") { Bind<cocos2d::MenuItem>(typeName); } // Cocos2d-x���� ��ư ���

	virtual std::vector<std::string> GetEnumNames() = 0; // ���� ���� �Լ�

	

	template <typename T>
	T* Get(size_t idx) {
		auto it = _objects.find(std::type_index(typeid(T)));
		if (it == _objects.end()) return nullptr;

		return dynamic_cast<T*>(it->second[idx]); // Ÿ�� ĳ����
	}

	cocos2d::Node* GetObject(size_t idx) { return Get<cocos2d::Node>(idx); }
	cocos2d::Sprite* GetImage(size_t idx) { return Get<cocos2d::Sprite>(idx); }
	cocos2d::MenuItem* GetButton(size_t idx) { return Get<cocos2d::MenuItem>(idx); }

	// �̺�Ʈ ���ε� �޼���
	static void BindEvent(cocos2d::Node* node, std::function<void(cocos2d::Touch*, cocos2d::Event*)> action, int eventType) {
		auto listener = cocos2d::EventListenerTouchOneByOne::create();

		listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			if (action) action(touch, event);
			return true; // ��ġ �̺�Ʈ�� ó���ߴٰ� ǥ��
			};

		listener->onTouchMoved = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			// �߰����� ������ ���⿡ ������ �� �ֽ��ϴ�.
			};

		listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event) {
			// �߰����� ������ ���⿡ ������ �� �ֽ��ϴ�.
			};

		// �̺�Ʈ �����ʸ� ��忡 �߰�
		cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);
	}
};
