#include"ReadFile.h"
#include<iostream>
#include<vector>
#include<set>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::string;

void readInput(vector<string> &ll)
{
	mhr::ReadFile inf("input.txt");
	string ln;
	while(inf.readLine(ln))
	{
		if(ln.length() > 0)
			ll.push_back(ln);
	}
	inf.close();
}

int main()
{
	vector<string> lns;
	readInput(lns);

	string ans = "";
	int pos = 5;

	for(string ln : lns)
	{
		for(char c : ln)
		{
			if(c == 'U' && pos > 3) pos-=3;
			else if(c == 'D' && pos < 7) pos+=3;
			else if(c == 'L' && (pos!=1 && pos!=4 && pos!=7)) pos--;
			else if(c == 'R' && (pos!=2 && pos!=6 && pos!=9)) pos++;
		}
		ans += std::to_string(pos);
	}

	cout << "PART1 answer = " << ans << endl;

	/////

	ans = "";
	pos = 5;
	for(string ln : lns)
	{
		for(char c : ln)
		{
			if(c == 'U' && pos==13) pos=11;
			else if(c == 'U' && pos==10) pos=6;
			else if(c == 'U' && pos==11) pos=7;
			else if(c == 'U' && pos==12) pos=8;
			else if(c == 'U' && pos==6) pos=2;
			else if(c == 'U' && pos==7) pos=3;
			else if(c == 'U' && pos==8) pos=4;
			else if(c == 'U' && pos==3) pos=1;

			else if(c == 'D' && pos==1) pos=3;
			else if(c == 'D' && pos==2) pos=6;
			else if(c == 'D' && pos==3) pos=7;
			else if(c == 'D' && pos==4) pos=8;
			else if(c == 'D' && pos==6) pos=10;
			else if(c == 'D' && pos==7) pos=11;
			else if(c == 'D' && pos==8) pos=12;
			else if(c == 'D' && pos==11) pos=13;

			else if(c == 'R' && pos==5) pos=6;
			else if(c == 'R' && pos==6) pos=7;
			else if(c == 'R' && pos==7) pos=8;
			else if(c == 'R' && pos==8) pos=9;
			else if(c == 'R' && pos==2) pos=3;
			else if(c == 'R' && pos==3) pos=4;
			else if(c == 'R' && pos==10) pos=11;
			else if(c == 'R' && pos==11) pos=12;

			else if(c == 'L' && pos==9) pos=8;
			else if(c == 'L' && pos==4) pos=3;
			else if(c == 'L' && pos==8) pos=7;
			else if(c == 'L' && pos==12) pos=11;
			else if(c == 'L' && pos==3) pos=2;
			else if(c == 'L' && pos==7) pos=6;
			else if(c == 'L' && pos==11) pos=10;
			else if(c == 'L' && pos==6) pos=5;
		}

		if(pos < 10) ans += std::to_string(pos);
		else if(pos == 10) ans += 'A';
		else if(pos == 11) ans += 'B';
		else if(pos == 12) ans += 'C';
		else if(pos == 13) ans += 'D';
	}

	cout << "PART2 answer = " << ans << endl;

	return 0;
}
