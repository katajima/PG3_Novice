#include "StageScene.h"
#include "Novice.h"

void StageScene::Init()
{
	player_.pos = { 640,500 };
	player_.speed = 3.0f;

	enemy_.pos = { 100,100 };

	bullet_.pos = { -10,-10 };


}

void StageScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}

}

void StageScene::Draw()
{
}
