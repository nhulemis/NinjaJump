#pragma once

#include "cocos2d.h"
#include "Game\Model\Ninja\Ninja.h"

#include "Define.h"

USING_NS_CC;

enum KeyCode
{
	k_space = EventKeyboard::KeyCode::KEY_SPACE
};

class GS_Gameplay : public cocos2d::Scene
{
private:
	Ninja*							m_ninja;
	PhysicsWorld*					m_physicsWorld;
	void							SetPhysicsWorld(PhysicsWorld* physicworld);
	bool							onContactBegin(PhysicsContact & contact);
public:
	~GS_Gameplay();

	static cocos2d::Scene*			createScene();

	virtual bool					init();

	void							onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void							onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void							update(float delta) override;

	// implement the "static create()" method manually
	CREATE_FUNC(GS_Gameplay);

	void							Destroy();
};
