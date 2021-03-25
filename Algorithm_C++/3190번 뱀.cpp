#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int N, K, L;

// ��� ��ġ
deque<pair<int, int>> board;
//����
vector<pair<int, char>> change;
// ���� ��ġ�� �ڸ�.
deque<pair<int, int>> _snake;
// ���� �̵� ���� 0 : ���� 1: ���� 2: ���� 3: ����.
int _move = 0;
// ���� �̵��� �ð�.(��)
int _sec = 1;
void snake(int& curx, int& cury);
int main()
{
	cin >> N >> K;
	int count = 0;


	// ��� ��ġ 
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		// ����� ��ġ
		board.push_back(make_pair(row - 1, col - 1));
	}

	// ���� ���� ��ȯ ���� 
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int sec;
		char direction;
		cin >> sec >> direction;
		change.push_back(make_pair(sec, direction));
	}
	// ���� �̵��ϱ� ����. ó�� ������ ������.
	_snake.push_back(make_pair(0, 0));
	int curx = 1;
	int cury = 0;
	bool check = false;
	while (1)
	{
		bool _break = true;
		// ���� �ִ°����� Ȯ��.
		for (int i = 0; i < _snake.size(); i++)
		{
			if (curx == _snake[i].second && cury == _snake[i].first)
			{
				_break = false;
				break;
			}
		}
		// ���� �ִ°��� ���Ÿ�.
		if (!_break)break;

		if (curx >= N || curx < 0 || cury < 0 || cury >= N)break;

		// ��� �ִ� ������ Ȯ�� 
		check = false;
		int _size = board.size();
		for (int i = 0; i < _size; i++)
		{
			int temp1, temp2;
			if (board.size() == 0)break;
			temp1 = board[0].first;
			temp2 = board[0].second;

			//��� �ִ°��� ����-> ��� �����.
			if (cury == temp1 && curx == temp2)
			{
				board.pop_front();
				check = true;
				break;
			}

			else
			{
				board.pop_front();
				board.push_back(make_pair(temp1, temp2));
			}
		}
		// ��� �ִ°� �Ȱ�.
		if (!check)
		{
			_snake.pop_front();
			_snake.push_back(make_pair(cury, curx));
		}
		// ��� �ִ� �� ��.
		else
			_snake.push_back(make_pair(cury, curx));


		// ���� ��ȯ
		if (count < L)
		{
			if (_sec == change[count].first)
			{
				if (change[count].second == 'L')
				{
					_move = (_move - 1 + 4) % 4;
				}
				else _move = (_move + 1 + 4) % 4;
				count++;
			}
		}
		// �� ������
		snake(curx, cury);
		_sec++;

	}
	cout << _sec << "\n";
	return 0;
}

void snake(int& curx, int& cury)
{

	// ����
	if (_move == 0)
	{
		curx++;
	}
	// ����
	else if (_move == 1)
	{
		cury++;
	}
	// ����
	else if (_move == 2)
	{
		curx--;
	}
	// ����
	else if (_move == 3)
	{
		cury--;
	}
}
