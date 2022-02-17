#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int w;
	vector<int> child;
}Node[maxn];
int n, m, s;
vector<int>path;
vector<vector<int>>ans;
void dfs(int index, vector<int>path, int sum) {
	if (sum > s)return;
	if (sum == s) {
		if (Node[index].child.size() != 0) return;
		ans.push_back(path);
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) {
		int child = Node[index].child[i];
		path.push_back(Node[child].w);
		dfs(child, path, sum + Node[child].w);
		path.pop_back();
	}
}
int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> Node[i].w;
	}
	int id, k, child;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> child;
			Node[id].child.push_back(child);
		}
	}
	path.push_back(Node[0].w);
	dfs(0, path, Node[0].w);
	sort(ans.begin(), ans.end(), greater<vector<int>>());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i][0]);
		for (int j = 1; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		cout << endl;
	}

	return 0;
}
