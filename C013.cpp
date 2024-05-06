//C13.

/*
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
Use the map of the area around the college as the graph. 
Identify the prominent land marks as nodes and perform DFS and BFS.
*/


#include<iostream>
#include<queue>
using namespace std;

class graph{

    int **adjmat;
    int *visit;
    int size;


    public :

    struct node{
        int val;
        node *next;
    };

    node **adjlist;

    graph(int);
    void initilize_visit();

    void input();
    void display_mat();
    void dfs_mat(int i);


    void initilize_list();
    void display_list();
    void bfs_list(int);

};

graph::graph(int m){

    size = m;
    adjmat = new int*[size];
    for(int i = 0 ; i < size ; i++){
        adjmat[i] = new int[size];
    }

    visit = new int [size];
    initilize_visit();

    adjlist = new node *[size];
    for(int i = 0 ; i < size ; i++){
        adjlist[i] = NULL;
    }
}

void graph::initilize_visit(){
    for(int i = 0 ; i < size ; i ++ ){
        visit[i] = 0;
    }
}


void graph::input(){

    cout<<"enter the 1 for connection or 0 for not "<<endl;

    for(int i = 0 ; i  < size ; i ++){
        for(int j = 0 ; j < size ; j++){
            cout<<"connection between "<<i <<" and "<<j<<" : "; 
            cin>>adjmat[i][j];
        }
    }
}

void graph::display_mat(){

    cout<<"The Adjacancy Matrix : "<<endl;
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j ++){
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void graph::dfs_mat(int start){

    cout<<start<<" ";
    visit[start] = 1;

    for(int i = 0 ; i < size ; i ++){
        if(adjmat[start][i] == 1 && visit[i] == 0){
            dfs_mat(i);
        }
    }

}


void graph::initilize_list(){

    node *t;

    for(int i = 0 ; i < size ; i ++){
        for(int j = 0 ; j < size ; j++){
            if(adjmat[i][j]==1){
                node* m = new node();
                m->val = j;
                m->next = NULL;


                if(adjlist[i] == NULL){
                    adjlist[i] = m;
                }else{
                    t = adjlist[i];
                    while(t->next != NULL ){
                        t = t->next;
                    }
                    t->next = m;
                }
            }
        }
    }
}


void graph::display_list(){

    for(int i = 0 ; i < size ; i ++){
        node *t = adjlist[i];
        cout<<i<<"-->";
        while(t != NULL){
            cout<<t->val<<" ";
            t = t->next;
        }
        cout<<endl;
    }
}


void graph::bfs_list(int start){
    queue<int> q;

    q.push(start);
    visit[start] = 1;

    while(!q.empty()){
        node *temp = adjlist[q.front()];
        cout<<q.front()<<" ";
        q.pop();

        for(int i = 0 ; i < size ; i ++){

            while(temp != NULL){
                if(visit[temp->val] == 0){
                    break;
                }else{
                    temp = temp->next;
                }
            }

            if(temp != NULL){
                q.push(temp->val);
                visit[temp->val] = 1;
            }
        }

    }

}





//////////////////////////////////////    main function   ///////////////////////////////////////////

int main(){

    graph g(4);

    g.input();
    g.display_mat();
    cout<<"the dfs using adjmat : "<<endl;
    g.dfs_mat(0);
    cout<<endl;


    g.initilize_visit();
    g.initilize_list();
    g.display_list();
    cout<<"the bfs using adjlist : "<<endl;
    g.bfs_list(0);
    cout<<endl;

    return 0;
}
