#include "GameManager.h"
#include"Novice.h"

GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	prevSceneNo_ = TITLE;
	currentSceneNo_ = prevSceneNo_;
}

GameManager::~GameManager()
{
}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		
		
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}
		
		
		
		
		sceneArr_[currentSceneNo_]->Update();
		
		
		
		sceneArr_[currentSceneNo_]->Draw();
		
		Novice::ScreenPrintf(0, 0, "Scene : %d", currentSceneNo_);

		
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	return 0;
}
