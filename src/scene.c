/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** initialisation_sprites.c
*/

#include "rpg.h"
#include "stdio.h"

char *get_scene_filepath(game_data_t *game_data)
{
    char *filepath = malloc(sizeof(char) * 20);
    filepath[0] = '\0';
    filepath = my_strcat(filepath, "./scene/ .txt\0");
    filepath[8] = game_data->season + 48;
    return (filepath);
}

void get_nb_buttons(scene_t *scene, game_data_t *game_data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(game_data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_buttons = 0;
    size_t size = 1;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '0')
            scene->nb_buttons++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void get_nb_obj(scene_t *scene, game_data_t *game_data)
{
    int return_getline = 0;
    char *scene_filepath = get_scene_filepath(game_data);
    int fd = open_file(scene_filepath);
    char type[51];
    scene->nb_obj = 0;
    size_t size = 1;
    int y;

    y = read(fd, type, 50);
    while (y != 0) {
        if (type[0] == '1')
            scene->nb_obj++;
        y = read(fd, type, 50);
    }
    close(fd);
}

void new_scene(game_data_t *game_data, scene_t *scene)
{
    int fd;
    char *file = malloc(sizeof(char) * 51);
    int y = 0;
    get_nb_buttons(scene, game_data);
    get_nb_obj(scene, game_data);
    scene->buttons = malloc(sizeof(button_t) * scene->nb_buttons);
    scene->obj = malloc(sizeof(obj_t) * scene->nb_obj);
    game_data->i_buttons = 0;
    game_data->i_obj = 0;

    fd = open_file(get_scene_filepath(game_data));
    y = read(fd, file, 50);

    while (y != 0) {
        if (file[0] == '0' && game_data->i_buttons < scene->nb_buttons) {
            set_button(file, game_data, scene, game_data->i_buttons);
        }
        if (file[0] == '1' && game_data->i_obj < scene->nb_obj)
            set_obj(file, game_data, scene, game_data->i_obj);
        if (file[0] == '2')
            set_background(file, game_data, scene);
        if (file[0] == '3')
            set_sound(scene, file);
        if (file[0] == '4')
            set_music(scene, file);
        y = read(fd, file, 50);
    }
    free(file);
}