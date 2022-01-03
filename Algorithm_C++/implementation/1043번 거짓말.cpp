#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int parent[51];
int result;
int findParent(int index);
void Union(int x, int y);
vector<int> people;
vector<vector<int>> section(50);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	int truth;
	cin >> truth;
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < truth; i++)
	{
		int num;
		cin >> num;
		people.push_back(num);
	}
	for (int i = 0; i < M; i++)
	{
		int count;
		cin >> count;
		int number;
		int preNum;
		for (int j = 0; j < count; j++)
		{
			if (j >= 1)
			{
				preNum = number;
				cin >> number;
				Union(preNum, number);
			}
			else cin >> number;
			section[i].push_back(number);
		}
	}
	for (int i = 0; i < M; i++)
	{
		bool chk = false;
		for (int j = 0; j < section[i].size(); j++)
		{
			if (chk == true)break;
			int chkNumber = section[i][j];
			for (int z = 0; z < people.size(); z++)
			{
				chkNumber = findParent(chkNumber);
				int cmpNumber = findParent(people[z]);
				if (chkNumber == cmpNumber)
				{
					chk = true;
					break;
				}
			}
		}
		if (chk == false) result++;
	}
	cout << result << "\n";
	return 0;
}
int findParent(int index)
{
	if (parent[index] == index)return index;
	return index=findParent(parent[index]);
}
void Union(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	parent[x] = y;
}