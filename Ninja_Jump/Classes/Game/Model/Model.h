#pragma once

#include "cocos2d.h"

class Model
{
public:
	Model();
	~Model();
	void						SetVisible(const bool& visible);
	bool						HasVisible() const;
	void						SetPosition(const cocos2d::Vec2& position);
	cocos2d::Vec2				GetPosition() const;

private:
	cocos2d::Vec2				m_position;
	bool						m_isVisible;
};

Model::Model()
{
}

Model::~Model()
{
	CCLOG("Destructor : ", "~Model");
}

inline void Model::SetVisible(const bool & visible)
{
	m_isVisible = visible;
}

inline bool Model::HasVisible() const
{
	return m_isVisible;
}

inline void Model::SetPosition(const cocos2d::Vec2 & position)
{
	m_position = position;
}

inline cocos2d::Vec2 Model::GetPosition() const
{
	return m_position;
}
