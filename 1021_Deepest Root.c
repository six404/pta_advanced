#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n;
bool visit[10001];
vector<int>tmp;
vector<vector<int>> v;
set<int> s;
int maxheight = 0;
void dfs(int node, int height) {
	if (height > maxheight) {
		tmp.clear();
		tmp.push_back(node);
		maxheight = height;
	}
	else if (height == maxheight) {
		tmp.push_back(node);
	}
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (visit[v[node][i]] == false) {
			dfs(v[node][i], height + 1);
		}
	}

}
int main() {
	cin >> n;
	v.resize(n + 1);
	int a, b, cnt = 0, s1 = 0;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			dfs(i,1);
			if (i == 1) {
				if (tmp.size() != 0)s1 = tmp[0];
				for (int j = 0; j < tmp.size(); j++) {
					s.insert(tmp[j]);
				}
			}
			cnt++;
		}
	}
	if (cnt != 1) {
		cout <<"Error: " << cnt << " components";

	}
	else {
		tmp.clear();
		maxheight = 0;
		fill(visit, visit + 10001, false);
		dfs(s1, 1);
		for (int i = 0; i < tmp.size(); i++) {
			s.insert(tmp[i]);
		}
		for (auto it = s.begin(); it != s.end(); it++) {
			printf("%d\n", *it);
		}
	}
	return 0;
}
