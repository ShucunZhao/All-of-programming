/*This program is an implementaion of section 13.4 in AOF Chapter 13.
* Whole step:
* 1.Read the input file(Num_of_Std-StdName-ClassNames).
* 2.Generate the unique	course name.
* 3.Count the student info of each class.
* 4.Write the output file which should insert .roster to the file name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

:/*
 * These two struct are used for extract the info from input file,
 * store them into a struct which can count the num of element 
 * and save the info correspond to each
 */
typedef struct student_tag{
	char * stdName;
	char ** className;
	int classNum;
}std_t;

typedef struct roster_tag{
	std_t ** stds;
	int stdNum;
}roster_t;

/* This struct is used for filting the unique class name
 */
typedef struct uniqClass_tag{
	char ** uniqClassName;
	int numUniqClass;
}uniqClass_t;

/* These two are same as above two, used for transform 
 * the std.class info to the calss.std info
 */
typedef struct stdInfo_tag{
	char * className;
	char ** stdName;
	int stdNum;
}stdInfo_t;

typedef struct output_tag{
	stdInfo_t ** stdInfo;
	int classNum;
}output_t;

/* This fuction is to read the input file and generate 
 * the roster_t struct for next step
*/
roster_t * readFile(char * filename){
//void readFile(char * filename){//(This line is for verification)
	//Step1: Read the input file and write the content into a string lines(by getline func).
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "Failed to open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i=0;
	while(getline(&cur, &linecap, f)>=0){
		lines = (char**)realloc(lines, (i+1)*sizeof(char*));
		lines[i] = cur;
		cur = NULL;
		i++;
	}
	free(cur);
	//Step2: Malloc for storing std and class info from lines.
	roster_t * ros = (roster_t*)malloc(sizeof(*ros));//malloc whole roster_t first.
	ros->stdNum = atoi(lines[0]);//First element of input file is stdNum.
	free(lines[0]);//free it
	ros->stds = (std_t**)malloc(ros->stdNum*sizeof(*ros->stds));//malloc each whole stds in roster_t
	//Step3: Use ros->stds struct to save the info we need.
	//In lines: After the first element when we find an number, the std_name is in front of it while
	//class info is in behind.
	int index = 0;//Count the stdNum for mallocing.
	for(size_t j=1; j<i; j++){
		if(strlen(lines[j])==2){//Find the remain  number element.(It contains an '\n' so len is 2 here.)
			if(atoi(lines[j])!=0){
				ros->stds[index] = (std_t*)malloc(sizeof(std_t));
				ros->stds[index]->classNum = atoi(lines[j]);
				free(lines[j]);//free() function is used for free the pointer,
								//All int type to store the value of pointer is
								//couldn't be freed at last, so you must free it
								//after you store the value(by parsing the pointer) like the lines[0] above.
				ros->stds[index]->stdName = lines[j-1];
				ros->stds[index]->className=(char**)malloc(ros->stds[index]->classNum*sizeof(char*));
				for(int n=0; n<ros->stds[index]->classNum; n++){
					//ros->stds[index]->className[n]=(char*)malloc(sizeof(char));//You has malloc in line66 
																				//so shouldn't malloc again(it's different from 
																				//array malloc), you just need to use each mem
																				//you allocted.
					ros->stds[index]->className[n]=lines[j+n+1];//Name index for class
				}
				index++;//Name next index for std.
			}
		}
	}
	free(lines);//free the lines cause we don't need it any more(and the line[j] ones is assigned for ros member.)
	//printf("ros->stdNum:%d\n", ros->stdNum);
	//printf("index:%d\n", index);
	if(ros->stdNum!=index){
		fprintf(stderr, "Num of std is invalid!\n");
		exit(EXIT_FAILURE);
		}
	/*
	//This part is for verification.(Print and free)
	for(int k=0; k<ros->stdNum; k++){
		printf("stdName:%s\n", ros->stds[k]->stdName);
		free(ros->stds[k]->stdName);
		for(int l=0; l<ros->stds[k]->classNum; l++){
			printf("class[%d]:%s\n", l, ros->stds[k]->className[l]);
			free(ros->stds[k]->className[l]);
		}
		free(ros->stds[k]->className);
		free(ros->stds[k]);
	}
	free(ros->stds);
	free(ros);
	//free(lines);*/
	while(fclose(f)!=0){
		fprintf(stderr, "File %s failed to close!\n", filename);
		exit(EXIT_FAILURE);
	}
	return ros;
}

/* To get the unique class by sorting and filting.*/
//void genClassList(roster_t * ros){
uniqClass_t * genClassList(roster_t * ros){
	char * curClass = ros->stds[0]->className[0];
	uniqClass_t * uniqClass = (uniqClass_t*)malloc(sizeof(*uniqClass));
	uniqClass->numUniqClass = 1;
	uniqClass->uniqClassName = (char**)malloc(sizeof(char*));
	uniqClass->uniqClassName[0] = curClass;
	int flag;//This flag is used for checking if there has same element of the whole calss set.
	for(int k=0; k<ros->stdNum; k++){
		for(int l=0; l<ros->stds[k]->classNum; l++){
			flag = 0;
			for(int m=0; m<uniqClass->numUniqClass; m++){
				if(strcmp(ros->stds[k]->className[l], uniqClass->uniqClassName[m])==0){
					flag = 1;//If find the same one, jump to next element.
					continue;
				}
			}
			if(flag){//If find the same one, jump to next element.
				continue;
			}
			uniqClass->numUniqClass++;
			curClass = ros->stds[k]->className[l];
			//Cause you has malloc at the begin of the genClassList, so use realloc here.
			uniqClass->uniqClassName = (char**)realloc(uniqClass->uniqClassName, (uniqClass->numUniqClass)*sizeof(char*));
			uniqClass->uniqClassName[uniqClass->numUniqClass-1] = curClass;
		}
	}
	for(int i=0; i<uniqClass->numUniqClass; i++){//(Verification: Print the uniuqe classes)
		printf("uniqClass->uniqClassName[%d]:%s\n", i, uniqClass->uniqClassName[i]);
		//free(uniqClass->uniqClassName[i]);
	}
	//free(uniqClass);
	return uniqClass;
}

