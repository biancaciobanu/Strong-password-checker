#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
char s[50];

int strong_pass(char s[50])
{  int len_ver=0;
   int lower_ver=1;
   int upper_ver=1;
   int digit_ver=1;
   int changes=0,result=0,k=0;
   int rep[strlen(s)],i;


   // rep=array of repeating characters
   for(i=0;i<strlen(s)-1;i++)
   {if(s[i]==s[i+1])
        rep[i]=1;
        else rep[i]=0;
   }
  for(i=0;i<strlen(s)-1;i++)
    if(rep[i]==1)
    k++;
  if(k>=2)
    result=1;

   //check if we find any missing character
   for(i=0;i<strlen(s);i++)
   {
       if(islower(s[i]))
        lower_ver=0;
       if(isupper(s[i]))
        upper_ver=0;
       if(isdigit(s[i]))
        digit_ver=0;
   }
   changes=lower_ver+upper_ver+digit_ver; //minimum changes needed for the missing case

  // fixing the length problem
  if(strlen(s)<6)
  {
      if(6-(strlen(s)+changes)>0)
      result=6-strlen(s);
  }
  else if(strlen(s)>20)
    if(strlen(s)-20>0)
    result=strlen(s)-20;
  if(result==0)
   result=changes;
   // identical characters case
   // working on it...
  // int raw_ver=1;
   //for(i=0;i<strlen(s)-1;i++)
  // {if(s[i]==s[i+1])
    //    k++;
      //  else k=0;
        //if(k==2)
          // {raw_ver=0;
          // break;}
   //}
  return result;
}

int main()
{
    cout<<"Insert you password: ";
    cin.getline(s,25);
    if(strong_pass(s)==0)
        cout<<"0, strong password";
    else cout<<"The password requires "<<strong_pass<<" MINUMUM change(s)";
    return 0;
}
