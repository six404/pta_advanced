#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> post, in;
map<int, int> level;
void pre(int root, int start, int end, int index) {
	if (start > end)return;
	int i = start;
	while (i < end && in[i] != post[root])i++;
	level[index] = post[root];
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
	pre(root - 1, i + 1, end, 2 * index + 2);
}
int main(){
	int n;
	cin >> n;
	post.resize(n);//!
	in.resize(n);//!
	for (int i = 0; i < n; i++) cin >> post[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	pre(n - 1, 0, n - 1, 0);
	auto it = level.begin();
	cout << it->second;
	while (++it != level.end())cout << " " << it->second;
	return 0;
}
