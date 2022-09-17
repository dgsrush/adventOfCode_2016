#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::map;

void readInput(vector<string> &lns)
{
	string ln;
	fstream inf("input.txt", std::ios_base::in);
	while(!inf.eof())
	{
		inf >> ln;
		lns.push_back(ln);
	}
	inf.close();
}

/////

int main()
{
	vector<string> lns;
	readInput(lns);

	string answer1("");
	string answer2("");

	for(int col = 0; col < lns[0].length(); col++)
	{
		map<char,int> mp;
		for(string ln : lns)
			mp[ln[col]]++;

		int max = 0;
		int min = INT_MAX;
		char c1, c2;
		map<char,int>::iterator it;
		for(it = mp.begin(); it != mp.end(); ++it)
		{
			if(it->second > max)
			{
				max = it->second;
				c1 = it->first;
			}
			if(it->second < min)
			{
				min = it->second;
				c2 = it->first;
			}
		}

		answer1 += c1;
		answer2 += c2;
	}

	cout << "PART1 answer = " << answer1 << endl; //ursvoerv
	cout << "PART2 answer = " << answer2 << endl; //vomaypnn

	return 0;
}
