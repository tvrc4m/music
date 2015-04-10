#include "common.h"
#include "play.h"

int pm_rand=0;
char *pm_filter=NULL;

void foreach_argv(int argc,char *argv[]){
	for (int i = 0; i < argc; ++i){
		if(strcmp(argv[i],"-r")==0){
			pm_rand=1;
		}else if(strcmp(argv[i],"-s")){
			pm_filter=argv[i];
		}
	}
}



int main(int argc, char const *argv[]){
	// fetch_music_file();
	int count=count_music(MUSIC_PATH);
	char *musics[count];
	init_music(musics,MUSIC_PATH);

	const char *command=argv[1];

	return paly();

	return 0;	
}