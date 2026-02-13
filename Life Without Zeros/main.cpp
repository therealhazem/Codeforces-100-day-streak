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

    string a,b;
    cin>>a>>b;
    long long oldsum = stoll(a) + stoll(b);
    string oldsums = to_string(oldsum);
    string na="";
    string nb="";
    string ns="";

    for(int i=0; i<a.length(); i++){
        if(a[i]!='0') na += a[i];
    }
    for(int i=0; i<b.length(); i++){
        if(b[i]!='0')nb += b[i];
    }

    for(int i=0; i<oldsums.length(); i++){
        if(oldsums[i]!='0')ns += oldsums[i];
    }

    long long newsum = stoll(na) + stoll(nb);

    (ns == to_string(newsum))? cout<<"YES": cout<<"NO";

    return 0;
}

