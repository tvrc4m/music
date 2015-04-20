#include "play.h"
#include "common.h"

extern int pm_rand;
extern char *pm_filter;
extern int pm_length;

int play(char **musics,int count){
	char *path;
	char *playlist[count];
	node queue;
	if(pm_filter!=NULL){
		queue=filter_music(musics,count,pm_filter);
	}else{
		char **list=array_slice(musics,count,pm_length);
		queue=padding_music(list,pm_length);
		free(list);
	}

	while((path=node_pop(queue))!=NULL){
		char afplay[255];
		memset(afplay,sizeof(afplay),0);
		sprintf(afplay,"afplay -q 1 %s",strrep(strrep(strrep(path," ","\\ "),"(","\\("),")","\\)"));
		printf("%s\n", afplay);
		system(afplay);
		// printf("%s\n", afplay);
	}
	node_free(queue);
	return 0;
}