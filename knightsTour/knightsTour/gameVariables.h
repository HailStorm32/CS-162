#pragma once

struct KnightsTour
{
	const struct xYCords
	{
		int posX;
		int posY;
	};
	
	int board[BOARD_WIDTH][BOARD_HEIGHT] = {};
};