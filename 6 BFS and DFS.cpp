/*
Lab Assignment 6
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
Use the map of the area around the college as the graph. 
Identify the prominent and marks as nodes and perform DFS and BFS on that.
*/

/*
Graph Example :
1)
                FC Clg  6
                 ^
                 |
                 |
                MCOE Clg 5
                 ^
                 |
                 |
    Pune------>MCOE--------->JM-------->COEP
    City        bus         corner      ground
      1         stop          3           4
                 2
2)
             4
             ^
             |
             |
       1----->2----->3         
3)

                
                 A              
              /  |  \
             B   C   D          
                / \
               E   F



*/

#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

class Graph
{
public:
    int V;
    string places[10];
    map<string, bool> visited;
    map<string, list<string>> adj;

    Graph(int v,string place[10]){
        V=v;
        for(int i=0;i<v;i++)
            places[i]=place[i];
    }
    void addEdge(string v, string w);
    void set_default(){
    for(int i=0;i<V;i++){
        visited[places[i]]=false;
    }
    }
    void DFS(string v);
    void BFS(string v);
};

void Graph::addEdge(string v, string w)
{
    adj[v].push_back(w);
}
 
void Graph::DFS(string v)
{
    visited[v] = true;
    cout << v << " ";

    list<string>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}


void Graph::BFS(string s)
{
    visited[s]=false;

    list<string> queue;

    visited[s] = true;
    queue.push_back(s);

    list<string>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(){
    
    int n;
    cout<<"\nEnter the number of elements in the graph - ";
    cin>>n;
    int mat[n][n];
    string name;
    string name_list[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name of vertice "<<i+1<<" - ";
        cin>>name;
        name_list[i] = name;
    }
    Graph g(n,name_list);
    char connected; 
    cout<<"\nY-YES & N-NO\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"\n"<<name_list[i]<<" connected "<<name_list[j]<<"--->";
            cin >> connected;
            if (connected=='y' || connected=='Y'){
                g.addEdge(name_list[i],name_list[j]);
            }
            else {
                continue;
            }
        }
        cout<<"\n--------------------------------\n";
    }
    char loop='y';
    while(loop=='y' || loop=='Y'){
        cout<<"-------------------------------------\n";
        cout<<"Enter place :: ";
        cin>>name;
        cout<<"\nDFS :: ";
        g.set_default();
        g.DFS(name);
        cout<<"\nBFS :: ";
        g.set_default();
        g.BFS(name);
        cout<<"\nYou want to continue (y/n) :: ";
        cin>>loop;
    }

    return 0;
}
