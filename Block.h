#ifndef BLOCK_H
#define BLOCK_H

class Pan;

enum BLOCK_TYPE {NONE, Z, RVS_Z, NEMO, L, RVS_L, O, STICK };
enum BLOCK_ACTION {LEFT, RIGHT, DOWN, DROP, TURN};

class Block {
private:
	BLOCK_TYPE type = NONE;
	int hmt = 0;
	int pos_arr[4] = { 0, };
public:
	Block();
	~Block();

	int* pos();
	void cal_pos(BLOCK_ACTION action, Pan *pan, int *tmp_pos);
	void init_pos();
	void turn_pos(int* arr, int hmt);
	bool left(Pan *pan);
	bool right(Pan *pan);
	bool drop(Pan *pan);
	bool down(Pan *pan);
	bool turn(Pan *pan);
	bool check(Pan *pan, int *pos);
	bool check_reach(Pan *pan);
	int cal_x(int pos);
	int cal_y(int pos);
};

#endif