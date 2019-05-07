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

			m_animate.insert(StateNinja::k_idle, res->CreateAnimate("Idle_%d.png", 10, 0.15));
			res->SetStateAnimate(Resources::k_jump);
		}
		break;
		case Resources::k_jump:
		{
			m_animate.insert(StateNinja::k_jump, res->CreateAnimate("Jump_%d.png", 10, 0.15));
			res->SetStateAnimate(Resources::k_jumpThrow);
		}
		break;
		case Resources::k_jumpThrow:
		{
			m_animate.insert(StateNinja::k_jumpThrow, res->CreateAnimate("Jump_Throw_%d.png", 10, 0.15));
			res->SetStateAnimate(Resources::k_dead);
		}
		break;
		case Resources::k_dead:
		{
			m_animate.insert(StateNinja::k_dead, res->CreateAnimate("Dead_%d.png", 10, 0.15));
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

void Ninja::SetChangedState(const bool & isChanged)
{
	m_isChangedState = isChanged;
}

bool Ninja::HasChangedState() const
{
	return m_isChangedState;
}

void Ninja::IdleState()
{
	m_sprite->stopAllActions();
	auto rep = RepeatForever::create(m_animate.at(StateNinja::k_idle));
	m_sprite->runAction(rep);
}

void Ninja::RunAction()
{
	m_sprite->stopAllActions();
	auto seq = Sequence::create(m_animate.at(StateNinja::k_jumpThrow),
		CallFuncN::create(CC_CALLBACK_0(Ninja::IdleState, this)),
		nullptr
		);
	m_sprite->runAction(seq);
}

Ninja::~Ninja()
{
}

void Ninja::OnInit(Scene* scene)
{
	m_state = StateNinja::k_idle;
	auto res = Resources::GetInstance();

	//1st create character
	res->CreateCharacter(Resources::TypeCharacter::k_girl);
	//2nd create animate
	CreateAnimate();

	// init sprite for ninja
	{
		m_sprite = Sprite::create("ninjagirl/Idle__000.png");
		SetPosition(Vec2(150, 150));
		m_sprite->setPosition(GetPosition());

		//Set physics body for ninja
		{
			auto bodyNinja = PhysicsBody::createBox(m_sprite->getContentSize() - Size(100, 0), PHYSICSBODY_MATERIAL_DEFAULT);
			bodyNinja->setDynamic(true);
			m_sprite->addComponent(bodyNinja);
		}
		auto PerTen = Director::getInstance()->getVisibleSize().height * 2 / 10;
		auto objectHeight = m_sprite->getContentSize().height;
		auto onePerTenScreen = (PerTen) / objectHeight;
		//CCLOG("one per ten screen : %f", onePerTenScreen);
		m_sprite->setScale(onePerTenScreen);
		scene->addChild(m_sprite, 1);
	}

	IdleState();
	SetChangedState(false);

}

void Ninja::OnUpdate()
{
	if (HasChangedState())
	{
		SetChangedState(false);
		SetPosition(GetPosition() + Vec2(50, 50));
		RunAction();
	}
	
}

void Ninja::SetStateNinja(const StateNinja & state)
{
	m_state = state;
}

void Ninja::SwitchState()
{
	SetStateNinja(Ninja::k_jump);
	SetChangedState(true);
}


