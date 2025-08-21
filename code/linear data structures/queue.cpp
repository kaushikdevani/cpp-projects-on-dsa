#include <iostream>
using namespace std;
/*class Queue() should not be there,this silly mistake has been later removed
also if time is there change front and rear to private*/
class Queue
{
    public:
        int front = -1;
        int rear = -1;
        int arr[4];
        Queue()
        {
            for(int i=0; i<4; i++)
            {
                arr[i] = 0;
            }
        }

        bool isFull()
        {
            if(rear+1==size(arr))
                return true;
            else 
                return false;
        }

        bool isEmpty()
        {
            if(rear==-1 && front==-1)
                return true;
            else 
                return false;
        }


        void enqueue(int val)
        {
            if(isEmpty())
            {
                rear=front=0;
                arr[rear]=val;
            }

            else if (isFull())
            {
                cout << "The Queue is full, cannot add anymore\n";

            }
            else 
            {
                rear ++;
                arr[rear]=val;
            }
        }

        int dequeue()
        {
            if(isEmpty())
            {
                cout << "no elements to dequeue \n";
                return 0;
            }

            else if ( rear == front )
            {
                int dvalue =arr[rear];
                arr[rear]=0;
                rear=-1;
                front=-1;
                return dvalue;
            }

            else 
            {
                int dvalue = arr[front];
                arr[front]=0;
                front ++;
                return dvalue;
            }

        }

        int count ()
        {
            int x = rear - front +1;
            if(isEmpty())
                return 0;
            else 
                return x;
        }

        void display()
        {
            cout << "here is the diplay of the queue: \n";
            for(int i=0; i<4; i++)
            {
                cout << arr[i] << " ";
            }
        }

};

int main()
{
    int input;
    int val;
    Queue q1;
    do{
        cout << "What operation do you want to perform? select operation.\n";
        cout << "1. enqueue()\n";
        cout << "2. dequeue()\n";
        cout << "3. isEmpty()\n";
        cout << "4. isFull()\n";
        cout << "5. count()\n";
        cout << "6. display()\n";
        cout << "7. clearscreen()\n";
        cout << "Enter 0 to exit\n";

        cin >> input;

        switch(input)
        {
            case 1 :
                cout<< "Operarion Enqueue executed, enter the value to be enqueued: \n";
                cin >> val;
                
                if(q1.isFull())
                {
                    q1.enqueue(val);
                }
                else
                {
                    q1.enqueue(val);
                    cout << val << " has been enqueued.\n";
                }
                
                break;
            case 2 :
                cout<< "Operarion Dequeue executed\n";
                cout<< q1.dequeue() << " has been dequeued\n";
                break;
            case 3 :
                if(q1.isEmpty())
                {
                    cout << "The Queue is empty\n";
                }
                else 
                {
                    cout << "The Queue is not empty\n";
                }
                break;
            case 4:
                if(!q1.isFull())
                {
                    cout << "The Queue is not Full\n";
                }
                else 
                {
                    cout<< "The Queue is Full\n";
                }      
                break;      
            case 5:
                cout << q1.count()<< " no of items in the list.\n";
                break;
            case 6:
                q1.display();
                cout <<endl;
                break;
            case 7:
                system("CLS");
                break;

            default:
                if(input==0)
                    break;
                cout << "Enter valied option\n";
                break;

        }


    }while(input!=0);
}