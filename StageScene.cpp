#include "StageScene.h"
#include "Novice.h"
#include"cmath"


// 2つの点間の距離を計算する関数
float Distance(const Vector2& point1, const Vector2& point2) {
	float dx = point1.x - point2.x;
	float dy = point1.y - point2.y;
	return std::sqrt(dx * dx + dy * dy);
}

void StageScene::Init()
{
	player_.pos = { 640,500 };
	player_.speed = 3.0f;
	player_.rad = 30;
	player_.isAlive = true;

	enemy_.pos = { 100,100 };
	enemy_.isAlive = true;
	enemy_.rad = 30;
	for (int i = 0; i < 50; i++) {
		bullet_[i].pos = {-10,-10};
		bullet_[i].rad = { 20 };
	}

}

void StageScene::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	// クリア条件
	if (enemy_.isAlive == false) {
		sceneNo = CLEAR;
	}

	// 移動
	if (keys[DIK_A]) {
		player_.pos.x -= player_.speed;
	}
	if (keys[DIK_D]) {
		player_.pos.x += player_.speed;
	}
	







	// 弾発射
	if (keys[DIK_SPACE]) {
		t++;
		for (int i = 0; i < 50; i++) {
			if (t % 5 == 0) {
				if (bullet_[i].isAlive == false) {
					bullet_[i].isAlive = true;
					bullet_[i].pos = player_.pos;
					break;
				}
			}
		}
	}

	// 弾更新処理
	for (int i = 0; i < 50; i++) {
		if (bullet_[i].isAlive) {
			bullet_[i].pos.y -= 3.0f;

			if (bullet_[i].pos.y <= 0) {
				bullet_[i].isAlive = false;
				bullet_[i].pos = { -10,-10 };
			}


			// 判定処理
			if (Distance(enemy_.pos, bullet_[i].pos) <= bullet_[i].rad + enemy_.rad) {
				enemy_.isAlive = false;
			}
		}
	}
}

void StageScene::Draw()
{
	// 敵
	Novice::DrawEllipse(int(enemy_.pos.x), int(enemy_.pos.y), int(enemy_.rad), int(enemy_.rad), 0.0f, RED, kFillModeSolid);

	// 弾
	for (int i = 0; i < 50; i++) {
		if (bullet_[i].isAlive) {
			Novice::DrawEllipse(int(bullet_[i].pos.x), int(bullet_[i].pos.y), int(bullet_[i].rad), int(bullet_[i].rad), 0.0f, BLACK, kFillModeSolid);
		}
	}

	// プレイヤー
	Novice::DrawEllipse(int(player_.pos.x), int(player_.pos.y), int(player_.rad), int(player_.rad), 0.0f, BLUE, kFillModeSolid);

}
