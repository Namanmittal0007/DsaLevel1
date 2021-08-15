#include<bits/stdc++.h>
using namespace std;
vector<int> devteam;
void mindev(int skills, vector<int> dev, int currdev, int currskills, vector<int> &currteam){
    if(currdev==dev.size()){
        if(currskills==((1<<skills)-1)){
            if(devteam.size()==0 or devteam.size()>currteam.size()){
                devteam =  currteam;
            }
        }
        return;
    }
    mindev(skills, dev, currdev+1, currskills, currteam);
    currteam.push_back(currdev);
    mindev(skills, dev, currdev+1, currskills | dev[currdev], currteam);
    currteam.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<string> skills(n);
    for(int i=0;i<n;i++){
        cin>>skills[i];
    }
    unordered_map<string,int> skillmap;
    for(int i=0;i<n;i++){
        skillmap[skills[i]]= (1<<i);
    }  
    int m;
    cin>>m;
    vector<int> dev(m,0);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            string devskill;
            cin>>devskill;
            dev[i]=dev[i] | skillmap[devskill];
        }
    }
    vector<int> currteam;
    mindev(n,dev,0,0, currteam);
    cout<<"[";
    for(int i=0;i<devteam.size();i++){
        if(i!=(devteam.size()-1)){
            cout<<devteam[i]<<", ";
        }
        else{
            cout<<devteam[i]<<"]";
        }
    }
    return 0;
}