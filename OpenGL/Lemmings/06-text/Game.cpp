#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init()
{
	bPlay = true;
	bLeftMouse = bRightMouse = false;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	scene.init();
	menuObj.init();
	menu = false;
}

bool Game::update(int deltaTime)
{
	scene.update(deltaTime);
	
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (menu) menuObj.render();
	else scene.render();
}

void Game::keyPressed(int key)
{
	if(key == 27) // Escape code
		bPlay = false;
	keys[key] = true;
	
}

void Game::keyReleased(int key)
{
	keys[key] = false;
	if (key == 'm' && menu){
		menu = false;
	}
	else if (key == 'm' && !menu){
		menu = true;
	}
	else if (key == '8'&& menu) {
		menuObj.selection();
	}
	else if (key == '2'&& menu) {
		menuObj.selection();
	}
	
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
	mouseX = x;
	mouseY = y;
	scene.mouseMoved(mouseX, mouseY, bLeftMouse, bRightMouse);
}

void Game::mousePress(int button)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		bLeftMouse = true;
		scene.mouseMoved(mouseX, mouseY, bLeftMouse, bRightMouse);
	}
	else if(button == GLUT_RIGHT_BUTTON)
	{
		bRightMouse = true;
		scene.mouseMoved(mouseX, mouseY, bLeftMouse, bRightMouse);
	}
}

void Game::mouseRelease(int button)
{
	if(button == GLUT_LEFT_BUTTON)
		bLeftMouse = false;
	else if(button == GLUT_RIGHT_BUTTON)
		bRightMouse = false;
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}





