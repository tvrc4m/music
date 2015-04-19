#ifndef PLAY_H
#define PLAY_H

#include <dirent.h>
#include "node.h"

int count_music(const char *dir_path);

int init_music(char **musics,const char *dir_path);

node filter_music(char **musics,int count,const char *search);

node rand_music(char **musics,int count,int length);

node padding_music(char **musics,int count);

int play(char **musics,int count);

#endif