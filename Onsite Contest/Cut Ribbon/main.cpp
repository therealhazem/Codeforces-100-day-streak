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

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    vector<int> arr = {a,b,c};
    sort(arr.begin(), arr.end());

    int rib=0;

    for (int i=n/arr[0]; i>=0; i--) {
        int used = i*arr[0];
        int rem = n-used;

        if(rem % arr[1] == 0) {
            rib = i + (rem/arr[1]);
            break;
        }
        if(rem % arr[2]==0) {
            rib = i+ (rem/arr[2]);
            break;
        }
    }

    cout<<rib;
    return 0;
}



