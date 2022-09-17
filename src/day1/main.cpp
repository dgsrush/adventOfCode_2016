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

void tokenize(string &str, string &delims, vector<string> &ll)
{
	string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		string chr(1, str[i]);
		if(delims.find(chr) != string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(tok);
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(tok);
}

void readInput(vector<string> &ll)
{
	mhr::ReadFile inf("input.txt");
	string ln;
	inf.readLine(ln);
	inf.close();

	string delims = ", ";
	vector<string> ss;
	tokenize(ln, delims, ss);
	for(string s : ss)
		ll.push_back(s);
}

string getNewDir(string dir, string lr)
{
	if(dir == "N")
	{
		if(lr == "L") return "W";
		return "E";
	}
	if(dir == "S")
	{
		if(lr == "L") return "E";
		return "W";
	}
	if(dir == "E")
	{
		if(lr == "L") return "N";
		return "S";
	}
	if(dir == "W")
	{
		if(lr == "L") return "S";
		return "N";
	}
	return "";
}

int main()
{
	int x = 0;
	int y = 0;
	string dir = "N";
	set<string> visited;
	visited.insert("0:0");
	int part2 = -1;

	vector<string> ll;
	readInput(ll);
	for(string ln : ll)
	{
		string lr(1, ln[0]);
		int dist = stoi(ln.substr(1));
		string newdir = getNewDir(dir, lr);
		for(int i = 0; i < dist; i++)
		{
			if(newdir == "N")      y++;
			else if(newdir == "S") y--;
			else if(newdir == "E") x++;
			else if(newdir == "W") x--;
			if(part2 < 0)
			{
				string visit = std::to_string(x) + ":" + std::to_string(y);
				if(visited.count(visit) > 0)
					part2 = abs(x) + abs(y);
				visited.insert(visit);
			}
		}
		dir = newdir;
	}

	cout << "PART1 answer = " << abs(x) + abs(y) << endl;
	cout << "PART2 answer = " << part2 << endl;
	return 0;
}
