#ifndef COORDINATE_H
#define COORDINATE_H

#include<ostream>
using namespace std;

class Coordinate {
	friend std::ostream &operator<<(std::ostream &out, Coordinate &coor);
public:
	Coordinate(int x = 0, int y = 0);
	void printCoordinate();
	//operate <<

private:
	int m_iX;
	int m_iY;
};

#endif