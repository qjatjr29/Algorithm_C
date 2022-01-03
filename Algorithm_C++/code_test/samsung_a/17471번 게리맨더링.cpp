#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
// �� ���� �α���
vector<int> people;
// ����Ǿ� �ִ���
vector<vector<bool>> adj;
// �湮 �� ������
vector<bool> visited;
//���� ���ű�����? --> �� �������� �� ���ű� ǥ��
vector<bool> district;
// ����Ǿ� �ִ��� Ȯ�� �ϴ� �Լ�
bool checkConnect(vector<int> checkVector, bool checkbool);
//  ���Ǹ����ϴ��� Ȯ�� �ϴ� �Լ�
bool checkCan();
// ���ű� ���� ���ϱ�
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

	// �� ���ű��� �ϳ� �̻�
	if (A_district.size() == 0 || B_district.size() == 0)return false;

	// �� ���ű��� ����Ǿ� �ִ��� Ȯ��
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
	// ���ű� �� ������ �ϳ��� �� �� �ִ� ���
	if (count >= 1)
	{
		// ���� ����
		if (checkCan())
		{
			// ���
			calcMinGap();
		}
	}
	for (int i = start; i <= N; i++)
	{
		// �̹� ���ű� �� ���Ե� ���
		if (district[i]) continue;
		// �ϴ� ���ű��� �־� ���� ����Ǿ� �ִ��� Ȯ���ϴ� �۾� --> checkConnect
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
