#pragma once
#include "Board.h"

class Snake {
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void ColorChange();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;
private:
	class Segment {
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color s);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location GetLocation() const;
	private:
		Location loc;
		Color c;
	};

private:
	static constexpr Color headColor = Colors::Yellow;
	Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	int color_variation = 0;
};
