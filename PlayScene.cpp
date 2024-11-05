#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include <random>
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), time_(0.0f),hImage_(-1)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	//hImage_ = Image::Load("Assets/Image/finger.png");
}

void PlayScene::Update()
{
	srand((unsigned int)time(NULL));
	if (time_ <= 0.0f) {
		Enemy* e = Instantiate<Enemy>(this);
		int tmp = rand() % 2;
		if (tmp == 0) {
			tmp = -(rand() % 2);
		}
		else {
			tmp = rand() % 2;
		}
		e->SetPosition(2 * tmp, 0, 30);
		tmp = rand() % 201 + 100;
		time_ = (float)(tmp / 100);
	}
	time_ -= 1.0f / 60.0f;
}

void PlayScene::Draw()
{
	Transform tmp;
	tmp.scale_ = { 0.2,0.2,0.2 };
	//Image::SetTransform(hImage_, tmp);
	//Image::Draw(hImage_);
}

void PlayScene::Release()
{
}
