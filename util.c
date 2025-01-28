/**
 * Chess-CLI
 *
 * 1/28/2025
 *
 * util.c
 *
 * Ethan Roe
 */

#include "util.h"

void initBoard(board_template board[][8], unsigned r, char c)
{
    if (r == 0 || r == 7)
    {
        if (c == 'A' || c == 'H')
        {
            board[r][c - 'A'].current = 'R';
        }
        else if (c == 'B' || c == 'G')
        {
            board[r][c - 'A'].current = 'N';
        }
        else if (c == 'C' || c == 'F')
        {
            board[r][c - 'A'].current = 'B';
        }
        else if (c == 'D')
        {
            board[r][c - 'A'].current = 'Q';
        }
        else
        {
            board[r][c - 'A'].current = 'K';
        }

        if (r == 0)
        {
            board[r][c - 'A'].color = WHITE;
        }
        else
        {
            board[r][c - 'A'].color = BLACK;
        }

        board[r][c - 'A'].occupied = true;
        board[r][c - 'A'].square[0] = c;
        board[r][c - 'A'].square[1] = r + '1';
        c = c + 1;
    }
    else if (r == 1 || r == 6)
    {
        if (r == 1)
            board[r][c - 'A'].color = WHITE;
        else
            board[r][c - 'A'].color = BLACK;

        board[r][c - 'A'].current = 'P';
        board[r][c - 'A'].occupied = true;
        board[r][c - 'A'].square[0] = c;
        board[r][c - 'A'].square[1] = r + '1';
        c = c + 1;
    }
    else if (r >= 2 && r <= 5)
    {
        board[r][c - 'A'].color = EMPTY;
        board[r][c - 'A'].current = 'e';
        board[r][c - 'A'].occupied = false;
        board[r][c - 'A'].square[0] = c;
        board[r][c - 'A'].square[1] = r + '1';
        c = c + 1;
    }
    if (c == 'I')
    {
        ++r;
        c = 'A';
    }
    if (r != 8)
        initBoard(board, r, c);
}

void printBoard(board_template board[][8], const char p)
{
    int i, j, max, y = 0, x = 0;

		printf("   \033[1m a   b   c   d   e   f   g   h \033[0m \n");
	for (i = 0; i < (max = (MOS%2)?MOS:(MOS-1)); i++) {
		if(i%2 == true) printf("\033[1m%d\033[0m ", y + 1);
		else printf("  ");
		for (j = 0; j < max; j++) {
			if (!i) { 
				if(!j) printf("\u250F");
				else if(j == (max-1)) printf("\u2513");
				else if(j%2) printf("\u2501\u2501\u2501");
				else if(!(j%2)) printf("\u2533");
			} else if (i == max-1) {
				if(!j)printf("\u2517");
				else if(j == (max-1)) printf("\u251B");
				else if(j%2) printf("\u2501\u2501\u2501");
				else if(!(j%2)) printf("\u253B");
			} else if (i%2) {
				if(!(j%2)) printf("\u2503");
				else {
					/*usleep(3000);
					fflush(stdout);*/
					if (board[y][x].occupied == false)
						printf("   ");
					else {
						if (p == 'a') {
							if (board[y][x].color == BLACK)
								printf(" %s%c%s ", KRED, board[y][x].current, RESET);
							else
								printf(" %s%c%s ", KYEL, board[y][x].current, RESET);
						} else {
							if (board[y][x].current == 'P') {
								if (board[y][x].color == BLACK)
									printf(" \u265F ");
								else
									printf(" \u2659 ");
							} else if (board[y][x].current == 'Q') {
								if (board[y][x].color == BLACK)
									printf(" \u265B ");
								else
									printf(" \u2655 ");
							} else if (board[y][x].current == 'B') {
								if (board[y][x].color == BLACK)
									printf(" \u265D ");
								else
									printf(" \u2657 ");
							} else if (board[y][x].current == 'R') {
								if (board[y][x].color == BLACK)
									printf(" \u265C ");
								else
									printf(" \u2656 ");
							} else if (board[y][x].current == 'N') {
								if (board[y][x].color == BLACK)
									printf(" \u265E ");
								else
									printf(" \u2658 ");
							} else if (board[y][x].current == 'K') {
								if (board[y][x].color == BLACK)
									printf(" \u265A ");
								else
									printf(" \u2654 ");
							}
						}
					}
					x++;
				}
			} else if (!(i%2)) {
				if(!j) printf("\u2523");
				else if(j == (max-1)) printf("\u252B");
				else if(j%2) printf("\u2501\u2501\u2501");
				else if(!(j%2)) printf("\u254B");
			}
		}
		x = 0;
		if(i%2 == true) {
			printf(" \033[1m%d\033[0m", y + 1);
			y++;
		} else
			printf("  ");
		printf("\n");
	}
	printf("   \033[1m a   b   c   d   e   f   g   h \033[0m \n");
	printf("\n");
}
