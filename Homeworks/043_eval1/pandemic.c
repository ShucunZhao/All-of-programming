#include "pandemic.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#define ONE_H_T 100000

/*
 * Parse each line of a string input to extract the country name and population, 
 * and return a country_t struct with those infotmation.
 * pre: Accept the correct formt string include name and population parts which is divided by comma, 
 * otherwise prints an error message and exit with failure status.
 * @param line - Input pointer point to string.
 * @return country_t - Output struct with tow elements: country, population.
 */
country_t parseLine(char * line){

  //Step 1: process the while error:	
  if(line==NULL){
  	fprintf(stderr, "The line pointer is invalid!\n");
	exit(EXIT_FAILURE);
  }
  if(strlen(line)<3){
    fprintf(stderr, "Input string is incorrect length.\n");
	exit(EXIT_FAILURE);
  }

  //Step 2: split the string into name-part and comma-part then check the comma part error:
  char * commaP = strchr(line, ',');
  //printf("commaP1: %s\n", commaP);
  //printf("*commaP1: %s\n", commaP);
  if(commaP==NULL){
  	fprintf(stderr, "There is no comma in input string!\n");
	exit(EXIT_FAILURE);
  }
  if(strchr(++commaP, ',')!=NULL){
  	fprintf(stderr, "There is more than one comma in input string!\n");
  	exit(EXIT_FAILURE);
  }
  //printf("commaP-line:%ld\n", (--commaP)-line);
  if(((--commaP)-line)>64){//The maximum of name part is 64 bits(we define the size of name in struct country_t is 64), 
	  					  //so before the ',' the length should small than 65.
   	fprintf(stderr, "The name part of string is out of 64 bits.\n");
  	exit(EXIT_FAILURE);
  }

  country_t ans;//Define a struct.
  //Step3: Process the name part:
  int i=0;
  while(*line!=','){
  	ans.name[i]=*line;
	i++;
	line++;
  }
  ans.name[i]='\0';//The last element of name should be '\0'.

  //Step4: Process the population part:
  commaP++;
  char num[strlen(commaP)-1];//We should delete the last '\0' in commaP array.
  int j=0;
  while(*commaP!='\n'){
	if(!isdigit(*commaP)){
		fprintf(stderr, "The population part has invalid digit exist!\n");
		//printf("invalid digit:%c\n", *commaP);
		exit(EXIT_FAILURE);
	}
	//printf("No.%d: %c\n", j, *commaP);
  	num[j]=*commaP;
	j++;
	commaP++;
  }
  num[j]='\0';//The last element of population should be '\0'.
  //for(int l=0;l<strlen(num);l++){
  //	printf("num[%d]:%c\n", l, num[l]);
  //}

  //Step5: Check the population if valid:
  unsigned long pop = atol(num);//the population is uint64_t.
  if(errno==ERANGE){//check whether the population is out of range.(long range is:
	 				//[-9223372036854775808, 92233720368547750807])
  	fprintf(stderr, "The population is too large!\n");
	exit(EXIT_FAILURE);
  }
  errno=0;//Why set errno as 0 here?
  /**Note:
   * In C, if the system is called correctly then the errno value won't be clear as 0, 
   * on the other word, only when the sys has something wrong/error the errno value would be set, 
   * so if your sys successfully run you should set the errno value into 0 by hand.
   */
  if(pop==0){//check whether the population is 0.
  	fprintf(stderr, "The populaton cannot be 0!\n");
	exit(EXIT_FAILURE);
  }
  ans.population = pop;
  //printf("ans.population:%ld\n", ans.population);
  return ans;
}

/*
 * Calculates the average of the numbers with a 7 length in the data set iteratively.
 * (So that the length of data array must not less than 6.)
 * @param data - The inputer data array.
 * @param n_days - The number of days over which the data is mesured.
 * @param avg - Stores each 7 consequent data's average result.
 */
void calcRunningAvg(unsigned * data, size_t n_days, double * avg){
  	// check data pointer.
	if(data==NULL){
		fprintf(stderr, "The data is invalid!\n");
		exit(EXIT_FAILURE);
	}
	// check n_days.
	if(n_days<7){
		fprintf(stderr, "The number of n_days is invalid!\n");
		exit(EXIT_FAILURE);
	}
	double sum=0;
	size_t avgSize = n_days - 6;
	for(size_t i=0;i<avgSize;i++){
		for(size_t j=i;j<i+7;j++){
			sum+=data[j];
		}
		avg[i]=sum/7;
		sum=0;//After using the sum of 7 days we should reset it into 0 for next set of data.
	}
}

/*
 * Calculate the cumulative number of cases that day per 100,000 people
 */
void calcCumulative(unsigned * data, size_t n_days, uint64_t pop, double * cum) {
  //
  if(data==NULL){
  	fprintf(stderr, "Input is invalid data!\n");
	exit(EXIT_FAILURE);
  }
  unsigned cumData = 0;
  // From 0 to n_days to calculate the culmulative number of cases.
  for(size_t i=0;i<n_days;i++){
	cumData+=data[i];
  	if(cumData>pop){
		fprintf(stderr, "The cumulative value is larger than population!\n");
		exit(EXIT_FAILURE);
	}
	//cum[i] = (double)data[i]*ONE_H_T/pop;
	//cum[i] = (data[i]*1.0)*ONE_H_T/pop;
	cum[i] = (double)cumData*ONE_H_T/pop;
  }
}

/*
 * Find the max number of daily cases of all countries.
 * @param countries - a struct pointer point to input countries info: name and pop
 * @param n_countries - the size of input struct array represent the number of the countries.
 * @param - data - intput daily cases data
 * @param - n_days - represent the coulumn size of input data(the row size of it is n_countries)
 */
void printCountryWithMax(country_t * countries,
                         size_t n_countries,
                         unsigned ** data,
                         size_t n_days) {
  //check the data ponter
  if(data==NULL){
  	fprintf(stderr, "The data pointer is invalid!\n");
	exit(EXIT_FAILURE);
  }
  //check the country_t struct ponter
  if(countries==NULL){
  	fprintf(stderr, "The struct pointer countries is invalid!\n");
	exit(EXIT_FAILURE);
  }
 //Sort the max data of each country:
  unsigned curMax=0;
  unsigned saveMax[n_countries];
  country_t * country = countries;//Because when we find the max data country we would interate the countries which will the address of the struct pointer countries, so we should set a new struct pointer to point to it at first.
  for(size_t i=0;i<n_countries;i++){
  	for(size_t j=0;j<n_days;j++){
		if(data[i][j]>curMax){
			curMax=data[i][j];
		}
	}
	//printf("The max of No.%ld country '%s' is:%d\n", i, countries->name, curMax);
	saveMax[i]=curMax;
	curMax=0;
	countries++;
  }
  size_t index=0;
  for(size_t k=0;k<n_countries;k++){
  	if(saveMax[k]>curMax){
		curMax = saveMax[k];
		index = k;
	}
  }
  int n=0;
  for(size_t l=0;l<n_countries;l++){
  	if(saveMax[l]==curMax){
		n++;
	}
	//printf("countries[%ld]:%s\n", l, (country+l)->name);
  }
  //printf("index:%ld\n", index);
  if(n>1){
  	printf("There is a tie between at least two countries.\n");
  }
  else{
	//char * country_name =(*(countries+index)).name;
  	printf("%s has the most daily cases with %u\n", (country+index)->name, curMax);
  }
}
