#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> getmazepath(int sr,int sc,int er,int ec){
    if(sr>er or sc>ec){
        vector<string> x;
        return  x;
    }
    if(sr==er and sc==ec){
        vector<string> fpath{""};
        return fpath;
    }
    vector<string> vpath,hpath;
    if(sc<ec){
        hpath=getmazepath(sr,sc+1,er,ec);
    }
    if(sr<er){
        vpath=getmazepath(sr+1,sc,er,ec);
    }
    vector<string> fpath;
    for(int i=0;i<hpath.size();i++){
        fpath.push_back('h'+hpath[i]);
    }
    for(int i=0;i<vpath.size();i++){
        fpath.push_back('v'+vpath[i]);
    }
    return fpath;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> result=getmazepath(1,1,n,m);
    if(result.size()>0){
        cout<<"["<<result[0];
        for(int i=1;i<result.size();i++){
            cout<<", "<<result[i];
        }
        cout<<"]";
    }
    return 0;
}