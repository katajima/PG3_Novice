#pragma once
#include "IScene.h"
struct Vector2
{
	float x;
	float y;
};

class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
private:



	struct Object
	{
		Vector2 pos;
		float speed;
		float rad;
		bool isAlive;
	};
	Object player_;
	Object enemy_;
	Object bullet_[50];

	int t = 0;

};

