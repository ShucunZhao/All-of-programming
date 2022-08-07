#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
class Matrix{
private:
	int numRows;
	int numColumns;
	vector<T> ** rows;
public:
	Matrix():numRows(0),numColumns(0),rows(NULL){};
	Matrix(int r, int c):numRows(r),numColumns(c),rows(new vector<T>*[r]){
		for(int i=0;i<r;i++){
			rows[i] = new vector<T>(c);
		}
	}
	Matrix(const Matrix & rhs):numRows(rhs.numRows),numColumns(rhs.numColumns){
		rows = new vector<T>*[numRows];
		for(int i=0;i<numRows;i++){
			rows[i] = new vector<T>(rhs[i]);
		}
	}
	~Matrix(){
		for(int i=0;i<numRows;i++){
			delete rows[i];
		}
		delete[] rows;
	}
	Matrix & operator=(const Matrix & rhs){
		if(this==&rhs){
			return *this;
		}
		vector<T> ** temp = new vector<T>*[rhs.numRows];
		for(int i=0;i<rhs.numRows;i++){
			temp[i] = new vector<T>(rhs[i]);
		}
		for(int j=0;j<numRows;j++){
			delete rows[j];
		}
		delete[] rows;
		rows = temp;
		numRows = rhs.numRows;
		numColumns = rhs.numColumns;
		return *this;
	}
	int getRows() const{
		return numRows;
	}
	int getColumns() const{
		return numColumns;
	}
	const vector<T> & operator[](int index) const{
		assert(index>=0&&index<=numRows);
		return *rows[index];
	 }
	vector<T> & operator[](int index){
		assert(index>=0&&index<=numRows);
		return *rows[index];
	}
	bool operator==(const Matrix & rhs)const{
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
	Matrix operator+(const Matrix & rhs) const{
		assert(numRows==rhs.numRows&&numColumns==rhs.numColumns);
		Matrix<T> sum(numRows, numColumns);
		for(int i=0;i<numRows;i++){
			for(int j=0;j<numColumns;j++){
				sum[i][j] = (*this)[i][j] + rhs[i][j];	
			}
		}
		return sum;
	}
};

template<typename T>
ostream & operator<<(ostream & s, const Matrix<T> & rhs){
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

#endif
