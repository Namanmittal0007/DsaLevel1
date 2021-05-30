#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
     if(str.length()==0){
         cout<<asf<<endl;
         return ;
     }
     for(int i=0;i<str.length();i++){
        char ch=str[i];
        string subs=(str.substr(0,i)+str.substr(i+1));
        printPermutations(subs,asf+ch);
     }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}