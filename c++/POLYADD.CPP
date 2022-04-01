/*poly addi*/
#include<iostream>
#include<stdlib.h>

using namespace std;
struct pol
	{ int coe;
	  int exp;
	};
typedef struct pol poly;
void polyread(poly p1[10],int n);
 int polyadd(poly p1[10],poly p2[10],poly psum[15], int m, int n);
void polydisp(poly p1[10],int n);

int main()
  {
   int i,j,m,n,sm;
   poly p1[10],p2[10],psum[15];
   cout<<" Enter the number of terms in the first polynomial"<<endl;
   cin>>m;
   cout<<" Enter the terms as coeficient & Exponent"<<endl;
   polyread(p1,m);
   cout<<"Enter the number of terms in the second polynomial"<<endl;
   cin>>n;
   cout<<"Enter the terms"<<endl;
   polyread(p2,n);
   sm=polyadd(p1,p2,psum,m,n);
   cout<<"The first polynomial is"<<endl;
   polydisp(p1,m);
   cout<<"The second polynomial is"<<endl;
   polydisp(p2,n);
   cout<<"The sum polynomial is"<<endl;
   polydisp(psum,sm);
   return 0;
  }
  void polyread(poly p1[10], int n)
    {
     for(int i=0;i<n;++i)
     cin>>p1[i].coe>>p1[i].exp;
    }
  polyadd(poly p1[10], poly p2[10], poly p3[15], int m, int n)
    {
     int i=0,j=0,k=0;
     while((i<m)&&(j<n))
      {
       if(p1[i].exp>p2[j].exp)
	 {
	  p3[k].coe=p1[i].coe;
	  p3[k].exp=p1[i].exp;
	  ++i;++k;
	 }
      else if(p1[i].exp<p2[j].exp)
	 {
	  p3[k].coe=p2[j].coe;
	  p3[k].exp=p2[j].exp;
	  ++j;++k;
	 }
       else
	 {
	  p3[k].coe=p1[i].coe+p2[j].coe;
	  p3[k].exp=p2[j].exp;
	  ++i;++j;++k;
	 }
      }
    if(i<m)
      while(i<m)
       {
	  p3[k].coe=p1[i].coe;
	  p3[k].exp=p1[i].exp;
	  ++i;++k;
	 }
     else
       while(j<n)
	{
	  p3[k].coe=p2[j].coe;
	  p3[k].exp=p2[j].exp;
	  ++j;++k;
	 }
    return(k);
   }
  void polydisp(poly p[10],int m)

    {
     for(int i=0;i<m;++i)
      cout<<p[i].coe<<"^"<<p[i].exp<<" ";
    }

