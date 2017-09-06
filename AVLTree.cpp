#include <iostream>
#include <math.c>

#define MAXSIZE 512

typedef struct tree_node{
        int key;
        struct tree_node* right;
        struct tree_node* left;
        unsigned int height;
}tree_node;
        
