#include<bits/stdc++.h>
using namespace std;
int vertices;
class edge{
    public:
    int src;
    int nbr;
    int wt;
    edge(int src,int nbr, int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
    void display(){
        cout<<"("<<this->src<<","<<this->nbr<<")";
    }
};
void hamiltonian(vector<list<edge>> graph,int src,unordered_set<int> visited,string path ){
    if(visited.size()==vertices){
        cout<<path;
        // bool cycle=false;
    }
    visited.insert(src);
    for(auto x:graph[src]){
        if(visited.find(x.nbr)==visited.end()){
            hamiltonian(graph,x.nbr,visited,path+to_string(x.nbr));
        }
    }
    visited.erase(src);
}
int main(){
    
    int edges;
    cin>>vertices>>edges;
    vector<list<edge>> graph(vertices);
    while(edges--){
        int src,nbr,wt;
        cin>>src>>nbr>>wt;
        graph[src].push_back(edge(src,nbr,wt));
        graph[nbr].push_back(edge(nbr,src,wt));
    }
    unordered_set<int> visited;
    int src;
    cin>>src;
    hamiltonian(graph,src,visited,to_string(src));
    return 0;
}

/*
7
9
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
2 5 10
0
*/