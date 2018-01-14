#include <iostream>
#include <Windows.h>
#include "Game.h"

using namespace std;


Game::Game() {
	cout << "게임이 생성되었습니다." << endl;
}

Game::~Game() {
	cout << "게임이 종료되었습니다." << endl;
}

void Game::start() {
	statue = 1;

	cout << "게임이 시작되었습니다." << endl;

	while (true) {

		switch (statue){
			case 1:
				active_block.down(&pan);
				if (active_block.check_reach(&pan)) {
					statue = 2;
				}
				break;
			case 2:
				statue = 3;
				pan.insert(&active_block);
				update_block();
				if (check_finish()) {
					statue = 4;
				}
				break;
			case 3:
				statue = 1;
				pan.del_line();
				break;
			case 4:
				t.join();
				return;
		}

		view();


		Sleep(100);
		second++;
	}
}

void Game::update_block() {
	active_block = next_block;
	next_block = Block();
}

void Game::view() {
	system("cls");

	for (int i = 20; i >= 0; i--) {
		printf("ㅣ");
		for (int j = 0; j < 10; j++) {
			if (pan.get_pan()[i][j] == 1) {
				printf("ㅁ");
			}
			else {
				printf("  ");
			}
		}
		printf("ㅣ\n");
	}
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");
}

bool Game::check_finish() {
	for (int i = 0; i < 10; i++) {
		if (pan.get_pan()[20][i] == 1) {
			return true;
		}
	}
	return false;
}
