#include "GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowSize.x, kWindowSize.y);
	NovicePlus::Init();

	//// ゲームループ
	GameManager::Run();

	// ライブラリの終了
	NovicePlus::Finalize();
	Novice::Finalize();
	return 0;
}
