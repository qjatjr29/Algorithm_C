#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> sensor;
vector<int> dist;
int result;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> K;
	if (K >= N)
	{
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;

		sensor.push_back(number);

	}
	//int sensorSize = sensor.size();
	sort(sensor.begin(), sensor.end());

	for (int i = 1; i < sensor.size(); i++)
	{
		int distance = sensor[i] - sensor[i - 1];
		dist.push_back(distance);
	}
	//int distSize = dist.size();
	sort(dist.begin(), dist.end());


	for (int i = 0; i < dist.size() - (K - 1); i++)
	{
		result += dist[i];
	}
	cout << result << "\n";
	return 0;
}