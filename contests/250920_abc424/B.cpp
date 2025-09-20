#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> counts(K);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        if (++counts[a - 1] == M) {
            cout << a << " ";
        }
    }
}