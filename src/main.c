/*
** EPITECH PROJECT, 2019
** Main
** File description:
** My_Defender
*/

#include "rpg.h"

int main(int argc, char **argv)
{
    scene_t *scene = malloc(sizeof(scene_t) * 4);
    game_data_t game_data;
    button_t buttons;
    game_data.current_scene = 0;
    game_data.season = my_getnbr(argv[1]);

    initialise_window(&game_data);
    new_scene(&game_data, &scene[game_data.current_scene]);
    /*if (argc != 1) {
        my_putstr("/my_rpg: bad arguments: ");
        my_put_nbr(argc - 1);
        my_putstr("given but");
        my_putstr("1 is required\nretry with -h\n");
        return (84);
    }*/
    while (sfRenderWindow_isOpen(game_data.window)) {
        game_loop(&game_data, scene);
    }
    //free(scene);
    //free(scene->buttons);
}
