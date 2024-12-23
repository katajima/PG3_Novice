#include "ClearScene.h"
#include "Novice.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}


}

void ClearScene::Draw()
{
}
