//�����̿� ģ����

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n, m, k; //n��, m�� ����������, k ������ ������� �н�
	int time[1001] = { 0, };
	cin >> n >> m >> k;
	int ans = 0;
	time[0] = 1;
	int idx = 0;//0���� ����
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