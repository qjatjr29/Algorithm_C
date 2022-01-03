#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> people;
queue<int> checkTime;
int secTime;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	people = vector<int>(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		int canEat;
		cin >> canEat;
		people[i + 1] = canEat;
		checkTime.push(i + 1);
	}

	while (1)
	{
		if (checkTime.empty())break;

		int curIndex = checkTime.front();
		checkTime.pop();
		people[curIndex]--;
		secTime++;
		if (people[curIndex] == 0)
		{
			people[curIndex] = secTime;
		}
		else
		{
			checkTime.push(curIndex);
		}

	}

	for (int i = 1; i < N; i++)
	{
		cout << people[i] << " ";
	}
	cout << people[N] << "\n";



	return 0;
}