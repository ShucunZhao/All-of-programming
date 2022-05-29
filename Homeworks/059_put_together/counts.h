#ifndef __COUNTS_H__
#define __COUNTS_H__

typedef struct countInfo_tag{
	char * value;
	size_t times;
}countInfo_t;

typedef struct counts_tag{
	size_t nums;
	countInfo_t ** countInfo;
	countInfo_t * unknow;
}counts_t;

counts_t * createCounts(void);

void addCount(counts_t * counts, const char * name);

void printCounts(counts_t * counts, char * filename);

void freeCounts(counts_t * counts);

#endif
