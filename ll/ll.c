#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

// TODO how to return errors to user?

struct ll_node
{
  int val;
  struct ll_node *next;
};

// linked lists, points to initial node
struct ll_node *lls[LL_SIZE];

// currently pointed nodes of linked lists
struct ll_node *ll_currents[LL_SIZE];

// handles for linklist instances
int next_handle = 0;

// initialise a linked list and return a handle to user for furhter use
int init_ll()
{
  fprintf(stderr, "initing ll library\n");

  // initial node
  struct ll_node *n = malloc(sizeof(struct ll_node));

  if (n == NULL)
  {
    return -1;
  }

  n->val = 0;

  ll_currents[next_handle] = n;
  lls[next_handle] = n;

  return next_handle++;
}

// returns status, 0 success, returns current nodes value via current_val, user provides current_val
int current(int h, int *current_val)
{
  struct ll_node *n = ll_currents[h];

  if (n == NULL)
  {
    return -1;
  }

  // fprintf(stderr, "loading node, address: %p\n", n);
  // fprintf(stderr, "loading node, val: %d\n", n->val);

  *current_val = n->val;
  // fprintf(stderr, "current_val: %d\n", *current_val);

  return 0;
}

// set current nodes value
int set_val(int h, int new_val)
{

  struct ll_node *current_node = ll_currents[h];

  if (current_node == NULL)
  {
    return -1;
  }

  // fprintf(stderr, "loading node, address: %p\n", current_node);
  // fprintf(stderr, "node val: %d\n", current_node->val);

  current_node->val = new_val;

  // fprintf(stderr, "node val: %d\n", current_node->val);

  return 0;
}

// TODO append new node to
int append(int h, int new_val)
{
  // Get current node,
  struct ll_node *current_node = ll_currents[h];

  // Create new node,
  struct ll_node *new_node = malloc(sizeof(struct ll_node));
  if (new_node == NULL)
  {
    return -1;
  }

  new_node->val = new_val;

  // Add to next
  current_node->next = new_node;

  // move currents
  ll_currents[h] = new_node;

  return 0;
}

int traverse(int h, void callback(int val))
{

  struct ll_node *n = lls[h];

  if (n == NULL)
  {
    return -1;
  }

  while (n != NULL)
  {
    callback(n->val);
    n = n->next;
  }

  return 0;
}

// TODO move current value to next value
int next(int h)
{

  return 0;
}

// TODO move current value to previous value
int prev(int h)
{

  return 0;
}