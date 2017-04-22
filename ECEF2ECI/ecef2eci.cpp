#include<fstream>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
float* multiplymat(float user1[3][3], float user2[3])
{
	float* finalm =new float[3];
	float summ=0;
	for(int i=0;i<=3;i++){
		for(int j=0; j<=3;j++)
			summ=summ+user1[i][j]*user2[j];
	        finalm[i]=summ;
	        summ=0;
    }
   return finalm;
}
int main()
{
	float ecef[3],theta,omega,t;
	float* eci;
	float temp[3];
	float data;

	std::ofstream clear ("output.txt", std::ios::out | std::ios::trunc);
	clear.close(); //clearing contents of output.txt file

    ifstream infile;
    infile.open("input.txt");
	/*cout<<"ECEF coordinates: \nEnter x: ";
	cin>>ecef[0];
	cout<<"\nEnter y: ";
	cin>>ecef[1];
	cout<<"\nEnter z: ";
	cin>>ecef[2];
	cout<<"\nEnter theta: ";
	cin>>theta;
	theta=theta*M_PI/180;
	cout<<"\nEnter omega: ";
	cin>>theta;
	omega=omega*M_PI/180;
	cout<<"\nEnter time period: ";
	cin>>t;*/
	infile>>data;
	while (!infile.eof())
	{
	ecef[0]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	ecef[1]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	ecef[2]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	theta=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	omega=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	t=data;
	infile.seekg(1,ios::cur );
	infile>>data;

    float rotmatrix[3][3]={{cos(theta),sin(theta),0},  {-sin(theta),cos(theta),0},  {0,0,1}};
	eci=multiplymat(rotmatrix,ecef);
	for (int m=0;m<3;m++){
		temp[m]=*eci;
		eci=eci+1;
	}

	float rotmatrix1[3][3]={{cos(omega*t),0,sin(omega*t)},  {0,1,0},  {-sin(omega*t),0,cos(omega*t)}};
	eci=multiplymat(rotmatrix,temp);
	for (int m=0;m<3;m++){
		temp[m]=*eci;
		eci=eci+1;
	}

     printf("\nECI coordinates: \nx=%f\ny=%f\nz=%f",temp[0],temp[1],temp[2]);

    ofstream outfile;
    outfile.open("output.txt", std::ios_base::app);
    outfile<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<"\n";
    outfile<<endl;
    outfile.close();

    }

    
	//printf("\nECI coordinates: \nx=%f\ny=%f\nz=%f",*eci,*(eci+1),*(eci+2));
	return 0;
}