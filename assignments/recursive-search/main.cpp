#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char knight = 'N';
char wall = '#';
char empty = ' ';
// char visited = '.';

int input_board(std::string filename, char board[11][11]) { 
    std::fstream filein(filename);
    std::string temp; 
    int counter = 0; 
    while(std::getline(filein, temp)) { 
        for(int i = 0; i < temp.length(); i++) { 
            board[counter][i] = temp[i];
        }

        counter++;
    }

    return counter;
}

void print_board(char board[11][11], int size) {
    std::cout << "[0;0H\n"; 
    for(int i = 0; i < size; i++) { 
        for(int j = 0; j < size; j++) {
            if(board[i][j] != wall) {
                std::cout << ":" << board[i][j];
            } else { 
                std::cout << " ";
            }
        }

        std::cout << ":" << std::endl;
    }
}

void solve(char board[11][11], int row, int col, int size, int counter) { 
    if(board[row][col] == wall || board[row][col] == knight) { 
        return;
    }

    board[row][col] = knight; 
    usleep(80000);
    print_board(board, size);

    //4 * row + col

    solve(board, row - 2, col + 1, size, counter); 
    solve(board, row - 1, col + 2, size, counter);
    solve(board, row + 1, col + 2, size, counter);
    solve(board, row + 2, col + 1, size, counter);
    solve(board, row + 2, col - 1, size, counter);
    solve(board, row + 1, col - 2, size, counter);
    solve(board, row - 1, col - 2, size, counter);
    solve(board, row - 2, col - 1, size, counter);
}

int main() { 
    char board[11][11]; 
    int size = input_board("board.dat", board);
    std::cout << "[2J;\n";
    print_board(board, size); 
    solve(board, 2, 2, size, 0);
    return 0; 
}