#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "node.h"

#define MUSIC_PATH "/music/"

#define COUNT(x) sizeof(x)/sizeof(x[0])

int start_with(char *src,char *start);

int end_with(char *src,char *end);

char *strrep(char *src,char *findstr,char *restr);

char **rand_array(char **array,int count);

char **array_slice(char **array,int count,int length);

void swap(void *v1,void *v2);

#endif