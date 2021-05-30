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
string spath="";
int spathwt=INT_MAX;
string lpath="";
int lpathwt=INT_MIN;
string cpath="";
int cpathwt=INT_MAX;
string fpath="";
int fpathwt=INT_MIN;
class duo{
    public:
    int wt;
    string path;
    duo(int wt,string path){
        this->wt=wt;
        this->path=path;
    }
};
struct compare{
    bool operator ()(duo d1,duo d2){
        return d1.wt>d2.wt;
    }
};
priority_queue<duo,vector<duo>,compare> pq;
void multisolver(vector<list<edge>> graph, int src, int dest, bool visited[],int criteria,int k,string path,int wgt){
    if(src==dest){
        if(wgt<spathwt){
            spath=path;
            spathwt=wgt;
        }
        if(wgt>lpathwt){
            lpath=path;
            lpathwt=wgt;
        }
        if(wgt>criteria and wgt<cpathwt){
            cpath=path;
            cpathwt=wgt;
        }
        if(wgt<criteria and wgt>fpathwt){
            fpath=path;
            fpathwt=wgt;
        }
        if(pq.size()<k){
            pq.push(duo(wgt,path));
        }
        else{
            pq.push(duo(wgt,path));
            pq.pop();
        }
        return;
    }
    visited[src]=true;
    for(auto x: graph[src]){
        if(visited[x.nbr]==false){
            multisolver(graph,x.nbr,dest,visited,criteria,k,path+to_string(x.nbr),wgt+x.wt);
        }
    }
    visited[src]=false;
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
    int src,dest,criteria,k;
    cin>>src>>dest>>criteria>>k;
    bool visited[vertices]={0};
    multisolver(graph,src,dest,visited,criteria,k,to_string(src),0);
    cout<<"Smallest Path = "<<spath<<"@"<<spathwt<<endl;
    cout<<"Largest Path = "<<lpath<<"@"<<lpathwt<<endl;
    cout<<"Just Larger Path than "<<criteria <<" = "<<cpath<<"@"<<cpathwt<<endl;
    cout<<"Just Smaller Path than "<<criteria <<" = "<<fpath<<"@"<<fpathwt<<endl;
    duo kth=pq.top();
    cout<<k<<"th largest path = "<<kth.path<<"@"<<kth.wt<<endl;
    return 0;
}
/*
7
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0
6
30
4
*/