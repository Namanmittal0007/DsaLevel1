#include<bits/stdc++.h>
using namespace std;
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
};
void makegroup(vector<list<edge>> graph, int src, vector<bool> &visited, vector<int> &group){
    visited[src]=true;
    group.push_back(src);
    for(auto x:graph[src]){
        if(!visited[x.nbr]){
            makegroup(graph,x.nbr,visited,group);
        }
    }
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<list<edge  >> graph(vertices);
    while(edges--){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(edge(v1,v2,wt));
        graph[v2].push_back(edge(v2,v1,wt));
    }
    vector<vector<int>> groups;
    vector<bool> visited={0};
    for(int i=0;i<vertices;i++){
        if(!visited[i]==false){
            vector<int> group;
            makegroup(graph,i,visited,group);
            groups.push_back(group);
        }
    }
    int totalpair=0;
    for(int i=0;i<groups.size();i++){
        for(int j=i+1;j<groups.size();j++){
            int currpair=groups[i].size()*groups[j].size();
            totalpair+=currpair;
        }
    }
    cout<<totalpair;
    return 0;
}
/*
7
5
0 1
2 3
4 5
5 6
4 6
*/