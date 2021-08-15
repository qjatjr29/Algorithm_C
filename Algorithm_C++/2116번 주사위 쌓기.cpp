#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> dice;
int under;
int result;
vector<int> settedDice;
void setDice(int index);
void calcDice();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	dice = vector<vector<int>>(N + 1, vector<int>(6, 0));


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int number;
			cin >> number;
			dice[i][j] = number;
		}
	}
	for (int i = 0; i < N; i++)
	{
		//settedDice = vector<vector<int>>(N + 1, vector<int>());
		settedDice = vector<int>();
		under = dice[0][i];
		setDice(0);
		/*	for (int j = 0; j < N; j++)
			{
				for (int z = 0; z < settedDice[j].size(); z++)
				{
					cout << settedDice[j][z] << " ";
				}
				cout << "\n";
			}*/
		calcDice();
	}

	cout << result << "\n";
	return 0;
}

void setDice(int index)
{
	if (index == N)return;
	int upIndex = 0;
	int underIndex = 0;
	for (int i = 0; i < 6; i++)
	{
		if (under == dice[index][i])
		{
			underIndex = i;
			break;
		}
	}

	int temp = -1;
	switch (underIndex)
	{
	case 0:
		upIndex = 5;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	case 1:
		upIndex = 3;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	case 2:
		upIndex = 4;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	case 3:
		upIndex = 1;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	case 4:
		upIndex = 2;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	case 5:
		upIndex = 0;
		under = dice[index][upIndex];
		for (int i = 0; i < 6; i++)
		{
			if (i == underIndex || i == upIndex)continue;
			temp = max(temp, dice[index][i]);
			//settedDice[index].push_back(dice[index][i]);
		}
		break;
	default:
		break;
	}
	settedDice.push_back(temp);
	setDice(index + 1);


}

void calcDice()
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		//sort(settedDice[i].begin(), settedDice[i].end());
		//temp += settedDice[i][3];
		temp += settedDice[i];
	}
	result = max(result, temp);
}
