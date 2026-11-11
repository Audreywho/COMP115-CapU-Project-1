# COMP115-CapU-Project-1


            Tic-Tac-Toe VS Computer

You are playing as 'O' while the computer plays as 'X'.

The computer will pick at random a legal move.

To run and compile enter in terminal: gcc tictactoe.c -o tictactoe 
             Return and follow it by: ./tictactoe




To play:



The board has 9 squares numbered 0 to 8.

Whatever number you type in the terminal through 0-8, you will place your symbol on it: 'O'.

The computers placements is indentifiable by the symbol 'X'.

The objective of the game is to win by being the first get 3 in a row: vertically, horrizontally or diagonally (there is no primary order of how they need to be placed).  

If the computer has already place their symbol on it, or you yourself, the teriminal will notify you to pick another square.

After each game either type 'y', to play again or 'q', to quit.




Function Purposes:



init_board -> Set all 9 squares to empty
display_board	-> Print the board (uses char c[9])
is_winner	-> Return true if a player has three in a row
other_player -> Return the opposite symbol
get_human_move	-> Ask until the user enters a valid square
get_computer_move	-> Pick a random empty square
take_turn	-> Let the current player make one move
play_game	-> Play one complete game
play_again	-> Ask whether to play another game




Possible improvments:



Building a program that can predict and assess the best next course of action using pattern recognition, as currently it is only programmed to pick a square at random. To extend to this, a feature that allows you to select the difficulty could also be added: easy setting could be the randomly selected number and hard could be the program that ditects patterns to win. 
