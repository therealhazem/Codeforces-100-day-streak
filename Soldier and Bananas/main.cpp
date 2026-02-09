#include <iostream>
using namespace std;

int main() {
    long long k, n, w;
    cin >> k >> n >> w;

    long long totalCost = k * w * (w + 1) / 2;

    if (totalCost > n)
        cout << totalCost - n;
    else
        cout << 0;

    return 0;
}
