#include<iostream>
#include<fstream>
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
	float sez[3];
	int i;
	float *ecef;
	float* eci;
	float temp[3];
	float data;
	//float rotmatrix;
	float angle[3],theta,omega,t;


    //float angle[3];
	std::ofstream clear ("output.txt", std::ios::out | std::ios::trunc);
	clear.close(); //clearing contents of output.txt file

    ifstream infile;
    infile.open("input.txt");
	/*cout<<"SEZ coordinates:\nEnter x: ";
	cin>>sez[0];
	cout<<"\nEnter y: ";
	cin>>sez[1];
	cout<<"\nEnter z: ";
	cin>>sez[2];
	cout<<"\n\nEnter XY_Z (in degrees): ";
	cin>>angle[0];
	angle[0]=angle[0]*M_PI/180;
	cout<<"Enter ZX_Y (in degrees): ";
	cin>>angle[1];
	angle[1]=angle[1]*M_PI/180;
	cout<<"Enter YZ_X (in degrees): ";
	cin>>angle[2];
	angle[2]=angle[2]*M_PI/180;*/

    infile>>data;
	while (!infile.eof())
	{
	sez[0]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	sez[1]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	sez[2]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	angle[0]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	angle[1]=data;
	infile.seekg(1,ios::cur );

	infile>>data;
	angle[2]=data;
	infile.seekg(1,ios::cur );
	infile>>data;

	float rotmatrix[3][3]={{cos(angle[0]),0,sin(angle[0])},  {0,1,0},  {-sin(angle[0]),0,cos(angle[0])}};
	ecef=multiplymat(rotmatrix,sez);
	for (int m=0;m<3;m++){
		temp[m]=*ecef;
		ecef=ecef+1;
	}

	printf("\nECEF coordinates: \nx=%f\ny=%f\nz=%f",temp[0],temp[1],temp[2]);

	/*cout<<"\n\nECEF coordinates: Enter theta: ";
	cin>>theta;
	theta=theta*M_PI/180;
	cout<<"\nEnter omega: ";
	cin>>theta;
	omega=omega*M_PI/180;
	cout<<"\nEnter time period: ";
	cin>>t;*/
    theta=data;
	infile.seekg(1,ios::cur );
	infile>>data;
	omega=data;
	infile.seekg(1,ios::cur );
	infile>>data;
	t=data;
	infile.seekg(1,ios::cur );
	infile>>data;


	float rotmatrix1[3][3]={{cos(theta),sin(theta),0},  {-sin(theta),cos(theta),0},  {0,0,1}};
	eci=multiplymat(rotmatrix,temp);
	for (int m=0;m<3;m++){
		temp[m]=*eci;
		eci=eci+1;
	}

	float rotmatrix2[3][3]={{cos(omega*t),0,sin(omega*t)},  {0,1,0},  {-sin(omega*t),0,cos(omega*t)}};
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

	return 0;
}