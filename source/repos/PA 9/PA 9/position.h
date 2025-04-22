#pragma once

class position {

private:

	int row;
	int col;

public:

	position();
	position(int newRow, int newCol);
	~position();

	int getRow() const;
	int getCol() const;

	void setRow(int newRow);
	void setCol(int newCol);

	bool isValid() const;

};