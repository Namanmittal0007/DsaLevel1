#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<string> words;
    for(int i=0; i<n; i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    cin>>k;
    vector<string> puzzles;
    for(int i=0; i<k; i++){
        string puzzle;
        cin>>puzzle;
        puzzles.push_back(puzzle);
    }
    unordered_map<char, vector<int>> wmap;
    for(int i=0; i<26; i++){
        wmap[(char)('a'+i)] = vector<int> ();
    }
    for(string word : words){
        int mask = 0;
        for(char c : word){
            mask = mask | 1<<(c-'a');
        }
        unordered_set<char> unique;
        for(int i=0;i<word.length();i++){
            char c = word[i];
            if(unique.find(c)==unique.end()){
                unique.insert(c);
                wmap[c].push_back(mask);
            }
        }
    }
    for(string puzzle : puzzles){
        int mask = 0;
        for(char c : puzzle){
            mask = mask | 1<<(c-'a');
        }
        int count = 0;
        char c = puzzle[0];
        vector<int> wordstocheck = wmap[c];
        for(int word : wordstocheck){
            if((mask & word) == word){
                count++;
            }
        }
        cout<<puzzle<<" -> "<<count<<endl;
    }
    return 0;
}
