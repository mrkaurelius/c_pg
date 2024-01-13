#include <stdlib.h>
#include <stdio.h>
#include <ll.h>

void my_callback(int val)
{
  printf("incallback val: %d\n", val);
}

int main()
{
  // Happy path "tests"
  int current_val = 0;
  int handle = init_ll();
  printf("test> ll handle: %d\n", handle);

  current(handle, &current_val);
  printf("test> readed current_val: %d\n", current_val);

  set_val(handle, 29);

  current(handle, &current_val);
  printf("test> readed current_val: %d\n", current_val);

  append(handle, 34);

  current(handle, &current_val);
  printf("test> readed current_val: %d\n", current_val);

  traverse(handle, my_callback);
  return 0;
}