#ifndef _PLAYSCENE_INCLUDE
#define _PLAYSCENE_INCLUDE

#include "Scene.h"
#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "MaskedTexturedQuad.h"
#include "Game.h"
#include "EntityManager.h"
#include "InterfazUsuario.h"
#include "Cursor.h"
#include "TextProcessor.h"
#include "EndScene.h"


class InterfazUsuario;
class DoorEnd;
class DoorStart;

class PlayScene :
	public Scene
{
public:
	PlayScene(string levelPath);
	~PlayScene();
	void init();
	void render();
	void update(int deltaTime);
	Scene* changeState();

private:
	void initShaders();
	void eraseMask(int mouseX, int mouseY);
	void applyMask(int mouseX, int mouseY);
	void effectForLemming(int mouseX, int mouseY, int effect);
	void setGUI();


private:
	VariableTexture colorTexture;
	MaskedTexturedQuad* map;
	InterfazUsuario* gui;
	VariableTexture maskTexture;
	ShaderProgram simpleTexProgram, maskedTexProgram;
	
	string path;
	float currentTime;
	glm::mat4 projection;
	bool bExit, bMouseLeft, bMoveCameraRight, bMoveCameraLeft, bEnd;
	bool bBasher, bBlocker, bDigger, bBuilder, bClimber, bFloater, bBomber, bExplosion;
	float cameraX, cameraY;
	EntityManager* manager;
	int buttonPressed;
	void doubleSceneSpeed();
	void decreaseSceneSpeed();

	int numDiggers, numBlockers, numBashers, numFloaters, numBombers, numClimbers, numBuilders;
	
	
};

#endif

