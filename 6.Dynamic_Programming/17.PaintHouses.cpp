#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cost[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>cost[i][j];
        }
    }
    int r=cost[0][0];
    int b=cost[0][1];
    int g=cost[0][2];
    for(int i=1;i<n;i++){
        int nr=cost[i][0]+min(b,g);
        int nb=cost[i][1]+min(r,g);
        int ng=cost[i][2]+min(r,b);
        r=nr;
        b=nb;
        g=ng;
    }
    cout<<min(r,min(b,g));
    return 0;
}
