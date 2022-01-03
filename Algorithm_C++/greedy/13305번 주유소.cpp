#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N;
vector<int> oil;
vector<int> road;
long long  result;

void oilCost(int curindex);
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	oil = vector<int>(N + 1, 0);
	road = vector<int>(N + 1, 0);

	for (int i = 1; i < N; i++)
	{
		// road[i] ==> i에서 i+1로 가는 도로의 길이.
		int roadNum;
		cin >> roadNum;
		road[i] = roadNum;
	}
	for (int i = 1; i <= N; i++)
	{
		// oil[i] ==> i번째 도시에서의 1L당 기름 가격
		int oilNum;
		cin >> oilNum;
		oil[i] = oilNum;
	}
	oilCost(1);

	cout << result << "\n";
	return 0;
}

void oilCost(int curindex)
{
	//기저 사례
	if (curindex == N)return;

	// 현재 위치의 1L당 가격
	long long curindexCost = oil[curindex];

	// 현재 위치에서 이동할 거리
	int move = 0;

	// 얼마나 많은 도시를 이동했는지 확인하는 변수
	int count = 0;

	// 현재 위치에서 부터 주유소의 가격이 지금 보다 낮을 때 까지 이동
	// 무조건 한칸은 움직여야 하니 i =curindex 부터 시작
	for (int i = curindex; i < N; i++)
	{
		long long temp = 0;
		// 주유소 가격이 지금보다 낮을 때 여기로 넘어간다.
		if (curindexCost > oil[i])
		{
			break;
		}
		count++;  // 한칸씩 움직일 때마다 ++
		move += road[i];	 // 한칸 움직일 때 이동 거리 + 해주기
	}

	result += curindexCost * move;

	//check[curindex] = curMinCost;
	oilCost(curindex + count);
	return;
}
