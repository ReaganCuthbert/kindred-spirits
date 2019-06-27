/*
* Name: Reagan Cuthbertson
* ID: 6346
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"


node *createNode(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->left = n->right = NULL;

	return n;
}



//in order traversal used for the first binary tree.
void nodeCounter(node *root, int *counter)
{
    if (root == NULL)
        return;

    nodeCounter(root->left, counter);
    *counter += 1;
    nodeCounter(root->right, counter);
}


//puts elements of binary tree in order based on inOrder traversal.
void inOrder(node *root, int *array, int *i)
{
    if(root == NULL)
        return;

    inOrder(root->left, array, i);
    array[*i] = root->data;
    *i += 1;
    inOrder(root->right, array, i);
}



//puts elements of binary tree in order based on a reversed inOrder traversal.
void reversedInOrder(node *root, int *array, int *i)
{
    if(root == NULL)
        return;

    reversedInOrder(root->right, array, i);
    array[*i] = root->data;
    *i += 1;
    reversedInOrder(root->left, array, i);
}



//puts elements of binary tree in order based on a preOrder traversal.
void preOrder(node *root, int *array, int *i)
{
    if(root == NULL)
        return;

    array[*i] = root->data;
    *i += 1;
    preOrder(root->left, array, i);
    preOrder(root->right, array, i);
}



//puts elements of binary tree in order based on a postOrder traversal.
void postOrder(node *root, int *array, int *i)
{
    if(root == NULL)
        return;

    postOrder(root->left, array, i);
    postOrder(root->right, array, i);
    array[*i] = root->data;
    *i += 1;
}



//creates refelected binary tree.
void createReflectedTree(node *root, node *reflectedRoot)
{
    if(root->left != NULL)
    {
        reflectedRoot->right = createNode(root->left->data);
        createReflectedTree(root->left, reflectedRoot->right);
    }


    if(root->right != NULL)
    {
        reflectedRoot->left = createNode(root->right->data);
        createReflectedTree(root->right, reflectedRoot->left);
    }
}



//checks to see if two binary trees's are reflections of each other.
int isReflection(node *a, node *b)
{
    int aCounter = 0;
    int bCounter = 0;

    nodeCounter(a, &aCounter);
    nodeCounter(b, &bCounter);

    if(aCounter != bCounter)
        return 0;


    int *firstTreeArr = malloc(sizeof(int) * aCounter);
    int *secondTreeArr = malloc(sizeof(int) * bCounter);

    int i = 0;

    inOrder(a, firstTreeArr, &i);

    i = 0;

    reversedInOrder(b, secondTreeArr, &i);

    for(i = 0; i < aCounter; i++)
    {
        if(firstTreeArr[i] != secondTreeArr[i])
        {
             free(firstTreeArr);
             free(secondTreeArr);
             return 0;
        }

    }


    free(firstTreeArr);
    free(secondTreeArr);


    return 1;
}



//returns a reflected binary tree of the binary tree inputed in the function.
node *makeReflection(node *root)
{
    if(root == NULL)
        return NULL;

    node *newRoot = createNode(root->data);

    createReflectedTree(root, newRoot);

    return newRoot;
}



//function that returns whether or not two trees are kindred spirits.
int kindredSpirits(node *a, node *b)
{
    int aCounter = 0;
    int bCounter = 0;

    nodeCounter(a, &aCounter);
    nodeCounter(b, &bCounter);

    if(aCounter != bCounter)
        return 0;

    int *firstTreeArr = malloc(sizeof(int) * aCounter);
    int *secondTreeArr = malloc(sizeof(int) * bCounter);

    int i = 0;

    preOrder(a, firstTreeArr, &i);

    i = 0;

    postOrder(b, secondTreeArr, &i);

    int isKindredSpirit = 1;

    for(i = 0; i < aCounter; i++)
    {
        if(firstTreeArr[i] != secondTreeArr[i])
        {
            isKindredSpirit = 0;
            break;
        }
    }


    if(!isKindredSpirit)
    {
        i = 0;
        preOrder(b, secondTreeArr, &i);
        i = 0;
        postOrder(a, firstTreeArr, &i);
    }


     for(i = 0; i < aCounter; i++)
    {
        if(firstTreeArr[i] != secondTreeArr[i])
        {
             free(firstTreeArr);
             free(secondTreeArr);
             return 0;
        }

    }


    free(firstTreeArr);
    free(secondTreeArr);

    return 1;
}



//returns personal opinion on the difficulty rating of the project.
double difficultyRating(void)
{
    return 3.5;
}



//returns the amount of time I spent on the project.
double hoursSpent(void)
{
    return 5.0;
}
