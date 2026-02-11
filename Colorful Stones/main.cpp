#include <iostream>

using namespace std;

string seq, inst;
int stone = 0;

int main()
{
    cin >> seq >> inst;

    for (int i = 0; i < inst.length(); i++)
    {
        if (inst[i] == seq[stone])
        {
            stone++;
        }
    }

    cout << stone + 1;

    return 0;
}
