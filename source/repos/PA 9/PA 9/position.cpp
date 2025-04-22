#include "position.h"

position::position() {

	row = -1;
	col = -1;

}

position::position(int newRow, int newCol) {

	row = newRow;
	col = newCol;

}

position::~position() {



}

int position::getRow() const {

	return row;

}

int position::getCol() const {

	return col;

}

void position::setRow(int newRow) {

	this->row = newRow;

}

void position::setCol(int newCol) {

	this->col = newCol;

}

bool position::isValid() const {

	return row >= 0 && row < 8 && col >= 0 && col < 8;

}