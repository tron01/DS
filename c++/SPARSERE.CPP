//Sparse Matrix Representation

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main()
{
int m,n,k=1,num;
int sp[10][3];
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
 cout<< "The sparse representation is"<<endl;
 for(int a=0;a<k;++a)
 for(int b=0;b<3;++b)
 {
 
 cout<<sp[a][b]<<"\t";
 cout<<endl;
 }
 return 0;
 }
