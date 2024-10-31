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
	//モデルのロード
	pModel_ = Model::Load("Assets/Model/oden.fbx");
	//pModel_ = Model::Load("Assets/oden.fbx");
	assert(pModel_ >= 0);
}

void Player::Update()
{
	//Aを押したら右に進む
	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.1f;
	}
	//Dを押したら左に進む
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.1f;
	}

	if (Input::IsKeyDown(DIK_E)) {
		ChildOden* cOden = Instantiate<ChildOden>(this);
		cOden->SetPosition(transform_.position_);
		cOden->SetScale(0.5, 0.5, 0.5);
	}

	transform_.rotate_.y += 1;
}

void Player::Draw()
{
	//モデルの描画
	Model::SetTransform(pModel_, transform_);
	Model::Draw(pModel_);
}

void Player::Release()
{
}
