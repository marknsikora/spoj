/*
 * Author: Mark Sikora
 * Date: 2011/02/25
 *
 */
     
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node Node;

struct _Node {
    unsigned int key;
    unsigned int value;
    Node *left;
    Node *right;
};
     
Node* node_new (unsigned int key, unsigned int value) {
    Node *node = (Node*) malloc (sizeof(Node));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

inline unsigned int max (unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

int tree_search (Node *tree, int key)
{
    if (tree == NULL || key == 0) {
        return 0;
    } else if (tree->key == key) {
        return tree->value;
    } else if (tree->key < key) {
        return tree_search (tree->left, key);
    } else if (tree->key > key) {
        return tree_search (tree->right, key);
    } else {
        return 0;
    }
}

void tree_insert (Node **tree, Node* node)
{
    if (*tree == NULL) {
        *tree = node;
    } else if ((*tree)->key < node->key) {
        tree_insert (&((*tree)->left), node);
    } else if ((*tree)->key > node->key) {
        tree_insert (&((*tree)->right), node);
    }
}

int calc_coins (unsigned int n, Node **tree)
{
    unsigned int alt, m;
    Node *node;
    if (!n) {
        return 0;
    }
    
    m = tree_search (*tree, n);
    if (!m) {
        alt = calc_coins (n/2, tree) +
            calc_coins (n/3, tree) +
            calc_coins (n/4, tree);
        m = max (n, alt);
        node = node_new (n, m);
        tree_insert (tree, node);
    }
    
    return m;
}

int main(int argc, char **argv)
{
    unsigned int n;
    Node *tree = NULL;
    
    assert(UINT_MAX > 1000000000);
    
    while(scanf("%u", &n) != -1) {
        n = calc_coins (n, &tree);
        printf ("%u\n", n);
    }
    
    return EXIT_SUCCESS;
}
