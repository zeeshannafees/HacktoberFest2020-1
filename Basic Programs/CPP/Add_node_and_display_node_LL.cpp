#include<iostream>
#include<conio.h>
using namespace std;
class Node{
    public:
        int data;
        Node* link;
};
Node* head= NULL;
void createNewNode(){
    char ch;
    do{
        Node* current;
        Node* new_node= new Node;
        cout<<"\nEnter the value:";
        cin>> new_node->data;
        new_node->link=NULL;
        if (head==NULL){
            head=new_node;
            current=new_node;
        }
        else{
            current->link=new_node;
            current=new_node;
        }
        cout<<"\nDo you want to add more nodes?";
        ch=getche();
    }
    while (ch!='n');
}
void addNodeAtBegin(){
    Node *beg=new Node;
    cout<<"\nEnter the data to add at the beginning:";
    cin>>beg->data;
    beg->link=head;
    head=beg;
}
void addNodeAtEnd(){
    Node *ptr;
    Node *last=new Node;
    ptr=head;
    cout<<"\nEnter the data to add at the end:";
    cin>>last->data;
    last->link=NULL;
    while(1){
        if (ptr->link!=NULL){
            ptr=ptr->link;
        }
        else{
            break;
        }
    }
    ptr->link=last;
    ptr=last;
}
void length(){
    int c=0;
    Node *new_node;
    new_node=head;
    while(new_node!=NULL){
        c++;
        new_node=new_node->link;
    }
    cout<<"\nThe link list has "<<c<<" elements in it"<<endl;
}
void print(){
    Node* new_node;
    new_node=head;
    if (new_node==NULL){
        cout<<"Link list is empty:";
    }
    else{
        cout<<"\nData of the link list are:"<<endl;
        while(new_node!=NULL){
            cout<<new_node->data<<"\t";
            new_node=new_node->link;
        }
    }
}
int main(){
    char ch;
    int i;
    do{
    cout<<"\nPress 1 to create a list"<<endl;
    cout<<"Press 2 to add element at the beginning of a list"<<endl;
    cout<<"Press 3 to add element at the end of a list"<<endl;
    cout<<"Press 4 to count the elements in a list"<<endl;
    cout<<"Press 5 to display the list"<<endl;
    cout<<"Enter your choice:";
    cin>>i;
    switch(i){
    case 1:
        createNewNode();
        break;
    case 2:
        addNodeAtBegin();
        break;
    case 3:
        addNodeAtEnd();
        break;
    case 4:
        length();
        break;
    case 5:
        print();
        break;
    default:
        cout<<"Wrong Input\n";
        main();
        break;
    }
    cout<<"\nDo you want to continue?";
    ch=getche();
    }while(ch!='n');
    return 0;
}
