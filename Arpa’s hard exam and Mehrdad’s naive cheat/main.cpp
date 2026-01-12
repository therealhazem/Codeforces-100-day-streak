#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    n %=4;
    if ( n == 1){
        cout<<8;
    }else if (n == 2){
        cout<<4;
    }else if (n == 3){
        cout<<2;
    }else if ( n == 0){
        cout<<6;
    }
    return 0;
}

