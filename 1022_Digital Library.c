#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
map<string, set<int>> title, author, key, pub, year;
void query(map<string, set<int>>& m, string& str) {
	if (m.find(str) != m.end()) {
		for (auto it = m[str].begin(); it != m[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
	else {
		cout << "Not Found" << endl;
	}
}
int main() {
	int n,m,id,num;
	cin >> n;
	string tt, ta, tk, tp, ty;
	for (int i = 0; i < n; i++) {
		cin >> id;
		getchar();
		getline(cin, tt);
		title[tt].insert(id);
		getline(cin, ta);
		author[ta].insert(id);
		while (cin >> tk) {
			key[tk].insert(id);
			char c = getchar();
			if (c == '\n')break;
		}
		getline(cin, tp);
		pub[tp].insert(id);
		getline(cin, ty);
		year[ty].insert(id);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &num);
		string tmp;
		getline(cin, tmp);
		cout << num << ": " << tmp << endl;
		if (num == 1)query(title, tmp);
		else if (num == 2)query(author, tmp);
		else if (num == 3)query(key, tmp);
		else if (num == 4)query(pub, tmp);
		else if (num == 5)query(year, tmp);
	}
	return 0;
}
