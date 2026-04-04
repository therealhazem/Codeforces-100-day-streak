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
        int sum=0;
        priority_queue<int, vector<int>, greater<int>> nums;

        for(int i=0; i<7; i++){
            int x;
            cin>>x;
            nums.push(x);
        }

        for(int i=0; i<6; i++){
            sum += -1*nums.top();
            nums.pop();
        }
        cout<<sum+nums.top()<<"\n";
    }
    return 0;
}
