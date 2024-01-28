#include <Scene_Title.h>

#include <NovicePlus.h>
#include <GameManager.h>

#include <Scene_Game.h>
#include <NormalTransition.h>

Scene_Title::Scene_Title() { Init(); }
Scene_Title::~Scene_Title() { Finalize(); }



void Scene_Title::Init() {

	
}

void Scene_Title::Update() {

	if (NovicePlus::IsDecisionMade()) {
		GameManager::SetNextScene(new Scene_Game(), false, new NormalTransition());
		return;
	}

}

void Scene_Title::Draw() {

	NovicePlus::DrawBox(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		0x202020ff
	);

	NovicePlus::DrawSprite(
		Vec2f(640.0f, 360.0f),
		kWindowSize.castFloat(),
		kWindowSize.castFloat(),
		"title",
		WHITE
	);


}

void Scene_Title::Finalize() {



}


