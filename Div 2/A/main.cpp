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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> ones_pos, zeros_pos;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones_pos.push_back(i + 1);
            else
                zeros_pos.push_back(i + 1);
        }

        int ones = ones_pos.size();
        int zeros = zeros_pos.size();

        if (ones == 0)
        {
            cout << 0 << "\n";
        }
        else if (ones % 2 == 0)
        {
            cout << ones << "\n";
            for (int idx : ones_pos)
                cout << idx << " ";
            cout << "\n";
        }
        else if (zeros % 2 == 1)
        {
            cout << zeros << "\n";
            for (int idx : zeros_pos)
                cout << idx << " ";
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    //  updating comment
    return 0;
}
