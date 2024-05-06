// B5.completed

/*
Aim : A book consists of chapters, 
chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. 
Find the time and space requirements of your method.				
*/


#include<iostream>
#include<string>
using namespace std;

struct node{
    string label;
    int count;
    node* child[50];
};


class Tree{

    node* root;

    public : 

    Tree(){
        root = NULL;
    }



    void insert(){
        root = new node();
        cout<<"enter the name of book : ";
        cin>>root->label;

        cout<<"enter the total number of chapters in book :";
        cin>>root->count;

        for(int i = 0 ; i < root->count; i++){
            root->child[i] = new node();

            cout<<"enter the name of chapter "<< i + 1<< " : ";
            cin>>root->child[i]->label;

            cout<<"enter the number of section : ";
            cin>>root->child[i]->count;

            for(int j = 0 ; j < root->child[i]->count ; j++){
                root->child[i]->child[j] = new node();

                cout<<"enter the name of section "<< i + 1 << " . "<< j + 1<<" : ";
                cin>>root->child[i]->child[j]->label;

                cout<<"enter the number of sub section : ";
                cin>>root->child[i]->child[j]->count;


                for(int k = 0 ; k < root->child[i]->child[j]->count ; k ++){
                    root->child[i]->child[j]->child[k] = new node();

                    cout<<"enter the name of sub section "<< i+1<<"."<<j+1<<"."<<k+1<<":";
                    cin>>root->child[i]->child[j]->child[k]->label;

                }
            }
        }
    }




    void display(){
        if(root != NULL){
            cout<<"-------------------- book --------------------"<<endl;
            cout<<"book name : "<<root->label<<endl;

            for(int i = 0 ; i < root->count ; i++){
                cout<<"->"<<root->child[i]->label<<endl;

                for(int j = 0 ; j < root->child[i]->count ; j++){
                    cout<<"--->"<<root->child[i]->child[j]->label<<endl;

                    for(int k = 0 ; k < root->child[i]->child[j]->count ; k++){
                        cout<<"----->"<<root->child[i]->child[j]->child[k]->label<<endl;
                    }
                }
            }
        }
    }


};



int main(){

    Tree t;
    int ch;

    do{
        cout<<"\n1.input\n2.display\n3.exit\nenter choice : ";
        cin>>ch;

        if(ch == 1){
            t.insert();
        }
        else if(ch == 2){
            t.display();
        }else if (ch == 3){
            cout<<"exited...";
        }else{
            cout<<"enter the valid choice ????";
        }
    }while(ch != 3);
}

