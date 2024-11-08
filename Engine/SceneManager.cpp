#include "SceneManager.h"
#include "../TestScene.h"
#include "../TitleScene.h"
#include "../PlayScene.h"
#include "../GameOverScene.h"
#include "Direct3D.h"
#include "Model.h"

SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent,"SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TITLE;
	nextSceneID_ = currentSceneID_;
	Instantiate<TitleScene>(this);
}

void SceneManager::Update()
{
    //次のシーンが現在のシーンと違う ＝ シーンを切り替えなければならない
    if (currentSceneID_ != nextSceneID_)
    {
        //そのシーンのオブジェクトを全削除(子オブジェクトをすべて削除)
        /*for (auto itr : childList_) {
            itr->ReleaseSub();
            SAFE_DELETE(itr);
            childList_.clear();
        }*/
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();

        //ロードしたデータを全削除
        Model::Release();

        //次のシーンを作成
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_TITLE: Instantiate<TitleScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        case SCENE_ID_GAMEOVER: Instantiate<GameOverScene>(this); break;
        }
        //無事シーンを生成出来たら、カレントシーンを更新
        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
