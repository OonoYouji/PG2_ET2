#pragma once

#include <string>
#include <map>
#include <assert.h>

/// <summary>
/// このソリューション内で使用する画像を一括で管理するクラス
/// </summary>
class GameTextureManager final {
public: // member method

	// Constructor & Destructor
	GameTextureManager();
	~GameTextureManager();

	// default method
	static void Init();
	static void Finalize();

public: // sub class

	/// <summary>
	/// 画像一つ一つが持つ
	/// </summary>
	struct Texture final {
		int graphHandle;
		std::string filePath;
	};

private: // static member object

	static std::string filePath_;
	static std::map<std::string, Texture> textures_;

public: // user method

	static int GetGraphHandle(const std::string& key) {
		/// 画像が存在しなければエラーを吐く
		/// 一度keyの確認問題なければこのクラスを初期化しているか確認;
		assert(textures_.find(key) != textures_.end());
		return textures_.find(key)->second.graphHandle;
	}

};

