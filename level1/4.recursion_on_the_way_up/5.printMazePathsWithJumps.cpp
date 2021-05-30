#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        if(sc==dc and sr==dr){
            cout<<psf<<endl;
            return ;
        }
        for(int i=1;i<=dc-sc;i++){
            char ch=i+'0';
            string x(1,'h');
            printMazePaths(sr,sc+i,dr,dc,psf+x+ch);
        }
        for(int i=1;i<=dr-sr;i++){
            char ch=i+'0';
            string x(1,'v');
            printMazePaths(sr+i,sc,dr,dc,psf+x+ch);
        }
        for(int i=1;i<=dc-sc and i<=dr-sr;i++){
            char ch=i+'0';
            string x(1,'d');
            printMazePaths(sr+i,sc+i,dr,dc,psf+x+ch);
        }
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }