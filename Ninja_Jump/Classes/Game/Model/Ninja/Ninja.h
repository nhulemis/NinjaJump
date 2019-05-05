#pragma once

#include "Game\Model\Model.h"
#include "cocos2d.h"
#include "Singleton.h"

USING_NS_CC;


class Ninja :public Singleton<Ninja>,public Model
{
	friend class Singleton<Ninja>;
public:
	enum StateNinja
	{
		none = 0,
		k_run,
		k_jump,
		k_doubleJump,
		k_dead
	};

	~Ninja();
	virtual void			OnInit(Scene* scene) override;
	virtual void			OnUpdate() override;

private:
	Ninja();
	void					CreateAnimate();
	Sprite*					m_sprite;

	Vec2					m_position;
	StateNinja				m_state;
	Animate*				m_idleAnimate;
	Animate*				m_runAnimate;
	Animate*				m_jumpAnimate;
	Animate*				m_jumpThrowAnimate;
	Animate*				m_deadAnimate;
};

