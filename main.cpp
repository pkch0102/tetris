#include <iostream>
#include <string>
#include <thread>
#include <conio.h>
#include "Game.h"

using namespace std;

#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define SPACE 32
#define UP 72

void input() {
	/*
	while (statue > 0 && statue < 4) {
		int key = _getch();


		if (key == LEFT) {
			if (active_block.left(&pan)) {
				view();
			}
		}
		else if (key == UP) {
			if (active_block.turn(&pan)) {
				view();
			}
		}
		else if (key == RIGHT) {
			if (active_block.right(&pan)) {
				view();
			}
		}
		else if (key == DOWN) {
			if (active_block.down(&pan)) {
				view();
			}
		}
		else if (key == SPACE) {
			if (active_block.drop(&pan)) {
				view();
			}
		}
	}
*/
}

int main()
{
	while (true) {
		system("cls");
		cout << "������ �����Ϸ��� 1, �����Ϸ��� 2�� �Է����ּ���" << endl;
		string input = "";
		cin >> input;

		if (input.compare("1") == 0) {
			thread t(&input);
			Game game = Game();
			game.start();
		}
		else if (input.compare("2") == 0) {
			break;
		}
		else {
			cout << "�ٽ� �Է����ּ���." << endl;
		}
	}

	return 0;
}
