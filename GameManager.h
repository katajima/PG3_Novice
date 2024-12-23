#pragma once

#include <memory>
#include "IScene.h"
#include"TitleScene.h"
#include"StageScene.h"
#include"ClearScene.h"


class GameManager
{
private:

	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


public:
	GameManager();
	~GameManager();

	int Run();


};

