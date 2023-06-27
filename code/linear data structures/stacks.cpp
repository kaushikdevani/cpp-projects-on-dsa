#include <iostream>
using namespace std;
/*Improvisations need to be done ex:methods has to have inputs, to show couts with values*/

class Stacks
{
    private:
        int lev = -1 ;
        int arr[5];
    public:
        Stacks()
        {
            for(int i=0;i<5;i++)
            {
                arr[i]=0;
            }
        
        }

        int count()
        {
            int cnt = lev + 1;
            return cnt;
        }

        bool isFull()
        {
            if(count()==5)
                return true;
            else 
                return false;
        }

        bool isEmpty()
        {
            if(count()==0)
                return true;
            else 
                return false;
        }

        void push()
        {
            if(isFull())
            {
                cout << "the stack in overflow state\n";
            }
            else
            {
                int val;
                cout << " Type the value you want to push: \n";
                cin >> val;
                lev ++ ;
                arr[lev] = val;
            }
        }
        
        int pop()
        {
            if(isEmpty())
            {
                cout << "the stack is empty\n";
                return 0;
            }
            else
            {
                int pnum = arr[lev];
                arr[lev]= 0;
                lev--;
                return pnum;

            }
        }

        int peak()
        {
            int pos;
            cout << "Enter the position at which you want to peek: \n";
            cin >> pos;
            return arr[pos];
        }

        void change()
        {
            int pos;
            int val;
            cout << "Enter the position at which you want to change: \n";
            cin >> pos;
            cout << "Enter the value to which you want to change: \n";
            cin >> val;

            arr[pos] = val;
        }
        
        void display()
        {
            cout << "Here is the complete stack: \n";
            for(int i=4;i>-1;i--)
            { 
                cout << arr[i]<<endl;
            }
        }

};

int main()
{
    Stacks st1;
    int userinput=1;

    do{
        cout << "select the opetarion that you want to perform, type the number :\n";
        cout << " 1. push() \n";
        cout << " 2. pop()\n";
        cout << " 3. isEmpty()\n";
        cout << " 4. isFUll()\n";
        cout << " 5. peek()\n";
        cout << " 6. count()\n";
        cout << " 7. change()\n";
        cout << " 8. display()\n";
        cout << " 9. clear screen\n";
        cout << "Enter 0 to exit.\n";

        
        cin >> userinput;

        switch(userinput)
        {
            case 1:
                st1.push();
                cout <<"The given value is sucessesfully pushed\n";
                break;
            
            case 2:
                cout << st1.pop() << " is popped out.\n";
                break;
            
            case 3:
                if(st1.isEmpty())
                {
                    cout << "the stack is empty\n";
                }    
                else
                {
                    cout << "the stack is not empty\n";
                }
                break;
            
            case 4:
                if(st1.isFull())
                {
                    cout << "the stack is full\n";
                }    
                else
                {
                    cout << "the stack is not Full\n";
                }
                break;

            case 5:
                cout << st1.peak() << "is the value \n";
                break;

            case 6:
                cout << st1.count()<<"is the no of occupied positions\n";
                break;

            case 7:
                st1.change();
                cout << "sucessesfully changed\n";
                break;

            case 8:
                "command prompt sucessful,\n";
                st1.display();
                break;

            case 9:
                system("CLS");
                break;

            case 0:
                break;


        }

    }while( userinput != 0);

    return 0;
}
