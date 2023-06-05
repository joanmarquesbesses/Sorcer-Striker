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
		currentAnim = &idle;
		position.y = App->player->position.y;
		position.x = App->player->position.x -15;
	}
	Boost::Update();
}

void Boost_Axe::Shoot()
{
	Particle* newParticle = App->particles->AddParticle(App->particles->LeftAxe, position.x, position.y - 20, Collider::Type::PLAYER_SHOT);
	newParticle->collider->AddListener(App->player);
	newParticle = App->particles->AddParticle(App->particles->RigthAxe, (position.x + 57) - 10, position.y - 20, Collider::Type::PLAYER_SHOT);
	newParticle->collider->AddListener(App->player);
	newParticle = nullptr;
}
