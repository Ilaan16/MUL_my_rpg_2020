/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "rpg.h"

typedef struct mouse mouse_t;
typedef struct game_data game_data_t;
typedef struct button button_t;
typedef struct obj obj_t;
typedef struct player player_t;
typedef struct sound sound_t;
typedef struct background background_t;
typedef struct scene scene_t;

struct mouse
{
    int click;
    int x;
    int y;
};

struct game_data
{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfClock *clock;
    sfTime *time;
    mouse_t mouse;
    int width;
    int height;
    int bitsPerPixel;
    int current_scene;
    int i_buttons;
    int i_obj;
    int season;
};

struct button
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rect;
    sfVector2f pos;
    sfVector2f size;
    int status;
    void (*callback)(game_data_t *game_data, obj_t *obj, scene_t **s);
};

struct obj
{
    sfRectangleShape *rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    int type;
    int status;
    void (*callback)(game_data_t *game_data, obj_t *obj, scene_t **s);
};

struct player
{
    sfTexture *texture;
    sfSprite *sprite;
};

struct sound
{
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
};

struct background
{
    sfVector2f size_background;
    sfTexture *texture;
    sfSprite *sprite;
};

struct scene
{
    background_t background;
    sound_t *sound;
    button_t *buttons;
    obj_t *obj;
    player_t player;
    int nb_buttons;
    int nb_obj;
};



#endif /* !STRUCT_H_ */
