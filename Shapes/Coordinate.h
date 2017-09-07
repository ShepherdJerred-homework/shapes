#pragma once

struct Coordinate {
	int x;
	int y;

	Coordinate();
	Coordinate(int x, int y);

	bool operator ==(const Coordinate) const;
	bool operator !=(const Coordinate) const;
};
