#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
vector<int> _friend1;
vector<int> _friend2;
vector<int> arr;



bool countPairing(vector<int>& arr, vector<int>& _friend1, vector<int>& _friend2, int& count, int m);

int main()
{
	int C, n, m;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> n >> m;
		int result = 0;
		arr.clear();
		_friend1.clear();
		_friend2.clear();
		for (int z = 0; z < n; z++)
		{
			arr.push_back(z);
		}
		for (int j = 0; j < m; j++)
		{
			int friend1, friend2;
			cin >> friend1 >> friend2;
			_friend1.push_back(friend1);
			_friend2.push_back(friend2);
		}
		/*for (int z = 0; z < m; z++)
		{
			countPairing(n / 2, _friend[0][0], _friend[0][1], 0, 0);
		}*/
		countPairing(arr, _friend1, _friend2, result, m);

		cout << result << "\n";
	}



	return 0;
}

bool countPairing(vector<int>& arr, vector<int>& _friend1, vector<int>& _friend2, int& count, int m)
{
	//bool check = false;
	if (arr.size() == 0)return true;
	vector<int> checkarr = arr;
	for (int i = 1; i < arr.size(); i++) // �ѹ� �� �������� �ٽ� ���ƿͼ� �ٽ� ����
	{
		for (int j = 0; j < m; j++)  // ģ�� �� �� ��ŭ �ݺ���
		{
			if ((checkarr[0] == _friend1[j] && checkarr[i] == _friend2[j]) || (checkarr[0] == _friend2[j] && checkarr[i] == _friend1[j]))
			{
				checkarr.erase(checkarr.begin() + i); // ó�������� �����ϴϱ� ������.. 2���������� ó���� ���ֹ����� �� �ڵ尡 �߸��Ǳ⶧��
				checkarr.erase(checkarr.begin());
				if (countPairing(checkarr, _friend1, _friend2, count, m)) count++;
				checkarr = arr; // �ٽ� arr�� �ʱ�ȭ 
				break;
			}
		}
	}

	return false;
}
