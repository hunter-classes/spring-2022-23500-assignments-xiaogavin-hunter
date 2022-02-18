#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

char knight = 'N';
char wall = '#';
char empty = ' ';
char visited = '.';
int counter = 0;

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
            std::cout << board[i][j];
        }

        std::cout << std::endl;
    }
}

void print_board(int board[11][11], int size) {
    std::cout << "[0;0H\n"; 
    for(int i = 0; i < size; i++) { 
        for(int j = 0; j < size; j++) {
            if(board[i][j] == -1) { 
                std::cout << " ";
            } else if(board[i][j] < 10) { 
                std::cout << ": " << board[i][j];
            } else { 
                std::cout << ":" << board[i][j];
            }
        }

        std::cout << std::endl;
    }
}

void solve(char board[11][11], int row, int col, int size, int solu[11][11], bool &solved) { 
    if(counter + 1 == 25) { 
        std::cout << "ran";
        solved = true;
        return;
    }

    if(board[row][col] == knight || board[row][col] == wall || board[row][col] == visited) { 
        return;
    }

    board[row][col] = knight;
    solu[row][col] = counter; 
    usleep(100000);

    print_board(solu, size);
    // print_board(board, size);
    counter++;
    std::cout << counter;

    if(!solved) solve(board, row + 2, col + 1, size, solu, solved);
    if(!solved) solve(board, row + 1, col + 2, size, solu, solved);
    if(!solved) solve(board, row + 1, col - 2, size, solu, solved);
    if(!solved) solve(board, row + 2, col - 1, size, solu, solved);
    if(!solved) solve(board, row - 1, col + 2, size, solu, solved);
    if(!solved) solve(board, row - 2, col + 1, size, solu, solved);
    if(!solved) solve(board, row - 2, col - 1, size, solu, solved); 
    if(!solved) solve(board, row - 1, col - 2, size, solu, solved);


    if(!solved) { 
        board[row][col] = visited;
        counter--;
        solu[row][col] = -1;
    }
    // if(!solved) board[row][col] = ' ';
    
}

int main() { 
    char board[11][11]; 
    int solu[11][11];

    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) { 
            solu[i][j] = -1;
        }
    }

    int size = input_board("board.dat", board);
    std::cout << "[2J;\n";
    print_board(board, size); 
    bool solved = false;
    solve(board, 2, 2, size, solu, solved);
    // print_board(board, size);
    print_board(solu, size);
    return 0; 
}