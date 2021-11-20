#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;


vector<string> cakes;
vector<int> cut_rows;
vector<int> cut_columns;
int solution(vector<string> cakes, vector<int> cut_rows, vector<int> cut_columns);

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cakes.push_back("AAAACX");
	cakes.push_back("AAAACX");
	cakes.push_back("AAAACX");
	cakes.push_back("ZZZZZX");
	cakes.push_back("ATTTTX");
	cakes.push_back("XUUUUU");
	cut_rows.push_back(1);
	cut_rows.push_back(2);
	cut_rows.push_back(4);
	cut_columns.push_back(2);
	cut_columns.push_back(3);
	int ans = solution(cakes, cut_rows, cut_columns);
	cout << ans << "\n";
	return 0;
}
int solution(vector<string> cakes, vector<int> cut_rows, vector<int> cut_columns) {
	int answer = 0;
	vector<int> alpha;
	alpha = vector<int>(26, 0);
	int preRowNumber = 0;
	
	for (int i = 0; i < cut_rows.size()+1; i++)
	{	
		int rowNumber;
		if (i == cut_rows.size())
		{
			rowNumber = cakes.size();
		}
		else rowNumber = cut_rows[i];
		int preColumnNumber = 0;
		for (int j = 0; j < cut_columns.size()+1; j++)
		{
			int columnNumber;
			int count = 0;
		
			if (j == cut_columns.size())
			{
				columnNumber = cakes.size();
			}
			else columnNumber = cut_columns[j];
			alpha = vector<int>(26, 0);

			for (int z = preRowNumber; z < rowNumber; z++)
			{
				for (int y = preColumnNumber; y < columnNumber; y++)
				{
					int alp = cakes[z][y] - '0' - 17;
					if (alpha[alp] == 0)
					{
						count++;
						alpha[alp] = 1;
					}
				}
			}
			preColumnNumber = columnNumber;
			answer = max(answer, count);
		}
		preRowNumber = rowNumber;
	}

	return answer;
}