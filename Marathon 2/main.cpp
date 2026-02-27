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

    string comp="";
    int countt = 1;

    for(int i=1; i<=s.length(); i++){
        if(i<s.length() && s[i]==s[i-1]){
            countt++;
        }else{
            comp += s[i - 1];
            if (countt > 1){
                comp += to_string(countt);
            }
            countt = 1;
        }
    }

    cout<<comp;
    return 0;
}

