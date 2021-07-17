//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int T, N;
//int Answer;
//vector<int> D;
//vector<vector<int>> adj;
//vector<bool> visited;
//void FindFriend(int startIndex);
//int main()
//{
//	cin.tie(NULL);
//	cin.sync_with_stdio(false);
//
//	cin >> T;
//	for (int test_case = 0; test_case < T; test_case++)
//	{
//
//		Answer = 0;
//		cin >> N;
//		D = vector<int>(N + 1, 0);
//		visited = vector<bool>(N + 1, false);
//		for (int i = 1; i <= N; i++)
//		{
//			int number;
//			cin >> number;
//			D[i] = number;
//		}
//
//		for (int i = 1; i <= N; i++)
//		{
//			if (visited[i] == false)
//			{
//				Answer++;
//				FindFriend(i);
//			}
//		}
//
//
//		
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//
//	return 0;
//}
//
//void FindFriend(int startIndex)
//{
//	queue<int> q;
//	visited[startIndex] = true;
//	q.push(startIndex);
//	while (1)
//	{
//		if (q.empty())break;
//		int curIndex = q.front();
//		q.pop();
//		
//		int friendNumber = curIndex + D[curIndex];
//		
//		if (friendNumber > 0 && friendNumber <= N )
//		{
//			if (visited[friendNumber] == true)
//			{
//				Answer--;
//			}
//			else
//			{
//				visited[friendNumber] = true;
//				q.push(friendNumber);
//			}
//		}	
//	}
//}




#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int Answer;
int N;
vector<int> D;
vector<vector<int>> adj;
vector<bool> visited;
void FindFriend(int startIndex);



int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		cin >> N;
		D = vector<int>(N + 1, 0);
		visited = vector<bool>(N + 1, false);
		for (int i = 1; i <= N; i++)
		{
			int number;
			cin >> number;
			D[i] = number;
		}

		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false)
			{
				Answer++;
				FindFriend(i);
			}
		}


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

void FindFriend(int startIndex)
{
	queue<int> q;
	visited[startIndex] = true;
	q.push(startIndex);
	while (1)
	{
		if (q.empty())break;
		int curIndex = q.front();
		q.pop();

		int friendNumber = curIndex + D[curIndex];

		if (friendNumber > 0 && friendNumber <= N)
		{
			if (visited[friendNumber] == true)
			{
				Answer--;
			}
			else
			{
				visited[friendNumber] = true;
				q.push(friendNumber);
			}
		}
	}
}
