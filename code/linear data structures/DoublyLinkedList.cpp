#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        int value;
        Node* previous;
        Node* next;

        Node()
        {
            key=0;
            value=0;
            previous=NULL;
            next=NULL;
        }

        Node(int k,int val)
        {
            key=k;
            value=val;
        }
};

class DoublyLinkedlist
{
    public:
        Node* head;

        DoublyLinkedlist()
        {
            head=NULL;
        }

        Node* nodeExist(int k)
        {
            Node* temp = NULL;
            Node* ptr = head ;
            if(head==NULL)
            {
                return temp;
            }
            else 
            {
                while(ptr != NULL)
                {
                    if(ptr->key==k)
                    {
                        temp=ptr;
                    }
                    ptr = ptr->next;
                }
                return temp;
            }
        }

        void appendNode(Node* n)
        {
            if (nodeExist(n->key)!=NULL)
            {
                cout << "key already exist, try again with different key\n";
            }
            else
            {
                if (head==NULL)
                {
                    head=n;
                    cout << "append success!\n";
                }
                else
                {
                    Node* str =head;
                    while(str->next!=NULL)
                    {
                        str = str->next;
                    }
                    str->next=n;
                    n->previous=str;
                    cout << "append success!\n";
                }

            }
        }

        void prependNode(Node* n)
        {
            if (nodeExist(n->key)!=NULL)
            {
                cout << "key already exist, try again with different key\n";
            }
            else
            {
                if (head==NULL)
                {
                    head=n;
                    cout << "prepend success!\n";
                }
                else
                {
                    head->previous=n;
                    n->next=head;
                    head=n;
                    cout << "prepend success!\n";
                }
            }
        }

        void insertNode(int k, Node* n)
        {
            if (nodeExist(k)==NULL)
            {
                cout << "Insert Failed\nEntered key does not exist.\n";
            }
            else
            {
                if (nodeExist(n->key)!=NULL)
                {
                    cout << "Insert Failed\n";
                    cout <<" The new nodes key already exists, try again with different key\n";
                }
                else
                {
                    Node* temp=nodeExist(k);
                    if(temp->next!=NULL){temp->next->previous=n;}
                    n->previous=temp;
                    n->next=temp->next;
                    temp->next=n;
                    cout << "Insert Sucessful! inserted after key: "<<k<<endl;
                }
            }
        }

        void deleteNode(int k)
        {
            if (nodeExist(k)==NULL)
            {
                cout << "Insert Failed\nEntered key does not exist.\n";
            } 
            else 
            {
                Node* temp=nodeExist(k);

                if (temp==head)
                {
                    if(head->next!=NULL){ head=head->next;}
                    else {head=NULL;}
                    cout << "Delete successful!\nThe first elt is delinked.\n";
                }
                else if(temp->next==NULL)
                {
                    temp->previous->next=NULL;
                    cout << "Delete successful!\n the last element is delinked.\n";
                }
                else
                {
                    temp->previous->next=temp->next;
                    temp->next->previous=temp->previous;
                    cout << "Delete Sucessful! delinked the entry with key: "<<k<<endl;
                }

            }
        }

        void updateNode(int k ,int val)
        {
            if (nodeExist(k)==NULL)
            {
                cout << "Update Failed\nEntered key does not exist.\n";
            } 
            else 
            {
                Node* temp=nodeExist(k);
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
                while(str!=NULL)
                {
                    cout<<"("<<str->key<<","<<str->value<<")"<<"<-->";
                    str=str->next;
                }
                cout<<endl;
            }
        }
};


int main()
{
    int input;
    int key;
    int value;
    DoublyLinkedlist d;

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
                d.appendNode(n1);

                break;

            case 2:
                cout<< "Type the key and value of the Node that you want to prepend\n";
                cin >> key;
                cin >> value;
                
                n1->key=key;
                n1->value=value;
                d.prependNode(n1);

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

                d.insertNode(k,n1);

                break;
            case 4:
                cout << "Type the key of Node which you want to delete\n";
                cin >> key;

                d.deleteNode(key);
                break;
            case 5:
                cout << "Type the key of Node which you want to update\n";
                cin >> key;
                cout << "Enter the new value\n";
                cin >> value;

                d.updateNode(key,value);
                break;
            case 6:
                d.show();
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