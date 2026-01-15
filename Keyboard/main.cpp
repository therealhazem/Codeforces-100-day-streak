#include <bits/stdc++.h>
using namespace std;

string letters="qwertyuiopasdfghjkl;zxcvbnm,./";
char miss;
string word;
int main() {
    cin>>miss;
    cin>>word;
        int steps=word.length();
        int pos = 0;
        if(miss == 'R'){
        while(steps!=0){
            for(int i=0; i<letters.length(); i++){
                if(word[pos] == letters[i]){
                    cout<<letters[i-1];
                    pos++;
                    steps--;
                }
            }
        }
    }else{
        while(steps!=0){
            for(int i=0; i<letters.length(); i++){
                if(word[pos] == letters[i]){
                    cout<<letters[i+1];
                    pos++;
                    steps--;
                }
            }
        }
    }
    return 0;
}

