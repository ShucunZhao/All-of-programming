#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int is_dir(char * path){//This function is used for directory check.
	struct stat st;
	if(stat(path, &st)==0){
		if(S_IFDIR & st.st_mode){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		printf("Argument %s stat error.\n", path);
		exit(EXIT_FAILURE);
	}
}

void cp_file(char * src_path, char * tar_path){//This is file writing function.
	char file[1024];
	sprintf(file, "%s/%s", tar_path, src_path);
	FILE * f_src = fopen(src_path, "r");
	//printf("src_path: %s\n", src_path);
	//printf("tar_path:%s\n", tar_path);
	FILE * f_tar = fopen(file, "w+");
	//printf("file: %s\n", file);
	if(f_src==NULL){
		printf("Couldn't track the source path: %s.\n", src_path);
		exit(EXIT_FAILURE);
	}
	if(tar_path==NULL){
		printf("Target creation failed.\n");
		exit(EXIT_FAILURE);
	}
	int c;
	while((c=fgetc(f_src))!=EOF){
	//	printf("contents of f_src: %c\n", c);
		fprintf(f_tar, "%c", c);
	}
	if(fclose(f_src)!=0){
		printf("Source stream %s couldn't close.\n", src_path);
	}
	if(fclose(f_tar)!=0){
		printf("Target stream %s couldn't close.\n", file);
	}
}

void cp_folder(char * src_path, char * tar_path){//This is the core function of the whole program, it would recursively executing when meet folder souce path. 
	//printf("src_path: %s\n", src_path);
	//printf("tar_path: %s\n", tar_path);
	char check_folder[1024];
	sprintf(check_folder,"%s/%s",tar_path,src_path);
	if(!opendir(check_folder)){//If need to write folder file, we should check the wheter target has the same folder(If not, create one.)
		if(mkdir(check_folder,0777)){
			printf("Failed to creat %s folder.\n", check_folder);
		}
	}
	//printf("check_folder:%s\n", check_folder);
	char src_folder[1024];
	struct dirent * filename;
	DIR * dp = opendir(src_path);
	while((filename=readdir(dp))){//The readdir function would traverse the whole path if it's a folder.
		if(!strncmp(filename->d_name,".",1)||!strncmp(filename->d_name,"..",2)){//We should delete the "." and ".." when meet folder(linux characteristic.)
			//printf("Deleted the symbol:'%s' of folder '%s'\n", filename->d_name, src_path);
			continue;
		}
		if(src_path[strlen(src_path)-1]!='/'){
			sprintf(src_folder, "%s/%s", src_path, filename->d_name);
		//	printf("src_folder: %s\n", src_folder);
		}
		else{
			sprintf(src_folder, "%s%s", src_path, filename->d_name);
		}
		//printf("filename->d_name: %s\n", filename->d_name);
		sprintf(src_folder, "%s/%s", src_path, filename->d_name);
		//printf("src_folder(new): %s\n", src_folder);
		if(is_dir(src_folder)){//If meet folder, recursively executing.
			cp_folder(src_folder, tar_path);
		}
		else{
			cp_file(src_folder, tar_path);
		}
	}
}

int main(int argc, char ** argv){
	if(!(is_dir(argv[argc-1]))){
		printf("The last argument %s is not a directory.\n", argv[argc-1]);		
		return EXIT_FAILURE;
	}
	for(int i=1;i<argc-1;i++){
		if(!is_dir(argv[i])){//When meet file argument just copy it.
			cp_file(argv[i], argv[argc-1]);
			continue;
		}
		cp_folder(argv[i], argv[argc-1]);//If meet folder, use folder copy function.
	}
	return EXIT_SUCCESS;
}
