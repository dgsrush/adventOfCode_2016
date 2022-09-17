#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::fstream;

bool validTri(int a, int b, int c)
{
	if(a >= (b + c)) return false;
	if(b >= (a + c)) return false;
	if(c >= (a + b)) return false;
	return true;
}

int main()
{
	int good = 0;
	int a, b, c;
	fstream inf("input.txt", std::ios_base::in);
	while(!inf.eof())
	{
		inf >> a >> b >> c;
		if(validTri(a, b, c)) good++;
	}

	cout << "PART1 answer = " << good << endl;

	/////

	inf.seekg(0, inf.beg);
	good = 0;
	int a1, a2, a3;
	int b1, b2, b3;
	int c1, c2, c3;
	while(!inf.eof())
	{
		inf >> a1 >> b1 >> c1;
		inf >> a2 >> b2 >> c2;
		inf >> a3 >> b3 >> c3;
		if(validTri(a1, a2, a3)) good++;
		if(validTri(b1, b2, b3)) good++;
		if(validTri(c1, c2, c3)) good++;
	}

	cout << "PART2 answer = " << good << endl;

	return 0;
}
