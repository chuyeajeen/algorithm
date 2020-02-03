#include <iostream>
using namespace std;
int dp[3][100001];

int main(void)
{
    int N;
    cin >> N;

    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % 9901;
    }
   int ans = (dp[0][N] + dp[1][N] + dp[2][N]) % 9901;
    cout << ans<< endl;

    return 0;

}