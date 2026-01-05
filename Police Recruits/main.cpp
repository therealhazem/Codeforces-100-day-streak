#include <iostream>

using namespace std;

int n;
int crimes = 0;
int police = 0;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==-1){
            crimes++;
            if(police > 0){
                crimes -=1;
                police -=1;
            }
        }else{
            police += x;
        }
    }

    cout<<crimes;
    return 0;
}

