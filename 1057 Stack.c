#include <iostream>
#include <stack>
using namespace std;
#define lowbit(i)((i)&(-i))
const int maxn = 1000001;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}
int getsum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (getsum(mid) >= k) right = mid;
        else left = mid + 1;
    }
    printf("%d\n",left);
}
int main(){
    int n, tmp;
    scanf("%d", &n);
    char str[15];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (str[1] == 'u') {
            scanf("%d", &tmp);
            s.push(tmp);
            update(tmp, 1);
        }
        else if (str[1] == 'o') {
            if (!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
            else {
                printf("Invalid\n");
            }
        }
        else {
            if (!s.empty()) PeekMedian();
            else printf("Invalid\n");
        }
    }

    return 0;
}
