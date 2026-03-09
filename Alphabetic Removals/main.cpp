#include <string>
#include <utility>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;

    map<char,int> letters;
    map<char,int> removee;
    for(char c:s) letters[c]++;

    for(char c='a'; c<='z' && k>0; c++){
        int take = min(k, letters[c]);
        removee[c] = take;
        k -= take;
    }

    for(char c:s){
        if(removee[c] > 0)removee[c]--;
        else cout<<c;
    }

    return 0;
}

