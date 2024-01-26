#include <Scene_GameOver.h>

#include <NovicePlus.h>
#include <GameManager.h>

#include <Scene_Game.h>
#include <Scene_Title.h>
#include <NormalTransition.h>

Scene_GameOver::Scene_GameOver() { Init(); }
Scene_GameOver::~Scene_GameOver() { Finalize(); }



void Scene_GameOver::Init() {



}

void Scene_GameOver::Update() {

	if (NovicePlus::IsDecisionMade()) {
		GameManager::SetNextScene(new Scene_Title(), false, new NormalTransition());
		return;
	}

}

void Scene_GameOver::Draw() {

	NovicePlus::DrawBox(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		0x202020ff
	);

	NovicePlus::DrawSprite(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		kWindowSize.castFloat(),
		"gameOver",
		WHITE
	);

}

void Scene_GameOver::Finalize() {



}
