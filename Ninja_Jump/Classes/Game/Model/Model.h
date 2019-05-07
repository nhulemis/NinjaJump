#pragma once

#include "cocos2d.h"

USING_NS_CC;
class Model
{
public:
	virtual void			OnInit(Scene* scene) = 0;
	virtual void			OnUpdate() = 0;
	virtual void			SetVisible(bool visible)
	{
		m_isVisible = visible;
	}
	virtual bool			HasVisible()const
	{
		return m_isVisible;
	}

	virtual void			SetPosition(const Vec2& position)
	{
		m_position = position;
		if (!m_sprite)
		{
			m_sprite->setPosition(m_position);
		}
	}

	virtual Vec2			GetPosition() const
	{
		return m_position;
	}
protected:
	Vec2					m_position;
	bool					m_isVisible;
	Sprite*					m_sprite;
};
