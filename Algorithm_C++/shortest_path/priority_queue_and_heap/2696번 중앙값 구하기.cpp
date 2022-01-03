#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M;
vector<int> store;
void medium(vector<int>& store);
vector<int> result;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M;
		store.clear();
		result.clear();
		for (int j = 0; j < M; j++)
		{
			int number;
			cin >> number;
			store.push_back(number);
		}
		medium(store);
		int count = 0;
		cout << result.size() << "\n";
		for (int z = 0; z < result.size(); z++)
		{
			if (count == 10)
			{
				count = 0;
				cout << "\n";
			}
			cout << result[z] << " ";
			count++;
		}
		cout << "\n";
	}

	return 0;
}

void medium(vector<int>& store)
{
	priority_queue<int> maxheap;
	priority_queue<int> minheap;
	for (int i = 0; i < store.size(); i++)
	{
		if (i % 2 == 0)
		{
			maxheap.push(store[i]);
		}
		else
		{
			minheap.push(-store[i]);
		}

		if (!minheap.empty() && !maxheap.empty() && maxheap.top() > (-minheap.top()))
		{
			int maxtop = maxheap.top();
			int mintop = -minheap.top();
			maxheap.pop();
			minheap.pop();
			maxheap.push(mintop);
			minheap.push(-maxtop);
		}
		if (i % 2 == 0)
		{
			result.push_back(maxheap.top());
			//cout << maxheap.top() << "\n";
		}
	}
}
