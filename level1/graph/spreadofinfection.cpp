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
    int t;
    vpath(int n, string path, int t){
        this->n=n;
        this->path=path;
        this->t=t;
    }
};
void spreadofinfection(vector<list<edge>> graph, int start, int time){
    queue<vpath> q;
    int visited[graph.size()]={0},count=0;
    q.push(vpath(start,to_string(start),1));
    while(!q.empty()){
        vpath top=q.front();
        q.pop();
        if(visited[top.n]>0){
            continue;
            
        }
        if(top.t>time){
                break;
        }
        visited[top.n]=top.t;
        count++;
        for(auto x:graph[top.n]){
            if(visited[x.nbr]==0){
                q.push(vpath(x.nbr,top.path+to_string(x.nbr),top.t+1));
            }
        }
    }
    cout<<count;
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
    int start,time;
    cin>>start>>time;
    spreadofinfection(graph,start,time);
    return 0;
}
