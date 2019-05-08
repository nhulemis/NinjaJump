#include "Resources.h"

Resources::~Resources()
{
}

void Resources::CreateCharacter(const TypeCharacter & type)
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ninjagirl/ninja_girl.plist", "ninjagirl/ninja_girl.png");
	
	//SetStateAnimate(k_idel);
	//CreateAnimate("Idle_%d.png", 10, 0.15);
	//CreateAnimate("Jump_%d.png", 10, 0.15);
	//CreateAnimate("Jump_Throw_%d.png", 10, 0.15);

	//m_framesIdle.pushBack();
}

Resources::StateLoadAnimate Resources::GetStateLoadAnimate() const
 {
	 return m_stateAnimate;
 }

Animate* Resources::CreateAnimate(std::string name, int numFrames, float delay)
 {
	 Vector<SpriteFrame*> frames;
	 for (int i = 0; i < 10; i++)
	 {
		 char _name[20] = { '\0' };
		 sprintf(_name,name.c_str(), i);
		 auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(_name);
		 frames.pushBack(frame);
	 }
	
	 return Animate::create(Animation::createWithSpriteFrames(frames, delay));

	 
 }

 void Resources::SetStateAnimate(const StateLoadAnimate & state)
 {
	 m_stateAnimate = state;
 }
