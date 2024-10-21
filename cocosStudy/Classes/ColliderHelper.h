#ifndef __COLLIDER_HELPER_H__
#define __COLLIDER_HELPER_H__

#include "cocos2d.h"

class ColliderHelper {
public:
    // 스프라이트에 박스 콜라이더 추가
    static cocos2d::PhysicsBody* addBoxCollider(cocos2d::Sprite* sprite, const cocos2d::Size& size, bool isDynamic = true);

    // 충돌 감지 리스너 설정
    static void setContactListener(cocos2d::Node* targetNode, const std::function<bool(cocos2d::PhysicsContact&)>& callback);
};

#endif // __COLLIDER_HELPER_H__
