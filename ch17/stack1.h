/*
 * 一个堆模块的接口
 */


#define STACK_TYPE int

void create_stack(size_t size);
void destroy_stack(void);
void push(STACK_TYPE value);

STACK_TYPE pop(void);

STACK_TYPE top(void);

int is_empty(void);
int is_full(void);

