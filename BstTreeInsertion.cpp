#include<iostream>
using namespace std ;

struct treeNode
{
    int data ;
    treeNode* left ;
    treeNode* right ;
} typedef Tree ;

Tree* createTree (int value )
{
    Tree* root = new Tree () ;
    root -> data = value ;
    root -> left = NULL ;
    root -> right = NULL ;
    return root ;
}

Tree* treeInsertion(Tree*root,int value)
{
    if (root == NULL)
    {
        root = createTree (value) ;
    }
    else if (root->data < value )
    {
        root -> right = treeInsertion(root->right,value) ;
    }
    else
    {
        root -> left = treeInsertion(root->left,value) ;
    }
    return root ;
}



void printTree (Tree*root)
{
    if (root == NULL)
        return ;
    else
    {
        cout<<"\n\t\t"<<root->data <<endl ;
        cout <<"Left : \n" ;
        printTree(root->left) ;
        cout <<"Right : \n" ;
        printTree(root->right) ;
    }
}

int main ()
{

    Tree* root = NULL ;

    root = treeInsertion(root,50) ;
    root = treeInsertion(root,45) ;
    root = treeInsertion(root,60) ;
    root = treeInsertion(root,40) ;
    root = treeInsertion(root,48) ;
    root = treeInsertion(root,58) ;
    root = treeInsertion(root,70) ;
    root = treeInsertion(root,38) ;
    root = treeInsertion(root,100) ;

    printTree (root) ;

    return 0 ;
}
