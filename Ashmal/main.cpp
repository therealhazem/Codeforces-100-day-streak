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
        int x;
        cin>>x;
        string s="";
        while(x--){
            string name;
            cin>>name;
            if(s==""){
                s.append(name);
            }else{
                name+s > s+name ? s=s+name : s=name+s;
            }
        }
        cout<<s<<"\n";
    }

    return 0;
}

