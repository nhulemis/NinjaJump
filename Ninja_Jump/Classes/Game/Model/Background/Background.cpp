#include "Background.h"
#include "Define.h"

Background::Background()
{
}

Background::~Background()
{
}

void Background::OnInit(Scene * scene)
{
	//create background 1
	m_background1 = Sprite::create(BG_IMG);
	m_background1->setPosition(Vec2(SCREEN_W / 2, SCREEN_H / 2));
	
	//create background 2
	m_background2 = Sprite::create(BG_IMG);
	m_background2->setPosition(Vec2(SCREEN_W / 2 + m_background1->getContentSize().width
								, SCREEN_H / 2));

	//add child
	m_background1->addChild(scene, -1);
	m_background2->addChild(scene, -1);
}

void Background::OnUpdate()
{
	m_background1->setPositionX(m_background1->getPositionX() - BG_SCROLL_SPEED);
	m_background2->setPositionX(m_background2->getPositionX() - BG_SCROLL_SPEED);

	if (m_background1->getPositionX() <= m_background1->getContentSize().width)
	{
		m_background1->setPositionX(m_background2->getPositionX()
			+ m_background2->getContentSize().width);
	}

	if (m_background2->getPositionX() <= m_background2->getContentSize().width)
	{
		m_background2->setPositionX(m_background1->getPositionX()
			+ m_background1->getContentSize().width);
	}
}
