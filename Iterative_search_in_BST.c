#include <stdio.h>
#include <malloc.h>
// Define the structure for a tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// Function to create a new node
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Recursive search function for BST
// ⚠️ Note: This is named "iterative_search", but it actually uses recursion
struct node *iterative_search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            // Key found
            return root;
        }
        else if (root->data > key)
        {
            // Search in the left subtree
            return iterative_search(root->left, key);
        }
        else
        {
            // Search in the right subtree
            return iterative_search(root->right, key);
        }
    }
    // If not found
    return NULL;
}

int main()
{
    // Creating nodes
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    // Linking nodes to form a BST
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Searching for a key in the BST
    struct node *n = iterative_search(p, 2);

    if (n != NULL)
        printf("Element %d found\n", n->data);
    else
        printf("Element not found\n");

    return 0;
}
