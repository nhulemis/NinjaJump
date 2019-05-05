#include "Ninja.h"
#include "Resource\Resources.h"
#include "Define.h"

Ninja::Ninja()
{
}

void Ninja::CreateAnimate()
{
	auto res = Resources::GetInstance();

	for (int i = Resources::StateLoadAnimate::NONE; i <= Resources::StateLoadAnimate::k_doneLoad; i++)
	{
		auto state = static_cast<Resources::StateLoadAnimate>(i);
		switch (state)
		{
		case Resources::NONE:
			res->SetStateAnimate(Resources::k_idel);
			break;
		case Resources::k_idel:
		{
			m_idleAnimate = res->CreateAnimate("Idle_%d.png", 10, 0.15);
			res->SetStateAnimate(Resources::k_jump);
		}
		break;
		case Resources::k_jump:
		{
			m_jumpAnimate = res->CreateAnimate("Jump_%d.png", 10, 0.15);
			res->SetStateAnimate(Resources::k_jumpThrow);
		}
		break;
		case Resources::k_jumpThrow:
		{
			m_jumpThrowAnimate = res->CreateAnimate("Jump_Throw_%d.png", 10, 0.15);
			res->SetStateAnimate(Resources::k_dead);
		}
		break;
		case Resources::k_dead:
		{
			m_deadAnimate = res->CreateAnimate("Dead_%d.png", 10, 0.15);
			res->SetStateAnimate(Resources::k_doneLoad);
		}
		break;
		case Resources::k_doneLoad:
			CCLOG("Done load animate");
			break;
		default:
			break;
		}
	}
}

Ninja::~Ninja()
{
}

void Ninja::OnInit(Scene* scene)
{
	m_state = StateNinja::none;
	auto res = Resources::GetInstance();

	//1st create character
	res->CreateCharacter(Resources::TypeCharacter::k_girl);
	//2nd create animate
	CreateAnimate();

	m_sprite = Sprite::create("ninjagirl/Idle__000.png");
	m_sprite->setPosition(Vec2(150, 150));
	auto PerTen = Director::getInstance()->getVisibleSize().height *2 / 10;
	auto objectHeight = m_sprite->getContentSize().height;
	auto onePerTenScreen = (PerTen) / objectHeight;
	//CCLOG("one per ten screen : %f", onePerTenScreen);
	m_sprite->setScale(onePerTenScreen);
	scene->addChild(m_sprite, 1);

	auto rep = RepeatForever::create(m_idleAnimate);
	
	m_sprite->runAction(rep);
	


}

void Ninja::OnUpdate()
{

}


