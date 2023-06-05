#include "Boost_Axe.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

Boost_Axe::Boost_Axe(int x, int y) : Boost(x, y)
{
	box.PushBack({ 0,0,16,21 });
	box.PushBack({ 18,0,16,21 });
	box.speed = 0.01f;
	currentAnim = &box;

	idle.PushBack({ 55,117,65,19 });

	collider = App->collisions->AddCollider({ 0, 0, 16, 21 }, Collider::Type::BOOST, (Module*)App->boost);
}

void Boost_Axe::Update()
{
	if (taken) {
		position.y = App->player->position.y;
		position.x = App->player->position.x - 9;
	}
	Boost::Update();
}

void Boost_Axe::Shoot()
{

}
