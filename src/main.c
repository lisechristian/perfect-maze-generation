/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function generator dante's star
*/

#include "generator.h"
#include <string.h>

void preset(maze_t *maze, char **av)
{
    maze->line = my_getnbr(av[2]);
    maze->col = my_getnbr(av[1]);
}

void execution(maze_t *maze, char **av)
{
    preset(maze, av);
    allocate_maze(maze);
    create_maze(maze);
    create_path(maze);
    if ((my_getnbr(av[1]) % 2) == 0)
        maze->tab[maze->line - 1][maze->col - 1] = '*';
    if ((my_getnbr(av[2]) % 2) == 0)
        maze->tab[maze->line - 1][maze->col - 1] = '*';
    if ((my_getnbr(av[1]) % 2) == 0 && (my_getnbr(av[2]) % 2) == 0)
        maze->tab[maze->line - 1][maze->col - 2] = '*';
    display_maze(maze);
}

int main(int ac, char **av)
{
    maze_t maze;

    if (ac != 3 && ac != 4)
        return 84;
    if (ac == 3)
        execution(&maze, av);
    if (ac == 4 && (strcmp(av[3], "perfect") == 0)) {
        execution(&maze, av);
    }
    return (0);
}
