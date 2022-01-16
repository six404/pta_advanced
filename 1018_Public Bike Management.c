#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool visit[501];
int e[501][501],dis[501],weight[501];
int c, n, s, m;//c->每个站最大承载  n->站点数  s->完蛋的站点 m->道路数
const int inf = 99999999;
int minNeed = inf, minBack = inf;
vector<int> pre[501], path, tmppath;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == 0) {
		int need = 0, back = 0;
		for (int i = tmppath.size()-1; i >= 0; i--) {
			int id = tmppath[i];
			if (weight[id] > 0) {
				back += weight[id];
			}
			else {
				if (back > (0 - weight[id])) {
					back += weight[id];
				}
				else {
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minBack = back;
			path = tmppath;
		}
		else if (need == minNeed && back < minBack) {
			minBack = back;
			path = tmppath;
		}
		tmppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tmppath.pop_back();
}
int main() {
	cin >> c >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		weight[i] = weight[i] - c / 2;
	}
	int a, b, l;
	fill(e[0], e[0] + 501 * 501, inf);
	fill(dis, dis + 501, inf);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> l;
		e[a][b] = e[b][a] = l;
	}
	dis[0] = 0;
	for (int i = 0; i < n + 1; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n + 1; j++) {
			if (visit[j] == false && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v < n + 1; v++) {
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[u] + e[u][v] == dis[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(s);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--) {
		printf("->%d", path[i]);
	}
	printf(" %d", minBack);

	return 0;
}
