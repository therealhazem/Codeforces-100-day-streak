#include <bits/stdc++.h>
using namespace std;

int n, m;
int steps = 0;
int main() {
    cin>>n>>m;
int save=n;
    while(n!=0 && n!=1){
        n-=2;
        steps++;
    }
    if(n==1){
        n--;
        steps++;
    }

    if(steps%m == 0){
        cout<<steps;
    }else{
        while(steps%m !=0 && steps<save){
            steps++;
        }
        if(steps%m == 0){
            cout<<steps;
        }else{
            cout<<-1;
        }
    }

    return 0;
}

