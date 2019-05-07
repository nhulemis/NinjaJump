#pragma once

#include "Game\Model\Model.h"
#include "cocos2d.h"

USING_NS_CC;


class Background
{
public:
	Background();
	~Background();
	
	void OnInit(Scene* scene);
	void OnUpdate();


private:
	Sprite *m_background1, *m_background2;
};

