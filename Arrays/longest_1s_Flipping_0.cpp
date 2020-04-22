/*
Given an array of 0s and 1s, find the length of longest sequence of 1s
we can get by flipping only single 0 to 1.
*/
#include <iostream>
using namespace std;

int main() 
{
    int ar[13] = {0,1,1,0,0,0,0,0,1,t1,1,1,0};
    int left_sum=0, right_sum=0, ans=0;
    int size = 13;
    for(int i=0; i<size; i++)
    {
        if(ar[i]==1)
            right_sum++;
        else
         {
             ans = max(left_sum+right_sum+1,   ans);
             left_sum = right_sum;
             right_sum = 0;
         }
    }
    if(right_sum)
        ans = max(left_sum+right_sum+1,   ans);
        
        
    cout<<ans;
}
