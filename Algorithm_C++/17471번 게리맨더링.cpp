#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
// 각 구역 인구수
vector<int> people;
// 연결되어 있는지
vector<vector<bool>> adj;
// 방문 한 곳인지
vector<bool> visited;
//같은 선거구인지? --> 참 거짓으로 두 선거구 표현
vector<bool> district;
// 연결되어 있는지 확인 하는 함수
bool checkConnect(vector<int> checkVector, bool checkbool);
//  조건만족하는지 확인 하는 함수
bool checkCan();
// 선거구 조합 구하기
void election(int start, int count);
void calcMinGap();
int result = 987654321;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	people = vector<int>(N + 1, 0);
	adj = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	visited = vector<bool>(N + 1, false);
	district = vector<bool>(N + 1, false);

	for (int i = 1; i <= N; i++)
	{
		int number;
		cin >> number;
		people[i] = number;
	}

	for (int i = 1; i <= N; i++)
	{
		int adjCount;
		cin >> adjCount;
		for (int j = 0; j < adjCount; j++)
		{
			int adjCity;
			cin >> adjCity;
			adj[i][adjCity] = true;
			adj[adjCity][i] = true;
		}
	}
	election(1, 0);
	if (result == 987654321)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << result << "\n";
	}

	return 0;
}

bool checkConnect(vector<int> checkVector, bool checkbool)
{
	visited = vector<bool>(N + 1, false);
	queue<int> checkQ;
	int firstIndex = checkVector.front();
	checkQ.push(firstIndex);
	visited[firstIndex] = true;
	int connectCount = 1;
	while (1)
	{
		if (checkQ.empty())break;
		int curIndex = checkQ.front();
		checkQ.pop();
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false && adj[curIndex][i] == true && district[i] == checkbool)
			{
				visited[i] = true;
				checkQ.push(i);
				connectCount++;
			}
		}
	}
	if (checkVector.size() == connectCount)return true;
	else return false;
}

bool checkCan()
{
	vector<int> A_district;
	vector<int> B_district;

	for (int i = 1; i <= N; i++)
	{
		if (district[i] == true)
		{
			A_district.push_back(i);
		}
		else
		{
			B_district.push_back(i);
		}
	}

	// 각 선거구에 하나 이상
	if (A_district.size() == 0 || B_district.size() == 0)return false;

	// 각 선거구가 연결되어 있는지 확인
	if (!checkConnect(A_district, true))
	{
		return false;
	}
	if (!checkConnect(B_district, false))
	{
		return false;
	}
	return true;
}

void election(int start, int count)
{
	// 선거구 에 구역이 하나라도 더 들어가 있는 경우
	if (count >= 1)
	{
		// 조건 만족
		if (checkCan())
		{
			// 계산
			calcMinGap();
		}
	}
	for (int i = start; i <= N; i++)
	{
		// 이미 선거구 에 포함된 경우
		if (district[i]) continue;
		// 일단 선거구에 넣어 놓고 연결되어 있는지 확인하는 작업 --> checkConnect
		district[i] = true;
		election(i, count + 1);
		district[i] = false;
	}
}

void calcMinGap()
{
	int firstDistrict = 0;
	int secondDistrict = 0;
	for (int i = 1; i <= N; i++)
	{
		if (district[i] == true)
		{
			firstDistrict += people[i];
		}
		else secondDistrict += people[i];
	}
	int gap = abs(firstDistrict - secondDistrict);
	result = min(gap, result);
}
