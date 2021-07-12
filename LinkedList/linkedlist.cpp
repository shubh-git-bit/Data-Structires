// This is a code for creation and displaying linked list
//nodes are inserted at the beginning of the list
#include <iostream>
using namespace std;
class Node //user defined data structure called node which has 2 fields: data and pointer to next node
{
    public: //public since all the functions need to access it
    int data; //to store the data
    Node* next; //to store the address of the next node
};
Node* head; //global node pointer 
Node* temp1;




void insertionAtBeginning(int data) //function to insert nodes at the beginning (data is passed by the main function)
{
    Node* temp = new Node(); //temp node pointer points to a new node created
    temp->data = data; //data is modified using the temp pointer
    temp->next = NULL; //the address of this node is set to NULLL using the temp pointer
    if(head == NULL) /*if its a empty list i.e, head node is pointing to NULL then let the head point to the same node
                         which temp is pointing to*/
    {
        head = temp;
        temp1 = head;
    }
    else /*if the list is already created and you want to enter the node at the beginning then first create a new node pointer temp1
        which points to the same node as head is pointing to
         then let head point to the newly created node and then using temp pointer the address field of the newly created node is set to 
         address of the old node which temp1 is pointing to*/
    {
        Node* temp1 = head; 
        head = temp;
        temp->next = temp1; /*please don't make the mistake of temp->next = temp1->next because that would mean the previous node's address pinter is being set to the new node's address field which is 
                            basically NULL. so the links won't be connected at all*/
    }
}



void insertionAtEnd(int data) //function to insert nodes at the end
{
    Node* temp = new Node(); //new node is created and temp points to it
    temp->data = data; //using temp its data is set
    temp->next = NULL; //the next link is set to NULL
    if(head == NULL) //if this is the first node
    {
        head = temp; //head points to the same node (first node) which temp is pointing to
        temp1 = head; //a new global pointer temp1 points to the same node which head does. This will come in handy. This is the key step
    }
    else        //means that list already has one or mode nodes. We need to append the node at the end of the list now
    {
        temp1->next = temp; /*the newly created node's address is taken by temp1's node's next field which means 
                            the latest node is linked to newly created node. How is it latest? we'll come to know in the next line*/
        temp1 = temp1->next; /*when head pointed to first node temp1 also pointed to first node. initially first node's address was NULL.
                                now, we need to store address of newly created node to the first node's next field. using temp1, we access
                                the first node's next field and set it to temp. After that temp1 points to the new node when we say temp1 = 
                                temp1->next*/
    }
}


void insertionAtNthPosition(int data, int position)
{
     Node* temp1;
    int counter=1;
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    temp1 = head;
    if(position<=0)
    {
        cout<<"Invalid position! cannot insert"<<endl;
        return;
    }
    if(position==1)
    {
        temp->next = temp1;
        head = temp;
        return;
    }
    Node* checker = head;
    while(checker!=NULL)
    {
        counter++;
        checker = checker->next;
    }
    if(position>counter)
    {
        cout<<"Invalid position! cannot insert"<<endl;
        return;
    }
    for(int i=0;i<position-2;i++)
    {
        temp1=temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void print() //function to print the linked list
{
    Node* temp = head; //using a temp node pointer to traverse. We don't use head because links will break
    cout<<"LIST:"<<endl;
    while(temp!=NULL) //while it doesnt point to NULL
    {
        cout<<temp->data<<"--->";
        temp = temp->next; /*temp points to next node. temp is used to acess the next address and that is set to temp. which means temp
                            is now pointing to next node*/
    }
    cout<<"NULL"<<endl;
}



int main()
{
    int n,data,method,position;
    string rank="";
    char flag;
    do{
        cout<<"********LINKED LIST********"<<endl;
        cout<<"How do you want to insert?"<<endl<<"1- at the beginning"<<endl<<"2- at the end"<<endl<<"3-insert at nth position"<<endl<<"4- display my list"<<endl;
        cin>>method;
        switch (method)
        {
            case 1: 
                cout<<"How many elements do you want to enter?"<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    if(i==0)
                        rank = "st";
                    else if(i==1)
                        rank = "nd";
                    else if(i==2)
                        rank = "rd";
                    else
                    rank = "th";
                    cout<<"Enter the "<<i+1<<rank<<" element to insert"<<endl;
                    cin>>data;
                    insertionAtBeginning(data);
                }
                print();
                break;
            case 2:
                cout<<"How many elements do you want to enter?"<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                     if(i==0)
                        rank = "st";
                    else if(i==1)
                        rank = "nd";
                    else if(i==2)
                        rank = "rd";
                    else
                    rank = "th";
                    cout<<"Enter the "<<i+1<<rank<<" element to append"<<endl;
                    cin>>data;
                    insertionAtEnd(data);
                }
                print();
                break;
            case 3:
                cout<<"Enter the position at which you want to insert"<<endl;
                cin>>position;
                cout<<"Enter the data to be inserted"<<endl;
                cin>>data;
                insertionAtNthPosition(data,position);
                print();
                break;
            case 4:
                print();
                break;
            default:
                break;
        }
        cout<<"continue program?(y/n)"<<endl;
        cin>>flag;
    }while(flag=='Y' || flag=='y');
    cout<<"THANK YOU!"<<endl;
    
    return 0;
}