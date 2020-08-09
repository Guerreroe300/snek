#pragma once
#include "Graphics.h"
#include "Location.h"
#include"Graphics.h"
#include <assert.h>
class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc,Color c);
	void DrawBorder();
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int offSetx = 50;
	static constexpr int offSety = 50;
	static constexpr int segmentSep = 5;
	static constexpr Color borderColor = Colors::Green;
	Graphics& gfx;
};
