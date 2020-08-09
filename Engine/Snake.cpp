#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		ColorChange();
		segments[nSegments].InitBody(bodyColor);
		++nSegments;
	}
}

void Snake::ColorChange()
{
	++color_variation;
	if (color_variation == 4) {
		color_variation = 1;
	}
	switch (color_variation) {
	case 1:
		bodyColor = Colors::Green;
		break;
	case 2:
		bodyColor = Colors::Magenta;
		break;
	case 3:
		bodyColor = Colors::Cyan;
		break;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color s)
{
	c = s;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location Snake::Segment::GetLocation() const
{
	return Location(loc);
}
