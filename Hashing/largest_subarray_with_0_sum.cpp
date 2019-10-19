#include <iostream>
using namespace std;

int subarray(int ar[], int len)
{
int maxlen=0;
int cursum=0;
int hash[100000];
// Initializing the hash array with -1
for(int i =0; i< 100000; i++)
    hash[i]=-1;
    
for(int i= 0; i<len; i++)
{
        cursum+=ar[i];
    
        if (cursum==0)
            maxlen=i+1;
        
        if(hash[cursum]> -1)  // If cursum is present is hash array
        {
            int l = (i-hash[cursum]);
            if (l>maxlen)
                maxlen=l;
        }
        else
           hash[cursum]=i;
}
return maxlen;
}

int main()
{
  int ar[]={15,-2,2,-8,1,7,10,23};
  int len = sizeof(ar)/sizeof(ar[0]);
  int res=subarray(ar,len);
  if(res)
    cout<<"Maximum length subarray with 0 sum is : "<<res;
  else
  cout<<"No such array found";

}
