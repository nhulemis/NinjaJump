#pragma once

#include "cocos2d.h"
#include "Define.h"

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

