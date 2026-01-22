<<<<<<< HEAD
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

    int n;
    int pep=0;

    cin>>n;

    while(n--){
        int x;
        cin>>x;
        pep+=x;
    }

    if(pep<=5){
        cout<<1;
    }else if(pep%5==0){
        cout<<pep/5;
    }else{
        cout<<pep/5 + 1;
    }

    return 0;
}
=======
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

    int n;
    int pep=0;

    cin>>n;

    while(n--){
        int x;
        cin>>x;
        pep+=x;
    }

    if(pep<=5){
        cout<<1;
    }else if(pep%5==0){
        cout<<pep/5;
    }else{
        cout<<pep/5 + 1;
    }

    return 0;
}
>>>>>>> 6c05bb93d41bb6fde1fdeb36b5216d66f6c12f6a
