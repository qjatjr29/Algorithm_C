#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long V, A, B;
//void snail(long long& day,long long height);
int main()
{
	cin >> A >> B >> V;
	long long int count;
	if (A >= V)cout << 1 << "\n";
	else
	{
		count = (V - A) / (A - B) + 1;
		if ((V - A) % (A - B) != 0)count++;
		cout << count << "\n";
	}


	//long long day = 1;
	//snail(day, A);
	//cout << day << "\n";
	return 0;
}

