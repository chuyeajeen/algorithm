//영식이와 친구들

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, m, k; //n명, m번 받을때까지, k 떨어진 사람에게 패스
	int time[1001] = { 0, };
	cin >> n >> m >> k;
	int ans = 0;
	time[0] = 1;
	int idx = 0;//0부터 시작
	while (1)
	{
		if (time[idx] == m)
			break;
		if (time[idx] % 2 == 0)
		{
			idx = (idx -k+n) % n;
			
		}
		else
		{
			idx = (idx + k) % n;
		}
		time[idx]++;
		ans++;

	}
	cout << ans << "\n";
	return 0;

}