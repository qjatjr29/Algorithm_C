#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, N;
vector<int> student;
vector<bool> checked;
vector<bool> visited;
int teamMate;
void findFriend(int start);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		cin >> N;
		teamMate = 0;
		student = vector<int>();
		student.push_back(0);
		checked = vector<bool>(N + 1, false);
		visited = vector<bool>(N + 1, false);
		for (int i = 1; i <= N; i++)
		{
			int studentNum;
			cin >> studentNum;
			student.push_back(studentNum);
		}

		for (int i = 1; i <= N; i++)
		{
			if (checked[i] == false)
			{
				findFriend(i);
			}
		}

		cout << N - teamMate << "\n";
	}

	return 0;
}

void findFriend(int start)
{
	checked[start] = true;

	int next = student[start];
	if (checked[next] == false)
	{
		findFriend(next);
	}
	else if (visited[next] == false)
	{
		int number = next;
		while (1)
		{
			if (number == start)break;
			teamMate++;
			number = student[number];
		}
		teamMate++;
	}
	visited[start] = true;

	//queue<int> q;
	//queue<int> temp;
	//vector<bool> visited;
	//visited = vector<bool>(N + 1, false);


	//bool checkCycle = false;

	//int next = student[start];

	//if (start == next)
	//{
	//	checked[start] = true;
	//	return;
	//}

	//q.push(next);
	//temp.push(next);
	//visited[next] = true;
	//while (1)
	//{
	//	if (q.empty())break;

	//	int curIndex = q.front();
	//	q.pop();
	//	// 프로젝트에 속할 수 있는 경우.
	//	if (curIndex == start)
	//	{
	//		checkCycle = true;
	//		break;
	//	}

	//	int nextIndex = student[curIndex];
	//	if (visited[nextIndex] == false && checked[nextIndex]==false && failed[nextIndex]==false)
	//	{
	//		visited[nextIndex] = true;
	//		q.push(nextIndex);
	//		temp.push(nextIndex);
	//	}
	//}
	//if (checkCycle)
	//{
	//	while (1)
	//	{
	//		if (temp.empty())break;
	//		int chkIndex = temp.front();
	//		temp.pop();
	//		checked[chkIndex] = true;
	//	}
	//}
	//else
	//{
	//	failed[start] = true;
	//	alone++;
	//}

}
