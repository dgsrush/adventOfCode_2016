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

void tokenize(const string &str, vector<string> &ll)
{
	string delims("-[]");
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

class Row
{
public:
	Row(const string &ln) { setValues(ln); }

	int getId() { return id; }
	string getName() { return name; }

	bool isReal()
	{
		string chkSum = calcChkSum();
		if(chkSum == checksum) return true;
		return false;
	}

	void decryptName()
	{
		for(char &c : name)
		{
			if(c == '-')
				c = ' ';
			else
			{
				int rot = id + (c - 97);
				c = (rot % 26) + 97;
			}
		}
	}

private:
	void setValues(const string &ln)
	{
		vector<string> tkns;
		tokenize(ln, tkns);

		checksum = tkns[tkns.size() - 1];
		tkns.pop_back();

		id = std::stoi(tkns[tkns.size() - 1]);
		tkns.pop_back();

		for(string s : tkns)
		{
			if(name.empty())
				name = s;
			else
				name += "-" + s;
		}
	}

	string calcChkSum()
	{
		map<char,int> mp;
		for(char c : name)
			if(c != '-') mp[c]++;

		string cs = "";
		for(int i = 0; i < 5; i++)
		{
			int max = 0;
			char maxc = '0';
			map<char,int>::iterator it, itr;
			for(it = mp.begin(); it != mp.end(); ++it)
			{
				if(it->second > max)
				{
					max = it->second;
					maxc = it->first;
					itr = it;
				}
			}
			cs += maxc;
			mp.erase(itr);
		}
		return cs;
	}

	string name;
	int id;
	string checksum;
};

/////

int main()
{
	vector<string> lns;
	readInput(lns);

	int answer1 = 0;
	int answer2 = -1;

	for(string ln : lns)
	{
		Row r(ln);
		if(r.isReal())
			answer1 += r.getId();

		if(answer2 < 0)
		{
			r.decryptName();
			if(r.getName() == "northpole object storage")
				answer2 = r.getId();
		}
	}

	cout << "PART1 answer = " << answer1 << endl; //245102
	cout << "PART2 answer = " << answer2 << endl; //324

	return 0;
}
