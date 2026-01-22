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
    string s;
    cin>>n>>s;
    int rem=0;

    for(int i=0; i<n-1; i++){
        if(i<=n-3 && s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
            rem++;
        }
    }

    cout<<rem;


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
    string s;
    cin>>n>>s;
    int rem=0;

    for(int i=0; i<n-1; i++){
        if(i<=n-3 && s[i]=='x' && s[i+1]=='x' && s[i+2]=='x'){
            rem++;
        }
    }

    cout<<rem;


    return 0;
}
>>>>>>> 6c05bb93d41bb6fde1fdeb36b5216d66f6c12f6a
