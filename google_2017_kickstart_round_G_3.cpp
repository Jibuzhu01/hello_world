#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ifstream cin("3_small.in");
	ofstream cout("3_small_out.txt");
	int T;
	cin >> T;
	int kase,i, j, k;
	for (kase = 1; kase <= T; kase++)
	{
		int row, col;
		cin >> row >> col;
		vector<vector<int>> matrix(row, vector<int>(col, 0));
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++) cin >> matrix[i][j];
		}
		vector<vector<int>> dp(col, vector<int>(col, 0));
		for (i = 0; i < col - 1; i++) dp[i][i + 1] = min(matrix[0][i], matrix[0][i + 1]);
		for (i = 2; i < col; i++)
		{
			for (j = 0; j < col - i; j++)
			{
				int coins = 1000000;
				for (k = 0; k <= i; k++) coins = min(coins, matrix[0][j + k]);
				for (k = 0; k < i; k++)
				{
					dp[j][j + i] = max(dp[j][j + i], dp[j][j + k] + dp[j + k + 1][j + i] + coins);
				}
			}
		}
		cout << "Case #" << kase << ": " << dp[0][col - 1]<<endl;
	}
}