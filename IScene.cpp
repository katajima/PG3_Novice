#include "IScene.h"


int IScene::sceneNo = TITLE;

IScene::~IScene(){}

int IScene::GetScene()
{
	return sceneNo;
}
