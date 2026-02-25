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
    deque<char> ans;
    for(char c:s) ans.push_back(c);

    int n;
    cin>>n;

    bool reversed = false;

    while(n--){
        int t;
        cin>>t;

        if(t==1) reversed = !reversed;
        else{
            int q;
            cin>>q;
            if(q == 1 && !reversed){
                char input;
                cin>>input;
                ans.push_front(input);
            }else if(q == 1 && reversed){
                char input;
                cin>>input;
                ans.push_back(input);
            }else if(q==2 && !reversed){
                char input;
                cin>>input;
                ans.push_back(input);
            }else{
                char input;
                cin>>input;
                ans.push_front(input);
            }
        }

    }
        if(reversed) reverse(ans.begin(), ans.end());
        for(char c:ans) cout<<c;


    return 0;
}

