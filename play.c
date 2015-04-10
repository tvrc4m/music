#include "play.h"
#include "common.h"

extern int pm_rand;
extern char *pm_filter;

int rand_play(char **musics,int count,int length){
	printf("%s\n", pm_filter);
	node queue=rand_music(musics,count,length);
	return play(queue);
}

int filter_play(char **musics,int count,const char *search){
	node queue=filter_music(musics,count,search);
	return play(queue);
}

int play(char **musics,int count){
	char *path;
	node queue;
	if(pm_filter==NULL){
		queue=filter_music(musics,count,pm_filter);
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