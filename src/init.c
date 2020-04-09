/*
** EPITECH PROJECT, 2020
** initialisation.c
** File description:
** initialisation
*/

#include "rpg.h"

void init_time_n_clock(game_data_t *game_data)
{
    game_data->clock = sfClock_create();
    game_data->time;
    float seconds;
}

void init_sound(char *filepath, scene_t *scene)
{
    scene->sound->soundbuffer = sfSoundBuffer_createFromFile(filepath);
    scene->sound->sound = sfSound_create();
    sfSound_setBuffer(scene->sound->sound, scene->sound->soundbuffer);
}

void init_and_draw_background(char *filepath, scene_t *scene, game_data_t *game_data)
{
    scene->background.size_background.x = 1;
    scene->background.size_background.y = 1;
    scene->background.sprite = sfSprite_create();
    scene->background.texture = NULL;
    scene->background.texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(scene->background.sprite, scene->background.texture, sfTrue);
    sfSprite_scale(scene->background.sprite, scene->background.size_background);
    sfRenderWindow_drawSprite(game_data->window, scene->background.sprite, NULL);
}

void init_button(game_data_t *game_data, scene_t *scene)
{
    scene->buttons[game_data->i_buttons].sprite = sfSprite_create();
    sfSprite_setPosition(scene->buttons[game_data->i_buttons].sprite, scene->buttons[game_data->i_buttons].pos);
    sfSprite_setTexture(scene->buttons[game_data->i_buttons].sprite, scene->buttons[game_data->i_buttons].texture, sfTrue);
    game_data->i_buttons++;
}

void init_obj(game_data_t *game_data, scene_t *scene)
{
    scene->obj[game_data->i_obj].sprite = sfSprite_create();
    sfSprite_setPosition(scene->obj[game_data->i_obj].sprite, scene->obj[game_data->i_obj].pos);
    sfSprite_setTexture(scene->obj[game_data->i_obj].sprite, scene->obj[game_data->i_obj].texture, sfTrue);
    sfSprite_scale(scene->obj[game_data->i_obj].sprite, (sfVector2f){0.5, 0.5});
    game_data->i_obj++;
}

void draw_sprite(game_data_t *game_data, scene_t *scene)
{
    sfRenderWindow_drawSprite(game_data->window, scene->background.sprite, NULL);
    for (int i = 0; i != scene->nb_buttons; i++)
        sfRenderWindow_drawSprite(game_data->window, scene->buttons[i].sprite, NULL);
    for (int i = 0; i != scene->nb_obj; i++)
        sfRenderWindow_drawSprite(game_data->window, scene->obj[i].sprite, NULL);
}

void play_sound(scene_t *scene)
{
    sfSound_play(scene->sound->sound);
}
