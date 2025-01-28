/**
 * Chess-CLI
 *
 * 1/28/2025
 *
 * main.c
 *
 * Ethan Roe
 */

#include "util.h"

int main(int argc, char *argv[])
{
    board_template board[8][8];

    initBoard(board, 0, 'A');
    printBoard(board, 'a');
}