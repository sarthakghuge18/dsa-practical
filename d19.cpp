#include <iostream>
using namespace std;

struct AVLnode
{
    int word;
    string mean;
    AVLnode *left, *right;
    int iHT;
};

class AVLtree
{

public:
    AVLnode *root;
    AVLtree()
    {
        root = NULL;
    }

    // inserting node in the avltree with its meaning

    AVLnode *insert(AVLnode *root, int w, string m)
    {

        // if root is null

        if (root == NULL)
        {
            root = new AVLnode;
            root->left = root->right = NULL;
            root->word = w;
            root->mean = m;
            root->iHT = 0;
        }

        else if (root->word != w)
        {

            if (root->word < w)
            {
                root->right = insert(root->right, w, m);
            }

            else
            {
                root->left = insert(root->left, w, m);
            }
        }

        else
        {

            cout << "\nRebundant Avlnode" << endl;
        }

        root->iHT = max(height(root->left), height(root->right)) + 1;

        if (bFactor(root) == 2)
        {
            if (root->left->word > w)
            {
                root = rr(root);
            }
            else
            {
                root = lr(root);
            }
        }

        if (bFactor(root) == -2)
        {
            if (root->right->word > w)
            {
                root = rl(root);
            }
            else
            {
                root = ll(root);
            }
        }

        return root;
    }

    // deleting node in the avltree with its meaning
    AVLnode *delete_node(AVLnode *curr, int x)
    {

        AVLnode *temp;
        if (curr == NULL)
        {
            cout << "\nWord not present!\n";
            return curr;
        }

        else if (x > curr->word)
            curr->right = delete_node(curr->right, x);

        else if (x < curr->word)
            curr->left = delete_node(curr->left, x);

        else if (curr->right == NULL || curr->left == NULL)
        {
            curr = curr->left ? curr->left : curr->right;
            cout << "\nWord deleted Successfully!\n";
        }

        else
        {
            temp = curr->right;
            while (temp->left)
                temp = temp->left;
            curr->word = temp->word;
            curr->right = delete_node(curr->right, temp->word);
        }

        if (curr == NULL)
            return curr;

        curr->iHT = max(height(curr->left), height(curr->right)) + 1;

        if (bFactor(curr) == 2)
        {
            if (bFactor(curr->left) >= 0)
                curr = rr(curr);
            else
                curr = lr(curr);
        }

        if (bFactor(curr) == -2)
        {
            if (bFactor(curr->right) <= 0)
                curr = ll(curr);
            else
                curr = rl(curr);
        }

        return (curr);
    }

    // rotation

    AVLnode *rr(AVLnode *curr)
    {
        AVLnode *temp = curr->left;
        curr->left = temp->right;
        temp->right = curr;
        curr->iHT = max(height(curr->left), height(curr->right)) + 1;
        temp->iHT = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }

    AVLnode *ll(AVLnode *curr)
    {
        AVLnode *temp = curr->right;
        curr->right = temp->left;
        temp->left = curr;
        curr->iHT = max(height(curr->left), height(curr->right)) + 1;
        temp->iHT = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }

    AVLnode *rl(AVLnode *curr)
    {
        curr->right = rr(curr->right);
        return ll(curr);
    }

    AVLnode *lr(AVLnode *curr)
    {
        curr->left = ll(curr->left);
        return rr(curr);
    }

    // height calculation

    int height(AVLnode *curr)
    {
        if (curr == NULL)
        {
            return -1;
        }
        else
        {
            return curr->iHT;
        }
    }

    // bFactor

    int bFactor(AVLnode *curr)
    {
        if (curr == NULL)
        {
            return -1;
        }
        else
        {
            return height(curr->left) - height(curr->right);
        }
    }

    // displaying

    void inOrder(AVLnode *curr)
    {
        if (curr != NULL)
        {
            inOrder(curr->left);
            cout << "\n\t" << curr->word << "\t" << curr->mean;
            inOrder(curr->right);
        }
    }

    void preOrder(AVLnode *curr)
    {
        if (curr != NULL)
        {
            cout << "\n\t" << curr->word << "\t" << curr->mean;
            preOrder(curr->left);
            preOrder(curr->right);
        }
    }
};

int main()
{
    int ch;
    AVLtree avl;
    AVLnode *temp = NULL;
    int word;
    string mean;
    cout << "\n--------------------------------------";
    cout << "\n\tAVL TREE IMPLEMENTATION";
    cout << "\n--------------------------------------";
    do
    {
        cout << "\n\t\tMENU";
        cout << "\n1.Insert 2.Inorder 3.Delete 4.Exit";
        cout << "\n--------------------------------";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter Word: ";
            cin >> word;
            cout << "\nEnter Meaning: ";
            cin >> mean;
            avl.root = avl.insert(avl.root, word, mean);
            break;
        case 2:
            cout << "\nInorder Traversal:\n\tWORD\tMEANING";
            avl.inOrder(avl.root);
            cout << "\n\nPreorder Traversal:\n\tWORD\tMEANING";
            avl.preOrder(avl.root);
            cout << '\n';
            break;
        case 3:
            cout << "\nEnter the word to be deleted : ";
            cin >> word;
            avl.root = avl.delete_node(avl.root, word);
            break;
        case 4:
            exit(0);
        }
    } while (ch != 4);
}