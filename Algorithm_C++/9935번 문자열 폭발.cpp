#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

string Word;
string bomb;
int bombSize;
vector<char> store;
char result[1000001];
bool checkAlpha(int curindex);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> Word >> bomb;
	/*for (int i = 0; i < firstWord.size(); i++)
	{
		store.push_back(firstWord[i]);
	}*/
	// 기저 사례는 남은 문자열이 없는경우
	// 더이상 bomb string이 없는 경우
	// 반복문 돌자.
	bombSize = bomb.size();

	int Curindex = 0;
	for (int i = 0; i < Word.size(); i++)
	{
		//Curindex++;
		result[Curindex++] = Word[i];

		int tempBombSize = bomb.size();
		if (Word[i] == bomb[--tempBombSize])
		{
			bool checkBomb = false;
			for (int j = Curindex - 1; j >= Curindex - bombSize; j--)
			{
				if (result[j] != bomb[tempBombSize--])
				{
					// 삭제 할것 없음.
					checkBomb = true;
					break;
				}
			}
			// 삭제할 것 존재.
			if (!checkBomb)
			{
				Curindex -= bombSize;
			}
		}

	}
	if (Curindex == 0)cout << "FRULA" << "\n";
	else
	{
		for (int i = 0; i < Curindex; i++)
		{
			cout << result[i] << "";
		}
		cout << "\n";
	}



	//while (1)
	//{
	//	int vectorSize = store.size();
	//	if (vectorSize == 0)
	//	{
	//		cout << "FRULA" << "\n";
	//		return 0;
	//	}
	//	bool checkBomb = false;
	//	int bombIndex;
	//	for (int i = 0; i < vectorSize; i++)
	//	{
	//		// bomb string 의 첫 인덱스값과 같은 경우 함수 들어간다.
	//		if (store[i] == bomb[bomb.size()-1])
	//		{
	//			// 만약 bomb string 찾으면  true가 되어있다.
	//			bombIndex = i;
	//			checkBomb=checkAlpha(i);
	//		}
	//		if (checkBomb)break;
	//	}
	//	// 잘라야함.
	//	if (checkBomb)
	//	{
	//		store.erase(store.begin() + bombIndex, store.begin() + bombIndex + bombSize);
	//	}
	//	// 자를것이 없음.
	//	else
	//	{
	//		for (int i = 0; i < store.size(); i++)
	//		{
	//			cout << store[i] << "";
	//		}
	//		cout << "\n";
	//		return 0;
	//	}

	//}



	return 0;
}

//bool checkAlpha(int curindex)
//{
//	int bombIndex = 1;
//	for (int i = curindex-1; i>=curindex-bombSize; i--)
//	{	
//		if (i >= store.size()) return false;
//		if (store[i] != bomb[bombIndex])
//		{
//			return false;
//		}
//		bombIndex++;
//	}
//	return false;
//}
