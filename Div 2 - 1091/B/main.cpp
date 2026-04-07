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
        int x,k,sp;
        cin>>x>>k;

        vector<int> nums(x);
        for(int i=0; i<x; i++){
            cin>>nums[i];
        }

        cin>>sp;
        sp--;

        int want=nums[sp];

        int left=0;
        int right=0;

        if(nums[0]!=want)left++;
        for(int i=1; i<=sp; i++){
            if(nums[i] != nums[i-1]) left++;
        }
        for(int i=sp+1; i<x; i++){
            if(nums[i] != nums[i-1]) right++;
        }
        if(nums[x-1] != want) right++;

        cout<<max(left, right)<<"\n";
    }
    return 0;
}
