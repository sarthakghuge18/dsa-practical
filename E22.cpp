//E22.

/*
Read the marks obtained by students of second year in an online examination of particular subject. 
Find out maximum and minimum marks obtained in that subject. 
Use heap data structure. Analyze the algorithm.
*/

#include<iostream>
using namespace std;

class heap{

    public:

        void heapify(int arr[],int n,int i){
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < n && arr[largest] < arr[left]){
                largest = left;
            }

            if(right < n && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest != i){
                swap(arr[largest],arr[i]);
                heapify(arr,n,largest);
            }
        }


        void heapsort(int arr[],int n){

            int size = n;

            while(size > 0){

                swap(arr[0], arr[size-1]);
                size--;

                heapify(arr,size,0);
            }

        }

        void display(int arr[],int n){

            for(int i = 0 ; i < n ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }
};


int main(){

    heap h;

    int arr[6] = {22,54,65,23,76,87};
    int n = 6;

    cout<<"original Array : "<<endl;
    h.display(arr,n);

    cout<<"Heapify Array : "<<endl;
    for(int i = (n/2) - 1 ; i >= 0 ; i--){
        h.heapify(arr,n,i);
    }
    h.display(arr,n);

    h.heapsort(arr,n);
    cout<<"Sorted Array : "<<endl;
    h.display(arr,n);


    return 0;
}