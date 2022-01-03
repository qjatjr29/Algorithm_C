#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector<vector<int>> S;
vector<int> arr;
vector<int> comb;
int gap = 987654321;
vector<vector<int>> CombS;
int combCount = 0;
void combinationS(int r, int index, int depth);
void calcGap();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	S = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	arr = vector<int>(N, 0);
	comb = vector<int>(N / 2);
	for (int i = 1; i <= N; i++)
	{
		arr[i - 1] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int number;
			cin >> number;
			S[i][j] = number;
		}
	}

	combinationS(N / 2, 0, 0);
	calcGap();
	cout << gap << "\n";
	return 0;
}

void combinationS(int r, int index, int depth)
{

	if (r == 0)
	{
		vector<int> temp;
		for (int i = 0; i < comb.size(); i++)
		{
			//cout << comb[i] << " ";
			temp.push_back(comb[i]);
		}
		CombS.push_back(temp);
		//cout << endl;
	}
	else if (depth == arr.size())return;
	else
	{
		comb[index] = arr[depth];
		combinationS(r - 1, index + 1, depth + 1);
		combinationS(r, index, depth + 1);
	}

}

void calcGap()
{
	for (int i = 1; i <= CombS.size(); i++)
	{
		int startTeam = 0;
		bool checkIndex[21] = { false, };
		for (int j = 0; j < CombS[i - 1].size(); j++)
		{
			checkIndex[CombS[i - 1][j]] = true;
			for (int z = 0; z < CombS[i - 1].size(); z++)
			{
				if (j == z)continue;
				else
				{
					startTeam += S[CombS[i - 1][j]][CombS[i - 1][z]];
				}
			}
		}
		vector<int> link;
		for (int j = 1; j <= N; j++)
		{
			if (checkIndex[j] == false)
			{
				link.push_back(j);
			}
		}

		int linkTeam = 0;
		for (int j = 0; j < link.size(); j++)
		{
			for (int z = 0; z < link.size(); z++)
			{

				if (j == z)continue;
				else
				{
					linkTeam += S[link[j]][link[z]];
				}
			}
		}
		/*	cout << "start-link : " << startTeam << " " << linkTeam << "\n";*/
		int _gap = abs(linkTeam - startTeam);
		gap = min(gap, _gap);
	}
}
