#include <Scene_Clear.h>

#include <NovicePlus.h>
#include <GameManager.h>

#include <Scene_Game.h>
#include <Scene_Title.h>
#include <NormalTransition.h>

Scene_Clear::Scene_Clear() { Init(); }
Scene_Clear::~Scene_Clear() { Finalize(); }



void Scene_Clear::Init() {



}

void Scene_Clear::Update() {

	if (NovicePlus::IsDecisionMade()) {
		GameManager::SetNextScene(new Scene_Title(), false, new NormalTransition());
		return;
	}

}

void Scene_Clear::Draw() {

	NovicePlus::DrawBox(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		0x202020ff
	);

	NovicePlus::DrawSprite(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		kWindowSize.castFloat(),
		"clear",
		WHITE
	);

}

void Scene_Clear::Finalize() {



}
