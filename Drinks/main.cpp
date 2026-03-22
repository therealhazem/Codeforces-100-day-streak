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
    int div = n;
    double sum = 0;
    while(n--){
        double x;
        cin>>x;
        x /=100.0000000;
        sum+=x;
    }
    cout<<setprecision(12)<<(sum*100)/div;
    return 0;
}

