// link list 

#include<iostream>
using namespace std;

struct node
{
       int val;
       node *link;
}*head=NULL;

void insertAtLast( node** head )
{
     char ch='y';
     node* ptr = *head;
     do{
             ptr=*head;
             cout<<"enter value :";
             node *newnode = new node;
             cin >> newnode->val;
             newnode->link = NULL;
             //newnode->val = no;
             
             if( ptr == NULL )
             {
                    ptr = newnode;
                    *head = newnode;
                    continue;
             }
             
             while( ptr->link != NULL )
                    ptr = ptr -> next;
             ptr ->link = newnode;
             
             cout<<"enter y to insert"<<endl;
             cin >> ch;
     }while(ch == 'y' );
}

void traverseF( node *head)
{
     cout<<" traversing"<<endl;
     while( head != NULL )
     {
            cout<< head->val<<"->";
            head=head->link;
     }
     cout<<endl;
}
void reverse(node *ptr)
{
     if( ptr->link == NULL )
     {
         head=ptr;
         return;
     }
     reverse(ptr->link);
     //cout<<head->val<<"->";
     ptr->link->link=ptr;
     ptr->link=NULL;
}
void traverseWithPrevRecursion( node *prev, node *curr)
{
   if(curr){
      traverseWithPrevRecursion(curr,curr->link);
      curr->link = prev;
    }
    else{
      head = prev;
    }
}
void travR(node *head)
{
     if( head == NULL )
     {
         return;
     }
     travR(head->link);
     cout<<head->val<< " -> ";
}
void reverseItr()
{
     node *curr, *future, *prv;
     prv = NULL; 
     curr = head;
     while(  curr != NULL)
     {
               future = curr->link;
               curr->link = prv;
               prv=curr;
               curr=future;
               
     }
     head = prv;
}

int main()
{
    cout<<"enter choice \n1. insert at last \n2 traverse from front \n3 traverse from last \n"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
                  case 1:
                       insertAtLast(&head);                      
                  case 2:
                       traverseF(head);
                       //break;
                  case 3:
                       //reverse( head );
                       reverseItr();
                       traverseF( head );
                  case 4:
                       //cout<<"reverse traversing using revurstion"<<endl;
                       //travR(head);
                  case 5:
                       //reverseItr();
                       //traverseWithPrevRecursion(NULL,head);
                  default:
                          cout<<"enter again\n"<<endl;
    }
    system("pause");
    return 0;
};
