#include<fstream>
#include<iostream>
#include "ecef2eci.h"
using namespace std;
int main()
{
	float data;
	float x2,y2,z2,theta2,omega2,t2;
	int star;
	/*x2 = 3;
	y2 = 4;
	z2 = 5;

	theta2 = 30;
	omega2 = 60;
	t2 = 2;*/

	std::ofstream clear ("output.txt", std::ios::out | std::ios::trunc);
	clear.close();


	//open a file in read mode
	ifstream infile;
	infile.open("input.txt");

	//cout<<"Now reading from file"<<endl;
	infile>>data;
	while (!infile.eof())
	{
    //infile >>data; //x
	x2=data;
    //cout<<x2<<endl;

	infile.seekg(1,ios::cur );

	infile >>data; //y
	y2=data;
	//cout<<y2<<endl;

	infile.seekg(1,ios::cur );

	infile >>data; //z
	z2=data;
	//cout<<z2<<endl;

	infile.seekg(1,ios::cur );

	infile >>data; //theta
	theta2=data;
	//cout<<theta2<<endl;

	infile.seekg(1,ios::cur );

	infile >>data; //omega
	omega2=data;
	//cout<<omega2<<endl;

	infile.seekg(1,ios::cur );

	infile >>data; //t
	t2=data;
	//cout<<t2<<endl; 

    infile.seekg(1,ios::cur );
    infile >>data;

    star=ecef2eci(x2,y2,z2,theta2,omega2,t2);
    }

	//closing the file
	infile.close();
	
    cout<<"Done!";
;
	//std::cout << star << std::endl; //sucessor failure notation
	return 0;
}
