// A4.completed

/*
To create ADT that implement the "set" concept.
a. Add (new Element) - Place a value into the set , 
b. Remove (element) Remove the value 
c. Contains (element) Return true if element is in collection, 
d. Size () Return number of values in collection 
Iterator () Return an iterator used to loop over collection, 
e. Intersection of two sets , 
f. Union of two sets, 
g. Difference between two sets, 
h. Subset
*/

#include<iostream>
using namespace std;


class Set{

    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;

    public : 

        void create(){
            int n;
            cout<<"enter the number of element : ";
            cin>>n;
            cout<<"enter the elements : "<<endl;
            for(int i = 0 ; i < n ; i++){
                cin>>arr[i];
                size++;
            }
        }


        void add(int x){
            if(size<MAX_SIZE){
                arr[size++] = x;
            }
        }


        void remove(int x){
            for(int i = 0 ; i < size ; i++){
                if(arr[i] == x){
                    for(int j = i; j < size - 1; j++){
                        arr[j] = arr[j+1];
                    }
                    size--;
                    return;
                }
            }    
        }


        int getSize(){
            return size;
        }

        void interator(){
            cout<<"Set elements : "<<endl;
            for(int i = 0 ; i < size ; i ++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        Set intersection(Set &a){
            Set iset;
            for(int i = 0; i < size ; i++){
                for(int j = 0 ; j < a.size ; j++){
                    if(arr[i] == a.arr[j]){
                        iset.add(arr[i]);
                        break;
                    }
                }
            }
            return iset;
        }


        Set unionSet(Set &b){
            Set uset;
            for(int i = 0 ; i < size ; i++){
                uset.add(arr[i]);
            }

            for(int i = 0; i < b.size ; i++){
                bool found = false;
                for(int j = 0 ; j < size ; j++){
                    if(arr[j] == b.arr[i]){
                        found = true;
                        break;
                    }
                }

                if(found == false){
                    uset.add(b.arr[i]);
                }
            }

            return uset;
        }


        Set difference(Set &c){
            Set dset;
            for(int i = 0 ; i < size ; i++){
                dset.add(arr[i]);
            }

            for(int i = 0 ; i < c.size ; i++){
                for(int j = 0 ; j < dset.size; j++){
                    if(c.arr[i] == dset.arr[j]){
                        dset.remove(dset.arr[j]);
                        break;
                    }
                }
            }
            return dset;
        }



        bool is_subset(Set &d){
            for(int i = 0 ; i < d.size; i++){
                bool found = false;
                for(int j = 0 ; j < size ; j++){
                    if(d.arr[i] == arr[j]){
                        found = true;
                        break;
                    }
                }
                if(found == false){
                    return false;
                }
            }
            return true;
        }

};


int main(){

    Set A;
    Set B;
    Set interSection_set;
    Set union_set;
    Set difference;
    bool is_subset;
    int choice ;

    do{
        cout<<"\n1.create set A\n2.create set B\n3.add element in set A\n4.add element in set B\n5.remove element from set A\n6.remove element from set B\n7.display set A\n8.display set B\n9.intersection\n10.union\n11.difference\n12.is_subset\n13.exit\n\nenter your choice : ";

        cin>>choice;

        switch(choice){

            case 1:{
                A.create();
                break;
            }
            case 2 : {
                B.create();
                break;
            }
            case 3 :{
                int a;
                cout<<"enter the element : ";
                cin>>a;
                A.add(a);
                break;
            }
            case 4 : {
                int a;
                cout<<"enter the element : ";
                cin>>a;
                B.add(a);
                break;
            }
            case 5 : {
                int a;
                cout<<"enter the element : ";
                cin>>a;
                A.remove(a);
                break;
            }
            case 6 : {
                int a;
                cout<<"enter the element : ";
                cin>>a;
                B.remove(a);
                break;
            }
            case 7 : {
                A.interator();
                break;
            }
            case 8 : {
                B.interator();
                break;
            }
            case 9 :{
                interSection_set = A.intersection(B);
                interSection_set.interator();
                break;
            }
            case 10 :{
                union_set = A.unionSet(B);
                union_set.interator();
                break;
            }
            case 11 :{
                difference = A.difference(B);
                difference.interator();
                break;
            }
            case 12 :{
                is_subset = A.is_subset(B);
                if(is_subset){
                    cout<<"yes"<<endl;
                }else{
                    cout<<"no"<<endl;
                }
                break;
            }
            case 13 :{
                cout<<"exited successfully ......."<<endl;
                break;
            }
            default : {
                cout<<"enter the valid number "<<endl;
            }
        }
    }while(choice != 13);
}