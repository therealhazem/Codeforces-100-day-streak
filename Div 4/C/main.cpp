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

    int n;
    cin>>n;

    while(n--){
        int x;
        cin>>x;
        int cou = 3*x;

        vector<int> ans;

        int small = 1;
        int big = cou;

        for(int i=0; i<x; i++){
            ans.push_back(small);
            ans.push_back(big);
            ans.push_back(big-1);

            small++;
            big -= 2;
        }

        for(int i=0; i<cou; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
