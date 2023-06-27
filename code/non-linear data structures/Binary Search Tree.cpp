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

class BST
{
    public:
        TreeNode* root;

        BST()
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

        void insertNode(TreeNode* node)
        {
            if (root==NULL)
                root = node;
            else
            {
                TreeNode* temp=root;
                while(temp!=NULL)
                {
                    if ( temp->value==node->value)
                    {
                        cout << "Duplicate values not allowed\n";
                        break;
                    }
                    else if (node->value<temp->value)
                    {
                        if (temp->left==NULL)
                        {
                            temp->left = node;
                            break;
                        }
                        else
                            temp = temp->left;
                    }
                    else if (node->value>temp->value)
                    {
                        if (temp->right==NULL)
                        {
                            temp->right = node;
                            break;
                        }
                        else
                            temp = temp->right;
                    }
                }
            }
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

        TreeNode* iterativeSearch(int value)
        {
            if (root==NULL)
                return root;
            else 
            {
                TreeNode* temp=root;
                while (temp!=NULL)
                {
                    if (value == temp->value)
                        return temp;
                    else if (value < temp->value)
                        temp = temp->left;
                    else
                        temp = temp->right;
                }
            }
            return NULL;
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

        TreeNode* minValueNode(TreeNode* r)
        {
            TreeNode* current =r;
            if (current == NULL)
                return NULL;
            else
            {
                while(current->left!=NULL)
                {
                    current = current->left;
                }
                return current;
            }
        }
        TreeNode* deleteNode(TreeNode* r, int val)
        {
            if (r==NULL)
                return NULL;
            else if(val<r->value)
                r->left = deleteNode(r->left,val);
            else if (val>r->value)
                r->right = deleteNode(r->right,val);
            else
            {
                if (r->left==NULL)
                {
                    TreeNode* temp = r->right;
                    delete r;
                    return temp;
                }
                else if (r->right==NULL)
                {
                    TreeNode* temp = r->left;
                    delete r;
                    return temp;
                }
                else
                {
                    TreeNode* minValNode = minValueNode(r->right);
                    r->value = minValNode->value;
                    r->right= deleteNode(r->right,minValNode->value);
                }
            }
            return r;
        }


};

int main()
{
    int option,value;
    BST bst1;
    
    do{
        cout<<"What operation do you want to perform?\n"<<"Select operation number, or enter 0 to exit.\n";
        cout<<"1.Insert Node"<<endl;
        cout<<"2.Search Node"<<endl;
        cout<<"3.Delete Node"<<endl;
        cout<<"4.Print BST values"<<endl;
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
                bst1.insertNode(node);
                break;
            case 2:
                cout<<"Enter the value of TreeNode that you want to search: ";
                cin>>value;
                if(bst1.iterativeSearch(value)==NULL)
                    cout<<"Given value is not in tree\n";
                else   
                    cout<< "Value found in the tree.\n";
                break;
            case 3:
                cout<< "Enter the value that you want to delete: ";
                cin>>value;
                if (bst1.iterativeSearch(value)!=NULL)
                {
                    bst1.deleteNode(bst1.root,value);
                    cout<<"Value deleted\n";
                }
                else
                    cout<<"No node with given value exists\n";
                break;
            case 4:
                cout<<"2D print-\n";
                bst1.print2D(bst1.root,5);
                cout<<endl;
                cout<<"InOrder print-\n";
                bst1.printInOrder(bst1.root);
                cout<<endl;
                cout<<"PreOrder print-\n";
                bst1.printPreOrder(bst1.root);
                cout<<endl;
                cout<<"PostOrder print-\n";
                bst1.printPostOrder(bst1.root);
                cout<<endl;
                cout<<"Breath Order print-\n";
                bst1.printLevelOrderBFS(bst1.root);
                cout<<endl;
                break;
            case 5:
                cout<<"Height of the tree is "<<bst1.height(bst1.root)<<endl;
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