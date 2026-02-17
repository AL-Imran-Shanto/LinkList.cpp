#include<iostream>
using namespace std ;

struct TreeNode
{
    char data ;
    TreeNode* left ;
    TreeNode* right ;
} typedef tree ;

tree* createTree (char x)
{
    tree* root = new tree () ;
    if (root!= NULL)
    {
        root->data = x ;
        root->left = NULL ;
        root->right = NULL ;
    }
    return root ;
}
void printTree (tree*root)
{
    if (root == NULL) return ;
    else {
        cout<< "\t\t"<<root->data << endl ;
        cout <<"Left Child : \n"  ;
        printTree (root->left) ;
        cout <<"Right Child : \n"  ;
        printTree (root->right) ;
    }
}

int main ()
{
    tree* root = createTree ('A') ;
    tree* r1 = createTree ('B') ;
    tree* r2 = createTree ('C') ;
    tree* r3 = createTree ('D') ;
    tree* r4 = createTree ('E') ;
    tree* r5 = createTree ('F') ;
    tree* r6 = createTree ('G') ;
    tree* r7 = createTree ('H') ;

    root->left = r1 ;
    root->right = r2 ;
    r1->left = r3 ;
    r1->right = r4 ;
    r2->left = r5 ;
    r2->right = r6 ;
    r5->left = r7 ;

    printTree (root) ;

    return 0 ;
}
