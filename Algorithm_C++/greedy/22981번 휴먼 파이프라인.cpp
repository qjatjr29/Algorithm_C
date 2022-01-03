#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int N;
long long K;
vector<long long> people;
long long result = 1000000000000000000;
void box();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		long long a;
		cin >> a;
		people.push_back(a);
	}
	sort(people.begin(), people.end());
	box();
	cout << result << "\n";
	return 0;
}

void box()
{

	for (int i = 1; i < N; i++)
	{
		long long v1 = people[0] * i;
		long long  v2 = people[i] * (N - i);

		long long temp = K / (v1 + v2);
		if (K % (v1 + v2) > 0)
		{
			temp++;
		}

		result = min(result, temp);
	}
}
