#include<bits/stdc++.h>
using namespace std;
int maxnum=INT_MIN;
void largestnum(string &num, int k){
    if(maxnum<stoi(num)){
        maxnum=stoi(num);
    }
    if(k==0){
        return;
    }
    for(int i=0; i<num.length();i++){
        for(int j=i+1;j<num.length();j++){
            if((num[i]-'0')<(num[j]-'0')){
                char temp=num[i];
                num[i]=num[j];
                num[j]=temp;
                largestnum(num,k-1);
                num[j]=num[i];
                num[i]=temp;
            }
        }
    }
}
int main(){
    string num;
    int k;
    cin>>num>>k;
    largestnum(num,k);
    cout<<maxnum;
    return 0;
}