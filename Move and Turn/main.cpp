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

    int ans;
    if (n%2==0) {
        int k= n/2;
        ans =4*(k+1)*(k+1)/4;
    } else {
        int k=n/2;
        ans = 4*(k+1)*(k+2)/2;
    }

    cout << ans << "\n";
    return 0;
}
