#ifndef GAME_H
#define GAME_H

#include "Pan.h"

class Game {

private:
	Pan pan = Pan();
	Block active_block = Block();
	Block next_block = Block();
	int statue = 0;
	int second = 0;

public:
	Game();
	~Game();

	void start();
	void update_block();
	void view();
	bool check_finish();
	void input();

};

#endif