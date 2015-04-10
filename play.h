#ifndef PLAY_H
#define PLAY_H

#include "node.h"

int count_music(const char *dir_path);

int init_music(char **musics,const char *dir_path);

node filter_music(char **musics,int count,const char *search);

node rand_music(char **musics,int count,int length);


int rand_play(char **musics,int count,int length);

int filter_play(char **musics,int count,const char *search);

int play(node queue);

#endif