


/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;


int Answer;
int n, t;
string b;
vector<char> temp;

void FindZero();
void FindOne();

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

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		cin >> n >> t;
		cin >> b;
		temp = vector<char>(n + 1, '2');


		FindZero();

		FindOne();

		for (int i = 0; i < n; i++)
		{
			if (temp[i] == '2') temp[i] = '0';
		}
		string result = "";
		for (int i = 0; i < n; i++)
		{
			result += temp[i];
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << result << "\n";
		//cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

void FindZero()
{
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '0')
		{
			if (i - t >= 0) temp[i - t] = '0';
			if (i + t < n)temp[i + t] = '0';
		}
	}
}

void FindOne()
{
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == '1')
		{
			// �̹� �����̳� ������ ��쿡 1�� �ִ� ���
			if (i - t >= 0 && i + t < n && (temp[i - t] == '1' || temp[i + t] == '1')) continue;

			// �Ѵ� ������ �ְ� �Ѵ� ��� ���� �� ������ ä��
			else if (i - t >= 0 && i + t < n && (temp[i - t] == '2' && temp[i + t] == '2'))
			{
				temp[i + t] = '1';
			}

			// ���� ���� ���̰ų� �̹� 0 �� �ִ� ���
			else if (i - t < 0 || temp[i - t] == '0')
			{
				// �������� ���� �ȿ� �ִ� ���
				if (i + t < n)
				{
					temp[i + t] = '1';
				}
			}

			// ������ -1 �� ��� �ְ� �������� ���� �Ѿ�ų� �̹� 0�ΰ��
			else if (i + t >= n || temp[i + t] == '0')
			{
				if (i - t >= 0)
				{
					temp[i - t] = '1';
				}
			}

		}
	}
}



