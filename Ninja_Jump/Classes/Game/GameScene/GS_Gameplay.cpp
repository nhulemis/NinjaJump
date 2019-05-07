#include "GS_Gameplay.h"

USING_NS_CC;

void GS_Gameplay::SetPhysicsWorld(PhysicsWorld * physicworld)
{
	m_physicsWorld = physicworld;
}

bool GS_Gameplay::onContactBegin(PhysicsContact & contact)
{
	return true;
}

GS_Gameplay::~GS_Gameplay()
{
	CCLOG("Destroy GS_Gameplay");
	Destroy();
}

Scene * GS_Gameplay::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = GS_Gameplay::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);

	return scene;
}

bool GS_Gameplay::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// set physic body for screen
	{
		auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
		auto edgeNode = Node::create();
		edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
		edgeNode->setPhysicsBody(edgeBody);
		addChild(edgeNode);
	}

	// add event listenner 
	{
		auto listennerKeyBoad = EventListenerKeyboard::create();
		listennerKeyBoad->onKeyPressed = CC_CALLBACK_2(GS_Gameplay::onKeyPressed, this);
		listennerKeyBoad->onKeyReleased = CC_CALLBACK_2(GS_Gameplay::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listennerKeyBoad, this);

		auto listennerPhysics = EventListenerPhysicsContact::create();
		listennerPhysics->onContactBegin = CC_CALLBACK_1(GS_Gameplay::onContactBegin, this);
	}

	// Init ninja
	{
		m_ninja = Ninja::GetInstance();
		m_ninja->SetVisible(true);
		m_ninja->OnInit(this);
	}
	
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
		m_ninja->SwitchState();
	}
}

void GS_Gameplay::update(float delta)
{
	//CCLOG("updating");
	m_ninja->OnUpdate();
}

void GS_Gameplay::Destroy()
{

}


