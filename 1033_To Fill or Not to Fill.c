#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999999;
struct st {
    double price, dis;
};
bool cmp(st a, st b) {
    return a.dis < b.dis;
}
int main(){
    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<st>st(n + 1);
    st[0] = { 0.0,d };
    for (int i = 1; i <= n; i++) {
        cin >> st[i].price >> st[i].dis;
    }
    sort(st.begin(), st.end(), cmp);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalprice = 0.0, ld = 0.0;
    if (st[0].dis != 0) {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    else {
        nowprice = st[0].price;
    }
    while (nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minpricedis = 0.0, minprice = inf;
        int flag = 0;
        for (int i = 1; i <= n && st[i].dis <= maxdis; i++) {
            if (st[i].dis <= nowdis)continue;
            if (st[i].price < nowprice) {
                totalprice += (st[i].dis - nowdis - ld) * nowprice / davg;
                ld = 0.0;
                nowprice = st[i].price;
                nowdis = st[i].dis;
                flag = 1;
                break;
            }
            if (st[i].price < minprice) {
                minprice = st[i].price;
                minpricedis = st[i].dis;
            }
        }
        if (flag == 0 && minprice != inf) {
            totalprice += (nowprice * (cmax - ld / davg));
            ld = cmax * davg - (minpricedis - nowdis);
            nowprice = minprice;
            nowdis = minpricedis;
        }
        if (flag == 0 && minprice == inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalprice);

    return 0;
}
