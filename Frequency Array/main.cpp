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
        int N;
        cin>>N;
        vector<int> seq(N);

        for(int i=0; i<N; i++) cin>>seq[i];
        set<int> s(seq.begin(), seq.end());

        if((int)s.size()==N) cout<<"prekrasnyy\n";
        else cout<<"ne krasivo\n";
    }

    return 0;
}

