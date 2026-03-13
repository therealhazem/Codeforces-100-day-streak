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
    int res = n;
    vector<int> nums(101,0);

    while(n--){
        int x;
        cin>>x;
        nums[x]++;
    }

    int biggest = *max_element(nums.begin(), nums.end());

    cout<<res-biggest;

    return 0;
}

