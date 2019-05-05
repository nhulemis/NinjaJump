#include "Ninja.h"
#include "Resource\Resources.h"
Ninja::Ninja()
{
}

Ninja::~Ninja()
{
}

void Ninja::OnInit()
{
	m_state = StateNinja::none;

	Resources::GetInstance()->CreateCharacter(Resources::TypeCharacter::k_girl);
}

void Ninja::OnUpdate()
{
}


