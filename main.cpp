#include <Novice.h>
#include "GameManager.h"
#include <memory>
const char kWindowTitle[] = "LE2A_09_カタジマ_ロウノシン_PG3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	
	
	std::unique_ptr<GameManager> game;
	game = std::make_unique<GameManager>();
	
	
	
	game->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
