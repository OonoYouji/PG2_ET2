#include "GameTextureManager.h"

#include <Novice.h>

/// static member object Initilize -----
std::string GameTextureManager::filePath_ = "./Resources/Images/";
std::map<std::string, GameTextureManager::Texture> GameTextureManager::textures_;

// Constructor & Destructor
GameTextureManager::GameTextureManager() { Init(); }
GameTextureManager::~GameTextureManager() { Finalize(); }

void GameTextureManager::Init() {

	/// textures_[(使用するkeyの設定)] = {(必ずNULLで初期化), (読み込む画像のファイルパス)};
	// 1x1
	textures_["white1x1"] = { NULL, "white1x1.png" };
	// 32x32
	textures_["playerBody"] = { NULL, filePath_ + "Player.png" };
	textures_["enemyBody"] = { NULL, filePath_ + "enemyBody.png" };
	textures_["enemyEye"] = { NULL, filePath_ + "enemyEye.png" };
	// 128x128
	textures_["circle"] = { NULL, filePath_ + "Circle.png" };
	// 1280x720
	textures_["title"] = { NULL, filePath_ + "title.png" };
	textures_["clear"] = { NULL, filePath_ + "clear.png" };
	textures_["gameOver"] = { NULL, filePath_ + "gameOver.png" };


	/// 上記で設定したファイルパスを利用し、graphHandleにロードする;
	for (auto& it : textures_) {
		it.second.graphHandle = Novice::LoadTexture(it.second.filePath.c_str());
	}

}

void GameTextureManager::Finalize() {
	/// すべて画像を解放する
	for (auto& it : textures_) {
		Novice::UnloadTexture(it.second.graphHandle);
	}
}
