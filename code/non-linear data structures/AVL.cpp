#include <iostream>
using namespace std;
#define globalspace 5

class TreeNode
{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode()
        {
            value=0;
            left=NULL;
            right=NULL;
        }
        TreeNode(int v)
        {
            value=v;
            left=NULL;
            right=NULL;
        }
};

class AVL
{
    public:
        TreeNode* root;

        AVL()
        {
            root = NULL;
        }

        bool isEmpty()
        {
            if (root==NULL)
                return true;
            else
                return false;
        }

        void printPreOrder(TreeNode* r)
        {
            if (r == NULL)
                return;
            cout << r->value << "  ";
            printPreOrder(r->left);
            printPreOrder(r->right);
        }

        void printInOrder(TreeNode* r)
        {
            if (r==NULL)
                return;
            printInOrder(r->left);
            cout<<r->value<< "  ";
            printInOrder(r->right);
        }

        void printPostOrder(TreeNode* r)
        {
            if (r==NULL)
                return;
            printPostOrder(r->left);
            printPostOrder(r->right);
            cout<<r->value<<"  ";
        }

        void print2D(TreeNode* r,int space)
        {
            if (r==NULL)
                return;
            space = space + globalspace;
            print2D(r->right,space);
            cout<<endl;
            for(int i = globalspace; i<space;i++)
            {
                cout<<" ";
            }
            cout<<r->value<<endl;
            print2D(r->left,space);
        }
     
        void printGivenLevel(TreeNode* r, int level)
        {
            if(r==NULL)
                return;
            else if (level==0)
                cout<<r->value<<" ";
            else
            {
                printGivenLevel(r->left,level-1);
                printGivenLevel(r->right,level-1);
            }
        }
        void printLevelOrderBFS(TreeNode* r)
        {
            int h = height(r);
            for (int i=0;i<=h;i++)
                printGivenLevel(r,i);
        }

        int height(TreeNode* r)
        {
            if (r==NULL)
                return -1;
            else
            {
                int lheight = height(r->left);
                int rheight = height(r->right);
                if (lheight>rheight)
                    return lheight+1;
                else 
                    return rheight+1;
            }
        }

        int getBalanceFactor(TreeNode* r)
        {
            int lheight = height(r->left);
            int rheight = height(r->right);
            return lheight-rheight;
        }

        TreeNode* rotateRight(TreeNode* r)
        {
            TreeNode* x = r->left;
            TreeNode* y = x->right;
            x->right =r;
            r->left = y;
            return x;
        }
        TreeNode* rotateLeft(TreeNode* r)
        {
            TreeNode* x = r->right;
            TreeNode* y = x->left;
            x->left = r;
            r->right = y;
            return x;
        }

        TreeNode* insertNode(TreeNode* r, TreeNode* newNode)
        {
            if (r==NULL)
            {
                r=newNode;
                cout << "Value successfully inserted.\n";
                return r;
            }

            else if (newNode->value < r->value)
            {
                r->left = insertNode(r->left,newNode);
            }

            else if (newNode->value > r->value)
            {
                r->right = insertNode(r->right,newNode);
            }

            else
            {
                cout<< "No Duplicate values allowed\n";
                return r;
            }

            int bf = getBalanceFactor(r);

            if (bf>1 && newNode->value<r->left->value)
            {
                return rotateRight(r);//left-left imbalance
            }
            else if (bf<-1 && newNode->value>r->right->value)
            {
                return rotateLeft(r);//right-right imbalance
            }
            else if (bf>1 && newNode->value>r->left->value)
            {
                r->left = rotateLeft(r->left); //left-right imbalance
                return rotateRight(r);
            }
            else if (bf<-1 && newNode->value<r->right->value)
            {
                r->right = rotateRight(r->right);//right-left imbalance
                return rotateLeft(r);
            }



            return r;
        }
};


int main()
{
    int option,value;
    AVL avl;
    
    do{
        cout<<"What operation do you want to perform?\n"<<"Select operation number, or enter 0 to exit.\n";
        cout<<"1.Insert Node"<<endl;
        cout<<"2.Search Node"<<endl;
        cout<<"3.Delete Node"<<endl;
        cout<<"4.Print AVL values"<<endl;
        cout<<"5.Height of the tree"<<endl;
        cout<<"6.Clear Screen"<<endl;
        cin>>option;
        TreeNode* node = new TreeNode;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Insert the value of the new node: ";
                cin>>value;
                node->value = value;
                avl.root=avl.insertNode(avl.root,node);
                break;
            // case 2:
            //     cout<<"Enter the value of TreeNode that you want to search: ";
            //     cin>>value;
            //     if(avl.iterativeSearch(value)==NULL)
            //         cout<<"Given value is not in tree\n";
            //     else   
            //         cout<< "Value found in the tree.\n";
            //     break;
            // case 3:
            //     cout<< "Enter the value that you want to delete: ";
            //     cin>>value;
            //     if (avl.iterativeSearch(value)!=NULL)
            //     {
            //         avl.deleteNode(avl.root,value);
            //         cout<<"Value deleted\n";
            //     }
            //     else
            //         cout<<"No node with given value exists\n";
            //     break;
            case 4:
                cout<<"2D print-\n";
                avl.print2D(avl.root,5);
                cout<<endl;
                cout<<"InOrder print-\n";
                avl.printInOrder(avl.root);
                cout<<endl;
                cout<<"PreOrder print-\n";
                avl.printPreOrder(avl.root);
                cout<<endl;
                cout<<"PostOrder print-\n";
                avl.printPostOrder(avl.root);
                cout<<endl;
                cout<<"Breath Order print-\n";
                avl.printLevelOrderBFS(avl.root);
                cout<<endl;
                break;
            case 5:
                cout<<"Height of the tree is "<<avl.height(avl.root)<<endl;
                break;
            case 6:
                system("CLS");
                break;
            default:
                cout<<"Enter proper option number"<< endl;
                break;
        }
    }while(option!=0);
    return 0;
}