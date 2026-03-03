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
    string s;
    cin>>n>>s;

    int maxx=0;
    string letters;

    unordered_map<string, int> doubles;

    for(int i=0; i<(s.size()-1); i++){
        string checker = "";
        checker += s[i];
        checker += s[i + 1];
        doubles[checker]++;

        int cou = doubles[checker];
        maxx = max(maxx, cou);
        if(maxx == cou) letters = checker;
    }

    cout<<letters;


    return 0;
}

