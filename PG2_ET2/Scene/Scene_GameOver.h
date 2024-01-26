#pragma once

#include <IScene.h>
#include <NovicePlus.h>

class Scene_GameOver final
	: public IScene {
public:

	Scene_GameOver();
	~Scene_GameOver();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:


};