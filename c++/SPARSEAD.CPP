//Sparse Matrix Addition
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
void sparseread(int a[10][3],int m, int n);
void sparsedis(int a[10][3]);
int  main()
{
int m,n,i=1,j=1,k=1,t1,t2;
int sp1[10][3],sp2[10][3], spsum[15][3];
    	system("cls");

cout<<" Enter the size of the matrix"<<endl;
cin>>m>>n;
cout<<"Enter the first matrix elements"<<endl;
sparseread(sp1,m,n);
cout<<"Enter the second matrix elements"<<endl;
sparseread(sp2,m,n);
t1=sp1[0][2]; t2=sp2[0][2];
while((i<=t1)&&(j<=t2))
{
 if (sp1[i][0]<sp2[j][0])
   {
     spsum[k][0]=sp1[i][0];
     spsum[k][1]=sp1[i][1];
     spsum[k][2]=sp1[i][2];
     ++k;
     ++i;
   }
 else if(sp1[i][0]>sp2[j][0])
     {
     spsum[k][0]=sp2[j][0];
     spsum[k][1]=sp2[j][1];
     spsum[k][2]=sp2[j][2];
     ++k;
     ++j;
    }
 else
    if(sp1[i][1]<sp2[j][1])
     {
     spsum[k][0]=sp1[i][0];
     spsum[k][1]=sp1[i][1];
     spsum[k][2]=sp1[i][2];
     ++k;
     ++i;
     }
   else if(sp1[i][1]>sp2[j][1])
     {
     spsum[k][0]=sp2[j][0];
     spsum[k][1]=sp2[j][1];
     spsum[k][2]=sp2[j][2];
     ++k;
     ++j;
     }
    else
      {
     spsum[k][0]=sp1[i][0];
     spsum[k][1]=sp1[i][1];
     spsum[k][2]=sp1[i][2]+sp2[j][2];
     ++k;
     ++i;++j;
     }
   }
   if (i<t1)
     while(i<=t1)
     {
     spsum[k][0]=sp1[i][0];
     spsum[k][1]=sp1[i][1];
     spsum[k][2]=sp1[i][2];
     ++k;
     ++i;
      }
    else
     while(j<=t2)
     {
     spsum[k][0]=sp1[i][0];
     spsum[k][1]=sp1[i][1];
     spsum[k][2]=sp1[i][2];
     ++k;
     ++j;
     }
 spsum[0][0]=m;spsum[0][1]=n;spsum[0][2]=k-1;
 cout<<" Sparse form of the first matrix"<<endl;
 sparsedis(sp1);
 cout<<"Sparse form of the second matrix"<<endl;
 sparsedis(sp2);
 cout<<"Sparse form of the sum matrix"<<endl;
 sparsedis(spsum);
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
void sparseread(int sp[10][3], int m, int n)
{
 int k,num;
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
 }
