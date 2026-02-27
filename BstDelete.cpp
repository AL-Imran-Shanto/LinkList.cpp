#include<iostream>
using namespace std ;

struct tree
{
    int data ;
    tree* left ;
    tree* right ;
};
tree* creatTree (int value)
{
    tree* root = new tree () ;
    root -> data = value ;
    root -> left = NULL ;
    root -> right = NULL ;
    return root ;
}

tree * insertion(tree* root, int value)
{
    if ( root == NULL) return creatTree (value) ;
    else if (root -> data > value)
    {
        root -> left = insertion(root -> left,value) ;
    }
    else if (root -> data < value)
    {
        root -> right = insertion(root -> right,value) ;
    }
    return root ;
}
tree* maxNode (tree* root)
{
    if (root == NULL) return root ;
    else
    {
        while (root ->right != NULL)
        {
            root = root -> right ;
        }
        return root ;
    }
}

tree* minNode (tree* root)
{
    if (root == NULL) return root ;
    else
    {
        while (root -> left != NULL)
        {
            root = root -> left ;
        }
        return root ;
    }
}
tree * deleteTree (tree* root, int key)
{
    if (root == NULL) return root ;
    else if (root->data >key)
    {
        root -> left = deleteTree (root -> left, key) ;

    }
    else if (root -> data < key )
    {
        root -> right = deleteTree (root -> right, key) ;

    }
    else
    {
        // 0 or 1 child

        if (root->left == NULL )
        {
            tree* temp = root ;
            temp = temp -> right ;
            delete root ;
            return temp ;
        }
        else if (root -> right == NULL)
        {
            tree* temp = root ;
            temp = temp -> left ;
            delete root ;
            return temp ;
        }
        // 2 child
        else
        {
            /*
              tree* temp = minNode(root -> right) ;
              root -> data = temp -> data ;
              root -> right = deleteTree ( root-> right, temp -> data) ;
              */

            tree* temp = maxNode(root -> left) ;
            root -> data = temp -> data ;
            root -> left = deleteTree(root -> left, temp -> data) ;
        }
    } return root ;
}

void printTree (tree*root)
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
    tree* root = NULL ;

    root = insertion(root,50) ;
    root = insertion(root,45) ;
    root = insertion(root,60) ;
    root = insertion(root,40) ;
    root = insertion(root,48) ;
    root = insertion(root,58) ;
    root = insertion(root,70) ;
    root = insertion(root,38) ;
    root = insertion(root,100) ;

    printTree (root) ;

    root = deleteTree (root, 38) ;
    cout << "After delete : " << endl ;
    printTree (root) ;

    return  0;
}
