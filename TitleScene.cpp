#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),tPict_(-1),select_(0)
{
	prevUpKey_ = false;
	prevDownKey_ = false;
	prevEnterKey_ = false;
}

void TitleScene::Initialize()
{
	//タイトル画像のロード
	tPict_ = Image::Load("Assets/Image/title.PNG");
	assert(tPict_ >= 0);
}

void TitleScene::Update()
{
	//上に行き過ぎないように
	if (select_ > 0) {
		if (Input::IsKey(DIK_W) || Input::IsKey(DIK_UP)) {
			if (prevUpKey_ == false) {//前フレームで押してないなら
				select_--;
				prevUpKey_ = true;
			}
		}
		else {
			prevUpKey_ = false;
		}
	}

	//下に行き過ぎないように
	if (select_ < 1) {
		if (Input::IsKey(DIK_S) || Input::IsKey(DIK_DOWN)) {
			if (prevDownKey_ == false) {//前フレームで押してないなら
				select_++;
				prevDownKey_ = true;
			}
		}
		else {
			prevDownKey_ = false;
		}
	}

	//エンターで決定
	if (Input::IsKey(DIK_RETURN)) {
		if (prevEnterKey_ == false) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			prevEnterKey_ = true;
			if (select_ == 0) {
				pSceneManager->ChangeScene(SCENE_ID_PLAY);
			}
			else {
				PostQuitMessage(0); //プログラム終了
			}
		}
		else {
			prevEnterKey_ = false;
		}
	}
}

void TitleScene::Draw()
{
	//タイトル画像の描画
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

void TitleScene::Release()
{
}
