#ifndef TREE_H
#define TREE_H

enum retval {FAIL,OK};

const int MAXSIZE = 100;

struct tree {
  char * array;
  int pos;
};


void init(tree &t);
void deinit(tree &t);
bool nullp(const tree & t);
retval insert(tree &t, char c);
tree cerca (const tree &t,char c);
void print_ordered(const tree &t);
void print_indented(const tree &t);
#endif
