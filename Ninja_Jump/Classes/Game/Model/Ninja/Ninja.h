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
		k_idle = 0,
		k_run,
		k_jump,
		k_jumpThrow,
		k_dead
	};

	~Ninja();
	virtual void			OnInit(Scene* scene) override;
	virtual void			OnUpdate() override;
	void					SetStateNinja(const StateNinja& state);
	void					SwitchState();

private:
	Ninja();
	void					CreateAnimate();
	void					SetChangedState(const bool& isChanged);
	bool					HasChangedState()const;
	void					IdleState();
	void					RunAction();

	bool					m_isChangedState;

	Vec2					m_position;
	StateNinja				m_state;

	Map<StateNinja, Animate*>		m_animate;
};

