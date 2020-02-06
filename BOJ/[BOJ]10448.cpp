//유레카 이론
#include<iostream>
using namespace std;

int main()
{
    int pibo[51] = { 0, };
    int check[1001] = { 0, };
    for (int i = 1; i <= 50; i++)
    {
        pibo[i] = i * (i + 1) / 2;
    }
    for (int i = 1; i < 50; i++)
    {
        for (int j = 1; j < 50; j++)
        {
            for (int k = 1; k < 50; k++)
            {
                int tmp = pibo[i] + pibo[j] + pibo[k];
                if (tmp <= 1000)
                    check[tmp] = 1;
            }
        }
    }
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        cout << check[num] << "\n";

    }
    return 0;
}