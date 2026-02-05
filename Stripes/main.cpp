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
    while (n--) {
        vector<string> grid(8);
        for (int i=0; i<8; i++) {
            cin>>grid[i];
        }

        bool red = false;
        for (int i=0; i<8; i++) {
            if (grid[i] == "RRRRRRRR") {
                red=true;
                break;
            }
        }
        red ? cout<<"R\n": cout<<"B\n";
    }

    return 0;
}
