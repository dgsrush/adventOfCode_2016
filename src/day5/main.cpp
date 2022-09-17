#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include<string>
#include<iostream>
#include"cryptopp850/md5.h"
#include"cryptopp850/hex.h"
#include"cryptopp850/files.h"
#include"cryptopp850/aes.h"

using std::string;
using std::cout;
using std::endl;
using namespace CryptoPP;

int main()
{
	string input = "ffykfhsq";
	string answer1 = "";
	string answer2 = "        ";
	Weak::MD5 md5;
	unsigned long i = 0;

	while(true)
	{
		string inp = input + std::to_string(i);
		string hash;
		StringSource(inp, true, new HashFilter(md5, new HexEncoder(new StringSink(hash))));

		if(hash.find("00000") == 0)
		{
			cout << inp << " " << hash << endl;

			if(answer1.length() < 8)
				answer1 += hash[5];

			int idx = hash[5] - 48;
			if(idx >= 0 && idx < 8)
			{
				if(answer2[idx] == ' ')
				{
					answer2[idx] = hash[6];
					if(answer2.find(" ") == std::string::npos) break;
				}
			}
		}
		i++;
	}

	cout << "PART1 answer = " << answer1 << endl; //c6697b55
	cout << "PART2 answer = " << answer2 << endl; //8c35d1ab

	return 0;
}
