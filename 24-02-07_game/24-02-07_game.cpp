// 24-02-07_game.cpp

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

const int HEIGHT = 10;
const int WIDTH = 20;
const int PLAYER_VISION = 5;
const char EMPTY = ' ';
const char PLAYER = 'A';
const char HEALTH = '$';
const char UP = 'w';
const char LEFT = 'a';
const char DOWN = 's';
const char RIGHT = 'd';
const char QUIT = 'q';
const char SAVE = 'o';
const char LOAD = 'p';

string save_file = "save_file.txt";
string save_directory = "C:\\Users\\eamon.burns.BELTEC\\coding\\cs131-a\\24-02-07_game\\game_saves\\";
ofstream output_file;
ifstream input_file;

// Board
char board[HEIGHT][WIDTH];

// Player coords
int x = WIDTH / 2, y = HEIGHT / 2;

// Functions
void display(char board[HEIGHT][WIDTH]);
void populate(char board[HEIGHT][WIDTH]);
void save();
void load();

int main() {
	int input;
	
	populate(board);
	display(board);

	while (true) {
		input = _getch();
		switch (input)
		{
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case QUIT:
			exit(0);
		case SAVE:
			save();
			break;
		case LOAD:
			load();
			break;
		default:
			break;
		}

		if (y < 0)
			y = 0;
		if (y > HEIGHT - 1)
			y = HEIGHT - 1;

		if (x < 0)
			x = 0;
		if (x > WIDTH - 1)
			x = WIDTH - 1;

		display(board);
	}
}

void display(char board[HEIGHT][WIDTH]) {
	system("cls");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			if (i == y && j == x) {
				cout << PLAYER;
			}
			else if ((abs(i - y) + abs(j - x) <= PLAYER_VISION)) {
				// Draw walls
				if ((i == 0 && j == 0)
					|| (i == 0 && j == WIDTH - 1)
					|| (i == HEIGHT - 1 && j == 0)
					|| (i == HEIGHT - 1 && j == WIDTH - 1)
					) {
					cout << '+';
					continue;
				}
				if (i == 0 || i == HEIGHT - 1) {
					cout << '-';
					continue;
				}
				if (j == 0 || j == WIDTH - 1) {
					cout << '|';
					continue;
				}
				cout << board[i][j];
			}
			else {
				cout << EMPTY;
			}
		}
		cout << endl;
	}
}

void populate(char board[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			board[i][j] = '.';
		}
	}
}

void save() {
	// Open file
	output_file.open(save_directory + save_file);
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == y && j == x) {
				output_file << PLAYER;
			}
			else {
				output_file << board[i][j];
			}
		}
		output_file << endl;
	}

	output_file.close();
}

void load() {
	char input;
	input_file.open(save_directory + save_file);
	input_file.clear();
	input_file.seekg(0);
	if (input_file.fail()) {
		cout << "Error reading file";
		system("pause");
		exit(1);
	}

	int i = 0,
		j = 0;
	while (input_file >> input) {
		if (input == PLAYER) {
			y = i;
			x = j;
			board[i][j] = '.';
		}
		else {
			board[i][j] = input;
		}
		j++;
		if (j >= WIDTH) {
			j = 0;
			i++;
		}
	}
	input_file.close();
	display(board);
}
