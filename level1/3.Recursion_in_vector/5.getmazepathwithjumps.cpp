#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> getmazepath(int sr,int sc,int er,int ec){
    if(sr==er and sc==ec){
        vector<string> fpath{""};
        return fpath;
    }
    vector<string> vpath,hpath,dpath,fpath;
    for(int i=1;i<=ec-sc;i++){
        hpath=getmazepath(sr,sc+i,er,ec);
        char ch=i+'0';
        for(int j=0;j<hpath.size();j++){
            string x(1,'h');
            fpath.push_back(x+ch+hpath[j]);
        }
    }
    for(int i=1;i<=er-sr;i++){
        vpath=getmazepath(sr+i,sc,er,ec);
        char ch=i+'0';
        for(int j=0;j<vpath.size();j++){
            string x(1,'v');
            fpath.push_back(x+ch+vpath[j]);
        }
    }
    for(int i=1;i<=ec-sc and i<=er-sr;i++){
        dpath=getmazepath(sr+i,sc+i,er,ec);
        char ch=i+'0';
        for(int j=0;j<dpath.size();j++){
            string x(1,'d');
            fpath.push_back(x+ch+dpath[j]);
        }
    }
    return fpath;
}
int main(){
    int n,m;
    cin>>n>>m;
    if(n<1 or m<1){
        cout<<"[]";
        return 0;
    }
    vector<string> result;
    result=getmazepath(1,1,n,m);
    if(result.size()>0){
        cout<<"["<<result[0];
        for(int i=1;i<result.size();i++){
            cout<<", "<<result[i];
        }
        cout<<"]";
    }
    
    return 0;
}