#pragma once

#include <IScene.h>

class Scene_Title final
	: public IScene {
public:

	Scene_Title();
	~Scene_Title();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;

private:



};