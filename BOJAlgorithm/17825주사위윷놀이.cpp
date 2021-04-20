#include <iostream>
#include<cstring>
#include<set>
using namespace std;
int resmax = 0;
int input[12];
int road[4][23];//21 , 13,  17,  23
bool dupset(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{ //NO dup -> false
	//DUP -> true
	set<pair<int, int>> dp;
	if (p1.first == 0 && p1.second == 0)
		dp.insert({ 4,4 });
	else if (p1.first == -1 && p1.second == -1)
		dp.insert({ -4,-4 });
	else
		dp.insert(p1);

	if (p2.first == 0 && p2.second == 0)
		dp.insert({ 5,5 });
	else if (p2.first == -1 && p2.second == -1)
		dp.insert({ -5,-5 });
	else
		dp.insert(p2);

	if (p3.first == 0 && p3.second == 0)
		dp.insert({ 6,6 });
	else if (p3.first == -1 && p3.second == -1)
		dp.insert({ -6,-6 });
	else
		dp.insert(p3);

	if (p4.first == 0 && p4.second == 0)
		dp.insert({ 7,7 });
	else if (p4.first == -1 && p4.second == -1)
		dp.insert({ -7,-7 });
	else
		dp.insert(p4);

	if (dp.size() != 4) return true;
	return false;
}
bool chkduppos(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{
	//false -> NO DUP
	//true-> DUP

	//�׳� ��¥ �ߺ��� ���
	bool ret = dupset(p1, p2, p3, p4);
	if (ret) return true;

	//�ߺ���ġ�� but �ٸ� �� üũ
	pair<int, int> tmp1, tmp2, tmp3, tmp4; //1,2,3 �࿡ �����ϴ� ���(0��)-> 0���� �ٽ� ��ǥ ������ֱ�
	//0�� ���� ��ǥ �ٽ� ������ְ� set�� Ȯ��-> ������� �ߺ�üũ
	
	//[0][1] ~[0][5] (0/1/2/3)
	tmp1 = p1; tmp2 = p2; tmp3 = p3; tmp4 = p4;
	if (p1.second <= 5 && p1.second >= 0 ) tmp1 = { 0, p1.second };
	if (p2.second <= 5 && p2.second >= 0) tmp2 = { 0, p2.second };
	if (p3.second <= 5 && p3.second >= 0) tmp3 = { 0, p3.second };
	if (p4.second <= 5 && p4.second >= 0) tmp4 = { 0, p4.second };
	ret = dupset(tmp1, tmp2, tmp3, tmp4);
	if (ret) return true;

	//[0][6] ~[0][10] (0/2/3)
	tmp1 = p1; tmp2 = p2; tmp3 = p3; tmp4 = p4;
	if (p1.second <= 10 && p1.second > 5 && p1.first != 1) tmp1 = { 0, p1.second };
	if (p2.second <= 10 && p2.second > 5 && p2.first != 1) tmp2 = { 0, p2.second };
	if (p3.second <= 10 && p3.second > 5 && p3.first != 1) tmp3 = { 0, p3.second };
	if (p4.second <= 10 && p4.second > 5 && p4.first != 1) tmp4 = { 0, p4.second };
	ret = dupset(tmp1, tmp2, tmp3, tmp4);
	if (ret) return true;


	//[0][11] ~[0][15] (0/3)
	tmp1 = p1; tmp2 = p2; tmp3 = p3; tmp4 = p4;
	if (p1.second <= 15 && p1.second > 10 && p1.first != 1 && p1.first != 2) tmp1 = { 0, p1.second };
	if (p2.second <= 15 && p2.second > 10 && p2.first != 1 && p2.first != 2) tmp2 = { 0, p2.second };
	if (p3.second <= 15 && p3.second > 10 && p3.first != 1 && p3.first != 2) tmp3 = { 0, p3.second };
	if (p4.second <= 15 && p4.second > 10 && p4.first != 1 && p4.first != 2) tmp4 = { 0, p4.second };
	ret = dupset(tmp1, tmp2, tmp3, tmp4);
	if (ret) return true;

	//[1/2/3][i] (25) ~ [1/2/3][j] (35) -> 1�� ����
	tmp1 = p1; tmp2 = p2; tmp3 = p3; tmp4 = p4;
	if (p1.second <= 15 && p1.second >= 13 && p1.first == 2) tmp1 = { 1, p1.second - 4 };
	if (p2.second <= 15 && p2.second >= 13 && p2.first == 2) tmp2 = { 1, p2.second - 4 };
	if (p3.second <= 15 && p3.second >= 13 && p3.first == 2) tmp3 = { 1, p3.second - 4 };
	if (p4.second <= 15 && p4.second >= 13 && p4.first == 2) tmp4 = { 1, p4.second - 4 };

	if (p1.second <= 21 && p1.second >= 19 && p1.first == 3) tmp1 = { 1, p1.second - 10 };
	if (p2.second <= 21 && p2.second >= 19 && p2.first == 3) tmp2 = { 1, p2.second - 10 };
	if (p3.second <= 21 && p3.second >= 19 && p3.first == 3) tmp3 = { 1, p3.second - 10 };
	if (p4.second <= 21 && p4.second >= 19 && p4.first == 3) tmp4 = { 1, p4.second - 10 };

	ret = dupset(tmp1, tmp2, tmp3, tmp4);
	if (ret) return true;

	//[0/1/2/3/][last] (40)
	int cnt40 = 0;
	if (road[p1.first][p1.second] == 40) cnt40++;
	if (road[p2.first][p2.second] == 40) cnt40++;
	if (road[p3.first][p3.second] == 40) cnt40++;
	if (road[p4.first][p4.second] == 40) cnt40++;
	if (cnt40 > 1) return true;

	return false;

}
int tmpcnt = 0;
void rec(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4, int sum, int moveind)
{
	//
	//cout << "(" << p1.first << " " << p1.second << ")  (" << p2.first << " " << p2.second << ")  (" << p3.first << " " << p3.second << ")  (" << p4.first << " " << p4.second << ")\n";
	//tmpcnt++;
	if (moveind >= 10)
	{
		//cout << "sum: " << tmpcnt << "\n###########\n";
		if (resmax < sum) resmax = sum;
		return;
	}
	int mval = input[moveind];
	int cal;
	bool dupl;

	//switching point �� ���� �ϴ°��-> �ϰ������� �� ��ȯ! 0�࿡ ����!
	if (p1.first == 0 && (p1.second == 5 || p1.second == 10 || p1.second == 15))
	{//10, 20, 30 �� ��� Ʋ�������
		p1 = { road[p1.first][p1.second] / 10, p1.second }; //�౳ȯ
	}
	if (p2.first == 0 && (p2.second == 5 || p2.second == 10 || p2.second == 15))
	{//10, 20, 30 �� ��� Ʋ�������
		p2 = { road[p2.first][p2.second] / 10, p2.second }; //�౳ȯ
	}
	if (p3.first == 0 && (p3.second == 5 || p3.second == 10 || p3.second == 15))
	{//10, 20, 30 �� ��� Ʋ�������
		p3 = { road[p3.first][p3.second] / 10, p3.second }; //�౳ȯ
	}
	if (p4.first == 0 && (p4.second == 5 || p4.second == 10 || p4.second == 15))
	{//10, 20, 30 �� ��� Ʋ�������
		p4 = { road[p4.first][p4.second] / 10, p4.second }; //�౳ȯ
	}
	//p1
	if (!(p1.first == -1 && p1.second == -1))
	{
		cal = p1.second + mval;
		switch (p1.first)
		{
		case 0:
			if (cal > 20)
			{//out of bound
				rec({ -1,-1 }, p2, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos({p1.first, cal}, p2, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec({ p1.first, cal }, p2, p3, p4, sum + road[p1.first][cal], moveind + 1);
				}
			}
			break;
		case 1:
			if (cal > 12)
			{
				rec({ -1,-1 }, p2, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos({ p1.first, cal }, p2, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec({ p1.first, cal }, p2, p3, p4, sum + road[p1.first][cal], moveind + 1);
				}
			}
			break;
		case 2:
			if (cal > 16)
			{
				rec({ -1,-1 }, p2, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos({ p1.first, cal }, p2, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec({ p1.first, cal }, p2, p3, p4, sum + road[p1.first][cal], moveind + 1);
				}
			}
			break;
		case 3:
			if (cal > 22)
			{
				rec({ -1,-1 }, p2, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos({ p1.first, cal }, p2, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec({ p1.first, cal }, p2, p3, p4, sum + road[p1.first][cal], moveind + 1);
				}
			}
			break;
		}
	}

	//p2
	if (!(p2.first == -1 && p2.second == -1))
	{
		cal = p2.second + mval;
		switch (p2.first)
		{
		case 0:
			if (cal > 20)
			{//out of bound
				rec(p1, { -1,-1 }, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, { p2.first, cal }, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, { p2.first, cal }, p3, p4, sum + road[p2.first][cal], moveind + 1);
				}
			}
			break;
		case 1:
			if (cal > 12)
			{//out of bound
				rec(p1, { -1,-1 }, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, { p2.first, cal }, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, { p2.first, cal }, p3, p4, sum + road[p2.first][cal], moveind + 1);
				}
			}
			break;
		case 2:
			if (cal > 16)
			{//out of bound
				rec(p1, { -1,-1 }, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, { p2.first, cal }, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, { p2.first, cal }, p3, p4, sum + road[p2.first][cal], moveind + 1);
				}
			}
			break;
		case 3:
			if (cal > 22)
			{//out of bound
				rec(p1, { -1,-1 }, p3, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, { p2.first, cal }, p3, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, { p2.first, cal }, p3, p4, sum + road[p2.first][cal], moveind + 1);
				}
			}
			break;
		}
	}

	//p3
	if (!(p3.first == -1 && p3.second == -1))
	{
		cal = p3.second + mval;
		switch (p3.first)
		{
		case 0:
			if (cal > 20)
			{//out of bound
				rec(p1, p2, { -1,-1 }, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, { p3.first, cal }, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2,{ p3.first, cal }, p4, sum + road[p3.first][cal], moveind + 1);
				}
			}
			break;
		case 1:
			if (cal > 12)
			{//out of bound
				rec(p1, p2, { -1,-1 }, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, { p3.first, cal }, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, { p3.first, cal }, p4, sum + road[p3.first][cal], moveind + 1);
				}
			}
			break;
		case 2:
			if (cal > 16)
			{//out of bound
				rec(p1, p2, { -1,-1 }, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, { p3.first, cal }, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, { p3.first, cal }, p4, sum + road[p3.first][cal], moveind + 1);
				}
			}
			break;
		case 3:
			if (cal > 22)
			{//out of bound
				rec(p1, p2, { -1,-1 }, p4, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, { p3.first, cal }, p4);
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, { p3.first, cal }, p4, sum + road[p3.first][cal], moveind + 1);
				}
			}
			break;
		}
	}


	//p4
	if (!(p4.first == -1 && p4.second == -1))
	{
		cal = p4.second + mval;
		switch (p4.first)
		{
		case 0:
			if (cal > 20)
			{//out of bound
				rec(p1, p2, p3,{ -1,-1 }, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, p3, { p4.first, cal });
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, p3, { p4.first, cal }, sum + road[p4.first][cal], moveind + 1);
				}
			}
			break;
		case 1:
			if (cal > 12)
			{//out of bound
				rec(p1, p2, p3, { -1,-1 }, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, p3, { p4.first, cal });
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, p3, { p4.first, cal }, sum + road[p4.first][cal], moveind + 1);
				}
			}
			break;
		case 2:
			if (cal > 16)
			{//out of bound
				rec(p1, p2, p3, { -1,-1 }, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, p3, { p4.first, cal });
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, p3, { p4.first, cal }, sum + road[p4.first][cal], moveind + 1);
				}
			}
			break;
		case 3:
			if (cal > 22)
			{//out of bound
				rec(p1, p2, p3, { -1,-1 }, sum, moveind + 1);
			}
			else {
				dupl = chkduppos(p1, p2, p3, { p4.first, cal });
				if (!dupl)
				{//�ߺ� X -> ���� �ܰ� ȣ��
					rec(p1, p2, p3, { p4.first, cal }, sum + road[p4.first][cal], moveind + 1);
				}
			}
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		cin >> input[i];

	memset(road, -1, sizeof(road));
	//init road
	for (int i = 0; i <= 20; i++) //1�� ���
		road[0][i] = i * 2;
	for (int i = 0; i <= 12; i++) //2�� ���
	{
		if (i <= 5)
			road[1][i] = i * 2;
		else if (i > 5 && i <= 8)
			road[1][i] = 10 + 3 * (i - 5);
		else
			road[1][i] = 5 * (i - 4);
	}
	for (int i = 0; i <= 16; i++) //3�� ���
	{
		if (i <= 12)
			road[2][i] = i * 2;
		else
			road[2][i] = 5 * (i - 8);
	}
	for (int i = 0; i <= 22; i++) //4�� ���
	{
		if (i <= 15)
			road[3][i] = i * 2;
		else if (i > 15 && i <= 19)
			road[3][i] = 28 - (i - 16); //25����
		else
			road[3][i] = 30 + (i - 20) * 5;
	}

	pair<int, int> p1, p2, p3, p4;
	rec({ 0,0 }, { 0,0 }, { 0,0 }, { 0,0 }, 0, 0); //{ 0,-1 } �� ������ġ

	cout << resmax;
	return 0;
}