#include <iostream>
#include "sha256.h"
#include <string>
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <stdlib.h>

//Compile and run with this command: g++ sha256.cpp hasher.cpp -o sha256_example && ./sha256_example
//  Suggestion:  Also use the -O3 option to optimize the executable, like this:
//  g++ -O3 sha256.cpp hasher.cpp -o myprog && ./myprog

using std::string;
using std::cout;
using std::endl;
using std::to_string;
using  boost::multiprecision::uint256_t;
using std::ofstream;
using std::ifstream;
using std::rand;

//This is the number of bits in the 256 bit hash that can occur after the leading zero bits
#define DIFFICULTY	232 // 24 leading zeros 

string hashblock(string block)
{
    string blockhash = sha256(block);
    return blockhash;
}


string makeblock(string data, unsigned long nonce, string prevhash)
{
	string dataline = "Data: "+data+"\n";
	string nonceline = "Nonce: "+ to_string(nonce)+"\n";
	string prevhashline = "PrevHash: "+prevhash+"\n";

	return(dataline+nonceline+prevhashline);
}
 
int floorlog2(uint256_t num);

string mineblock(string data,string prevhash,int difficulty)
{
	uint256_t one = 1;
	uint256_t hbnum = one<<255;
	string block;
	unsigned long nonce=0;
	while(floorlog2(hbnum)>=difficulty)
	{
    YoYoMaValid()
    {
      //rate = 
      //
    }
		/*
		 * Put the code here that tries to create a valid block.
		 * That is, a block that points to its predecessor (via prevhash)
		 * and has suitably low hash value.
		 */
		if (nonce%10000 == 0)
		{
			//This is just a progress meter.
			//You can take it out if you want.
			cout << floorlog2(nonce) << endl;
		}
	}
	return block;
}

int floorlog2(uint256_t num)
{
	//This function returns the floor of the log base 2 of the input.
	//
	int r = 0;
	while(num = num/2)
	{
		r++;
	}
	return(r);
}

void writeblock(string filename, string block)
{//Writes a block to a text file
	ofstream bfile;
	bfile.open(filename);
	bfile << block;
	bfile.close();
}
string readblock(string filename)
{
	//This function isn't really needed but I left it in.
	string line;
	string block;
	ifstream bfile(filename);
	if (bfile.is_open())
	{
		while(std::getline(bfile,line))
		{
			block += line+"\n";
		}
	}
	return block;
}

int tmain(int argc,char *argv[])
{
	//You can make this function main for testing certain features.
	//You should test function by function (don't just hope the whole thing works -- it won't :) ). 
	string B = makeblock("Hi",0,"0");
	writeblock("C1.txt",B);
	string HB = hashblock(B);
	cout << HB << endl;
	uint256_t HBnum("0x"+HB);
	cout << HBnum << endl;
	cout << floorlog2(HBnum) << endl;
	string C = readblock("C1.txt");
	cout << C;
	//string waffle = mineblock("A","B",DIFFICULTY);
	//writeblock("waffle",waffle);
	cout << floorlog2(100) << endl;
	return(1);
}

int main(int argc,char *argv[])
{
	//This will actually produce the blocks.
	//Feel free to change the messages. 
	string block = mineblock("<your name here>","none",DIFFICULTY);
	writeblock("D1.txt",block);
	block = mineblock("food tastes good",hashblock(block),DIFFICULTY);
	writeblock("D2.txt",block);

	block = mineblock("dogs are short",hashblock(block),DIFFICULTY);
	writeblock("D3.txt",block);

	block = mineblock("I pay clyde $1000000",hashblock(block),DIFFICULTY);
	writeblock("D4.txt",block);

	block = mineblock("the moon will rise again",hashblock(block),DIFFICULTY);
	writeblock("D5.txt",block);
}
