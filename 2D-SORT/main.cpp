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


bool myscanner(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    while(n--){
        int t;
        scanf("%d", &t);
        priority_queue<pair<int,int>, vector<pair<int,int>>,
            bool(*)(pair<int,int>, pair<int,int>)> pairs(myscanner);

        while(t--){
            int first, second;
            scanf("%d %d", &first, &second);
            pairs.push({first, second});
        }

        while(!pairs.empty()){
            printf("%d %d\n", pairs.top().first, pairs.top().second);
            pairs.pop();
        }
    }
    return 0;
}

