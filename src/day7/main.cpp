#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::set;

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

void tokenize(const string &str, vector<string> &ll1, vector<string> &ll2)
{
	bool io = true;
	string delims("[]");
	string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		string chr(1, str[i]);
		if(delims.find(chr) != string::npos)
		{
			if(tok.length() > 0)
			{
				if(io)
					ll1.push_back(tok);
				else
					ll2.push_back(tok);
				tok = "";
				io = !io;
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
	{
		if(io)
			ll1.push_back(tok);
		else
			ll2.push_back(tok);
	}
}

bool isAbba(string &s)
{
	if(s.length() != 4) return false;
	if(s[0] != s[3]) return false;
	if(s[1] != s[2]) return false;
	if(s[0] == s[1]) return false;
	return true;
}

bool containsAbba(string &s)
{
	int cnt = s.length() - 3;
	for(int i = 0; i < cnt; i++)
	{
		string ss = s.substr(i, 4);
		if(isAbba(ss)) return true;
	}
	return false;
}

bool isAba(string &s)
{
	if(s.length() != 3) return false;
	if(s[0] != s[2]) return false;
	if(s[0] == s[1]) return false;
	return true;
}

void getAbas(string &s, set<string> &ll)
{
	int cnt = s.length() - 2;
	for(int i = 0; i < cnt; i++)
	{
		string ss = s.substr(i, 3);
		if(isAba(ss))
			ll.insert(ss);
	}
}

bool isOppositeAba(string &s1, string &s2)
{
	if(s1.length() != 3) return false;
	if(s2.length() != 3) return false;
	if(!isAba(s1)) return false;
	if(!isAba(s2)) return false;
	if(s1[0] != s2[1]) return false;
	if(s1[1] != s2[0]) return false;
	return true;
}

/////

int main()
{
	vector<string> lns;
	readInput(lns);

	int answer1 = 0;
	int answer2 = 0;

	for(string ln : lns)
	{
		vector<string> ll1, ll2;
		tokenize(ln, ll1, ll2);

		bool brkt = false;
		for(string l2 : ll2)
		{
			if(containsAbba(l2))
			{
				brkt = true;
				break;
			}
		}
		if(!brkt)
		{
			for(string l1 : ll1)
			{
				if(containsAbba(l1))
				{
					answer1++;
					break;
				}
			}
		}

		//

		set<string> l1abas;
		set<string> l2abas;
		for(string l1 : ll1)
			getAbas(l1, l1abas);
		for(string l2 : ll2)
			getAbas(l2, l2abas);

		set<string>::iterator it1, it2;
		bool done = false;
		for(it1 = l1abas.begin(); it1 != l1abas.end(); ++it1)
		{
			for(it2 = l2abas.begin(); it2 != l2abas.end(); ++it2)
			{
				string s1 = *it1;
				string s2 = *it2;
				if(isOppositeAba(s1, s2))
    			{
					answer2++;
					done = true;
					break;
				}
			}
			if(done) break;
		}
	}

	cout << "PART1 answer = " << answer1 << endl; //105
	cout << "PART2 answer = " << answer2 << endl; //258

	return 0;
}
