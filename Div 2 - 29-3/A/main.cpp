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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int x;
        cin>>x;

        for(int i=x; i>=1; i--){
            cout<<i<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
