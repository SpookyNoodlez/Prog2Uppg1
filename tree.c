#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "date.h"

TreeNode *createNode(struct Date date, int code)
{
    TreeNode *result = malloc(sizeof(TreeNode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->date = date;
        result->code = code;
    }
    return result;
}

TreeNode *insertNode(TreeNode *root, Date date, int code)
{
    if (root == NULL)
    { //landed in an empty node
        root = createNode(date, code);
    }
    else if (isEarlier(date, root->date))
    {
        root->left = insertNode(root->left, date, code); //recursive funktion call
    }
    else
    {
        root->right = insertNode(root->right, date, code); //recursive funktion call
    }

    return root;
}

void deleteBranch(TreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    deleteBranch(p->left);
    deleteBranch(p->right);
    free(p);
}

void printBranch(TreeNode *p)
{
    if (p == NULL)
    {
        return;
    }
    printBranch(p->left);
    printBranch(p->right);
    printf("%d|%d.%d.%d\n",p->code, p->date.day,p->date.month,p->date.year);
}