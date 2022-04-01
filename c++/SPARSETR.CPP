//Sparse Matrix Transpose

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
void sparsetrans(int a[10][3], int b[10][3]);
void sparsedis(int a[10][3]);
int main()
{
int m,n,k=1,num;
int sp[10][3],tsp[10][3];
    	system("cls");
cout<<" Enter the size of the matrix"<<endl;
cin>>m>>n;
cout<<"Enter the matrix elements"<<endl;
for(int i=0;i<m;++i)
for(int j=0;j<n;++j)
{
cin>>num;
if(num!=0)
 {
   sp[k][0]=i;
   sp[k][1]=j;
   sp[k][2]=num;
   ++k;
  }
 }
 sp[0][0]=m;sp[0][1]=n;sp[0][2]=k-1;
 sparsetrans(sp,tsp);
 sparsedis(sp);
 sparsedis(tsp);

 }
 void sparsetrans(int a[10][3], int b[10][3])
 {
  int m,n,t,q=1;
  m=a[0][1];n=a[0][1];t=a[0][2];
  b[0][0]=n;b[0][1]=m,b[0][2]=t;
  for(int col=0; col<n;++col)
  for(int p=1;p<=t;++p)
  if (a[p][1]==col)
    {
      b[q][0]=a[p][1];
      b[q][1]=a[p][0];
      b[q][2]=a[p][2];
     q=q+1;
    }
  }
 void sparsedis(int a[10][3])
 {
 for(int i=0; i<=a[0][2];++i)
 {
 for(int j=0;j<3;++j)
 cout<<a[i][j]<<"\t";
 cout<<endl<<endl;
 }
 }
