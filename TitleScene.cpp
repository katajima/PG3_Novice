#include "TitleScene.h"
#include"Novice.h"

void TitleScene::Init()
{
	tex = Novice::LoadTexture("1.png");

}

void TitleScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		sceneNo = STAGE;
	}

}

void TitleScene::Draw()
{

	Novice::DrawSprite(0, 0, tex, 1280, 720, 0.0f, WHITE);

}
