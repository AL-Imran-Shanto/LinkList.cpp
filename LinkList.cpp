#include<iostream>
using namespace std ;

struct Node
{
    int data ;
    struct Node* next ;
};

Node * creatNode (int value)
{
    Node * temp = new Node () ;
    temp->data = value ;
    temp->next = NULL ;
    return temp       ;
}

void printLinkList (Node* head)
{
    Node * temp = head ;
    while (temp!= NULL)
    {
        cout << temp->data << " " ;
        temp = temp ->next ;
    }
}

void insertFront (Node* head,int value)
{
    Node * temp = creatNode (value) ;
    temp->next = head ;
    head = temp ;
    printLinkList (head) ;
}
void insertMid (Node * head, int value, int key)
{
    Node * prv =  head ;
    Node * temp = creatNode (value) ;

    while (prv!=NULL && prv->data != key)
    {
        prv = prv->next ;
    }
    temp->next = prv->next ;
    prv->next = temp ;
    printLinkList (head) ;
}



void insertLast (Node * head, int value)
{
    Node * temp = creatNode (value) ;
    Node * prv = head ;

    while (prv->next != NULL)
    {
        prv = prv -> next ;
    }
    prv->next = temp ;
    temp->next = NULL ;
    printLinkList (head) ;
}

// delete Part

void deleteFront (Node* head)
{
    Node* temp = head ;
    if (temp == NULL)
        return ;
    else
    {
        head = head -> next ;
        delete (temp) ;
    }
    printLinkList (head) ;
}

void deleteMid (Node * head,int key)
{
    Node * temp = head ;
    Node * prv = NULL ;

    if (head == NULL)
        return ;
    while (temp != NULL && temp -> data !=key)
    {
        prv = temp ;
        temp = temp -> next ;
    }
    prv ->next = temp -> next ;
    delete (temp) ;
    printLinkList (head) ;

}

void deletelast (Node*head)
{
    Node * temp = head ;
    Node * prv = NULL ;

    while (temp->next != NULL)
    {
        prv = temp ;
        temp = temp -> next ;
    }
    prv -> next = NULL ;
    delete (temp) ;
    printLinkList (head) ;
}
int main ()
{
    Node * head = creatNode (10);
    Node * n1 = creatNode (20) ;
    Node * n2 = creatNode (30) ;
    Node * n3 = creatNode (40) ;
    Node * n4 = creatNode (50) ;
    Node * n5 = creatNode (60) ;

    head -> next = n1 ;
    n1 -> next = n2 ;
    n2 -> next = n3 ;
    n3 -> next = n4 ;
    n4 -> next = n5 ;
    n5 -> next = NULL ;

    /*
        printLinkList ( head) ;
        cout << "\n\n" ;

        insertFront (head,6) ;
        cout << "\n\n" ;
        insertLast (head, 70) ;

        cout << "\n\n" ;
        insertMid (head, 38,30) ;

        cout << "\n\n" ;
        deleteFront (head) ;

    cout << "\n\n" ;
    deleteMid (head,50) ;
*/
    cout << "\n\n" ;
    deletelast (head) ;





    return 0 ;
}
