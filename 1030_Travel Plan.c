#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 99999999;
int n, m, s, d;
bool visit[501];
int e[501][501], cost[501][501], dis[501];
int mincost = inf;
vector<int> pre[501];
vector<int> path, tmppath;
void dfs(int v) {
	tmppath.push_back(v);
	if (v == s) {
		int tmpcost = 0;
		for (int i = tmppath.size() - 1; i > 0; i--) {
			int id = tmppath[i], nextid = tmppath[i - 1];
			tmpcost += cost[id][nextid];
		}
		if (tmpcost < mincost) {
			mincost = tmpcost;
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
int main(){
	cin >> n >> m >> s >> d;
	int start, end,distance,co;
	fill(e[0], e[0] + 501 * 501, inf);
	fill(dis, dis + 501, inf);
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> distance >> co;
		e[start][end] = e[end][start] = distance;
		cost[start][end] = cost[end][start] = co;
	}
	pre[s].push_back(s);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j] == false && dis[j] < minn) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)break;
		visit[u] = true;
		for (int v = 0; v < n; v++) {
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
	dfs(d);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[d], mincost);
}
