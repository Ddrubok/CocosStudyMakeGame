#include "ColliderHelper.h"

using namespace cocos2d;

PhysicsBody* ColliderHelper::addBoxCollider(Sprite* sprite, const Size& size, bool isDynamic) 
{
    auto body = PhysicsBody::createBox(size);
    body->setDynamic(isDynamic);
    body->setContactTestBitmask(0xFFFFFFFF); 
    sprite->setPhysicsBody(body);
    return body;
}

void ColliderHelper::setContactListener(Node* targetNode, const std::function<bool(PhysicsContact&)>& callback) 
{
   
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = callback;

    targetNode->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, targetNode);
}
