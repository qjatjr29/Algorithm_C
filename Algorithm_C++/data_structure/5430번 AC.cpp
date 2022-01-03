#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string p;
int n;
string arr;
bool check = true;
// ������ ��찡 �ƴϸ� true ���������� false
bool _reverse = true;
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		deque<int> AC;
		check = true;
		_reverse = true;
		cin >> p;
		cin >> n;
		cin >> arr;
		string arr_temp = "";
		for (int j = 0; j < arr.size(); j++)
		{
			// ù����
			if (arr[j] == '[') continue;
			// ���ڰ� ��� ������
			else if (arr[j] <= '9' && arr[j] >= '0')
				arr_temp += arr[j];
			// , ] �� ���ڰ� �������
			else if (arr[j] != ',' || arr[j] != ']')
			{
				if (!arr_temp.empty())
				{
					AC.push_back(stoi(arr_temp));
					arr_temp.clear();
				}
			}
		}
		for (int j = 0; j < p.size(); j++)
		{
			/*	for (int z = 0; z < AC.size() ; z++)
				{
					cout << AC[z] << " ";
				}
				cout << "\n";*/

				// ������
			if (p[j] == 'R')
			{
				_reverse = !_reverse;
				/*deque<int> store;

				for (int z = 0; z < AC.size(); z++)
				{
					int temp = AC[z];
					store.push_front(temp);
				}
				AC = store;*/
			}
			// �ϳ��� ����
			else if (p[j] == 'D')
			{
				// �����ߴ� ���
				if (AC.size() == 0)
				{
					check = false;
					break;
				}
				// �ȵ��������
				if (_reverse)
				{
					AC.pop_front();
				}
				// ������ ���
				else AC.pop_back();
			}
		}

		// ������ ���
		if (check)
		{
			cout << "[";
			if (AC.size() == 0)
			{
				cout << "]" << "\n";
			}
			// ������ ���� ����
			else if (_reverse)
			{
				for (int j = 0; j < AC.size(); j++)
				{
					if (j == AC.size() - 1)
					{
						cout << AC[j] << ']' << "\n";
					}
					else
						cout << AC[j] << ',';
				}
			}
			else if (!_reverse)
			{
				for (int j = AC.size() - 1; j >= 0; j--)
				{
					if (j == 0)
					{
						cout << AC[j] << ']' << "\n";
					}
					else
						cout << AC[j] << ',';
				}
			}
		}
		else
			cout << "error" << "\n";
	}


	return 0;
}