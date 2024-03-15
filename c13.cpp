#include<iostream>
using namespace std;

class graph{

    public :

        //initilize the matrix and visit
        int matrix[10][10];
        int visit[10];

        //create constructor to set visit value 
        graph(){
            for(int i = 0 ; i < 10 ; i++){
                visit[i] = 0;
            }
        }

        //taking input from user
        void input(int v){
            
            int row = v;
            int col = v;

            cout<<"Enter (1 or 0)"<<endl;
            cout<<"1 represent edge is present \n0 represent edge is not present \n";
            for( int  i = 0 ; i< row ; i++){
                for (int j = 0 ; j < col ; j++){
                    cout<<"At "<< i<< " , "<<j<<" : ";
                    cin>>matrix[i][j];
                }
            }
        }


        //displaying the matrix 
        void display(int v){

            int row = v;
            int col = v;

            cout<<"\nmatrix representation of graph : "<<endl;
            for(int i = 0 ; i < row ; i++){
                for (int j = 0 ; j < col ; j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        //displaying in DFS manner in the form of character 
        void dfs(int x ,int v){

            char ch = 'a'+ x -1;
            cout<<ch<<" ";
            visit[x-1] = 1;
            for(int i = 0 ; i < v ; i++){
                if(matrix[x-1][i]==1 && visit[i]==0){
                    dfs(i+1,v);
                }
            }
        }
};

int main (){

    graph g;

    int v;
    cout<<"enter the vertices : ";
    cin>>v;

    g.input(v);
    g.display(v);

    int e;
    cout<<"enter the starting edge : ";
    cin>>e;
    g.dfs(e,v);

}


//sample input for 4 vertices
//0 1 0 1 1 0 1 1 0 1 0 1 1 1 1 0