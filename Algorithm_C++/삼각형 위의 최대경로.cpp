#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> triangle[101];
vector<int> path[101];
void clear(vector<int> triangle[], vector<int> path[]);
void settriangle(vector<int> triangle[]);
void maxsum(vector<int> triangle[], vector<int> path[], int curindex);
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		clear(triangle, path);
		settriangle(triangle);
		path[0].push_back(triangle[0][0]);
		path[1].push_back(triangle[0][0] + triangle[1][0]);
		path[1].push_back(triangle[0][0] + triangle[1][1]);
		maxsum(triangle, path, 2);
	}


	return 0;
}
// 초기화.
void clear(vector<int> triangle[], vector<int> path[])
{
	for (int i = 0; i < 101; i++)
	{
		triangle[i].clear();
		path[i].clear();
	}
}
// 처음 값 넣어주기.
void settriangle(vector<int> triangle[])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int number;
			cin >> number;
			triangle[i].push_back(number);
		}
	}
}

void maxsum(vector<int> triangle[], vector<int> path[], int curindex)
{
	// 마지막 까지 다 왔을 경우.
	if (curindex == n)
	{
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (max < path[n - 1][i])max = path[n - 1][i];
		}
		cout << max << "\n";
		return;
	}
	// 첫번째 경로값은 무조건 바로 위에서만 올수 있음.
	path[curindex].push_back(path[curindex - 1][0] + triangle[curindex][0]);
	// 두번째에서 n-1 번까지는 바로 위 혹은 왼쪽 위에서 오는 값 최대값 비교하여.
	for (int i = 1; i < curindex; i++)
	{
		int _max = max(path[curindex - 1][i - 1], path[curindex - 1][i]);
		path[curindex].push_back(_max + triangle[curindex][i]);
	}
	// 마지막 경로는 무조건 왼쪽 위에서만 올수 있음.
	path[curindex].push_back(path[curindex - 1][curindex - 1] + triangle[curindex][curindex]);
	curindex++;
	maxsum(triangle, path, curindex);

}
