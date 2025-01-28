/**
 * Chess-CLI
 *
 * 1/28/2025
 *
 * util.h
 *
 * Ethan Roe
 */

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#ifndef UTIL_H_
#define UTIL_H_

#define WHITE 2
#define BLACK 1
#define EMPTY 0

#define MOS 17
# define KRED  "\x1B[31m"
# define KYEL  "\x1B[33m"
# define RESET "\033[0m"

// struct for default board template
typedef struct board_template
{
    char current;
    char square[2];
    bool occupied;
    int color;
} board_template;

typedef enum KingStatus
{
    check,
    checkmate,
    clear
} KingStatus;

//
// function prototypes for main lib
//

void initBoard(board_template board[][8], unsigned r, char c);

void printBoard(board_template board[][8], const char p);

#endif