#ifndef __KV_H__
#define __KV_H__

typedef struct kvpair_tag{
	char * key;
	char * value;
}kvpair_t;

typedef struct kvSet_tag{
	size_t kvNum;
	kvpair_t ** kvpair; 
}kvSet_t;

void stripNewline(char * str);

kvSet_t * readKv(char * filename);

void kvFreeMem(kvSet_t * kvSet);

#endif
