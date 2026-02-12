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
        int live,apart;
        cin>>live>>apart;
        int maxap=2;
        int floor=1;

        while(live > maxap){
            maxap += apart;
            floor++;
        }
        cout<<floor<<"\n";

    }

    return 0;
}

