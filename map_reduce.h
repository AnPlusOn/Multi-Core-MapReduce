#ifndef MAP_REDUCE
#define MAP_REDUCE
#include "word_count.h"
extern int map_count;
extern int reduce_count;
extern void* current_key; //used by reduce
typedef struct value_key_link
{
void* key;
int value;
struct key_value_link* next;
} key_value_link;

typedef struct
{
  int tag_index;
  int thread_id;
} map_tag;
typedef struct
{
void* context_data;
key_value_link* pairs;
range* context_range;
int index;
int pairs_count;
int are_you_done;
int map_count;
} map_index;
typedef struct indexed_map
{
  key_value_link* pairs;
  int pairs_count;
} indexed_map;
typedef struct reduce_index
{
  key_value_link* pairs;
  range* reduced_range;
  int (*key_compare) (void*);
} reduce_index;
key_value_link* map(void *(data_parser) (void*), void* data, void* (data_routine) (void*), int );
char* toString(int);
void link_heads(key_value_link** , int   );
key_value_link* goto_end_link(key_value_link*  );
void* reduce(key_value_link* , int , int , int (key_compare) (void*));
#endif
