#include <dirent.h>
#include <regex.h>
#include <time.h>
#include "common.h"
#include "play.h"

int count_music(const char *dir_path){
	static int count=0;
	DIR *dir;
	struct dirent *entry;
	if((dir=opendir(dir_path))==NULL){
		perror("opendir");
		exit(-1);
	}
	while((entry=readdir(dir))!=NULL){
		if(start_with(entry->d_name,".")!=0){
			if(entry->d_type==8 && end_with(entry->d_name,".wav")==0){
				count+=1;
			}else if(entry->d_type==4){
				char *new_dir=(char*)calloc(sizeof(char),strlen(MUSIC_PATH)+strlen(entry->d_name));
				sprintf(new_dir,"%s%s",MUSIC_PATH,entry->d_name);
				count_music((const char*)new_dir);
			}
		}
	}
	closedir(dir);
	return count;
}

int init_music(char **musics,const char *dir_path){
	static int cur=0;
	DIR *dir;
	struct dirent *entry;
	if((dir=opendir(dir_path))==NULL){
		printf("指定的路径%s错误\n", dir_path);
		exit(-1);
	}
	while((entry=readdir(dir))!=NULL){
		if (start_with(entry->d_name,".")!=0){
			if(entry->d_type==8 && end_with(entry->d_name,".wav")==0){
				cur+=1;
				char *full_path=(char *)calloc(sizeof(char),strlen(dir_path)+1+strlen(entry->d_name));
				sprintf(full_path,"%s/%s",dir_path,entry->d_name);
				musics[cur]=full_path;
			}else if(entry->d_type==4){
				char *new_dir=(char*)calloc(sizeof(char),strlen(dir_path)+strlen(entry->d_name));
				sprintf(new_dir,"%s%s",dir_path,entry->d_name);
				init_music(musics,(const char*)new_dir);
			}
		}
	}
	closedir(dir);
	return 0;
}

node padding_music(char **musics,int count){
	node queue=node_init("padding music");
	for(int i=1;i<count;i++){
		node_push(queue,musics[i]);
	}
	return queue;
}

node filter_music(char **musics,int count,const char *search){
	node queue=node_init("filter_music");
	regex_t reg;
	regcomp(&reg,search,REG_EXTENDED | REG_NOSUB);
	for(int i=1;i<count;i++){
		if(regexec(&reg, musics[i], 1, NULL, 0)==0){
			node_push(queue,musics[i]);
		}
	}
	regfree(&reg);
	return queue;
}