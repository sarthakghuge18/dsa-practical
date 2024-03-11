#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
};

class bst
{
public:
    node *root;
    bst()
    {
        root = NULL;
    }

    //***************************** create a tree ********************************************

    void create()
    {
        int num;
        cout << "enter the number of element insert : ";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            insert();
        }
    }

    //********************************** inserting node into a tree ****************************

    void insert()
    {
        int value;
        cout << "enter value : ";
        cin >> value;
        node *p = new node;
        p->data = value;
        p->left = NULL;
        p->right = NULL;

        if (root == NULL)
        {
            root = p;
        }
        else
        {
            node *temp = root;

            while (1)
            {
                if (p->data <= temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = p;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = p;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    //********************************** searching in tree ***********************************

    void search(int key)
    {
        node *temp = root;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << key << " found ";
                break;
            }
            else
            {
                if (key <= temp->data)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        if (temp == NULL)
        {
            cout << key << " not found ";
        }
    }

    //****************************** minimum data value in tree **********************************

    void minimum()
    {
        node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        cout << "minimum number is : " << temp->data;
    }

    //********************************** height of tree *****************************************

    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int ans;
        if (h1 > h2)
        {
            ans = h1 + 1;
        }
        else
        {
            ans = h2 + 1;
        }
        return ans;
    }

    //******************************************* preorder display tree ****************************

    void preorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    //******************************************* Inorder display tree ****************************

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    //******************************************* postorder display tree ****************************

    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    //*********************************** mirror of tree *****************************************

    int mirror(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        mirror(root->left);
        mirror(root->right);
        swap(root->left, root->right);
    }
};

// ****************************************** main function ***************************************

int main()
{
    bst b;
    int choice;
    do
    {
        cout << "\n1.create\n2.insert\n3.search\n4.minimum\n5.height\n6.mirror\n7.display\n8.exit\n";
        cout << "enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.create();
            break;

        case 2:
            b.insert();
            break;

        case 3:
            int key;
            cout << "search value : ";
            cin >> key;
            b.search(key);
            break;

        case 4:
            b.minimum();
            break;

        case 5:
            cout<<"the height of tree : "<<b.height(b.root);
            break;

        case 6:
            b.mirror(b.root);
            break;

        case 7:
            cout<<"\npreorder : ";
            b.preorder(b.root);
            cout<<"\ninorder : ";
            b.inorder(b.root);
            cout<<"\npostorder : ";
            b.postorder(b.root);
            break;

        case 8:
            cout << "exited successfully .........";
            break;

        default:
            cout << "enter the valid number ?????";
            break;
        }

    } while (choice != 8);
}