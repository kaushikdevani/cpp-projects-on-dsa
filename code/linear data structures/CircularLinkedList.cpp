#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        int value;
        Node* next;

        Node()
        {
            key=0;
            value=0;
            next=NULL;
        }

        Node(int k,int val)
        {
            key=k;
            value=val;
        }
};

class CircularLinkedList
{
    public:
        Node* head;

        CircularLinkedList()
        {
            head=NULL;
        }
        
        Node* nodeExists(int k)
        {
            Node* str = head;
            Node* temp = NULL;            
            if (head==NULL)
            { 
                cout << "The list is empty\n";
                return temp;
            }
            else 
            {
                do{
                    if (str->key==k)
                    {
                        temp = str;
                    }
                    str=str->next;
                }while(str!=head);
                return temp;
            }
        }

        void appendNode(Node* n)
        {

            if (nodeExists(n->key)!=NULL)
            {
                cout << "key already exist, try again with different key\n";
            }
            else
            {
                if (head==NULL)
                {
                    head=n;
                    head->next=head;
                    cout << "append success!\n";
                }
                else
                {
                    Node* str = head->next;
                    if (str==NULL){str=head;}
                    while(str->next!=head)
                    {
                        str=str->next;
                    }
                    str->next=n;
                    n->next=head;
                    cout << "append success!\n";
                }
            }
        }

        void prependNode(Node* n)
        {
            if (nodeExists(n->key)!=NULL)
            {
                cout << "key already exist, try again with different key\n";
            }
            else
            {
                if (head==NULL)
                {
                    head=n;
                    head->next=head;
                    cout << "append success!\n";
                }
                else
                {
                    n->next=head;
                    Node* str = head->next;
                    if (str==NULL){str=head;}
                    while(str->next!=head)
                    {
                        str=str->next;
                    }
                    str->next=n;
                    head=n;
                    cout << "append success!\n";                  
                }
            }
        }

        void insertNode(int k, Node* n)
        {
            if (nodeExists(k)==NULL)
            {
                cout << "Insert Failed\nEntered key does not exist.\n";
            }
            else
            {
                if (nodeExists(n->key)!=NULL)
                {
                    cout << "Insert Failed\n";
                    cout <<" The new nodes key already exists, try again with different key\n";
                }
                else
                {
                    Node* temp=nodeExists(k);
                    n->next=temp->next;
                    temp->next=n;
                    cout << "Insert Sucessful! inserted after key: "<<k<<endl;
                }
            }
        }

        void deleteNode(int k)
        {
            if (nodeExists(k)==NULL)
            {
                cout << "Insert Failed\nEntered key does not exist.\n";
            } 
            else 
            {
                Node* temp=nodeExists(k);

                if (temp==head)
                {
                    if(head->next==head)
                    {head=NULL;
                    cout << "Delete successful!\nThe first elt is delinked.\n";}
                    else
                    {
                        Node* str = head;
                        do{
                            str=str->next;
                        }while(str->next!=head);
                        str->next=head->next;
                        head = head->next;
                        cout << "Delete successful!\nThe first elt is delinked.\n";
                    //     head=head->next;
                    //     Node* str = head->next;
                    //     if (str==NULL){str=head;}
                    //     while(str->next!=head)
                    //     {
                    //         str=str->next;
                    //     }
                    //     str->next=head;
                    //     cout << "Delete Sucessful! delinked the entry with key: "<<k<<endl;
                    }                    
                }
                else
                {
                    Node* str = head;
                    do{
                        str=str->next;
                    }while(str->next!=temp);
                    str->next=temp->next;   
                    cout << "Delete Sucessful! delinked the entry with key: "<<k<<endl;                 
                    // Node* nextnode = temp;
                    // do{
                    //     temp=temp->next;
                    // }while(temp->next!=temp);
                    // temp->next=nextnode->next;
                    // cout << "Delete Sucessful! delinked the entry with key: "<<k<<endl;
                }
            }
        }

        void updateNode(int k,int val)
        {
            if (nodeExists(k)==NULL)
            {
                cout << "Update Failed\nEntered key does not exist.\n";
            } 
            else 
            {
                Node* temp=nodeExists(k);
                temp->value=val;
                cout << "Update Sucessful! updated the entry with key: "<<k<<" to value: "<<val<<endl;
            }            
        }

        void show()
        {
            if (head==NULL)
            {
                cout<< "No elemnts to show";
            }
            else
            {
                Node* str= head;
                cout<<"Printing the linked list:\n";
                do{
                    cout << "("<<str->key<<","<<str->value<<")"<<"<-->";
                    str=str->next;
                }while(str!=head);
            }            
        }
};

int main()
{
    int input;
    int key;
    int value;
    CircularLinkedList c;

    do{
        cout << "\nselect the operation that you want to perform, type the number :\n";
        cout << " 1. appendNode() \n";
        cout << " 2. prependNode()\n";
        cout << " 3. insertNode()\n";
        cout << " 4. deleteNode()\n";
        cout << " 5. updateNode()\n";
        cout << " 6. show()\n";
        cout << " 7. clear screen()\n";
        cout << "Enter 0 to exit.\n";
       
        cin >> input;

        Node* n1 = new Node;

        switch(input)
        {
            case 1:
                cout<< "Type the key and value of the Node that you want to append\n";
                cin >> key;
                cin >> value;
                
                n1->key=key;
                n1->value=value;
                c.appendNode(n1);

                break;

            case 2:
                cout<< "Type the key and value of the Node that you want to prepend\n";
                cin >> key;
                cin >> value;
                
                n1->key=key;
                n1->value=value;
                c.prependNode(n1);

                break;

            case 3:
                cout << "Type the key of Node after which you want to insert\n";
                int k;
                cin >> k;
                
                cout<< "Type the key and value of the Node that you want to insert\n";
                cin >> key;
                cin >> value;
                n1->key=key;
                n1->value=value;

                c.insertNode(k,n1);

                break;
            case 4:
                cout << "Type the key of Node which you want to delete\n";
                cin >> key;

                c.deleteNode(key);
                break;
            case 5:
                cout << "Type the key of Node which you want to update\n";
                cin >> key;
                cout << "Enter the new value\n";
                cin >> value;

                c.updateNode(key,value);
                break;
            case 6:
                c.show();
                break;
            case 7:
                system("CLS");
                break;
            default:
                cout << "enter valied number\n";
        }
    }while(input!=0);
    return 0;
}