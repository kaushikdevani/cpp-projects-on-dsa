#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        int val;
        Node* next;

        Node()
        {
            key=0;
            val=0;
            next=NULL;
        }

        Node(int k, int v)
        {
            key=k;
            val=v;
            next=NULL;
        }

};

class SinglylinkedList
{
    public:
        Node* head;
        SinglylinkedList()
        {
            head=NULL;
        }
        SinglylinkedList(Node* n)
        {
            head=n;
        }

        Node* keyExist(int k)
        {
            Node* temp =NULL;
            Node* str = head;
            if (head==NULL)
            {
                return temp;
            }

            else
            {
                if(head->key==k)
                {
                    temp=head;
                }
                else
                {
                    do{
                        if(str->next!=NULL)
                        {
                            str=str->next;
                        }
                        
                        if (str->key==k)
                        {
                            temp=str;
                        }
                    }while(str->next!=NULL);
                }
                return temp;
            }
        }
        void appendNode(Node* n)
        {
            if (keyExist(n->key)!=NULL)
            {
                cout << keyExist(n->key)->val << " "<<  keyExist(n->key)->key << " "<<  keyExist(n->key)->next;
                cout << "cannot be appended, key already exist, try using a different key\n";
            }
            else 
            {
                if (head==NULL)
                {
                    head=n;
                    cout << "Append successful\n";
                }
                else 
                {
                    Node* str = head;
                    while (str->next!=NULL)
                    {
                        str=str->next;
                    }
                    str->next = n;
                    cout << "Append successful\n";
                }
            }

        }

        void prependNode(Node* n)
        {
            if (keyExist(n->key)!=NULL)
            {
                cout << "cannot be appended, key already exist, try using a different key\n";
            }
            else 
            {
                if (head==NULL)
                {
                    head=n;
                    cout << "Prepend successful\n";
                }
                else 
                {
                    n->next = head;
                    head = n;
                    cout << "prepend successful\n";
                }
            }
        }

        void insertNode(int k, Node* n)
        {
            if (keyExist(k)==NULL)
            {
                cout << "the entered key is invalied\n";
            }
            else
            {
                if (keyExist(n->key)!=NULL)
                {
                    cout << "cannot be appended, key already exist, try using a different key\n";
                }
                else
                {
                Node* temp = keyExist(k);
                n->next=temp->next;
                temp->next = n;
                cout << "Insert successful\n";
                }
            }
        }

        void deleteNode(int k)
        {
            if (keyExist(k)==NULL)
            {
                cout << "the entered key is invalied\n";
            }
            else
            {
                Node* temp = keyExist(k);
                if (temp==NULL)
                {
                    cout << "delete failed! The List is empty";
                }
                else
                {
                    Node* str = head;
                    if (head->key==k)
                    {
                        head=head->next;
                        cout << "delete successful\n";
                    }
                    else
                    {
                        while (str->next->key!=k)
                        {
                            str = str->next;
                        }
                        str->next=temp->next;
                        cout << "delete successful! Node with key:"<< k << " has been delinked\n";
                    }

                }

            }
        }
        void updateNode(int k, int val)
        {
            if (keyExist(k)==NULL)
            {
                cout << "the entered key is invalied\n";
            }
            else 
            {
                Node* temp = keyExist(k);
                temp->val = val;
                cout << "Update successful\n";
            }
        }

        void show()
        {
            if(head==NULL)
            { cout<< "the list is empty\n";}
            else
            {
                cout << "here is the list:\n";
                Node* str = head;
                while( str !=NULL)
                {
                    cout<<"("<<str->key<<","<<str->val<<")"<<"-->";
                    str=str->next;
                }
            }
            
        }

};

int main()
{
    int input;
    int key;
    int value;
    SinglylinkedList s;

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
                n1->val=value;
                s.appendNode(n1);

                break;

            case 2:
                cout<< "Type the key and value of the Node that you want to prepend\n";
                cin >> key;
                cin >> value;
                
                n1->key=key;
                n1->val=value;
                s.prependNode(n1);

                break;

            case 3:
                cout << "Type the key of Node after which you want to insert\n";
                int k;
                cin >> k;
                
                cout<< "Type the key and value of the Node that you want to insert\n";
                cin >> key;
                cin >> value;
                n1->key=key;
                n1->val=value;

                s.insertNode(k,n1);

                break;
            case 4:
                cout << "Type the key of Node which you want to delete\n";
                cin >> key;

                s.deleteNode(key);
                break;
            case 5:
                cout << "Type the key of Node which you want to update\n";
                cin >> key;
                cout << "Enter the new value\n";
                cin >> value;

                s.updateNode(key,value);
                break;
            case 6:
                s.show();
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