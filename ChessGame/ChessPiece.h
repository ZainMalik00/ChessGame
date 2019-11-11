#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>

class ChessPiece {
	private:
		unordered_map<char, int> location;
	public:
		location<char, int> getPos(char x, int y);
};

#endif