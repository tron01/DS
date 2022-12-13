#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void un_ion(char * ,char * ,char *);
void inter(char * ,char * ,char *);
void diff(char * ,char * ,char *);

void main(){

char s1[20],s2[20],s3[20];
printf("Enter the first string:");
scanf("%s",s1);
printf("\nEnter the second string:");
scanf("%s",s2);

un_ion(s1,s2,s3);

printf("\nUnion is:%s",s3);

inter(s1,s2,s3);
printf("\ninter :%s",s3);

diff(s1,s2,s3);
printf("\ndiff is:%s",s3);
printf("\n");

}

void un_ion(char * s1 ,char * s2 ,char * s3){
int i,l;
l=strlen(s1);
for(i=0;i<l;i++){
  if(s1[i]=='0' && s2[i]=='0'){
      
      s3[i]='0';
    
   }else{
       s3[i]='1';
        }

 }
 
 s3[i]='\0';

}

void inter(char * s1,char *s2 ,char *s3)
{
int i,l;
l=strlen(s1);
for(i=0;i<l;i++){
  if(s1[i]=='1' && s2[i]=='1'){
      
      s3[i]='1';
    
   }else{
       s3[i]='0';
        }

 }
 
 s3[i]='\0';

}

void diff(char * s1,char *s2 ,char *s3){

int i,l;
l=strlen(s1);
for(i=0;i<l;i++){
  if(s1[i]=='1' && s2[i]=='0'){
      
      s3[i]='1';
    
   }else{
       s3[i]='0';
        }

 }
 
 s3[i]='\0';
}

