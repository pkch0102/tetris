#include "Block.h"
#include "Pan.h"
#include <conio.h>
#include <stdlib.h>
#include <ctime>

Block::Block() {
	init_pos();
}
Block::~Block() {

}

int* Block::pos() {

	return pos_arr;
}

void Block::cal_pos(BLOCK_ACTION action, Pan *pan, int *tmp_pos) {
	if (action == LEFT) {
		tmp_pos[0] = pos_arr[0] - 100;
		tmp_pos[1] = pos_arr[1] - 100;
		tmp_pos[2] = pos_arr[2] - 100;
		tmp_pos[3] = pos_arr[3] - 100;
	}
	else if (action == RIGHT) {
		tmp_pos[0] = pos_arr[0] + 100;
		tmp_pos[1] = pos_arr[1] + 100;
		tmp_pos[2] = pos_arr[2] + 100;
		tmp_pos[3] = pos_arr[3] + 100;
	}
	else if (action == DOWN) {
		tmp_pos[0] = pos_arr[0] - 1;
		tmp_pos[1] = pos_arr[1] - 1;
		tmp_pos[2] = pos_arr[2] - 1;
		tmp_pos[3] = pos_arr[3] - 1;
	}
	else if (action == DROP) {
		tmp_pos[0] = pos_arr[0];
		tmp_pos[1] = pos_arr[1];
		tmp_pos[2] = pos_arr[2];
		tmp_pos[3] = pos_arr[3];
		while (true) {
			bool check = true;
			for (int i = 0; i < 4; i++) {
				int pos = pos_arr[i] - 1;
				int x = cal_x(pos);
				int y = cal_y(pos);
				int (*tmp_pan)[10] = pan->get_pan();

				if (y == -1 || tmp_pan[y][x] != 0) {
					check = false;
					break;
				}
			}
			if (check) {
				tmp_pos[0] = tmp_pos[0] - 1;
				tmp_pos[1] = tmp_pos[1] - 1;
				tmp_pos[2] = tmp_pos[2] - 1;
				tmp_pos[3] = tmp_pos[3] - 1;
			}
			else {
				break;
			}
		}
	}
	else if (action == TURN) {
		int curTmp = (hmt == 3) ? 0 : hmt++;
		turn_pos(tmp_pos, curTmp);
	}
}

void Block::init_pos() {
	srand((unsigned int)time(NULL));
	type = (BLOCK_TYPE)((rand() % 7) + 1);

	pos_arr[0] = 522;
	turn_pos(pos_arr, hmt);
}

