#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include <random>

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	srand((unsigned int)time(NULL));
	Instantiate<Player>(this);
}

void PlayScene::Update()
{
	if (time_ <= 0.0f) {
		Enemy* e = Instantiate<Enemy>(this);
		int tmp = rand() % 5;
		e->SetPosition(20 * tmp, 0, 30);
		tmp = rand() % 301;
		time_ = (float)(tmp / 100);
	}
	time_ -= 1.0f / 60.0f;
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
