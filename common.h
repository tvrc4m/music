#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include "node.h"

#define MUSIC_PATH "/music/"

#define COUNT(x) sizeof(x)/sizeof(x[0])

typedef void *(*read_dir_callback)(char *dir_path,struct dirent *entry);

int start_with(char *src,char *start);

int end_with(char *src,char *end);

char *strrep(char *src,char *findstr,char *restr);



#endif