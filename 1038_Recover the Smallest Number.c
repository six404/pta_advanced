#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    return a + b < b + a;
}
string str[10001];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    sort(str, str + n, cmp);
    string tmp;
    for (int i = 0; i < n; i++) {
        tmp += str[i];
    }
    while (tmp.length() != 0 && tmp[0] == '0') {
        tmp.erase(tmp.begin());
    }
    if (tmp.length() == 0)cout << 0;
    else cout << tmp;

    return 0;
}
