#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int src;
    int nbr;
    int wt;
    edge(int src, int nbr, int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
    void display(){
        cout<<this->src<<","<<this->nbr<<","<<this->wt<<"  ";
    }
};
void getconnectedgraph(vector<list<edge>> graph,int src,bool visited[],vector<int> &cycle){
    visited[src]=true;
    cycle.push_back(src);
    for(auto x:graph[src]){
        if(!visited[x.nbr]){
            getconnectedgraph(graph,x.nbr,visited,cycle);
        }
    }
}
int main(){
    int vertices;
    cin>>vertices;
    vector<list<edge>> graph(vertices);
    int edges;
    cin>>edges;
    while(edges--){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(edge(v1,v2,wt));
        graph[v2].push_back(edge(v2,v1,wt));
    }
    bool visited[vertices]={0};
    vector<vector<int>> cycles;
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            vector<int> cycle;
            getconnectedgraph(graph,i,visited,cycle);
            cycles.push_back(cycle);
        }
    }
    if(cycles.size()==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
/*
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10
*/