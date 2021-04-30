#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N;
vector<string> map;
//vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> result;
bool chk = false;
int housecount = 0;
void house(int curX, int curY);
int main()
{
	cin >> N;
	//map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	map = vector<string>(N + 1, "");
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < N; i++)
	{
		/*for (int j = 0; j < N; i++)
		{
			int number;
			cin >> number;
			map[i][j] = number;
		}*/
		string number;
		cin >> number;
		map[i] = number;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == '1' && visited[i][j] == false)
			{
				housecount = 0;
				house(i, j);
				result.push_back(housecount);
			}
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}


	return 0;
}

void house(int curX, int curY)
{
	if (curX < 0 || curY < 0 || curX >= N || curY >= N)return;
	if (visited[curX][curY])return;
	visited[curX][curY] = true;
	if (map[curX][curY] == '1')
	{
		housecount++;
		house(curX - 1, curY);
		house(curX, curY - 1);
		house(curX + 1, curY);
		house(curX, curY + 1);
	}
	else return;
}
