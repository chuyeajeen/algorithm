#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;
int arr[101][101];
int visit[101][101];
int ans,sum;
int n, L, R;
vector<pair<int, int>> v;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int y, int x)
{

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && visit[ny][nx]==0)
        {
            int sub = abs(arr[y][x] - arr[ny][nx]);
            if (sub >= L && sub <= R)
            {
                visit[ny][nx]=1;
                v.push_back(make_pair(ny, nx));
                sum += arr[ny][nx];
                dfs(ny, nx);
            }
        }
    }
}

int main()
{
	cin >> n >> L >> R;
	int count = 0;
    int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

    while (1)
    {
        bool check = false;
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit[i][j])
                    continue;
                v.clear();
                visit[i][j] = 1;
                v.push_back(make_pair(i, j));
                sum = arr[i][j];
                dfs(i, j);

                if (v.size() > 1)
                {
                    int size = v.size();
                    check = true;
                    for (int k = 0; k < size; k++)
                    {
                        arr[v[k].first][v[k].second] = sum / size;
                    }
                }
            }
        }

        if (check == false)
            break;
        ans++;
    }
    cout << ans << endl;
	return 0;
}

