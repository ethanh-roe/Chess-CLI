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
#include <string.h>

#ifndef UTIL_H_
#define UTIL_H_

#define WHITE 2
#define BLACK 1
#define EMPTY 0

// struct for default board template
typedef struct board_template {
    char current;
    char currentSquare[2];
    bool occupied;
    int color;
} board_template;

typedef enum KingStatus {
    check,
    checkmate,
    clear
} KingStatus;

//
// function prototypes for main lib
//

void initBoard(board_template board[][8], unsigned r, char c);

#endif