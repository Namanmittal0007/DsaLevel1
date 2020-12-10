#include <iostream>
using namespace std;

void printDecreasing(int n){
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    printDecreasing(--n);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}