/*To transform the information from student-class to class-student*/
output_t * infoToStd(roster_t * ros, uniqClass_t * uniqClass){
//void infoToStd(roster_t * ros, uniqClass_t * uniqClass){//(verification)
	output_t * output = (output_t*)malloc(sizeof(*output));
	output->classNum = uniqClass->numUniqClass; 
	output->stdInfo = (stdInfo_t**)malloc(output->classNum*sizeof(stdInfo_t*));
	for(int i=0; i<output->classNum; i++){
		output->stdInfo[i] = (stdInfo_t*)malloc(sizeof(stdInfo_t));
		output->stdInfo[i]->className = uniqClass->uniqClassName[i];
		output->stdInfo[i]->stdName = (char**)malloc(sizeof(char*));//Why??
		output->stdInfo[i]->stdNum = 0;
		int index = 0;
		for(int k=0; k<ros->stdNum; k++){
			for(int l=0; l<ros->stds[k]->classNum; l++){
				if(strcmp(ros->stds[k]->className[l], output->stdInfo[i]->className)==0){
					output->stdInfo[i]->stdNum++;
					if(output->stdInfo[i]->stdNum>1){
						output->stdInfo[i]->stdName = (char**)realloc(output->stdInfo[i]->stdName, output->stdInfo[i]->stdNum*sizeof(char*));
					}
					output->stdInfo[i]->stdName[index] = ros->stds[k]->stdName;
					index++;
				}
			}
		}
	}
	/*(verification)
	for(int j=0; j<output->classNum; j++){
		printf("Class:%s\n", output->stdInfo[j]->className);
		for(int k=0; k<output->stdInfo[j]->stdNum; k++){
			printf("std[%d]:%s\n", k, output->stdInfo[j]->stdName[k]);
		}
		free(output->stdInfo[j]->stdName);
		free(output->stdInfo[j]);
	}
	free(output->stdInfo);
	free(output);*/
	return output;
}	

/*To strip the '\n' from each class name to generate the output filename*/
void stripNewline(char * str){
	char * p = strchr(str, '\n');
	if(p!=NULL){
		*p='\0';
	}
}

/*Add prefix to gengerate the filename*/
char * makeFilename(char * prefix){
	stripNewline(prefix);
	const char * suffix = ".roster.txt";
	unsigned len = strlen(prefix)+strlen(suffix)+1;
	char * ans = (char*)malloc(len*sizeof(char));
	snprintf(ans, len, "%s%s", prefix, suffix);
	return ans;
}

/*Write the output file*/
void writeFile(output_t * output){
	for(int i=0; i<output->classNum; i++){
		char * filename = makeFilename(output->stdInfo[i]->className);
		FILE * f = fopen(filename, "w+");
		if(f==NULL){
			fprintf(stderr, "Failed to open %s\n", filename);
			exit(EXIT_FAILURE);
		}
		for(int j=0; j<output->stdInfo[i]->stdNum; j++){
			fprintf(f, "%s", output->stdInfo[i]->stdName[j]);
		}
		while(fclose(f)!=0){
			fprintf(stderr, "File %s failed to close!\n", filename);
			exit(EXIT_FAILURE);
		}
		free(filename);
	}
}

/*Free all memory(not repeated) at last*/
void freeMem(roster_t * ros, uniqClass_t * uniqClass, output_t * output){
	//First: Free the output part memory.
	for(int j=0; j<output->classNum; j++){
		printf("Class:%s\n", output->stdInfo[j]->className);
		for(int k=0; k<output->stdInfo[j]->stdNum; k++){
			printf("std[%d]:%s\n", k, output->stdInfo[j]->stdName[k]);
		}
		free(output->stdInfo[j]->stdName);
		free(output->stdInfo[j]);
	}
	free(output->stdInfo);
	free(output);
	//Second: Free the roster part memory and the related memory like uniqClass->uniqClassName[i] would be
	//freed together.
	for(int k=0; k<ros->stdNum; k++){
		printf("stdName:%s\n", ros->stds[k]->stdName);
		free(ros->stds[k]->stdName);
		for(int l=0; l<ros->stds[k]->classNum; l++){
			printf("class[%d]:%s\n", l, ros->stds[k]->className[l]);
			free(ros->stds[k]->className[l]);
		}
		free(ros->stds[k]->className);
		free(ros->stds[k]);
	}
	free(ros->stds);
	free(ros);
	//Third: Free the uniqClass part memory.
	free(uniqClass->uniqClassName);
	free(uniqClass);
}

int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "Command line argument invalid!\n");
		return EXIT_FAILURE;
	}
	//readFile(argv[1]);//(verification)
	roster_t * ros = readFile(argv[1]);
	uniqClass_t * uniqClass = genClassList(ros);
	output_t * output = infoToStd(ros, uniqClass);
	writeFile(output);
	freeMem(ros, uniqClass, output);
	return EXIT_SUCCESS;
}
