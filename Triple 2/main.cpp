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
        unordered_map<int, int> nums;
        int x;
        cin>>x;
        int ans=-1;
        while(x--){
            int z;
            cin>>z;
            nums[z]++;
            if(nums[z]>=3)ans=z;
        }
        cout<<ans<<"\n";
    }

    return 0;
}

