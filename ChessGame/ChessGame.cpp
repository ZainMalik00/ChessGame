#include "pch.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;
using namespace sf;

int main(int argc, char ** argv) {
	RenderWindow renderWindow(VideoMode(640, 480), "Chess Game");
	Event event;

	unordered_map<char, int> board;

	Texture pieces;
	pieces.loadFromFile("textures/Pieces.png");
	
	IntRect dimensions(0, 0, 314, 302);

	Sprite item(pieces, dimensions);


	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == Event::EventType::Closed)
				renderWindow.close();
		}

		renderWindow.clear(Color::White);
		renderWindow.draw(item);
		renderWindow.display();
	}

}