#include <stdio.h>
#include <stdlib.h>

typedef struct point_tag{
	int x;
	int y;
}point_t;

typedef struct polygon_tag{
	size_t num_points;
	point_t * points;
}polygon_t;

polygon_t * makeRectangle(point_t c1, point_t c2){
	polygon_t * answer = malloc(sizeof(*answer));
	answer->num_points = 2;
	answer->points =(point_t*)malloc(answer->num_points*sizeof(*answer->points));
	answer->points[0]=c1;
	answer->points[1]=c2;
	return answer;
}

typedef struct matrix_tag{
	double ** values;
	size_t rows;
	size_t cols;
} matrix_t;

int main(int argc, char ** argv){
	point_t c1;
	point_t c2;
	c1.x=1;
	c1.y=1;
	c2.x=2;
	c2.y=2;
	polygon_t * test = makeRectangle(c1, c2);
	free(test->points);
	free(test);
	///////////////////
	matrix_t Mat;
	//Mat = (matrix_t*)malloc(sizeof(*Mat));
	//printf("The size of Mat:%ld\n", sizeof(*Mat));
	Mat.rows = 2;
	Mat.cols = 3;
	Mat.values=(double**)malloc(Mat.rows*sizeof(double*));
	for(int i=0; i<Mat.rows; i++){
		Mat.values[i] = (double*)malloc(Mat.cols*sizeof(double));
	}
	for(int i=0;i<Mat.rows;i++){
		for(int j=0;j<Mat.cols;j++){
			Mat.values[i][j]=j;
		}
	}
	for(int i=0;i<Mat.rows;i++){
		for(int j=0;j<Mat.cols;j++){
			printf("%.lf ", Mat.values[i][j]);
			//free(Mat->values[i][j]);
		}
		printf("\n");
		free(Mat.values[i]);
	}
	free(Mat.values);
	//free(Mat);//
	return EXIT_SUCCESS;
}
