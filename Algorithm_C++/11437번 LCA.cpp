//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N, M;
//// 부모노드 구할때 쓰는 bool형
//vector<bool> _check;
//// 연결된 두 정점
//vector<vector<int>> connect;
//// 각 노드의 부모노드 값 + 깊이 저장
//vector<vector<int>> parentnode;
//// 공통 조상을 알고 싶은 노드들.
//vector<pair<int, int>> findnode;
//// 공통 조상 저장.
//vector<pair<int, int>> _result;
//void findparent(int nodenum);
//void result(int number1, int number2, int& firstcount,int& secondcount);
//int main()
//{
//	cin >> N;
//	connect = vector<vector<int>>(N + 1, vector<int>());
//	_check = vector<bool>(N + 1, false);
//	parentnode = vector<vector<int>>(N + 1, vector<int>());
//
//	for (int i = 0; i < N - 1; i++)
//	{
//		int num1, num2;
//		cin >> num1 >> num2;
//		connect[num1].push_back(num2);
//		connect[num2].push_back(num1);
//	}
//	parentnode[1].push_back(1);
//	findparent(1);
//
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int num1, num2;
//		cin >> num1 >> num2;
//		findnode.push_back(make_pair(num1, num2));
//	}
//
//	parentnode[1].pop_back();
//	for (int i = 0; i < M; i++)
//	{
//		_result.clear();
//		int firstcount = 0;
//		int secondcount = 0;
//		int num1 = findnode[i].first;
//		int num2 = findnode[i].second;
//		result(num1, num2, firstcount,secondcount);
//	
//		int ans = 1;
//		int min = 20000;
//		for (int j = 0; j < _result.size(); j++)
//		{
//			if (min > _result[j].first)
//			{
//				min = _result[j].first;
//				ans = _result[j].second;
//			}
//		}
//		cout << ans << "\n";
//	}
//
//
//
//	return 0;
//}
//
//// 각 노드의 부모노드 값 저장.
//void findparent(int nodenum)
//{
//	if (_check[nodenum])return;
//	_check[nodenum] = true;
//	int _size = connect[nodenum].size();
//	for (int i = 0; i < _size; i++)
//	{
//
//		int temp = connect[nodenum][i];
//		if (parentnode[temp].size() == 0)
//		{
//			parentnode[temp].push_back(nodenum);
//			findparent(temp);
//		}
//	}
//
//}
//
//
//void result(int number1, int number2, int& firstcount,int& secondcount)
//{
//	// 기저 사례
//	if (parentnode[number1].size() == 0 || parentnode[number2].size() == 0) return;
//	// 둘 중 하나가 부모 노드일경우	
//	if (number1 == parentnode[number2][0])
//	{
//		int mincount = min(firstcount, secondcount);
//		_result.push_back(make_pair(mincount, number1));
//		return;
//	}
//	if (number2 == parentnode[number1][0])
//	{
//		int mincount = min(firstcount, secondcount);
//		_result.push_back(make_pair(mincount, number2));
//		return;
//	}
//	// 부모노드가 같을 경우
//	if (parentnode[number1][0] == parentnode[number2][0])
//	{
//		int mincount = min(firstcount, secondcount);
//		_result.push_back(make_pair(mincount, parentnode[number1][0]));
//		return;
//	}
//	int _firstcount = firstcount + 1;
//	int _secondcount = secondcount + 1;
//	result(parentnode[number1][0], number2, _firstcount,secondcount);
//	result(number1, parentnode[number2][0], firstcount,_secondcount);
//
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
// 부모노드 구할때 쓰는 bool형
vector<bool> _check;
// 연결된 두 정점
vector<vector<int>> connect;
// 각 노드의 부모노드 값 + 깊이 저장
vector<vector<int>> parentnode;
void findparent(int nodenum, int& depth);
int main()
{
	cin >> N;
	connect = vector<vector<int>>(N + 1, vector<int>());
	_check = vector<bool>(N + 1, false);
	parentnode = vector<vector<int>>(N + 1, vector<int>());

	for (int i = 0; i < N - 1; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		connect[num1].push_back(num2);
		connect[num2].push_back(num1);
	}
	parentnode[1].push_back(1);
	parentnode[1].push_back(1);
	int depth = 1;
	findparent(1, depth);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num1, num2;
		int ans = 1;
		int _min = 20000;
		cin >> num1 >> num2;
		int depthgap;
		int temp;

		if (parentnode[num1][1] > parentnode[num2][1])
		{
			depthgap = parentnode[num1][1] - parentnode[num2][1];
			temp = num1;
			for (int j = 0; j < depthgap; j++)
			{
				temp = parentnode[temp][0];
			}
			num1 = temp;
		}

		if (parentnode[num2][1] > parentnode[num1][1])
		{
			depthgap = parentnode[num2][1] - parentnode[num1][1];
			temp = num2;
			for (int j = 0; j < depthgap; j++)
			{
				temp = parentnode[temp][0];
			}
			num2 = temp;
		}

		int depth = parentnode[num1][1];
		if (num1 == num2)
		{
			ans = num1;

		}
		else
		{
			for (int j = 0; j < depth; j++)
			{
				if (parentnode[num1][0] == parentnode[num2][0])
				{
					ans = parentnode[num1][0];
					break;
				}
				num1 = parentnode[num1][0];
				num2 = parentnode[num2][0];
			}
		}
		cout << ans << "\n";
	}

	return 0;
}

// 각 노드의 부모노드 값 저장.
void findparent(int nodenum, int& depth)
{
	// 노드 확인 한 곳이면 리턴.
	if (_check[nodenum])
	{
		depth--;
		return;
	}
	_check[nodenum] = true;
	int _size = connect[nodenum].size();
	if (_size == 0)
	{
		depth--; return;
	}
	for (int i = 0; i < _size; i++)
	{
		int temp = connect[nodenum][i];
		if (parentnode[temp].size() == 0)
		{
			depth = parentnode[nodenum][1];
			parentnode[temp].push_back(nodenum);
			parentnode[temp].push_back(depth + 1);
			findparent(temp, depth);
		}
	}

}

