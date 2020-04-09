/*
** EPITECH PROJECT, 2020
** set_ressources
** File description:
** set_ressources
*/

#include "rpg.h"

void set_background(char *file, game_data_t *game_data, scene_t *scene)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 50);
    filepath = goto_quote2(i, file, filepath);
    init_and_draw_background(filepath, scene, game_data);
    free(filepath);
}

void set_button(char *file, game_data_t *game_data, scene_t *scene, int y)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 51);
    filepath = goto_quote2(i, file, filepath);
    i = goto_quote(i, file);
    scene->buttons[y].pos.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].pos.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].size.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].size.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->buttons[y].texture = sfTexture_createFromFile(filepath, NULL);
    init_button(game_data, scene);
    free(filepath);
}

void set_obj(char *file, game_data_t *game_data, scene_t *scene, int y)
{
    int i = 0;
    char *filepath = malloc(sizeof(char) * 51);
    filepath = goto_quote2(i, file, filepath);
    i = goto_quote(i, file);
    scene->obj[y].pos.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].pos.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].size.x = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].size.y = my_getnbr(file + i);
    i = goto_coma(i, file);
    scene->obj[y].texture = sfTexture_createFromFile(filepath, NULL);
    init_obj(game_data, scene);
    free(filepath);
}

void set_sound(scene_t *scene, char *file)
{
    char *filepath = malloc(sizeof(char) * 51);
    filepath = goto_quote2(0, file, filepath);
    init_sound(filepath, scene);
    free(filepath);
}

void set_music(scene_t *scene, char *file)
{
    char *filepath = malloc(sizeof(char) * 51);
    filepath = goto_quote2(0, file, filepath);
    init_sound(filepath, scene);
    play_sound(scene);
}