#include <iostream>
#include <queue>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	int poptime=0, endtime=0;//各个窗口最早可以进队的时间和服务最晚结束时间
	queue<int> q;
};
int main(int argc, char** argv) {
	int n, m, k, q, index = 1;
	cin >> n >> m >> k >> q;
	vector<int> time(k + 1), result(k + 1);
	for (int i = 1; i <= k; i++) {//输入每个人所需要的服务时间
		cin >> time[i];
	}
	vector<node> window(n + 1);
	vector<bool> sorry(k + 1, false);
	for (int i = 1; i <= m; i++) {//每排人的编号
		for (int j = 1; j <= n; j++) {
			if (index <= k) {
				window[j].q.push(time[index]);
				if (window[j].endtime >= 540) sorry[index] = true;
				window[j].endtime += time[index];
				if (i == 1) {
					window[j].poptime = window[j].endtime;
				}
				result[index] = window[j].endtime;
				index++;
			}
		}
	}
	while (index <= k) {
		int tmpmin = window[1].poptime, tmpwindow = 1;
		for (int i = 2; i <= n; i++) {
			if (window[i].poptime < tmpmin) {
				tmpwindow = i;
				tmpmin = window[i].poptime;
			}
		}
		window[tmpwindow].q.pop();
		window[tmpwindow].q.push(time[index]);
		window[tmpwindow].poptime += window[tmpwindow].q.front();
		if (window[tmpwindow].endtime >= 540) {
			sorry[index] = true;
		}
		window[tmpwindow].endtime += time[index];
		result[index] = window[tmpwindow].endtime;
		index++;
	}
	for (int i = 1; i <= q; i++) {
		int qq, min;
		cin >> qq;
		min = result[qq];
		if (sorry[qq] == true) {
			cout << "Sorry" << endl;
		}
		else {
			printf("%02d:%02d\n", (min + 480) / 60, (min + 480) % 60);
		}
	}

	return 0;
}
