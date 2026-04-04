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

bool isprime(long long x)
{
    if(x < 2) return false;
    for(long long i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    vector<int> ask(t);
    int maxi = 0;

    for(int i=0; i<t; i++){
        cin>>ask[i];
        maxi = max(maxi, ask[i]);
    }

    vector<long long> prime;
    long long num = 2;

    while((int)prime.size() < maxi){
        if(isprime(num)){
            prime.push_back(num);
        }
        num++;
    }

    for(int k=0; k<t; k++){
        int n = ask[k];

        cout<<1<<" ";
        for(int i=1; i<n; i++){
            cout<<prime[i-1] * prime[i] << " ";
        }
        cout<<"\n";
    }

    return 0;
}



/*
used Chatgpt to make it with prime because of the power 18
my code logic was

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

    int n;
    cin>>n;

    while(n--){
        int x;
        cin>>x;

        vector<long long> ans;
        long long i=1;

        while((int)ans.size() < x){
            ans.push_back(i);
            i*=2;
        }

        for(int i=0; i<x; i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

*/
