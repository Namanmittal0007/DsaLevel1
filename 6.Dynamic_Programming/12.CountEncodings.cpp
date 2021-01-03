#include<bits/stdc++.h>
 using namespace std;
 int main(){
     string s;
     cin>>s;
     int dp[s.length()]={0};
     dp[0]=1;
     bool flag=false;
     for(int i=1;i<s.length();i++){
         if(s[i-1]=='0' and s[i]=='0'){
             dp[i]=0;
             flag=true;
             break;
         }
         else if(s[i-1]=='0' and s[i]!='0'){
             dp[i]=dp[i-1];
         }
         else if(s[i-1]!='0' and s[i]=='0'){
             if(s[i-1]=='1' || s[i-1]=='2'){
                 dp[i]=(i>=2?dp[i-2]:1);
             }
             else{
                 dp[i]=0;
                 flag=true;
                 break;             
             }
         }
         else{
             if(s[i-1]=='1' || s[i-1]=='2'){
                 dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
             }
             else{
                 dp[i]=dp[i-1];
             }
         }
     }
     cout<<dp[s.length()-1];
     return 0;
 }
