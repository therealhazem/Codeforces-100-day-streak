#include <iostream>

using namespace std;

int n;
int divs=0;
int last=0;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(last==0){
            divs++;
            last=x;
        }else{
            if((last == 10 && x == 10) || (last == 01 && x == 01)){
                divs+=0;
            }else{
                divs++;
                last = x;
            }
        }
    }
    cout<<divs;
    return 0;
}

