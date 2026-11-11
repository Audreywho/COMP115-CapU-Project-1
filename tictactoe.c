#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h> 
#include <ctype.h>
#include <time.h>

#define squares 9
#define empty ' '
#define human 'O'
#define computer 'X'


static const int win_lines [8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}
};


void init_board(char board[]) {
    for (int i = 0; i < squares; i++) {
        board[i] = empty;
    }

}

void display_board(const char board[]) {

    char c[squares];

    for (int i = 0; i < squares; i++) {
        c[i] = (board[i] == empty) ? (char) ('0' + i) : board[i];

    }


    printf("\n");

    printf(" %c | %c | %c\n", c[0], c[1], c[2]);

    printf("---+---+---\n");

    printf(" %c | %c | %c\n", c[3], c[4], c[5]);

    printf("---+---+---\n");

    printf(" %c | %c | %c\n", c[6], c[7], c[8]);

    printf("\n");

}


bool is_winner(const char board[], char player) {
    for (int i = 0; i < 8; i++) {
        if (board[win_lines[i][0]] == player && board[win_lines[i][1]] == player && board[win_lines[i][2]] == player) {

            return true;

        }
    }

    return false;

}

char other_player (char player) {
    return (player == human) ? computer : human;
}

int get_human_move (const char board[]) {
    char line [100];
    bool valid = false;
    int move = -1;

    while (!valid) {
        printf("Your turn (%c). Enter a square number (0-8): ", human);

        if (fgets (line, sizeof line, stdin) == NULL) {
            printf("\nInput closed. Goodbye!\n");
            exit(0);
        }

        char *end;
        long value = strtol(line, &end, 10);
        
        while (*end == ' ' || *end == '\t') {
            end++;
        }

        if (end == line || (*end != '\n' && *end != '\0')) {
            printf(" That is not a number. Enter a digit from 0 to 8.\n");
        }
        else if (value < 0 || value > 8) {
            printf(" %ld is out of range. Enter a digit from 0 to 8.\n", value);
        }

        else if (board[value] != empty) {
            printf(" That square is already taken. Choose an empty one.\n");
        }

        else {
            move = (int)value;
            valid = true;
        }
    }

    return move;
}


int get_computer_move(const char board[]) {
    int move;
    do {
        move = rand() % squares;
    }
    while (board[move] != empty);
    return move;
}

void take_turn(char board[], char player){
    int move;

    if (player == human) {
        move = get_human_move(board);
    }
    else {
        printf("Computer (%c) is thinking...\n", computer);
        move = get_computer_move(board);
        printf("Computer (%c) chose square %d.\n", computer, move);
    }
    board[move] = player;
}

void play_game(void) {
    char board[squares];
    char player = human;
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < squares && !game_over; turn++) {
        take_turn(board, player);
        display_board(board);

        if (is_winner(board, player)) {
            if (player == human) {
                printf("Congratulations, you (%c) win!\n", human);
            }

            else {
                printf("The computer (%c) wins. Better luck next time!\n", computer);
            }
            
            game_over = true;

        }

        else {
            player = other_player(player);
        }


    }

    if (!game_over) {
        printf("It's a draw!\n");
    }
}

bool play_again(void) {
    char line[100];

    while (true) {
        printf("\nPlay again? (y = yes, q = quit): ");

        if (fgets(line, sizeof line, stdin) == NULL) {
            return false;
        }
       
        char answer = (char)tolower((unsigned char)line[0]);
        if (answer == 'y') {
            return true;
        }

        if (answer == 'q') {
            return false;
        }

        printf(" Please type y or q.\n");

    }
}

int main(void){
    srand((unsigned int)time (NULL));

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, type the number of an empty square:\n");

do {
    play_game();
}

while (play_again());

    printf("Thanks for playing. Goodbye!\n");
return 0;

}