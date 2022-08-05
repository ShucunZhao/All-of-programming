#include "IntMatrix.h"
//#include <iostream>

//using namespace std;

IntMatrix::IntMatrix():numRows(0),numColumns(0),rows(NULL){

}

IntMatrix::IntMatrix(int r, int c):numRows(r),numColumns(c),rows(new IntArray*[r]){
	for(int i=0;i<numRows;i++){
		rows[i] = new IntArray(numColumns);
	}
}

IntMatrix::IntMatrix(const IntMatrix & rhs):numRows(rhs.numRows),numColumns(rhs.numColumns){
	rows = new IntArray*[numRows];
	for(int i=0;i<numRows;i++){
		rows[i] = new IntArray(rhs[i]);
		/*
		rows[i] = new IntArray(numColumns);
		for(int j=0;j<numColumns;j++){
			(*this)[i][j] = rhs[i][j];
		}
		*/
	}
}

IntMatrix::~IntMatrix(){
	for(int i=0;i<numRows;i++){
		//delete[] rows[i]//KeyPoint: U cannot use delete[] here because
					//the rows[i] is the 1D obejct, so you must use delete to free it, if u use delete[] that would free the memory form the fourth bytes.
		delete rows[i];//Key point!
					  //Must free it with delete not delete[]!
	}
	delete[] rows;//rows is 2D object so must use delete[] to free!
}

IntMatrix & IntMatrix::operator=(const IntMatrix & rhs){
	if(this==&rhs){
		return *this;
	}
	//int res;
	IntArray ** temp = new IntArray*[rhs.numRows];
	for(int i=0;i<rhs.numRows;i++){
		temp[i] = new IntArray(rhs[i]);
		/*
		for(int j=0;j<rhs.numColumns;j++){
			//res = rhs.rows[i][j];
			//temp[i][j] = res;
			temp[i][j] = (rhs.rows[i])[j];	
		}
		*/
	}
	for(int j=0;j<numRows;j++){
		delete rows[j];
	}
	delete[] rows;
	numRows = rhs.numRows;
	numColumns = rhs.numColumns;
	rows = temp;
	return *this;
}

int IntMatrix::getRows() const{
	return numRows;
}

int IntMatrix::getColumns() const{
	return numColumns;
}

const IntArray & IntMatrix::operator[](int index) const{
	assert(index>=0&&index<=numRows);
	IntArray & result = *rows[index];
	return result;
	//return *rows[index];
}

IntArray & IntMatrix::operator[](int index){
	assert(index>=0&&index<=numRows);
	IntArray & result = *rows[index];
	return result;
	//return *rows[index];
}

bool IntMatrix::operator==(const IntMatrix & rhs) const{
	if(this==&rhs){
		return 1;
	}
	if((numRows!=rhs.numRows)||(numColumns!=rhs.numColumns)){
		return 0;
	}
	for(int i=0;i<numRows;i++){
		for(int j=0;j<numColumns;j++){
			if((*this)[i][j]!=rhs[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const{
	assert(numRows==rhs.numRows&&numColumns==rhs.numColumns);
	IntMatrix sum(numRows, numColumns);
	//int dataX;
	//int dataY;
	for(int i=0;i<numRows;i++){
		for(int j=0;j<numColumns;j++){
			//dataX = rows[i][j];
			//dataY = rhs.rows[i][j]
			//sum[i][j] = dataX + dataY;
			sum[i][j] = (*this)[i][j] + rhs[i][j];
			//cout<<sum[i][j];
		}
	}
	return sum;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs){
	if(rhs.getRows()==0){
		s<<"[ ]";
		return s;
	}
	for(int i=0;i<rhs.getRows();i++){
		s<<"[";
		for(int j=0;j<rhs.getColumns();j++){
			s<<rhs[i][j];
			if(j!=rhs.getColumns()-1){
				s<<",";
			}
		}
		s<<"]"<<"\n";
	}
	//s<<"]";
	return s;
}
