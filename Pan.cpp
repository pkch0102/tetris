#include "Pan.h"

Pan::Pan() {
	
}

Pan::~Pan() {}

int Pan::del_line() {
	int cnt = 0;

	int tmp_pan[24][10] = { 0, };

	int idx = 0;
	for (int i = 0; i < 21; i++) {
		bool isFilled = true;
		for (int j = 0; j < 10; j++) {
			if (game_pan[i][j] == 0) {
				isFilled = false;
				break;
			}
		}
		if (!isFilled) {
			for (int j = 0; j < 10; j++) {
				tmp_pan[idx][j] = game_pan[i][j];
			}
			idx++;
		}
		else {
			cnt++;
		}
	}

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 10; j++) {
			game_pan[i][j] = tmp_pan[i][j];
		}
	}

	return cnt;
}

int(*Pan::get_pan(void))[10]{
	return game_pan;
}


void Pan::insert(Block *block) {
	for (int i = 0; i < 4; i++) {
		int pos = block->pos()[i];
		int x = block->cal_x(pos);
		int y = block->cal_y(pos);

		game_pan[y][x] = 1;
	}
}