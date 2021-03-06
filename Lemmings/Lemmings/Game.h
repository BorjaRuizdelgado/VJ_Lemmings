#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE

#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <GL/glew.h>
#include <GL/glut.h>

#include "Scene.h"
#include "Menu.h"
#include "AudioEngine.h"
#include "Cursor.h"


// Game is a singleton (a class with a single instance) that represents our whole application


class Game {

public:
	Game() {}
	
	static Game &instance() {
		static Game G;
		return G;
	}
	
	void init();
	bool update(int deltaTime);
	void render();
	
	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);
	
	bool getKey(int key) const;
	bool getSpecialKey(int key) const;
	bool getLeftMousePressed() const;
	bool getRightMousePressed() const;
	void getMousePosition(int& x, int& y) const;
	void closeGame();

private:
	bool bPlay;                       // Continue to play game
	bool keys[256], specialKeys[256]; // Store key states so that 
	                                  // we can have access at any time
	int mouseX, mouseY;               // Mouse position
	bool bLeftMouse, bRightMouse;     // Mouse button states
	bool menu;

	Scene* scene;
	static Cursor cursor;
};


#endif // _GAME_INCLUDE


