#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    cout << d << endl;
}