#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// function for creating nodes
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{

    // create nodes manually

    // struct node* p;
    // p = (struct node *) malloc(sizeof(struct node));
    // p->data = 1;
    // p->left = NULL;
    // p->right = NULL;

    // struct node* p1;
    // p1 = (struct node *) malloc(sizeof(struct node));
    // p1->data = 2;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct node* p2;
    // p2 = (struct node *) malloc(sizeof(struct node));
    // p2->data = 3;
    // p2->left = NULL;
    // p2->right = NULL;

    // create nodes using createnode function
    struct node *p = createnode(4);
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(5);
    struct node *p4 = createnode(2);

    // linking of nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("preorder traversal:\n");
    preorder(p);

    printf("\n");

    printf("postorder traversal:\n");
    postorder(p);

    printf("\n");

    printf("inorder traversal:\n");
    inorder(p);
}