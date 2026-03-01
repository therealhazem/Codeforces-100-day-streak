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

    int n,m;
    cin>>n>>m;

    unordered_map<string, string> words;

    for(int i=0; i<m; i++){
        string one,two;
        cin>>one>>two;
        words[one]=two;
    }

    for(int i=0; i<n; i++){
        string word;
        cin>>word;

        string second = words[word];

        if(word.length() <= second.length()) cout<<word;
        else cout<<second;
        if(i != n-1) cout<<" ";
    }
    cout<<"\n";

    return 0;
}

