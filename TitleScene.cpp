#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),tPict_(-1),select_(0)
{
	prevUpKey_ = false;
	prevDownKey_ = false;
}

void TitleScene::Initialize()
{
	//�^�C�g���摜�̃��[�h
	tPict_ = Image::Load("Assets/Image/title.JPG");
	assert(tPict_ >= 0);
}

void TitleScene::Update()
{
	////��ɍs���߂��Ȃ��悤��
	//if (select_ > 0) {
	//	if (Input::IsKey(DIK_W) || Input::IsKey(DIK_UP)) {
	//		if (prevUpKey_ == false) {//�O�t���[���ŉ����ĂȂ��Ȃ�
	//			select_--;
	//			prevUpKey_ = true;
	//		}
	//	}
	//	else {
	//		prevUpKey_ = false;
	//	}
	//}

	////���ɍs���߂��Ȃ��悤��
	//if (select_ < 1) {
	//	if (Input::IsKey(DIK_S) || Input::IsKey(DIK_DOWN)) {
	//		if (prevDownKey_ == false) {//�O�t���[���ŉ����ĂȂ��Ȃ�
	//			select_++;
	//			prevDownKey_ = true;
	//		}
	//	}
	//	else {
	//		prevDownKey_ = false;
	//	}
	//}

	//�G���^�[�Ō���
	if (Input::IsKeyDown(DIK_RETURN)) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	//�^�C�g���摜�̕`��
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

void TitleScene::Release()
{
}
