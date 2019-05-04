#include "GS_Gameplay.h"

USING_NS_CC;

GS_Gameplay::~GS_Gameplay()
{
	CCLOG("Destroy GS_Gameplay");
	Destroy();
}

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

	auto listennerKeyBoad = EventListenerKeyboard::create();
	listennerKeyBoad->onKeyPressed = CC_CALLBACK_2(GS_Gameplay::onKeyPressed, this);
	listennerKeyBoad->onKeyReleased = CC_CALLBACK_2(GS_Gameplay::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listennerKeyBoad, this);

	m_ninja =Ninja::GetInstance();
	m_ninja->SetVisible(true);

	scheduleUpdate();
	return true;
}

void GS_Gameplay::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	
	if ((double)keyCode == KeyCode::k_space)
	{
		CCLOG("Press keyboad : %d", keyCode);
	}
}

void GS_Gameplay::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if ((double)keyCode == KeyCode::k_space)
	{
		CCLOG("Release keyboad : %d", keyCode);
	}
}

void GS_Gameplay::update(float delta)
{
	//CCLOG("updating");
}

void GS_Gameplay::Destroy()
{

}


