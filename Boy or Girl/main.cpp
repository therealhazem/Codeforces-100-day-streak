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

    string s;
    cin>>s;
    priority_queue<char> letters;
    for(char c:s) letters.push(c);

    int num=0;
    char last='-';

    int cycle = letters.size();
    for(int i=0; i<cycle; i++){
        if(letters.top() != last){
            last = letters.top();
            num++;
        }
        letters.pop();
    }

    (num%2==0)?cout<<"CHAT WITH HER!":cout<<"IGNORE HIM!";

    return 0;
}

