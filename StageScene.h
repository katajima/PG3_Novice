#pragma once
#include "IScene.h"


class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
private:

	struct Vector2
	{
		float x;
		float y;
	};

	struct Object
	{
		Vector2 pos;
		float speed;
		float rad;
		bool isAlive;
	};
	Object player_;
	Object enemy_;
	Object bullet_;

};

