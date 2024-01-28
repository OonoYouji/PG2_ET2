#pragma once

#include <IScene.h>
#include <QuadVertex.h>

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