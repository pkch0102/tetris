#ifndef PAN_H
#define PAN_H

#include "Block.h"

class Pan {
private:
	int game_pan[24][10] = { 0, };

public:
	Pan();
	~Pan();

	int del_line();
	int(*get_pan(void))[10];
	void insert(Block *block);
};

#endif