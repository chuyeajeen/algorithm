//그림비교
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector < pair<int, pair<int, int>>> answer;
char arr[51][5][7];
int n;
void check(int i, int j)
{
    int ans = 0;
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 7; x++)
        {
            if (arr[i][y][x] != arr[j][y][x])
                ans++;
        }
    }
    answer.push_back(make_pair(ans, make_pair(i, j)));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            check(i, j);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer[0].second.first + 1 << " " << answer[0].second.second + 1 << endl;
    return 0;
}