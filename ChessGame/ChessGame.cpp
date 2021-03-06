#include "pch.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;
using namespace sf;

int dim = 333;
Texture pieceTexture, boardTexture;

class Pos {
private:
	int X;
	int Y;

public:
	Pos() {
		X = 700;
		Y = 700;
	}

	Pos(int x, int y) {
		X = x * 100;
		Y = (7 - y) * 100;
	}

	int getX() {
		return X;
	}

	int getY() {
		return Y;
	}

};

class Piece {
private:
	Sprite chessPiece;
	bool alive;
	Pos pos;

public:
	Piece() {}

	Piece(Sprite chessP, bool a, int x, int y) {
		chessPiece = chessP;
		chessPiece.setScale(0.3f, 0.3f);
		alive = a;
		setPos(x,y);

	}

	void scale(float x, float y) {
		chessPiece.setScale(x, y);
	}

	Pos getPos() {
		return pos;
	}

	void setPos(int x, int y) {
		pos = Pos(x, y);
		chessPiece.setPosition(pos.getX()*1.0, pos.getY()*1.0);
	}
	Sprite getSprite() {
		return chessPiece;
	}
};

class Team {
private: 
	Piece pieces[16];
	bool alive = true;
	int index = 0;

public:
	Team(){}

	void addPiece(Piece p) {
		if (index < 16) {
			pieces[index++] = p;
		}
	}
	
	Piece getPiece(int i) {
		return pieces[i];
	}

};

class Game {
private:
	Team white;
	Team black;
public:
	Game() {}
	
	Game(Team w, Team b) {
		this->white = w;
		this->black = b;
	}

	Team getWhiteTeam() {
		return white;
	}
	Team getBlackTeam() {
		return black;
	}
};

Game teamSetup(Game g) {
	
	Team W, B;
	//WHITE
	
	Piece pawnW0(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 0, 1);
	Piece pawnW1(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 1, 1);
	Piece pawnW2(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 2, 1);
	Piece pawnW3(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 3, 1);
	Piece pawnW4(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 4, 1);
	Piece pawnW5(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 5, 1);
	Piece pawnW6(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 6, 1);
	Piece pawnW7(Sprite(pieceTexture, IntRect(2000 - dim, 0, dim, dim)), true, 7, 1);
	
	Piece rookW0(Sprite(pieceTexture, IntRect(2000 - dim * 2, 0, dim, dim)), true, 0, 0);
	Piece rookW1(Sprite(pieceTexture, IntRect(2000 - dim * 2, 0, dim, dim)), true, 7, 0);
	
	Piece knightW0(Sprite(pieceTexture, IntRect(2000 - dim * 3, 0, dim , dim)), true, 1, 0);
	Piece knightW1(Sprite(pieceTexture, IntRect(2000 - dim * 3, 0, dim, dim)), true, 6, 0);

	Piece bishopW0(Sprite(pieceTexture, IntRect(2000 - dim * 4, 0, dim, dim)), true, 2, 0);
	Piece bishopW1(Sprite(pieceTexture, IntRect(2000 - dim * 4, 0, dim, dim)), true, 5, 0);

	Piece queenW(Sprite(pieceTexture, IntRect(2000 - dim * 5, 0, dim, dim)), true, 3, 0);
	Piece kingW(Sprite(pieceTexture, IntRect(0, 0, dim, dim)), true, 4, 0);

	W.addPiece(pawnW0);
	W.addPiece(pawnW1);
	W.addPiece(pawnW2);
	W.addPiece(pawnW3);
	W.addPiece(pawnW4);
	W.addPiece(pawnW5);
	W.addPiece(pawnW6);
	W.addPiece(pawnW7);
	W.addPiece(rookW0);
	W.addPiece(knightW0);
	W.addPiece(bishopW0);
	W.addPiece(queenW);
	W.addPiece(kingW);
	W.addPiece(bishopW1);
	W.addPiece(knightW1);
	W.addPiece(rookW1);

	//BLACK

	Piece pawnB0(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 0, 6);
	Piece pawnB1(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 1, 6);
	Piece pawnB2(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 2, 6);
	Piece pawnB3(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 3, 6);
	Piece pawnB4(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 4, 6);
	Piece pawnB5(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 5, 6);
	Piece pawnB6(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 6, 6);
	Piece pawnB7(Sprite(pieceTexture, IntRect(2000 - dim, dim, dim, dim)), true, 7, 6);
	
	Piece rookB0(Sprite(pieceTexture, IntRect(2000 - dim * 2, dim, dim, dim)), true, 0, 7);
	Piece rookB1(Sprite(pieceTexture, IntRect(2000 - dim * 2, dim, dim, dim)), true, 7, 7);

	Piece knightB0(Sprite(pieceTexture, IntRect(2000 - dim * 3, dim, dim, dim)), true, 1, 7);
	Piece knightB1(Sprite(pieceTexture, IntRect(2000 - dim * 3, dim, dim, dim)), true, 6, 7);
	
	Piece bishopB0(Sprite(pieceTexture, IntRect(2000 - dim * 4, dim, dim, dim)), true, 2, 7);
	Piece bishopB1(Sprite(pieceTexture, IntRect(2000 - dim * 4, dim, dim, dim)), true, 5, 7);
	
	Piece queenB(Sprite(pieceTexture, IntRect(2000 - dim * 5, dim, dim, dim)), true, 3, 7);
	Piece kingB(Sprite(pieceTexture, IntRect(0, dim, dim, dim)), true, 4, 7);

	B.addPiece(pawnB0);
	B.addPiece(pawnB1);
	B.addPiece(pawnB2);
	B.addPiece(pawnB3);
	B.addPiece(pawnB4);
	B.addPiece(pawnB5);
	B.addPiece(pawnB6);
	B.addPiece(pawnB7);
	B.addPiece(rookB0);
	B.addPiece(knightB0);
	B.addPiece(bishopB0);
	B.addPiece(queenB);
	B.addPiece(kingB);
	B.addPiece(bishopB1);
	B.addPiece(knightB1);
	B.addPiece(rookB1);

	g = Game(W, B);
	return g;

}

int main(int argc, char ** argv) {
	RenderWindow renderWindow(VideoMode(800, 800), "Chess Game");
	Event event;

	//init
	int i=0, j=0;
	bool count = true, boardRender=false;
 
	Game game;
	Piece piece; 

	//Textures
	pieceTexture.loadFromFile("textures/Pieces.png");
	boardTexture.loadFromFile("textures/Chessboard.png");

	//Board Sprite
	Sprite board(boardTexture, IntRect(0, 0, 800, 800));

	game=teamSetup(game);

	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == Event::EventType::Closed)
				renderWindow.close();
		}

		if (boardRender == false){
			boardRender = true;
			renderWindow.draw(board);

			for (i = 0; i < 16; i++) {
				piece = game.getWhiteTeam().getPiece(i);
				renderWindow.draw(piece.getSprite());
				piece = game.getBlackTeam().getPiece(i);
				renderWindow.draw(piece.getSprite());
			}


			//renderWindow.draw(item1);

			renderWindow.display();
		}

	}

}