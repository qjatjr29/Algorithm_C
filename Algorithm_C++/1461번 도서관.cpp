#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
vector<int> MinusCase;
vector<int> PlusCase;
int result;
void removeCase(vector<int>& Case);

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int bookPosition;
		cin >> bookPosition;
		if (bookPosition < 0)
		{
			MinusCase.push_back(-bookPosition);
		}
		else
		{
			PlusCase.push_back(bookPosition);
		}

	}
	sort(MinusCase.begin(), MinusCase.end(), greater<int>());
	sort(PlusCase.begin(), PlusCase.end(), greater<int>());

	// 다 - 일때
	if (N == MinusCase.size())
	{
		int maxMinus = MinusCase[0];
		while (1)
		{
			if (MinusCase.size() == 0)break;
			removeCase(MinusCase);
		}
		result = result - maxMinus;
	}
	// 다 + 일때
	else if (N == PlusCase.size())
	{
		int maxPlus = PlusCase[0];
		while (1)
		{
			if (PlusCase.size() == 0)break;
			removeCase(PlusCase);
		}
		result = result - maxPlus;
	}

	else
	{
		int maxMinus = MinusCase[0];
		int maxPlus = PlusCase[0];
		if (maxMinus <= maxPlus)
		{
			removeCase(PlusCase);
			result = result - maxPlus;
		}
		else
		{
			removeCase(MinusCase);
			result = result - maxMinus;
		}
		while (1)
		{
			if (MinusCase.size() == 0)break;
			removeCase(MinusCase);
		}
		while (1)
		{
			if (PlusCase.size() == 0)break;
			removeCase(PlusCase);
		}
	}


	cout << result << "\n";

	return 0;
}

void removeCase(vector<int>& Case)
{
	if (Case.size() == 0)return;
	result += 2 * Case[0];
	if (Case.size() >= M)
	{
		Case.erase(Case.begin(), Case.begin() + M);
	}
	else
	{
		Case.clear();
	}
}


