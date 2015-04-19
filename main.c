#include "common.h"
#include "play.h"

int pm_rand=0;
char *pm_filter=NULL;

void foreach_argv(int argc,const char *argv[]){
	for (int i = 0; i < argc; ++i){
		if(strcmp(argv[i],"-r")==0){
			pm_rand=1;
		}else if(strcmp(argv[i],"-s")==0){
			pm_filter=(char *)argv[i+1];
		}
	}
}



int main(int argc, char const *argv[]){
	// fetch_music_file();
	int count=count_music(MUSIC_PATH);
	char *musics[count];
	init_music(musics,MUSIC_PATH);

	char **list=rand_array(musics,count);

	foreach_argv(argc,argv);

	return play(list,count);

	return 0;	
}