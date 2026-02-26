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

    while(n--) {
        string s;
        cin>>s;

        int openRound=0;
        int openSquare=0;
        int ans=0;

        for (char c:s) {
            if (c=='(') openRound++;
            else if (c=='[') openSquare++;
            else if (c==')' && openRound>0) {
                openRound--;
                ans++;
            }else if (c==']' && openSquare>0) {
                openSquare--;
                ans++;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}

