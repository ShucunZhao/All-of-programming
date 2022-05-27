typedef struct kvpair_tag{
	char * key;
	char * value;
}kvpair_t;

typedef struct kvSet_tag{
	size_t kvNum;
	kvpair_t ** kvpair; 
}kvSet_t;

typedef struct count_tag{
	char * Val;
	size_t Count;
}count_t;

typedef struct uniqSet_tag{
	size_t num;
	count_t ** countSet;
}uniqSet_t;
