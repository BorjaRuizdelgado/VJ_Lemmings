#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"


void Game::init() {
	bPlay = true;
	bLeftMouse = bRightMouse = false;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	scene = new Menu();
	scene->init();
}

bool Game::update(int deltaTime) {
	scene->update(deltaTime);
	scene = scene->changeState();
	return bPlay;
}

void Game::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene->render();

}

void Game::keyPressed(int key) {
	keys[key] = true;
}
void Game::closeGame() {
	bPlay = false;
}

void Game::keyReleased(int key) {
	keys[key] = false;
}

void Game::specialKeyPressed(int key) {
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key) {
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y) {
	mouseX = x;
	mouseY = y;
}

void Game::mousePress(int button) {
	if(button == GLUT_LEFT_BUTTON)
		bLeftMouse = true;
	
	else if(button == GLUT_RIGHT_BUTTON)
		bRightMouse = true;
}

void Game::mouseRelease(int button) {
	if(button == GLUT_LEFT_BUTTON)
		bLeftMouse = false;
	else if(button == GLUT_RIGHT_BUTTON)
		bRightMouse = false;
}

bool Game::getKey(int key) const {
	return keys[key];
}

bool Game::getSpecialKey(int key) const {
	return specialKeys[key];
}

bool Game::getLeftMousePressed() const {
	return bLeftMouse;
}

bool Game::getRightMousePressed() const {
	return bRightMouse;
}

void Game::getMousePosition(int& x, int& y) const {
	x = mouseX;
	y = mouseY;
}





