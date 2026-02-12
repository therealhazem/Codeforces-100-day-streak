#include <bits/stdc++.h>
using namespace std;


long long solving(long long a, long long b, long long x, long long y, long long n) {
    long long deca = a-x;
    if (deca > n) deca = n;
    a -= deca;
    n -= deca;

    long long db = b-y;
    if (db > n) db = n;
    b -= db;

    return a*b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        long long a,b,x,y,n;
        cin >>a>>b>>x>>y>>n;

        cout<<min(
            solving(a,b,x,y,n),
            solving(b,a,y,x,n)
        )<<"\n";}

    return 0;
}
