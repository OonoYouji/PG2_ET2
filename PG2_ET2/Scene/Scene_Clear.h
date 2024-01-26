#pragma once

#include <IScene.h>
#include <NovicePlus.h>

class Scene_Clear final
	: public IScene {
public:

	Scene_Clear();
	~Scene_Clear();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:


};