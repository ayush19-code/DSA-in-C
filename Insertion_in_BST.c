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

// Preorder traversal (Root -> Left -> Right)
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to insert a key into the BST
void insert(struct node *root, int key)
{
    struct node *prev = NULL;

    // Traverse the tree to find the correct position
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d in BST (already exists)\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    // Create a new node for insertion
    struct node *newNode = createnode(key);

    // Link the new node to its parent
    if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

int main()
{
    // Create nodes manually
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    // Link nodes to form the BST
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder traversal before insertion:\n");
    preorder(p);

    // Insert a new key into the BST
    insert(p, 56);

    printf("\nPreorder traversal after insertion:\n");
    preorder(p);

    return 0;
}
