#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	int come, time;
};
bool cmp(node a, node b) {
	return a.come < b.come;
}
int total;
int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	vector<node> v;
	node nd;
	int h, m, s, d;
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &h, &m, &s, &d);
		if (h >= 17) continue;
		nd.come = h * 60 * 60 + m * 60 + s;
		nd.time = d * 60;
		v.push_back(nd);
	}
	sort(v.begin(), v.end(), cmp);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= k; i++) q.push(28800);
	for (int i = 0; i < v.size(); i++) {
		if (q.top() <= v[i].come) {
			q.push(v[i].come + v[i].time);
			q.pop();
		}
		else {
			total += q.top() - v[i].come;
			q.push(q.top() + v[i].time);
			q.pop();
		}
	}
	(!v.size()) ? printf("0.0") : printf("%.1lf", ((double)total / 60.0) / (double)v.size());
	return 0;
}
