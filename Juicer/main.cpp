#include <bits/stdc++.h>
using namespace std;

int n,b,d;
int emp = 0;
int main() {
cin>>n>>b>>d;
int save = d;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x>b){
            emp +=0;
        }else{
            d -=x;
        }
        if(d<0){
            emp++;
            d=save;
        }
    }
    cout<<emp;
    return 0;
}

