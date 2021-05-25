/*
** EPITECH PROJECT, 2021
** perfect_maze.c
** File description:
** create a perfect maze
*/

#include "generator.h"
#include <stdlib.h>
#include <stdio.h>

maybe_vector_t verify_neighbour(maze_t *maze, vector_t pos)
{
    vector_t dirs[4];
    int count = 0;

    if (pos.y - 2 >= 0 && maze->tab[pos.y - 2][pos.x] == 'X')
        dirs[count++] = (vector_t) {0, -1};
    if (pos.y + 2 <= maze->line - 1 && maze->tab[pos.y + 2][pos.x] == 'X')
        dirs[count++] = (vector_t) {0, 1};
    if (pos.x + 2 <= maze->col - 1 && maze->tab[pos.y][pos.x + 2] == 'X')
        dirs[count++] = (vector_t) {1, 0};
    if (pos.x - 2 >= 0 && maze->tab[pos.y][pos.x - 2] == 'X')
        dirs[count++] = (vector_t) {-1, 0};
    if (count == 0)
        return (maybe_vector_t) {(vector_t) {0, 0}, false};
    return (maybe_vector_t) {dirs[rand() % count], true};
}

void add_space(maze_t *maze, vector_t *pos, vector_t dir)
{
    maze->tab[pos->y + dir.y][pos->x + dir.x] = ' ';
    if (dir.x == 1)
        maze->tab[pos->y + dir.y * 2][pos->x + dir.x * 2] = '>';
    if (dir.x == -1)
        maze->tab[pos->y + dir.y * 2][pos->x + dir.x * 2] = '<';
    if (dir.y == 1)
        maze->tab[pos->y + dir.y * 2][pos->x + dir.x * 2] = 'v';
    if (dir.y == -1)
        maze->tab[pos->y + dir.y * 2][pos->x + dir.x * 2] = 'A';
    pos->x += dir.x * 2;
    pos->y += dir.y * 2;
}

void backtrack(maze_t *maze, vector_t *pos)
{
    const char cell = maze->tab[pos->y][pos->x];
    vector_t dir;

    if (cell == '>')
        dir = (vector_t) {-1, 0};
    if (cell == '<')
        dir = (vector_t) {1, 0};
    if (cell == 'A')
        dir = (vector_t) {0, 1};
    if (cell == 'v')
        dir = (vector_t) {0, -1};
    maze->tab[pos->y][pos->x] = '*';
    maze->tab[pos->y + dir.y][pos->x + dir.x] = '*';
    pos->x += dir.x * 2;
    pos->y += dir.y * 2;
}

void create_path(maze_t *maze)
{
    vector_t final_pos = {maze->line, maze->col};
    vector_t pos = (vector_t) {0, 0};
    maybe_vector_t dir = verify_neighbour(maze, pos);

    while (pos.x != 0 || pos.y != 0 || dir.is_defined) {
        if (!dir.is_defined) {
            backtrack(maze, &pos);
        } else
            add_space(maze, &pos, dir.vec);
        dir = verify_neighbour(maze, pos);
    }
}

void display_maze(maze_t *maze)
{
    int i = 0;

    while (i < maze->line) {
        if (i == maze->line - 1) {
            printf("%s", maze->tab[i]);
        } else {
            printf("%s\n", maze->tab[i]);
        }
        i++;
    }
}
