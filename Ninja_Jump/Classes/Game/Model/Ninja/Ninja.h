#pragma once

#include "Game\Model\Model.h"
#include "cocos2d.h"
#include "Singleton.h"

USING_NS_CC;
enum StateNinja
{
	none = 0,
	k_run,
	k_jump,
	k_doubleJump,
	k_die
};

class Ninja :public Singleton<Ninja>,public Model
{
	friend class Singleton<Ninja>;
public:
	~Ninja();
	virtual void			OnInit() override;
	virtual void			OnUpdate() override;

private:
	Ninja();
	Vec2					m_position;
	StateNinja				m_state;
};

