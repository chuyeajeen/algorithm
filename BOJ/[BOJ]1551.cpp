//수열의 변화
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string> //stoi 헤더
#include<string.h> //strtok 헤더
using namespace std;

int main()
{
	int n, k;
	int arr[21] = { 0, };
	int ans[20] = { 0, };
	cin >> n >> k ;

	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			scanf("%d,", &arr[i]);
		else
			scanf("%d", &arr[i]);
	}
	int cpy_n = n;
	for(int j=0;j<k;j++)
	{
		for (int i = 0; i < cpy_n - 1; i++)
		{
			arr[i] = arr[i + 1] - arr[i];
		}
		cpy_n -= 1;
	}
	for (int i = 0; i <= n -k-2; i++)
	{
		cout << arr[i] << ",";
	}
	cout << arr[n - k-1] << "\n";
	return 0;
}

