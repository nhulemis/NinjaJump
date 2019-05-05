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

	~Resources();
	void CreateCharacter(const TypeCharacter& type);

private:
	Resources() {}

	cocos2d::Vector<cocos2d::SpriteFrame*> m_framesIdle;
};