void Block::turn_pos(int* arr, int hmt) {

	arr[0] = pos_arr[0];

	if (type == Z) {
		if (hmt == 0 || hmt == 2) {
			arr[1] = pos_arr[0] - 100 + 1;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] + 100;
		}
		else if (hmt == 1 || hmt == 3) {
			arr[1] = pos_arr[0] + 100 + 1;
			arr[2] = pos_arr[0] + 100;
			arr[3] = pos_arr[0] - 1;
		}
	}
	else if (type == RVS_Z) {
		if (hmt == 0 || hmt == 2) {
			arr[1] = pos_arr[0] + 100 + 1;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] - 100;
		}
		else if (hmt == 1 || hmt == 3) {
			arr[1] = pos_arr[0] - 100 + 1;
			arr[2] = pos_arr[0] - 100;
			arr[3] = pos_arr[0] - 1;

		}
	}
	else if (type == L) {
		if (hmt == 0) {
			arr[1] = pos_arr[0] + 2;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] + 100;
		}
		else if (hmt == 1) {
			arr[1] = pos_arr[0] - 200;
			arr[2] = pos_arr[0] - 100;
			arr[3] = pos_arr[0] + 1;
		}
		else if (hmt == 2) {
			arr[1] = pos_arr[0] - 2;
			arr[2] = pos_arr[0] - 1;
			arr[3] = pos_arr[0] - 100;
		}
		else if (hmt == 3) {
			arr[1] = pos_arr[0] + 200;
			arr[2] = pos_arr[0] + 100;
			arr[3] = pos_arr[0] - 1;
		}
	}
	else if (type == RVS_L) {
		if (hmt == 0) {
			arr[1] = pos_arr[0] + 2;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] - 100;
		}
		else if (hmt == 1) {
			arr[1] = pos_arr[0] - 200;
			arr[2] = pos_arr[0] - 100;
			arr[3] = pos_arr[0] - 1;
		}
		else if (hmt == 2) {
			arr[1] = pos_arr[0] - 2;
			arr[2] = pos_arr[0] - 1;
			arr[3] = pos_arr[0] + 100;
		}
		else if (hmt == 3) {
			arr[1] = pos_arr[0] + 200;
			arr[2] = pos_arr[0] + 100;
			arr[3] = pos_arr[0] + 1;
		}
	}
	else if (type == NEMO) {
		arr[1] = pos_arr[0] + 1;
		arr[2] = pos_arr[0] + 1 + 100;
		arr[3] = pos_arr[0] + 100;
	}
	else if (type == O) {
		if (hmt == 0) {
			arr[1] = pos_arr[0] + 1;
			arr[2] = pos_arr[0] - 100;
			arr[3] = pos_arr[0] + 100;
		}
		else if (hmt == 1) {
			arr[1] = pos_arr[0] - 100;
			arr[2] = pos_arr[0] - 1;
			arr[3] = pos_arr[0] + 1;
		}
		else if (hmt == 2) {
			arr[1] = pos_arr[0] - 1;
			arr[2] = pos_arr[0] + 100;
			arr[3] = pos_arr[0] - 100;
		}
		else if (hmt == 3) {
			arr[1] = pos_arr[0] + 100;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] - 1;
		}
	}
	else if (type == STICK) {
		if (hmt == 0 || hmt == 2) {
			arr[1] = pos_arr[0] + 2;
			arr[2] = pos_arr[0] + 1;
			arr[3] = pos_arr[0] - 1;
		}
		else if (hmt == 1 || hmt == 3) {
			arr[1] = pos_arr[0] - 200;
			arr[2] = pos_arr[0] - 100;
			arr[3] = pos_arr[0] + 100;
		}
	}
}

bool Block::left(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(LEFT, pan, pos);

	if (check(pan, pos)) {
		for (int i = 0; i < 4; i++) {
			pos_arr[i] = pos[i];
		}

		return true;
	}

	return false;
}

bool Block::right(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(RIGHT, pan, pos);

	if (check(pan, pos)) {
		for (int i = 0; i < 4; i++) {
			pos_arr[i] = pos[i];
		}

		return true;
	}

	return false;
}

bool Block::drop(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(DROP, pan, pos);

	if (check(pan, pos)) {
		for (int i = 0; i < 4; i++) {
			pos_arr[i] = pos[i];
		}

		return true;
	}

	return false;
}

bool Block::down(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(DOWN , pan, pos);

	if (check(pan, pos)) {
		for (int i = 0; i < 4; i++) {
			pos_arr[i] = pos[i];
		}

		return true;
	}

	return false;
}

bool Block::turn(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(TURN, pan, pos);

	if (check(pan, pos)) {
		for (int i = 0; i < 4; i++) {
			pos_arr[i] = pos[i];
		}

		return true;
	}

	return false;
}

bool Block::check(Pan *pan, int *pos) {
	for (int i = 0; i < 4; i++) {
		int x = cal_x(pos[i]);
		int y = cal_y(pos[i]);

		if (x < 0 || x>9 || y > 23 || y < 0 || pan->get_pan()[y][x] == 1) {
			return false;
		}
	}

	return true;
}

bool Block::check_reach(Pan *pan) {
	int pos[4] = { 0, };
	cal_pos(DOWN, pan, pos);

	return !check(pan, pos);
}

int Block::cal_x(int pos) {

	int x = (pos /= 100);
	
	return x;
}

int Block::cal_y(int pos) {

	int y = (pos %= 100);

	return y;
}