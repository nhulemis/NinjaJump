#include "GS_Gameplay.h"

USING_NS_CC;

Scene * GS_Gameplay::createScene()
{
	return GS_Gameplay::create();
}

bool GS_Gameplay::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	return true;
}
