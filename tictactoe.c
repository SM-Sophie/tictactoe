#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



struct player{
    char symbol;
    bool active;
    bool isHuman;
};

char board[3][3];

void initBoard(){
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            board[i][j] = ' ';
            
        }
        
    }
}

void printBoard(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%c] ", board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(struct player p){
    int r;
    int c;
    if (p.isHuman == true){
    while (1){
        printf("Wähle ein Feld\n");
        scanf("%d %d", &r, &c);
        if (r < 0 || r > 2 || c < 0 || c > 2) {
            printf("Ungültige Eingabe! Werte müssen zwischen 0 und 2 liegen.\n\n");            
            continue;
        }
        if (board[r][c] != ' '){
            printf("Bitte wähle ein anderes Feld\n\n");
            continue;
        }
   
        board[r][c] = p.symbol;
        break;
    
    }}
    else{
            while (1) {
                printf("Der Bot setzt einen Zug...\n");
                r = rand() % 3;
                c = rand() % 3;
                if (board[r][c] == ' ') {
                    board[r][c] = p.symbol;
                    break;
                }
    }
}}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}



bool isBoardFull(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}



struct player player1 = {'X', true, true};
struct player player2 = {'O', false,true};


int main() {

    char wahl;


    while (1) {
        printf("1 oder 2 Spieler? (1/2)\n");
        wahl = getchar();  // Ein Zeichen einlesen

        // Eingabepuffer leeren (um Enter-Taste zu entfernen)
        while (getchar() != '\n');

        if (wahl == '1' || wahl == '2') {

            break;  // Falls die Eingabe gültig ist, verlasse die Schleife
        }

        printf("Ungültige Eingabe! Bitte erneut versuchen.\n");
    }

    if (wahl == '1') {
        player2.isHuman = false;
    }
    initBoard();
    while (!isBoardFull()&& !checkWin()) {
        printBoard();
        if (player1.active){
            makeMove(player1);
            if (checkWin()) {
                printBoard();
                printf("Spieler X hat gewonnen!\n");
                return 0;
            }
            player1.active = false;
            player2.active = true;
        }
        else{
            makeMove(player2);
            if (checkWin()) {
                printBoard();
                printf("Spieler %c hat gewonnen!\n", player2.symbol);
                return 0;
            }
            player1.active = true;
            player2.active = false;
        }

    }
        printf("Unentschieden!\n");
        return 0;
    }

    
