#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30


int isSimilar(char w1[],int s1, char w2[], int s2)
{
 if(s2>s1+1 || s2<s1)
  return 0;
 for(int i=0; i<s1; i++){
     int ans=0;
    for(int j=0; j<s2; j++)
    {
      if(w2[j]-w1[i]==0)
       {
         ans=1;
         break;
       } 
    }
     if(ans==0)
        return 0; 
 }
 return 1;
}   

void optA(char line[], char word[]){
 if(strstr(line, word) != NULL)
  printf("%s",line);
}

void optB(char line[], char word[], int Wsize){
    char w[WORD];
 for(int i=0; i<strlen(line); i++){
    
  int j=0;
   while(line[i]!=' ' && line[i]!='\t' && line[i]!='\n' && line[i]!='\r')
  {
   w[j]=line[i];
   j++;
   i++;  
  }
  w[j]='\0';
 if(isSimilar(word,Wsize,w,strlen(w))==1)
  printf("%s\n", w);
 }
}

int main(){

char s[LINE];
char word[LINE];
char opt;
fgets(s, LINE , stdin);
//get the word and the opt
int i=0;
while(s[i]!=' ' && s[i]!='\t' && s[i]!='\n')
{
 word[i]=s[i];
 i++;
}
opt=s[i+1];
int Wsize=i;
//reading the file
switch(opt)
{
 case 'a':
 while(fgets(s, LINE , stdin))
  optA(s,word);
 break;

 case 'b':
 while(fgets(s, LINE , stdin))
  optB(s,word,Wsize);
 break; 
}
    return 0;
}