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
    while(n--){
        string s;
        cin >> s;

        set<char> letters;
        int days=0;
        int i=0;

        while(i<s.size()){
            letters.clear();
            days++;
            while(i<s.size() && (letters.count(s[i]) || letters.size()<3)){
                letters.insert(s[i]);
                i++;
            }
        }

        cout<<days <<"\n";
    }


    return 0;
}

