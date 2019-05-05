#pragma once

#include "Singleton.h"
#include "cocos2d.h"

USING_NS_CC;
class Resources : public Singleton<Resources>
{
	friend class Singleton<Resources>;
public:

	enum TypeCharacter
	{
		k_boy = 0,
		k_girl
	};

	enum StateLoadAnimate
	{
		NONE =0,
		k_idel,
		k_jump,
		k_jumpThrow,
		k_dead,
		k_doneLoad
	};

	~Resources();
	void					CreateCharacter(const TypeCharacter& type);
	StateLoadAnimate		GetStateLoadAnimate()const;

	Animate*				CreateAnimate(std::string name, int numFrames, float delay);
	void					SetStateAnimate(const StateLoadAnimate& state);

private:
	Resources() {}


	StateLoadAnimate		m_stateAnimate;
	
	
};
