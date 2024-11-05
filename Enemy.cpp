#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),eModel_(-1),speed_(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	//‚Æ‚è‚ ‚¦‚¸
	eModel_ = Model::Load("Assets/Model/obs.fbx");
	assert(eModel_ >= 0);
	transform_.scale_ = { 2.0,2.0,2.0 };
	transform_.rotate_.y = 180;
	SphereCollider* col = new SphereCollider(0.6f);
	this->AddCollider(col);
	speed_ = 0.08f;
}

void Enemy::Update()
{

	if (FindObject("Player")) {
		transform_.position_.z -= speed_;
		if (transform_.position_.z < 0.0f) {
			KillMe();
		}
	}
}

void Enemy::Draw()
{
	Model::SetTransform(eModel_, transform_);
	Model::Draw(eModel_);
}

void Enemy::Release()
{
}
