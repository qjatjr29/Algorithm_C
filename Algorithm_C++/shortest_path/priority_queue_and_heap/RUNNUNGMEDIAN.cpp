#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int a, b;
const int _div = 20090711;
vector<long long> store;
long long sum;
void _sum(vector<long long>& store);
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> N >> a >> b;
		sum = 0;
		store.clear();
		store = vector<long long>(N);
		store[0] = 1983;
		for (int i = 1; i < N; i++)
		{
			long long inputnumber = (store[i - 1] * a + b) % _div;
			store[i] = inputnumber;
		}

		_sum(store);
		cout << sum << "\n";
	}

	return 0;
}

void _sum(vector<long long>& store)
{
	priority_queue<long long> maxheap;
	priority_queue<long long> minheap;
	for (int i = 0; i < store.size(); i++)
	{

		if (i % 2 == 0)
		{
			maxheap.push(store[i]);
		}
		else minheap.push(-store[i]);

		if (!maxheap.empty() && !minheap.empty() && maxheap.top() > (-minheap.top()))
		{
			long long maxtemp = maxheap.top();
			long long mintemp = -minheap.top();
			maxheap.pop();
			minheap.pop();
			maxheap.push(mintemp);
			minheap.push(-maxtemp);
		}
		sum = (sum + maxheap.top()) % _div;
	}

}


