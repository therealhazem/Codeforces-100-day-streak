#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin>>x;
    while(x--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int n=0;

    if(b>a)n++;
    if(c>a)n++;
    if(d>a)n++;

    cout<<n<<"\n";
    }
    return 0;
}
