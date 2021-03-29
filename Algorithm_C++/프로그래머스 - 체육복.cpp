#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n;
vector<int> lost;
vector<int> reserve;
int solution(int n, vector<int> lost, vector<int>reserve);
int main()
{
	cin >> n;
	//lost.push_back(1);
	lost.push_back(5);
	lost.push_back(7);
	lost.push_back(9);
	//lost.push_back(6);
	reserve.push_back(1);
	reserve.push_back(2);
	reserve.push_back(3);
	/*reserve.push_back(6);*/
	//reserve.push_back(5);
	reserve.push_back(4);
	reserve.push_back(6);
	reserve.push_back(8);



	cout << solution(n, lost, reserve) << "\n";

	return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	int lost_size = lost.size();
	int reserve_size = reserve.size();
	vector<int> temp = lost;
	for (int i = 0; i < lost.size(); i++)
	{
		// 도난 당한 학생의 번호.
		int peopleNumber = lost[i];
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == peopleNumber)
			{
				reserve.erase(reserve.begin() + j);
				lost.erase(lost.begin() + i);
				i--;
				break;
			}
		}
	}
	lost_size = lost.size();
	for (int i = 0; i < lost.size(); i++)
	{
		// 도난 당한 학생의 번호.
		int peopleNumber = lost[i];
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == peopleNumber - 1 || reserve[j] == peopleNumber + 1)
			{
				lost_size--;
				reserve.erase(reserve.begin() + j);
				break;
			}
		}
	}
	answer = n - lost_size;



	return answer;
}
