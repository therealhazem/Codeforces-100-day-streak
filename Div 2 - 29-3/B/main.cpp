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
    cin>>t;

    while(t--){
        int c;
        cin>>c;

        vector<int> chairs(c+1);
        vector<int> marked(c+1);

        int sit=0;

        for(int i=1; i<=c; i++){
            cin>>chairs[i];
        }

        for(int i=1; i<=c; i++){
            marked[chairs[i]] = i;
        }

        int stop=0;

        for(int i=1; i<=c; i++){
            if(marked[i] < i){
                stop++;
                sit = max(sit, i-stop);
            }

        }

        cout<<sit<<"\n";
    }
    return 0;
}
