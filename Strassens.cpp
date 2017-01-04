
//STRASSEN’S ALGORITHM

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<time.h>
#include<dos.h>
int a[10][10],b[10][10],c[10][10],d[10][10];
void strassen();
void seqMatMult();
void main()
{
int n;
clock_t after,before;
clrscr();
cout<<endl<<"Enter the elements of the matrix A(2*2):";
//cin>>n;
for(int i=1;i<=2;i++)
for(int j=1;j<=2;j++)
{
cout<<"\n";
cin>>a[i][j];
}
cout<<endl<<"Enter the elements of the matrix B(2*2) :";
//cin>>n;
for(i=1;i<=2;i++)
{
for(j=1;j<=2;j++)
{
cout <<"\n";
cin>>b[i][j];}}//end of two for loops
before=clock();
seqMatMult();
after=clock();
float f2=float((after-before)/CLOCKS_PER_SEC);
cout<<endl<<"Standard matrix multiplication done in "<<f2<<"secs"<<endl;
cout<<endl<<"The resultant matrix is:"<<endl;
for(i=1;i<=2;i++)
{
cout<<"\n";
for(j=1;j<=2;j++)
{
cout<<c[i][j];
cout<<"\t";
}
cout<<"\n";
}
before = clock();
strassen();
after = clock();
float f1=float((after-before)/CLOCKS_PER_SEC);
cout<<endl<<"Strassen's matrix multiplication done in "<<f1<<"secs"<<endl;
cout<<"\nThe resultant matrix is:";
for(i=1;i<=2;i++)
{
cout<<"\n";
for(j=1;j<=2;j++)
{
cout<<c[i][j];
cout<<"\t";
}
cout<<"\n";
}
getch();
}
void seqMatMult()
{

	 for (int i = 1; i <=2; i++)
	   {
		for (int j = 1; j <= 2; j++)
			{
				c[i][j] = 0;
				for (int k = 1; k <=2; k++)
				c[i][j] += a[i][k]*b[k][j];
				delay(1000);

			}
	    }

}
void strassen()
{
delay(1000);
int p,q,r,s,t,u,v,i,j,n;
p=(a[1][1]+a[2][2])*(b[1][1]+b[2][2]);
q=(a[2][1]+a[2][2])*b[1][1];
r=a[1][1]*(b[1][2]-b[2][2]);
s=a[2][2]*(b[2][1]-b[1][1]);
t=(a[1][1]+a[1][2])*b[2][2];
u=(a[2][1]-a[1][1])*(b[1][1]+b[1][2]);
v=(a[1][2]-a[2][2])*(b[2][1]+b[2][2]);
c[1][1]=p+s-t+v;
c[1][2]=r+t;
c[2][1]=q+s;
c[2][2]=p+r-q+u;
}
