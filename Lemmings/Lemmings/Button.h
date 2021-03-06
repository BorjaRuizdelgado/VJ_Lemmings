#ifndef _BUTTON_INCLUDE
#define _BUTTON_INCLUDE

#include "Shader.h"
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "ShaderProgram.h"
#include "MaskedTexturedQuad.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Text.h"
class Button
{
public:
	Button(glm::ivec2 size, glm::vec2 position, string texture, string number);
	~Button();
	void render();
	void update(string number);
	bool checkColision(int mouseX, int mouseY);
	void select();
	void deselect();
	void increaseText();
	void decreaseText();
private:
	Sprite* button;
	Sprite* selectedButton;
	Texture image;
	Texture selected;
	ShaderProgram shaderProgram;
	glm::mat4 projection;
	string number;
	Text buttonText;
	glm::vec2 position;
	bool pressed;
	void initShader();
	glm::ivec2 size;
};

#endif

