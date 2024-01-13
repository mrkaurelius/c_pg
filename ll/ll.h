// A simple and easy to use linked list library utilizing integer handles

#define LL_SIZE 1024

int init_ll();
int current(int h, int *current_val);
int set_val(int h, int new_val);
int append(int h, int new_val);
int traverse(int h, void callback(int val));
int next(int h);
int prev(int h);