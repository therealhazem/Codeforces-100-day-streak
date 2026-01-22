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
        int cou;
        cin>>cou;

        vector<int> nums(cou);
        for(int i=0; i<cou; i++)
            cin>>nums[i];

        unordered_set<int> mine;
        bool printed = false;

        for(int i=cou-1; i >= 0; i--) {
            if(mine.find(nums[i]) == mine.end()){
                mine.insert(nums[i]);
            }else{
                cout<<cou - mine.size()<<"\n";
                printed = true;
                break;
            }
        }

        if(!printed)
            cout<<0<<"\n";
    }

    return 0;
}
