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
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(ans, arr[i]^arr[j]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
