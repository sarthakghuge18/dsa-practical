//C15.

/*
You have a business with several offices; 
you want to lease phone lines to connect them up with each other; 
and the phone company charges different amounts of money to connect different pairs of cities. 
You want a set of lines that connects all your offices with a minimum total cost. 
Solve the problem by suggesting appropriate data structures.
*/

#include <iostream>
using namespace std;

class graph
{
    int n;
    int adjacent[10][10];
    string office[10];

public:
    void input()
    {
        cout << "enter the number of offices : ";
        cin >> n;

        cout << "enter the name offices : " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "office " << i + 1 << " : ";
            cin >> office[i];
        }

        cout << "enter the connection : ";
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {

                if (i == j)
                {
                    adjacent[i][j] = 0;
                    continue;
                }

                cout << "enter the connection " << office[i] << " and " << office[j] << " : ";
                cin >> adjacent[i][j];
                adjacent[j][i] = adjacent[i][j];
            }
        }
    }

    void display()
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adjacent[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    void prims(){
        int visit[n];
        int mincost = 0;
        int cost = 0;
        int minindex;
        int count = n-1;

        //initilize visit

        for(int i = 0 ; i < n ; i ++){
            visit[i] = 0;
        }

        cout << "\n\nShortest path: ";
        visit[0] = 1;
        cout << office[0] << "-> ";

        while(count--){

            mincost = INT16_MAX;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j ++){

                    if(visit[i] == 1 && visit[j] ==0 && adjacent[i][j] < mincost && adjacent[i][j] != 0){
                        mincost = adjacent[i][j];
                        minindex = j;
                    }

                }
            }

            visit[minindex] = 1;
            cout<<office[minindex]<<"->";
            cost = cost + mincost;


        }
        cout<<endl;
        cout<<"min cost "<<cost;
    }
};

// int main()
// {
//     graph g;
//     g.input();
//     g.display();
//     g.prims();
// }
int main () {
    graph o;
    int choice;
    do {
        cout << "\n\nMINIMUM SPANNING TREE\n1. Input data\n2. Display data\n3. Calculate minimum cost\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                o.input ();
                break;
            case 2:
                o.display ();
                break;
            case 3:
                o.prims();
                break;
        }
    } while (choice != 4);
    return 0;
}