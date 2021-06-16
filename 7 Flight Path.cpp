/*There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city.
Use adjacency list representation of the graph or use adjacency matrix representation of the graph. 
Check whether the graph is connected or not. Justify the storage representation used.*/
#include <iostream>
#include<queue>
#define n 10        // max size for adjacency matrix
int adj_m[n][n];    // adjaceny matrix declaration

void traverse(int u,int x, bool visited[]){
    visited[u] = true; //mark vertex as visited
    for(int v = 0; v<x; v++){
        if(adj_m[u][v]!=0){
            //check if visited; if not visited traverse again
            if(!visited[v])
                traverse(v,x, visited);
      }
   }
}
bool isConnected(int x){
    bool *vis = new bool[n];
    // here we consider u as start point=0(city 1) which can also be dyanmically allocated
    for(int u=0; u < x; u++){
        for(int i = 0; i<x; i++)
            vis[i] = false;     //initialize as no node is visited
            traverse(u,x, vis); //As we call the function we update the visited array
            for(int i = 0; i<x; i++){
                if(!vis[i]) 
                //if there is a node, not visited we can conclude graph is not connected
                    return false;
      }
   }
   return true;
}

using namespace std;
int main(){
    int x; //Number of cities
    cout<<"Enter number of cities :: ";
    cin>>x;

    //Input cities
    char arr[x][20];
    for (int i=0;i<x;i++){
        cout<<"Enter "<<i+1<<" city name :: ";
        cin>>arr[i];
    }
    
    //adjacency matrix
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++)
        {
            cout<<"\nIs city "<<arr[i]<<" connected to city "<<arr[j]<<endl
                <<"Enter y if yes :: ";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y')
            {
                int a;
                cout<<"Enter fuel reuired to go from "<<arr[i]<<" to "<<arr[j]<<"\n"
                    <<"Enter :: ";
                cin>>a;
                adj_m[i][j]=a;
            }
            else
            {
                adj_m[i][j]=0;
            }
        }
        cout<<"\n-------------------------------\n";
    }
    
    //Printing adjacency matrix
    cout<<"ADJ MAT\n";
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            cout<<adj_m[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n-------------------------------\n";
    if(isConnected(x))
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
    
    return 0;
}


