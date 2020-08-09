#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	int altDimension = dimension - segmentSep;
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(((loc.x * dimension) + offSetx) + segmentSep, ((loc.y * dimension) + offSety) + segmentSep, altDimension, altDimension, c);
}

void Board::DrawBorder()
{
	int point1x = offSetx;
	int point1y = offSety;
	int point1z;

	int point2x = offSetx + (width * dimension);
	int point2y = offSety + (height * dimension);
	int point2z;

	gfx.DrawRect(point1x - 10, point1y - 10, point2x + 10, point1y, borderColor);
	gfx.DrawRect(point1x - 10, point2y, point2x + 10, point2y + 10, borderColor);
	gfx.DrawRect(point1x - 10, point1y - 10, point1x, point2y, borderColor);
	gfx.DrawRect(point2x, point1y, point2x + 10, point2y, borderColor);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}
