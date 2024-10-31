#include "Enemy.h"
#include "Engine/Model.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),eModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	//‚Æ‚è‚ ‚¦‚¸
	eModel_ = Model::Load("Assets/Model/oden.fbx");
	assert(eModel_ >= 0);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.02;
}

void Enemy::Draw()
{
	Model::SetTransform(eModel_, transform_);
	Model::Draw(eModel_);
}

void Enemy::Release()
{
}
