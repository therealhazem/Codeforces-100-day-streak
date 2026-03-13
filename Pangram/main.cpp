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

    int n;
    cin>>n;
    string s;
    cin>>s;

    if(n<26){
        cout<<"NO";
        return 0;
    }

    vector<int> arr(26,0);
    for(char c:s){
       int x = tolower(c)-'a';
       arr[x]++;
    }

    if(*min_element(arr.begin(), arr.end()) > 0)cout<<"YES";
    else cout<<"NO";


    return 0;
}

