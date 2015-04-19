
#include "common.h"

int start_with(char *src,char *start){
	int len=strlen(src),ls=strlen(start);
	if(len<ls) return 1;
	for(int i=0;i<ls;i++,src++,start++){
		if(*src!=*start) return 1;
	}
	return 0;
}

int end_with(char *src,char *end){
	char *temp=src+strlen(src)-strlen(end);
	return strcmp(temp,end);
}

char *strrep(char *src,char *findstr,char *repstr){
	int len=strlen(src),findlen=strlen(findstr),replen=strlen(repstr);
	char *dest;
	if(len<findlen){
		dest=(char*)malloc(sizeof(char)*len);
		return dest;
	}
	dest=(char *)calloc(sizeof(char),len*replen);
	for(int i=0;i<len;i++){
		if(i+findlen<=len){
			char *temp=(char*)calloc(sizeof(char),replen);
			temp=strncpy(temp,src,findlen);
			// printf("%s\n", temp);
			if(strcmp(temp,findstr)==0){
				strcat(dest,repstr);
				src+=findlen;
				i+=findlen-1;
			}else{
				// printf("%s\n", &*src);
				char *name=(char*)malloc(sizeof(char));
				sprintf(name,"%c",*src);
				strcat(dest,name);
				free(name);
				// printf("%s\n", dest);
				src++;
			}
		}else{
			char *name=(char*)malloc(sizeof(char));
			sprintf(name,"%c",*src);
			strcat(dest,name);
			free(name);
			src++;
		}
	}

	return dest;
}

char **rand_array(char **array,int count){
	int recursive=count*10;
	while(recursive--){
		srand(time(NULL)*recursive);
		int f=rand()%count;
		srand(time(NULL)*recursive*f);
		int s=rand()%count;
		char *temp=array[f];
		array[f]=array[s];
		array[s]=temp;
	}
	return array;
}

char **array_slice(char **array,int count,int length){
	if(count<=length) return array;
	char **newarray=(char**)calloc(sizeof(char*),length);
	for(int i=0;i<length;i++){
		newarray[i]=array[i];
	}
	return newarray;
}

void swap(void *v1,void *v2){
	void *temp=v1;
	printf("--%s\n", v1);
	v1=v2;
	v2=temp;
	printf("--%s\n", v1);

}