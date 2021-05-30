#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int src;
    int nbr;
    int wt;
    edge(int a,int b,int c){
        src=a;
        nbr=b;
        wt=c;
    }
};
class vpath{
    public:
    int n;
    string path;
    vpath(int n, string path){
        this->n=n;
        this->path=path;
    }
};
bool cyclebfs(vector<list<edge>> graph, int src, bool visited[] ){
    queue<vpath> q;
    q.push(vpath(src,to_string(src)));
    visited[src]=true;
    while(!q.empty()){
        vpath top=q.front();
        q.pop();
        if(visited[top.n]==true){
            return true;
        }
        for(auto x:graph[top.n]){
            if(!visited[x.nbr]){
                q.push(vpath(x.nbr,top.path+to_string(x.nbr)));
            }
        }
    }
    return false;
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    vector<list<edge>> graph(vertices);
    while(edges--){
        int v1,v2,wt;
        graph[v1].push_back(edge(v1,v2,wt));
        graph[v2].push_back(edge(v2,v1,wt));
    }
    bool visited[vertices]={0};
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            bool flag=cyclebfs(graph,i,visited);
            if(flag){
                cout<<"true";
                return 0;
            }
        }
    }
    cout<<"false";
    return 0;
}
