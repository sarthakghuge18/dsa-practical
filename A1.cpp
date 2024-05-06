// A1.completed

/*
   Aim :  Consider telephone book database of N clients. 
   Make use of a hash table implementation to quickly look up client‘s telephone number. 
   Make use of two collision handling techniques and 
   compare them using number of comparisons required to find a set of telephone numbers.
*/


#include<iostream>
using namespace std;
#define size 13


// ************************ using linear probing ******************************

class linear_probing{

    int hash[size];
    int flag[size];

    public :

    linear_probing(){
        for(int i = 0 ; i < size ; i++){
            flag[i] = 0;
        }
    }


    void insert(int x){
        int loc;
        loc = x % size ;

        for(int i = 0 ; i < size ; i++){
            if(flag[loc] == 0){
                hash[loc] = x;
                flag[loc] = 1;
                break;
            }else{
                loc = (loc + 1) % size;
            }
        }
    }


    void create(){
        int x,n;
        cout<<"Enter the numbers of persons : ";
        cin>>n;
        cout<<"Enter the phone number of person : "<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>x;
            insert(x);
        }
    }


    void search(int x){
        int loc;
        bool result = false;
        loc = x % size;

        for(int i = 0 ; i < size ; i++){
            if(flag[loc] == 1 && hash[loc] == x){
                result = true;
            }else{
                loc = (loc + 1) % size ;
            }
        }

        if(result){
            cout<<"phone number is found"<<endl;
        }else{
            cout<<"phone number is not found "<<endl;
        }
    }


    void print(){
        cout<<"Hash table is : "<<endl;

        for(int i = 0 ; i < size ; i++){
            cout << "(" << i << ") -> ";
            if(flag[i]==1){
                cout<<hash[i]<<endl;
            }else{
                cout<<"------"<<endl;
            }
        }

    }

};


// ************************ using chaining *******************************


struct node{
    int data;
    node* next;
};

class chaining{

    node *hash[size];

    public :

    chaining(){
        for(int i = 0 ; i < size ; i++){
            hash[i] = NULL;
        }
    }

    
    void insert(int x){
        int loc = x % size;
        node* p = new node;
        p->data = x;
        p->next = NULL;
        if(hash[loc]== NULL){
            hash[loc] = p;
        }else{
            node* q = hash[loc];
            while(q->next != NULL){
                q = q->next;
            }
            q->next = p;
        }
    }


    void create(){
        int x;
        int n;
        cout<<"Enter the number of person : ";
        cin>>n;
        cout<<"Enter the phone number of person : "<<endl;
        for(int i = 0 ; i < n ; i++){
            cin>>x;
            insert(x);
        }
    }


    void display(){
        cout<<"hash table is : "<<endl;
        for(int i = 0 ; i < size ; i++){
            node* q = hash[i];
            cout << "(" << i << ") -> ";
            while(q != NULL){
                cout<<q->data<<" -> ";
                q = q->next;
            }
            cout<<"NULL";
            cout<<endl;
        }

    }
};


// **************************** main function ********************************
int main(){

    //******************** linear probing ***************************

    linear_probing l;
    l.create();
    l.print();
    l.search(10);


    //***********************chaining *****************************

    chaining c;
    c.create();
    c.display();

}
