#include "Resources.h"

Resources::~Resources()
{
}

void Resources::CreateCharacter(const TypeCharacter & type)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ninjagirl/girlninja.plist", "ninjagirl/girlninja.png");
	
	for (int i = 0; i < 10; i++)
	{
		char name[20] = { '\0' };
		sprintf(name, "Idle_%d.png", i);
		//std::string _name = name + temp;
		auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
		m_framesIdle.pushBack(frame);
	}
	//m_framesIdle.pushBack();
}
