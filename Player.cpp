#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "ChildOden.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//���f���̃��[�h
	pModel_ = Model::Load("Assets/Model/oden.fbx");
	assert(pModel_ >= 0);
	transform_.rotate_.x = 90;
	transform_.scale_ = { 2.0,2.0,2.0 };
	transform_.position_.y += 0.5;
}

void Player::Update()
{
	//A����������E�ɐi��
	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.1f;
	}
	//D���������獶�ɐi��
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.1f;
	}

	if (Input::IsKeyDown(DIK_E)) {
		if (coNum_ > 0) {
			ChildOden* cOden = Instantiate<ChildOden>(this);
			//Transform tmp = transform_;
			//tmp.position_.y += 0.5;
			cOden->SetPosition(transform_.position_);
			cOden->SetScale(0.5, 0.5, 0.5);
			coNum_--;
		}
	}

	if (Input::IsKeyDown(DIK_R)) {
		if (coNum_ < 7) {
			coNum_++;
		}
	}

	//transform_.rotate_.y += 1;
}

void Player::Draw()
{
	//���f���̕`��
	Model::SetTransform(pModel_, transform_);
	Model::Draw(pModel_);
}

void Player::Release()
{
}
