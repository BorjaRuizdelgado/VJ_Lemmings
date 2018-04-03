#pragma once
#include "Scene.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Sprite.h"
#include "Text.h"
#include "PlayScene.h"
#include "StartScene.h"
#include "InstructionsScene.h"


class Menu :
	public Scene
{
public:
	Menu();
	~Menu();
	void init();
	void render();
	void update(int deltaTime);
	virtual Scene* changeState();
	
private:
	bool bPlay, bExit, bInstructions, bCredits, bUp, bDown,pooledUp,pooledDown;
	ShaderProgram simpleTexProgram, maskedTexProgram;
	Texture titleTexture, bgTexture, buttonTexture;
	Sprite* title;
	Sprite* background;
	Sprite *playButton, *instructionsButton, *creditsButton, *exitButton;
	float buttonPosX;
	float buttonSizeX;
	float buttonSizeY;


	glm::mat4 projection;
	Text playText;
	int selected;
	void initShaders();
	int checkButtonsColison();
};

