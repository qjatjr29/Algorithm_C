#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

string A, B;
bool chk = false;
void changeA(string temp);
void changeB();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> A >> B;

	//changeA(A);
	changeB();

	if (chk)cout << 1 << "\n";
	else cout << 0 << "\n";


	return 0;
}

void changeA(string temp)
{
	if (temp.size() > B.size())return;

	if (temp.size() == B.size())
	{
		if (temp == B)
		{
			chk = true;
		}
		return;
	}
	string sTemp = temp;

	// 첫번째 케이스
	//  문자열 B의 temp.size()+1 인덱스 값이 A 일 때 
	if (B[temp.size()] == 'A')
	{
		sTemp += "A";
		changeA(sTemp);
	}
	if (chk)return;
	// 두번째 케이스
	// 문자열 B의 temp.size()+1 인덱스 값이 B 일 때
	else
	{
		//sTemp = sTemp.substr(0, sTemp.size() - 1);
		reverse(sTemp.begin(), sTemp.end());
		sTemp += "B";
		changeA(sTemp);
	}



}

void changeB()
{
	while (1)
	{
		if (B.size() < A.size())break;
		if (A == B)
		{
			chk = true;
			break;
		}

		if (B[B.size() - 1] == 'A')
		{
			B = B.substr(0, B.size() - 1);
		}
		else
		{
			B = B.substr(0, B.size() - 1);
			reverse(B.begin(), B.end());
		}

	}

}
