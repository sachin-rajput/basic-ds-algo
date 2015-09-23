/***
 * Author: Sachin Rajput
 * Quesiton: Given a binary tree, find out the maximum sum of value from root to each leaf.
 * Reference: http://www.geeksforgeeks.org/find-the-maximum-sum-path-in-a-binary-tree/ 
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

 
/* A tree node structure */
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
 
// A utility function that prints all nodes on the path from root to target_leaf
bool printPath (node *root, node *target_leaf)
{
    // base case
    if (root == NULL)
        return false;
 
    // return true if this node is the target_leaf or target leaf is present in
    // one of its descendants
    if (root == target_leaf || printPath(root->left, target_leaf) ||
            printPath(root->right, target_leaf) )
    {
        printf("%d ", root->data);
        return true;
    }
 
    return false;
}
 
// This function Sets the target_leaf_ref to refer the leaf node of the maximum 
// path sum.  Also, returns the max_sum using max_sum_ref
void getTargetLeaf (node *node1, int *max_sum_ref, int curr_sum, node **target_leaf_ref)
{
    if (node1 == NULL)
        return;
 
    // Update current sum to hold sum of nodes on path from root to this node
    curr_sum = curr_sum + node1->data;
 
    // If this is a leaf node and path to this node has maximum sum so far,
    // then make this node target_leaf
    if (node1->left == NULL && node1->right == NULL)
    {
        if (curr_sum > *max_sum_ref)
        {
            *max_sum_ref = curr_sum;
            *target_leaf_ref = node1;
        }
    }
 
    // If this is not a leaf node, then recur down to find the target_leaf
    getTargetLeaf (node1->left, max_sum_ref, curr_sum, target_leaf_ref);
    getTargetLeaf (node1->right, max_sum_ref, curr_sum, target_leaf_ref);
}
 
// Returns the maximum sum and prints the nodes on max sum path
int maxSumPath (node *node1)
{
    // base case
    if (node1 == NULL)
        return 0;
 
	node *target_leaf;
    int max_sum = INT_MIN;
 
    // find the target leaf and maximum sum
    getTargetLeaf (node1, &max_sum, 0, &target_leaf);
 
    // print the path from root to the target leaf
    printPath (node1, target_leaf);
 
    return max_sum;  // return maximum sum
}
 
/* Utility function to create a new Binary Tree node */
node* newNode (int data)
{
	node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Driver function to test above functions */
int main()
{
	node *root = NULL;
 
    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
 
    printf ("Following are the nodes on the maximum sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d \n", sum);
 
    // free all memory ..
    return 0;
}