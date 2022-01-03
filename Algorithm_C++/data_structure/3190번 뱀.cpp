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

// 사과 위치
deque<pair<int, int>> board;
//방향
vector<pair<int, char>> change;
// 뱀이 위치한 자리.
deque<pair<int, int>> _snake;
// 뱀의 이동 방향 0 : 동쪽 1: 남쪽 2: 서쪽 3: 북쪽.
int _move = 0;
// 뱀이 이동한 시간.(초)
int _sec = 1;
void snake(int& curx, int& cury);
int main()
{
	cin >> N >> K;
	int count = 0;


	// 사과 위치 
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		// 사과의 위치
		board.push_back(make_pair(row - 1, col - 1));
	}

	// 뱀의 방향 변환 정보 
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int sec;
		char direction;
		cin >> sec >> direction;
		change.push_back(make_pair(sec, direction));
	}
	// 뱀이 이동하기 시작. 처음 방향은 오른쪽.
	_snake.push_back(make_pair(0, 0));
	int curx = 1;
	int cury = 0;
	bool check = false;
	while (1)
	{
		bool _break = true;
		// 뱀이 있는곳인지 확인.
		for (int i = 0; i < _snake.size(); i++)
		{
			if (curx == _snake[i].second && cury == _snake[i].first)
			{
				_break = false;
				break;
			}
		}
		// 뱀이 있는곳에 간거면.
		if (!_break)break;

		if (curx >= N || curx < 0 || cury < 0 || cury >= N)break;

		// 사과 있는 곳인지 확인 
		check = false;
		int _size = board.size();
		for (int i = 0; i < _size; i++)
		{
			int temp1, temp2;
			if (board.size() == 0)break;
			temp1 = board[0].first;
			temp2 = board[0].second;

			//사과 있는곳에 도착-> 사과 사라짐.
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
		// 사과 있는곳 안감.
		if (!check)
		{
			_snake.pop_front();
			_snake.push_back(make_pair(cury, curx));
		}
		// 사과 있는 곳 감.
		else
			_snake.push_back(make_pair(cury, curx));


		// 방향 전환
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
		// 뱀 웅직임
		snake(curx, cury);
		_sec++;

	}
	cout << _sec << "\n";
	return 0;
}

void snake(int& curx, int& cury)
{

	// 동쪽
	if (_move == 0)
	{
		curx++;
	}
	// 남쪽
	else if (_move == 1)
	{
		cury++;
	}
	// 서쪽
	else if (_move == 2)
	{
		curx--;
	}
	// 북쪽
	else if (_move == 3)
	{
		cury--;
	}
}
