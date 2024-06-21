// 24-02-07_game.cpp

#include <iostream>
#include <fstream>
#include <conio.h>
#include <locale>
#include <vector>

#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

const int HEIGHT = 10;
const int WIDTH = 20;

const int PLAYER_VISION = 5;
const char PLAYER = 'A';
const char HEALTH = '$';

const char WALLS[] = "|-+";
const char EMPTY = ' ';

const char UP = 'w';
const char LEFT = 'a';
const char DOWN = 's';
const char RIGHT = 'd';

const char QUIT = 'q';
const char SAVE = 'o';
const char LOAD = 'p';

string save_file = "save_file.txt";
string save_directory = "C:\\cs131-game\\game_saves\\";
ofstream output_file;
ifstream input_file;

// Objects

// Position
struct Pos {
	int x;
	int y;
};

// Player and enemies
class Entity {
public:
	Entity(int x, int y) {
		this->p.x = x;
		this->p.y = y;
	}
	Pos get_pos() {
		return this->p;
	}
	void set_pos(Pos p) {
		this->p = p;
	}
private:
	Pos p;
};

// Board
class Board {
public:
	Board(int width, int height) {
		this->width = width;
		this->height = height;
		for (int i = 0; i < this->height; i++) {
			vector<char> row;
			for (int i = 0; i < this->width; i++) {
				row.push_back('.');
			}
			this->board.push_back(row);
		}
	}
	int get_height() {
		return this->height;
	}
	int get_width() {
		return this->width;
	}
	void display();
	void save();
	void load();
	vector<Entity> entities;
private:
	int width;
	int height;
	vector<vector<char>> board;
};

int main() {
	std::locale::global(std::locale("en_US.utf-8"));

	int board_width, board_height;
	std::cout << "Input board width (0 = default): ";
	std::cin >> board_width;
	if (board_width == 0) board_width = WIDTH;

	std::cout << "Input board height (0 = default): ";
	std::cin >> board_height;
	if (board_height == 0) board_width = WIDTH;

	Board board(board_width, board_height);


	int x = board_width / 2, y = board_height / 2;
	Entity player(x, y);

	board.entities = { player };
	
	board.display();
	
	while (true) {
        for (int i = 0; i < board.entities.size(); i++) {
            Pos p = board.entities[i].get_pos();
            std::cout << "e[" << i << "]: x: " << p.y << ", y: " << p.y << std::endl;
        }

        std::cout << "Waiting for input" << std::endl;
		while (!_kbhit()) {}; // Wait for keypress

		Pos player_pos = player.get_pos();
        std::string msg;
		switch (_getch()) {
		case UP:
            msg = "up pressed";
			player_pos.y--;
			break;
		case DOWN:
            msg = "down pressed";
			player_pos.y++;
			break;
		case LEFT:
            msg = "left pressed";
			player_pos.x--;
			break;
		case RIGHT:
            msg = "right pressed";
			player_pos.x++;
			break;
		case SAVE:
			board.save();
			break;
		case LOAD:
			board.load();
			break;
		case QUIT:
			exit(0);
		default:
            msg = "default";
			break;
		}

		if (player_pos.y < 0)
			player_pos.y = 0;
		if (player_pos.y > board_height - 1)
			player_pos.y = board_height - 1;

		if (player_pos.x < 0)
			player_pos.x = 0;
		if (player_pos.x > board_width - 1)
			player_pos.x = board_width - 1;
        msg += "\nnew pos: x: " + std::to_string(player_pos.x) + ", y: " + std::to_string(player_pos.y);

		player.set_pos(player_pos);
        board.entities = { player };

		board.display();
        std::cout << msg << std::endl;
	}
}

void Board::save() {
	// open the save file
    output_file.open(save_directory + save_file);
    if (output_file.fail()) {
        std::cout << "Unable to write save file";
        system("pause");
        return;
    }

    // almost the same as the display code, but writing
    // to the save file instead of the console
    Pos playerPos = this->entities[0].get_pos();
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            // place a 'P' where the player is
            if (i == playerPos.y && j == playerPos.x) {
                output_file << 'P';
                continue;
            }
            output_file << this->board[i][j];
        }
        output_file << '\n';
    }
    output_file.close();
}

void Board::load() {
	// open the save file
    input_file.open(save_directory + save_file);
    if (input_file.fail()) {
        std::cout << "Unable to read save file";
        system("pause");
        return;
    }

    char input;
    int i = 0, j = 0;
    // read the input file, one character at a time
    while (input_file >> input) {
        // place the character into it's corresponding coordinates on the board
        this->board[i][j] = input;

        // found the player! update their x and y coordinates to match
        if (input == 'P') {
            // @todo : set position on player
            // y = i;
            // x = j;
            this->board[i][j] = '.';
        }

        // move to the next column
        j++;

        // if finished with the row
        if (j >= this->width) {
            i++;   // go to the next row
            j = 0; // and move back to the first column
        }
    }
    // close out the file
    input_file.close();
}

void Board::display()
{
    system("cls"); // clear the console

    std::string buffer;

    Pos player_pos = this->entities[0].get_pos();

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {

            // print the player when i,j match the player's x,y
            if (i == player_pos.y && j == player_pos.x) {
                buffer += PLAYER;
                // std::wcout << PLAYER_SPRITE;
                continue;
            }

            // only draw if the current position is within "PLAYER_VISION" of the player's position
            if ((abs(i - player_pos.y) + abs(j - player_pos.x)) <= PLAYER_VISION) {
                if ((i == 0 && j == 0)
                    || (i == 0 && j == this->width - 1)
                    || (i == this->height - 1 && j == 0)
                    || (i == this->height - 1 && j == this->width - 1)) {
                    // std::cout << '+';
                    buffer += '+';
                    continue;
                }
                if (j == 0 || j == this->width - 1) {
                    // std::cout << '|';
                    buffer += '|';
                    continue;
                }
                if (i == 0 || i == this->height - 1) {
                    // std::cout << '-';
                    buffer += '-';
                    continue;
                }
                // std::cout << board[i][j];
                buffer += board[i][j];
            }
            else {
                // std::cout << EMPTY;
                buffer += EMPTY;
            }
        }
        // std::cout << '\n';
        buffer += '\n';
    }
    std::cout << buffer << std::flush;
}
