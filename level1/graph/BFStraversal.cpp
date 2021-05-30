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
class verticepath{
    public:
    int v;
    string path;
    verticepath(int v,string path){
        this->v=v;
        this->path=path;
    }
};
void bfs(vector<list<edge>> graph, int start){
    queue<verticepath> q;
    q.push(verticepath(start,to_string(start)));
    bool visited[graph.size()]={0};
    while(!q.empty()){
        verticepath top=q.front();
        visited[top.v]=true;
        for(auto curr:graph[top.v]){
            if(!visited[curr.nbr]){
                q.push(verticepath(curr.nbr,top.path+to_string(curr.nbr)));
            }
        }
        cout<<top.v<<"@"<<top.path<<endl;
        q.pop();
    }
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<list<edge>> graph(vertices);
    while(edges--){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back(edge(v1,v2,wt));
        graph[v2].push_back(edge(v2,v1,wt));
    }
    int start;
    cin>>start;
    bfs(graph,start);
    return 0;
}