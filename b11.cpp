#include <iostream>
using namespace std;

class node
{
public:
    string word;
    string meaning;
    node *left;
    node *right;

    node(string x, string y)
    {
        word = x;
        meaning = y;
        left = NULL;
        right = NULL;
    }
};

class dictionary
{

public:
    node *root;
    node *q;

    dictionary()
    {
        root = NULL;
        q = NULL;
    }

    //***************************** inserting node *******************************

    void insert(node *p, string key, string meaning)
    {
        if (key < p->word)
        {
            if (p->left != NULL)
            {
                insert(p->left, key, meaning);
            }
            else
            {
                p->left = new node(key, meaning);
            }
        }
        else if (key > p->word)
        {
            if (p->right != NULL)
            {
                insert(p->right, key, meaning);
            }
            else
            {
                p->right = new node(key, meaning);
            }
        }
    }

    //******************************** check comparision required *********************

    void comparision(node *p, string key)
    {
        static int count = 0;
        while (p != NULL)
        {
            if (key < p->word)
            {
                count++;
                p = p->left;
            }
            else if (key > p->word)
            {
                count++;
                p = p->right;
            }

            else if (key == p->word)
            {
                count++;
                cout << "number of comaparision to find the word : " << count << endl;
                return;
            }
        }
    }

    //***************************** updating node meaning *************************

    void update(node *p, string key)
    {
        while (p != NULL)
        {
            if (key < p->word)
            {
                p = p->left;
            }
            else if (key > p->word)
            {
                p = p->right;
            }

            else if (key == p->word)
            {
                cout << "enter its new meaning : ";
                cin >> p->meaning;
                return;
            }
        }

        cout << "\nword not found " << endl;
    }

    //******************************* deleting node ********************************

    void delete_node(node* p, string key){
        node* s;
        while (p != NULL){
            if(key < p->word){
                q = p;
                p = p->left;
            }
            else if(key > p->word){
                q = p;
                p = p->right;
            }else if(key == p->word){   //word found 

                //************* no child ***************

                if(p->left == NULL && p->right == NULL){   
                    if(q->left == p){
                        delete p;
                        q->left = NULL;
                        return;
                    }

                    if(q->right == p){
                        delete p;
                        q->right = NULL;
                        return;
                    }
                }

                // ************** left child *************

                if(p->left != NULL && p->right == NULL){
                    if(q->right == p){
                        q->right = p->left;
                        delete p;
                        return;
                    }
                    else{
                        q->left = p->left;
                        delete p;
                        return ;
                    }
                }


                //************* right child **************

                if(p->left == NULL &&  p->right != NULL){
                    if(q->right == p){
                        q->right = p->right;
                        delete p;
                        return ;
                    }
                    else{
                        q->left = p->right;
                        delete p;
                        return;
                    }
                }


                //**************** both child present **************

                if(p->left != NULL && p->right != NULL){
                    s = min_node(p->right);
                    p->word = s->word;
                    p->meaning = s->meaning;
                    delete_node(s,s->word);
                    return;
                }
            }
        }

        cout<<"\nword not found "<<endl;
    }


    //********************** display in inorder ***********************************

    void inorder(node *p)
    {
        if (p == NULL)
        {
            return;
        }
        
        inorder(p->left);
        cout << p->word << " : " << p->meaning << endl;
        inorder(p->right);
    }

    //****************************** minimum node *********************************

    node* min_node(node* p){
        while(p->left != NULL){
            q = p;
            p = p->left;
        }
        return p;
    }
};

//********************************** main function *****************************

int main()
{
    dictionary d;
    int choice;
    int n;
    string newword;
    string newmeaning;
    string searchword;

    do{
        cout<<"\n1.insert\n2.update\n3.comparision\n4.delete\n5.display\n6.exit\n";
        cout<<"enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"enter number of word to inserted : ";
                cin>>n;
                for(int i = 0 ; i < n; i++){
                    cout<<"enter the word to be inserted : ";
                    cin>>newword;
                    cout<<"enter the meaning to inserted : ";
                    cin>>newmeaning;
                    if(d.root == NULL){
                        d.root = new node(newword,newmeaning);
                    }
                    else{
                        d.insert(d.root,newword,newmeaning);
                    }
                }
                break;

            case 2:
                cout<<"enter the word to search : ";
                cin>>searchword;
                d.update(d.root,searchword);
                break;

            case 3:
                cout<<"enter the word to search : ";
                cin>>searchword;
                d.comparision(d.root,searchword);
                break;

            case 4:
                cout<<"enter the word to delete : ";
                cin>>searchword;
                d.delete_node(d.root,searchword);
                break;

            case 5:
                cout<<"Dictionary : "<<endl;
                d.inorder(d.root);
                break;

            
            
        }
    }while(choice != 6);
}