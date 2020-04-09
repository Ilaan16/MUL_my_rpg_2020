/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** defender.h
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"

int open_file(char *filepath);
int goto_coma(int i, char *file);
char *goto_quote2(int i, char *file, char *filepath);
int goto_quote(int i, char *file);

void mouse_management(game_data_t *game_data, sfEvent *event, button_t *buttons);
void event_management(game_data_t *game_data, scene_t *scene);
void game_loop(game_data_t *game_data, scene_t *scene);

void init_time_n_clock(game_data_t *game_data);
void init_sound(char *filepath, scene_t *scene);
void init_and_draw_background(char *filepath, scene_t *scene, game_data_t *game_data);
void init_button(game_data_t *game_data, scene_t *scene);
void init_obj(game_data_t *game_data, scene_t *scene);
void draw_sprite(game_data_t *game_data, scene_t *scene);
void play_sound(scene_t *scene);

char *get_scene_filepath(game_data_t *game_data);
void get_nb_buttons(scene_t *scene, game_data_t *game_data);
void get_nb_obj(scene_t *scene, game_data_t *game_data);
void new_scene(game_data_t *game_data, scene_t *scene);

void set_background(char *file, game_data_t *game_data, scene_t *scene);
void set_button(char *file, game_data_t *game_data, scene_t *scene, int y);
void set_obj(char *file, game_data_t *game_data, scene_t *scene, int y);
void set_sound(scene_t *scene, char *file);
void set_music(scene_t *scene, char *file);

void openwindow(game_data_t *game_data);
void initialise_window(game_data_t *game_data);

#endif /* !DEFENDER_H_ */
