/*
 * tree.h -- 二叉查找树
 * 树不允许有重复的项
 */

#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

#define SLEN 20

typedef struct  item 
{
    char petname[SLEN];
    char petkind[SLEN];

} Item;

typedef struct trnode 
{
    Item item;
    struct tnode * left;
    struct tnode * right;
} Trnode;

typedef struct tree
{
    Trnode * root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);

void TreeIsEmpty(const Tree * ptree);

bool treeEsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(Item * pi, const Tree * ptree);

bool deleteItem(Item * pi, Tree * ptree);

void Traverse(const Tree * pt, void(*pfun)(Item item));
void DeleteAll(Tree * ptree);

#endif

