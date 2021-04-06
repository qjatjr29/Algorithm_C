#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
//vector<string> word;
int alpha[26];
int result;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string inputWord;
		cin >> inputWord;
		//word.push_back(inputWord);
		for (int j = 0; j < inputWord.size(); j++)
		{
			alpha[inputWord[j] - 65] += pow(10, inputWord.size() - 1 - j);
		}
	}
	// 대문자 아스키 코드 65-90
	sort(alpha, alpha + 26);
	int MAXnum = 9;
	for (int i = 25; i > 15; i--)
	{
		result += MAXnum * alpha[i];
		MAXnum--;
	}

	cout << result << "\n";

	return 0;
}






//bool compare(string a, string b)
//{
//	return a.size() < b.size();
//}


//sort(word.begin(), word.end(), compare);
//int wordCount = 1;
//int curindex = 0;
//int MAXnum = 9;
//for (int i = N - 1; i >= 0; i--)
//{
//	int num = 0;
//	for (int j = 0; j < word[i].size(); j++)
//	{
//		if (alpha[word[i][j]] == 0)
//		{
//			alpha[word[i][j]] = MAXnum;
//			num += (MAXnum * pow(10, word[i].size() - 1 - j));
//			MAXnum--;
//		}
//		else
//		{
//			num += (alpha[word[i][j]] * pow(10, word[i].size() - 1 - j));
//		}
//	}
//	result += num;
//}
//cout << result << "\n";