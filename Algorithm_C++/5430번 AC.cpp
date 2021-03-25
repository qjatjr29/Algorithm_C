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
// 뒤집는 경우가 아니면 true 뒤집혔으면 false
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
			// 첫시작
			if (arr[j] == '[') continue;
			// 숫자가 들어 있을때
			else if (arr[j] <= '9' && arr[j] >= '0')
				arr_temp += arr[j];
			// , ] 로 숫자가 끝난경우
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

				// 뒤집기
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
			// 하나씩 빼기
			else if (p[j] == 'D')
			{
				// 에러뜨는 경우
				if (AC.size() == 0)
				{
					check = false;
					break;
				}
				// 안뒤집은경우
				if (_reverse)
				{
					AC.pop_front();
				}
				// 뒤집은 경우
				else AC.pop_back();
			}
		}

		// 마지막 출력
		if (check)
		{
			cout << "[";
			if (AC.size() == 0)
			{
				cout << "]" << "\n";
			}
			// 뒤집혀 있지 않음
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