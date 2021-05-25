/*
** EPITECH PROJECT, 2021
** create_maz.c
** File description:
** allocate and create maze
*/

#include "generator.h"
#include <stdlib.h>

void allocate_maze(maze_t *maze)
{
    int i = 0;
    int j = 0;

    maze->tab = malloc(sizeof(char *) * (maze->line + 1));

    for (; i < maze->line; i++)
        maze->tab[i] = malloc(sizeof(char) * (maze->col + 2));
}

void create_maze(maze_t *maze)
{
    int i = 0;

    for (; i < maze->line; i++) {
        for (int j = 0; j < maze->col; j++) {
            maze->tab[i][j] = 'X';
        }
        maze->tab[i][maze->col] = '\0';
    }
    maze->tab[0][0] = '*';
    maze->tab[i] = NULL;
}
