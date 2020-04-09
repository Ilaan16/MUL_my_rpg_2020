/*
** EPITECH PROJECT, 2020
** window.c
** File description:
** window
*/

#include "rpg.h"

void openwindow(game_data_t *game_data)
{
    game_data->width = 1920;
    game_data->height = 1080;
    game_data->bitsPerPixel = 32;
    sfVideoMode mode = {game_data->width, game_data->height, game_data->bitsPerPixel};
    game_data->window = sfRenderWindow_create(mode, "My_RPG", sfDefaultStyle, NULL);
}

void initialise_window(game_data_t *game_data)
{
    openwindow(game_data);
    sfRenderWindow_setFramerateLimit(game_data->window, 60);
    sfRenderWindow_setMouseCursorVisible(game_data->window, sfTrue);
}