#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int check[1001];

int main()
{
	int simul;
	cin >> simul;
	for (int test_case = 0; test_case < simul; test_case++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v[1001];
		for (int i = 0; i < m; i++)
		{
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
		}
		cout << n - 1 << endl;

	}


	return 0;
}


