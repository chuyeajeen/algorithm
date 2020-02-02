//나무재테크
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
//int arr[11][11];
//int sam[11][11];
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
//
//struct tree {
//	int x;
//	int y;
//	int age;
//};
//
//bool cmp(tree& v1, tree& v2)
//{
//		return v1.age < v2.age;
//}
//int main()
//{
//
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector < tree> v;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			int tmp;
//			cin >> tmp;
//			arr[i][j] = 5;
//			sam[i][j] = tmp;
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		int x, y, age;
//		cin >> x >> y >> age;
//		v.push_back({ x, y, age });
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		sort(v.begin(), v.end(), cmp); // 나이순으로 정렬한 cmp 함수 짜기
//		int size = v.size();
//		int idx = 0;
//		vector<tree> die;
//		while(size--)
//		{
//			int y = v[idx].x;
//			int x = v[idx].y;
//			int age = v[idx].age;
//			if (arr[y][x] >= age) //봄
//			{
//				arr[y][x] -= age;
//				v[idx].age++;
//				idx++;
//			}
//			//else	//봄 나무 죽었을때(여름) -> 이렇게 처리하면 해당 죄표의 양분이 바로 추가되어 안됨-> 봄을 다 돌린 후 여름 양분 추가해야함
//			//{
//			//	arr[y][x] += (int)v[idx].age / 2;
//			//	v.erase(v.begin() + idx);
//			//}
//			else
//			{
//				die.push_back({ y,x,age });
//				v.erase(v.begin() + idx);
//			}
//		}
//
//		for (int j = 0; j < die.size(); j++)
//		{
//			arr[die[j].x][die[j].y] += (int)die[j].age / 2;
//		}
//
//
//		size = v.size();
//		for (int j = 0; j < size; j++)  //가을
//		{
//			if (v[j].age % 5 == 0)
//			{
//				
//				for (int k = 0; k < 8; k++)
//				{
//					int nx = v[j].x + dx[k];
//					int ny = v[j].y + dy[k];
//
//					if (nx > 0 && nx <= n && ny > 0 && ny <= n)
//					{
//						v.push_back({ nx,ny,1 });
//					}
//				}
//			}
//		}
//
//		for (int j = 1; j <= n; j++) //겨울
//		{
//			for (int k = 1; k <= n; k++)
//			{
//				arr[j][k] += sam[j][k];
//			}
//		}
//	}
//
//	printf("%d", v.size());
//	return 0;
//}
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<int> tree[12][12];
int Map[12][12];
int cpy[12][12];
int main()
{

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			cin >> tmp;
			Map[i][j] = 5;
			cpy[i][j] = tmp;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;
		tree[y][x].push_back(age);
	}

	while (k--)
	{
		for (int i = 1; i <= n; i++) //봄 여름
		{
			for (int j = 1; j <= n; j++)
			{
				sort(tree[i][j].begin(), tree[i][j].end());

				int size = tree[i][j].size();
				int sum = 0;
				vector<int> tmp;
				for (int k = 0; k < size; k++)
				{
					if (Map[i][j] >= tree[i][j][k])
					{
						Map[i][j] -= tree[i][j][k];
						tmp.push_back(tree[i][j][k] + 1);
					}
					else
					{
						sum += tree[i][j][k] / 2;
					}
				}
				Map[i][j] += sum;
				tree[i][j] = tmp;
			}
		}

		for (int i = 1; i <= n; i++)//가을
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 0; k < tree[i][j].size(); k++)
				{
					if (tree[i][j][k] % 5 == 0)
					{
						for (int l = 0; l < 8; l++)
						{
							int ny = i + dy[l];
							int nx = j + dx[l];
							if (nx > 0 && nx <= n && ny > 0 && ny <= n)
							{
								tree[ny][nx].push_back(1);
							}
						}
					}

					
				}

				Map[i][j] += cpy[i][j];
			}
		}

	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += tree[i][j].size();
		}
	}

	cout << ans << endl;
	return 0;
}