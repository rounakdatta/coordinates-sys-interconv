#include<fstream>
#include<iostream>
#include<cmath>
#include "ecef2eci.h"
using namespace std;
int ecef2eci(float x,float y,float z,float theta,float omega, float t) //first void will be responsible for returning error codes
{
	float x1,y1,z1;
	//float x,y,z,x1,y1,z1,theta,omega,t;
	//cout<<"ECEF coordinates: \nEnter x: ";
	//cin>>x;
	//cout<<"\nEnter y: ";
	//cin>>y;
	//cout<<"\nEnter z: ";
	//cin>>z;
	//cout<<"\nEnter theta: ";
	//cin>>theta;
	theta=theta*3.14159265/180;
	//cout<<"\nEnter omega: ";
	//cin>>omega;
	omega=omega*3.14159265/180;
	//cout<<"\nEnter time period: ";
	//cin>>t;
	x1=(z/sin(theta))*cos(omega*t);
	y1=(z/sin(theta))*sin(omega*t);
	z1=z;

	//not displaying data on screen!
	//printf("\nECI coordinates: \nx=%f\ny=%f\nz=%f",x1,y1,z1);

    ofstream outfile;
    outfile.open("output.txt", std::ios_base::app);
    //outfile.seekp (eof());
    //outfile.eof();
    outfile<<x1<<" "<<y1<<" "<<z1<<"\n";
    outfile<<endl;
    outfile.close();

	return 0; //return error codes/success codes here
}
