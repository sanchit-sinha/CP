/* A program to construct Binary Tree from preorder traversal */
#include<bits/stdc++.h> 
int index=0;
/* A binary tree node structure */
struct node 
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}node; 

/* Utility function to create a new Binary Tree node */
struct node* newNode (int data) 
{ 
    struct node temp = (struct node)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 

/* A recursive function to create a Binary Tree from given pre[] 
preLN[] arrays. The function returns root of tree. index_ptr is used 
to update index values in recursive calls. index must be initially 
passed as 0 */
struct node*root=NULL;
struct node *constructTreeUtil(struct node*root,int pre[], char preLN[], int n) 
{ 
     // store the current value of index in pre[] 

    // Base Case: All nodes are constructed 
    if (index == n) 
        return NULL; 
        if(index==0){
            root = newNode ( pre[index] ); 
    index++; 
        root->left = constructTreeUtil(root->left,pre, preLN, n); 
    root->right = constructTreeUtil(root->right,pre, preLN,n); 
        }

    // Allocate memory for this node and increment index for 
    // subsequent recursive calls 


    // If this is an internal node, construct left and right subtrees and link the subtrees 
    if (preLN[index] == 'N'&&index!=0) 
    { 
          root = newNode ( pre[index] ); 
    index++; 
    root->left = constructTreeUtil( root->left,pre, preLN, n); 
    root->right = constructTreeUtil(root->right,pre, preLN,n); 
    }
    if(preLN[index]=='L'&&index!=0){
           root = newNode ( pre[index] ); 
    index++; 
    return;
    }

    return root; 
} 

// A wrapper over constructTreeUtil() 


/* This function is used only for testing */
void printInorder (struct node* node) 
{ 
    if (node == NULL) 
        return; 

    /* first recur on left child */
    printInorder (node->left); 

    /* then print the data of node */
    printf("%d ", node->data); 

    /* now recur on right child */
    printInorder (node->right); 
} 

/* Driver function to test above functions */
int main() 
{ 
    struct node *root = NULL; 

    /* Constructing tree given in the above figure 
        10 
        / \ 
        30 15 
    / \ 
    20 5 */
    int pre[] = {10, 30, 20, 5, 15}; 
    char preLN[] = {'N', 'N', 'L', 'L', 'L'}; 
    int n = sizeof(pre)/sizeof(pre[0]); 

    // construct the above tree 
    root = constructTreeUtil(root,pre, preLN, n); 

    // Test the constructed tree 
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n"); 
    printInorder (root); 

    return 0; 
}