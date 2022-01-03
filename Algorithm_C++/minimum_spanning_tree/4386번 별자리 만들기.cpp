#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

int n;
vector<pair<double, double>> star;
vector<int> parentNode;
vector<pair<double, pair<int, int>>> dist;
vector<bool> visited;
double result;
int getParent(int index);
double calcCost(double sx, double sy, double dx, double dy);
void constellation();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;
	parentNode = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		star.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double cDistance = calcCost(star[i].first, star[i].second, star[j].first, star[j].second);
			dist.push_back(make_pair(cDistance, make_pair(i, j)));
		}
	}
	sort(dist.begin(), dist.end());
	for (int i = 1; i <= n; i++)
	{
		parentNode[i] = i;
	}

	constellation();

	cout << setprecision(3) << result << "\n";

	return 0;
}

int getParent(int index)
{
	if (parentNode[index] == index)return index;
	return getParent(parentNode[index]);
}

double calcCost(double sx, double sy, double dx, double dy)
{
	double a = pow(sx - dx, 2);
	double b = pow(sy - dy, 2);
	return sqrt(a + b);
}

void constellation()
{
	for (int i = 0; i < dist.size(); i++)
	{
		int parent1 = getParent(dist[i].second.first);
		int parent2 = getParent(dist[i].second.second);
		if (parent1 == parent2) continue;
		result += dist[i].first;
		if (parent1 > parent2)
		{
			parentNode[parent1] = parent2;
		}
		else
		{
			parentNode[parent2] = parent1;
		}
	}

}
