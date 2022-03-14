#include "ShieldCGComponent.h"
#include "Transform2D.h"
#include "Engine.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

ShieldCGComponent::ShieldCGComponent(Actor* owner, const char* name)
{
	m_owner = owner;
	getTransform()->setScale({ 150,150 });
	CircleCollider* circleCollider = new CircleCollider({ 75, this });
	this->setCollider(circleCollider);
	setName(name);
}

void ShieldCGComponent::start()
{
	Actor::start();

	addComponent(new SpriteComponent("images/ball.png"));
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());
}

void ShieldCGComponent::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Fallows The Owner Location
	getTransform()->setWorldPostion(m_owner->getTransform()->getWorldPosition());

	//Rotates 
	m_timer += deltaTime;
	getTransform()->setRotation(-m_timer);
}

void ShieldCGComponent::onCollision(Actor* actor)
{
	
	if (actor->getName() == "Agent2")
	{
		//destroy the actor
		Engine::destroy(actor);
		//destroy this actor
		Engine::destroy(this);
	}
}
