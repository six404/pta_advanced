#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	string name;
	int status, month, time, day, hour, min;
};
bool cmp(node a, node b) {
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double bill(node call, int rate[]) {
	double total = rate[call.hour] * call.min + rate[24] * 60 * call.day;
	for (int i = 0; i < call.hour; i++) {
		total += rate[i] * 60;
	}
	return total / 100.0;
}
int main(int argc, char** argv) {
	int rate[25] = { 0 }, n;
	for (int i = 0; i < 24; i++) {
		cin >> rate[i];
		rate[24] += rate[i];
	}
	cin >> n;
	vector<node> data(n);
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].min);
		cin >> tmp;
		data[i].status = (tmp == "on-line") ? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].min;
	}
	sort(data.begin(), data.end(), cmp);
	map<string, vector<node> > custom;
	for (int i = 1; i < n; i++) {
		if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
			custom[data[i - 1].name].push_back(data[i - 1]);
			custom[data[i].name].push_back(data[i]);
		}
	}
	for (auto it : custom) {
		vector<node> tmp = it.second;
		cout << it.first;
		printf(" %02d\n", tmp[0].month);
		double total = 0.0;
		for (int i = 1; i < tmp.size(); i += 2) {
			double t = bill(tmp[i], rate) - bill(tmp[i - 1], rate);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", tmp[i - 1].day, tmp[i - 1].hour, tmp[i - 1].min, tmp[i].day, tmp[i].hour, tmp[i].min, tmp[i].time - tmp[i - 1].time, t);
			total += t;
		}
		printf("Total amount: $%.2f\n", total);
	}

	return 0;
}
