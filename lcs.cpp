#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	string x,y;
	int n,lx,ly,lcs;
	while(1)
	{
		cin >> x >> y;
		if(x == "#END")
			return 0;
		x = ' ' + x;
		y = ' ' + y;
		lx = x.length();
		ly = y.length();
		int ** dp = new int* [lx];
		for(int i = 0;i < lx;i ++)
			dp[i] = new int [ly];
		for(int i = 0;i < lx;i ++)
			for(int j = 0;j < ly;j ++)
				dp[i][j] = 0;
		lcs = 0;
		for(int i = 1;i < lx;i ++){
			for(int j = 1;j < ly;j ++){
				if(x[i] == y[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
		cout << dp[lx - 1][ly - 1] << "\n";
	}
	return 0;
}
