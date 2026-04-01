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


long long sumN(long long n){
    return n * (n + 1) / 2;
}

long long evenSum(long long n){
    long long k = n / 2;
    return k * (k + 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long A, B;
    cin >> A >> B;

    if(A > B) swap(A, B);

    long long total = sumN(B) - sumN(A - 1);
    long long even = evenSum(B) - evenSum(A - 1);
    long long odd = total - even;

    cout << total << endl;
    cout << even << endl;
    cout << odd << endl;

    return 0;
}

