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

    string letters;
    getline(std::cin, letters);

    bool alpha[123] = {false};

    for(int i=0; i<letters.size(); i++){
        alpha[(int)letters[i]]= true;
    }

    int rep=0;
    for(int i=97; i<=122; i++){
        alpha[i]==true ? rep++: rep+=0;
    }

    cout<<rep;
    return 0;
}

