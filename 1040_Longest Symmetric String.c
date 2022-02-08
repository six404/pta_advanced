1.暴力
#include <iostream>
 
using namespace std;
 
bool isSymmetric(string &str, int i, int j, int &maxSize)
{
    int left = i, right = j, mid = (i + j) / 2 ;
    for (; i <= mid; ++i)
    {
        if(str[i] != str[j--]) return false;
    }
    maxSize = right - left + 1;
    return true;
}
 
int main()
{
    string str;
    getline(cin, str);
    int max = 1;
    for (int i = 0; i < str.size(); ++i)
    {
        int maxSize = 1;
        for (int j = i + 1; j < str.size(); j++)
        {
            if(str[i] == str[j])
            {
                if(isSymmetric(str, i, j, maxSize))
                {
                    if(maxSize > max) max = maxSize;
                }
            }
        }
    }
    cout << max;
    return 0;
}



2.动态规划
#include <iostream>
using namespace std;
int dp[1010][1010];
int main() {
    string s;
    getline(cin, s);
    int len = s.length(), ans = 1;
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
