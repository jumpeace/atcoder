#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int faces[6];
    for (int i = 0; i < 6; i++) {
        cin >> faces[i];
    }

    string s;
    cin >> s;

    // faces のインデックスと面の対応
    // 0:上, 1:前, 2:右, 3:左, 4:後, 5:下
    for (char cmd: s) {
        int top = faces[0];
        int front = faces[1];
        int right = faces[2];
        int left = faces[3];
        int back = faces[4];
        int bottom = faces[5];

        if (cmd == 'N') {
            faces[0] = front;
            faces[1] = bottom;
            faces[5] = back;
            faces[4] = top;
        } else if (cmd == 'S') {
            faces[0] = back;
            faces[4] = bottom;
            faces[5] = front;
            faces[1] = top;
        } else if (cmd == 'E') {
            faces[0] = left;
            faces[3] = bottom;
            faces[5] = right;
            faces[2] = top;
        } else if (cmd == 'W') {
            faces[0] = right;
            faces[2] = bottom;
            faces[5] = left;
            faces[3] = top;
        }
    }

    cout << faces[0] << endl;

    return 0;
}
