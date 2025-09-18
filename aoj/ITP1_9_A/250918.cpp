#include <iostream>
#include <string>

using namespace std;

int main() {
    string w;
    cin >> w;

    string t;
    int count = 0;
    while (cin >> t && t != "END_OF_TEXT") {
        for (auto &c : t) 
            c = tolower(c);
        for (auto &c : w)
            c = tolower(c);
        if (t == w)
            count++;
    }
    cout << count << endl;
}