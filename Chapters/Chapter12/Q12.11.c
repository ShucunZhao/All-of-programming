#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_tag{
	double ** values;
	size_t rows;
	size_t cols;
}matrix_t;

/*
 * This function can be used for much situation.
 * @param left - Left matrix
 * @param right - Righr matrix
 * return matrix_t - Multiply result: left*right
 */
matrix_t * multiply(matrix_t * left, matrix_t * right){
	if(left->cols!=right->rows){
		fprintf(stderr, "Two matrix couldn't multiply!\n");
		exit(EXIT_FAILURE);
	}
	matrix_t * result = (matrix_t*)malloc(sizeof(*result));
	result->rows = left->rows;
	result->cols = right->cols;
	//Allocate the memory for storing double array.(Core step, or your struct cannot store data correctly.)
	result->values = (double**)malloc(result->rows*sizeof(double*));
	//This step is the core algorithm of multiply of two matrix.
	for(size_t x=0;x<result->rows;x++){
		result->values[x] = (double*)malloc(result->cols*sizeof(double));
	}
	for(int i=0;i<result->rows;i++){
		for(int j=0;j<result->cols;j++){
			result->values[i][j]=0;
			for(int k=0;k<left->cols;k++){
				result->values[i][j]+=left->values[i][k]*right->values[k][j];
			}
		}
	}
	return result;
}

/*
 * Read the matrix from the command line argument files which is
 * combined with width(column), height(row) and matrix data.
 * @param filename - The input file stream.
 * return matrix_t - Convert result from reading string format into struct.
 */ 
matrix_t * readMatrix(const char * filename){
	FILE * f = fopen(filename, "r");
	if(f==NULL){
		fprintf(stderr, "The file %s is invalid!\n", filename);
		exit(EXIT_FAILURE);
	}
	//Step1: Read each line of the input file stream.(Reference from video12.7)
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i = 0;
	while(getline(&cur,&linecap,f)>=0){
		lines = realloc(lines, (i+1)*sizeof(*lines));
		lines[i] = cur;
		cur = NULL;
		i++;
	}
	free(cur);
	//Step2: Information extraction: Convert the string into struct
	matrix_t * Mat = (matrix_t*)malloc(sizeof(*Mat));
	Mat->cols = atoi(&lines[0][0]);
	Mat->rows = atoi(&lines[1][0]);
	free(lines[0]);
	free(lines[1]);
	if(i!=Mat->rows+2){
		fprintf(stderr, "Data size of %s is not match rows! \n ", filename);
		exit(EXIT_FAILURE);
	}
	//Step2.1: Allocate the memory for storing double array.(Core step, or your struct cannot store data correctly.)
	Mat->values = (double**)malloc(Mat->rows*sizeof(double*));
	for(size_t x=0;x<Mat->rows;x++){
		Mat->values[x] = (double*)malloc(Mat->cols*sizeof(double));
	}
	//Step2.2: Use strtod(str, &endPtr) function to extract the double part.
	//(Let the endPtr past when we need to read next double target.)
	char * str;
	char * endPtr;
	int index;
	double save;
	for(size_t j=2;j<i;j++){
		index=0;
		str = lines[j];
		//if(str==' '){error}
		save = strtod(str, &endPtr);
		Mat->values[j-2][index] = save;
 		while(*endPtr!='\n'&&*endPtr!='\0'){
			if(*endPtr==' '){
				endPtr++;
				continue;
			}
			str = endPtr;
			index+=1;
			if(index>Mat->cols-1){
				fprintf(stderr, "Data of %s is out of columns!\n ", filename);
				exit(EXIT_FAILURE);
			}
			save = strtod(str, &endPtr);
			Mat->values[j-2][index] = save;
		}
		free(lines[j]);
		if(index!=Mat->cols-1){
			fprintf(stderr, "Data size of %s was not match columns!\n ", filename);
			exit(EXIT_FAILURE);
		}
	}
	free(lines);
	if(fclose(f)!=0){
		fprintf(stderr, "The file %s failed to close.\n", filename);
		exit(EXIT_FAILURE);
	}
	return Mat;
}

void printMatrix(matrix_t * matrix){
	for(int i=0; i<matrix->rows; i++){
		for(int j=0; j<matrix->cols; j++){
			printf("%lf ", matrix->values[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(matrix_t * matrix){
	for(int i=0; i<matrix->rows;i++){
		free(matrix->values[i]);
	}
	free(matrix->values);
	free(matrix);
}

int main(int argc, char ** argv){

	if(argc!=3){
		fprintf(stderr, "You should enter 3 command line arguments!\n");
		exit(EXIT_FAILURE);
	}

	matrix_t * leftMat = readMatrix(argv[1]);
	matrix_t * rightMat = readMatrix(argv[2]);
	printf("The input left matrix is:\n");
	printMatrix(leftMat);
	printf("The input right matrix is:\n");
	printMatrix(rightMat);

	matrix_t * result = multiply(leftMat, rightMat);
	printf("The result matrix of multipy is:\n");
	printMatrix(result);
	
	freeMatrix(leftMat);
	freeMatrix(rightMat);
	freeMatrix(result);
	return 0;
}
