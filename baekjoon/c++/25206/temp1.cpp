#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total = 0; double sum = 0;
    for (int i = 0; i < 20; ++i) {
        string _, s; double d, p = 0; cin >> _ >> d >> s;
        if (s != "P") total += (int)d;
        if (s == "A+") p = 4.5;
        if (s == "A0") p = 4.0;
        if (s == "B+") p = 3.5;
        if (s == "B0") p = 3.0;
        if (s == "C+") p = 2.5;
        if (s == "C0") p = 2.0;
        if (s == "D+") p = 1.5;
        if (s == "D0") p = 1.0;
        sum += d * p;
    }
    cout << sum / total;

    return 0;
}
