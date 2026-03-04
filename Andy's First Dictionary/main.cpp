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

    string line, word;
    set<string> seen;
    priority_queue<string, vector<string>, greater<string>> pq;

    while(getline(cin, line)) {
        word = "";
        for(char c:line){
            if(c!=' ') word += tolower(c);
            else if(!word.empty()) {
                if(!seen.count(word)){
                    pq.push(word); seen.insert(word);
                }
                word = "";
            }
        }
        if(!word.empty() && !seen.count(word)){
             pq.push(word); seen.insert(word);
        }
    }

    while(!pq.empty()){
        cout<<pq.top()<<"\n";
        pq.pop();
    }

}

