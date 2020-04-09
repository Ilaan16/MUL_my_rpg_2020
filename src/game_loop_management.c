/*
** EPITECH PROJECT, 2020
** sprite_management.c
** File description:
** sprite_management
*/

#include "rpg.h"

void mouse_management(game_data_t *game_data, sfEvent *event, button_t *buttons)
{
    sfVector2i pos = {0, 0};

    if (event->mouseButton.button == sfMouseLeft) {
        pos = sfMouse_getPositionRenderWindow(game_data->window);
        game_data->mouse.click = 1;
    }
    game_data->mouse.x = pos.x;
    game_data->mouse.y = pos.y;
}

void event_management(game_data_t *game_data, scene_t *scene)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game_data->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game_data->window);
        }
        //if (game_data->mouse.x >= 1775 && game_data->mouse.x <= 1825 && game_data->mouse.y >= 1000 && game_data->mouse.y <= 1050)
            //sfRenderWindow_close(game_data->window);
        if (event.type == sfEvtMouseButtonPressed) {
            game_data->mouse.click = 0;
            mouse_management(game_data, &event, scene->buttons);
        }
    }
}

void game_loop(game_data_t *game_data, scene_t *scene)
{
    event_management(game_data, &scene[game_data->current_scene]);
    sfRenderWindow_clear(game_data->window, sfBlack);
    draw_sprite(game_data, scene);
    sfRenderWindow_display(game_data->window);
}