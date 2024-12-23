#pragma once


enum SCENE {TITLE,STAGE,CLEAR};

class IScene
{
protected:
	//
	static int sceneNo;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

public:

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetScene();


};

