#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	
	
	//text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}
	words.setFont(font);
	words.setCharacterSize(24);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	// if 'W' is pressed, output to consol
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "'W' was pressed\n";
	}

	//if multiple keys are pressed at the same time
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "Multiple keys have been pressed, namely 'J', 'K' & 'L'\n";
	}

	//if the escape key is pressed
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	//mouse inputs
	int x = input->getMouseX();
	int y = input->getMouseY();
	std::string coordinates = std::to_string(x) + ", " + std::to_string(y);
	words.setString(coordinates);
}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(words);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}