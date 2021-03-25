#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<int> soobin;
void young(vector<int>& soobin);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		soobin.push_back(number);
	}
	young(soobin);


	return 0;
}

void young(vector<int>& soobin)
{
	priority_queue<int> maxheap;
	priority_queue<int> minheap;

	for (int i = 0; i < soobin.size(); i++)
	{
		if (i % 2 == 0)
		{
			maxheap.push(soobin[i]);
		}
		else minheap.push(-soobin[i]);
		if (!maxheap.empty() && !minheap.empty() && maxheap.top() > -minheap.top())
		{
			int maxtop = maxheap.top();
			int mintop = -minheap.top();
			maxheap.pop();
			minheap.pop();
			maxheap.push(mintop);
			minheap.push(-maxtop);
		}
		cout << maxheap.top() << "\n";
	}
}
