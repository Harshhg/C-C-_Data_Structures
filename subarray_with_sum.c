#include <iostream>
using namespace std;

int main()
{
    int tc;
    int n;
    int s,i;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        cin>>s;
        int temp =0;
        int ar[n];
        int end=0;
        int flag=0;
        for(i=0; i<n; i++)
            cin>>ar[i];
        for(int i=0; i<n; i++)
        {
            temp=0;end=i;
            while(end<n)
                {
                    temp=temp+ar[end];
                    end++;
                    if(temp==s)
                        {flag=1;break;}
                    if(temp>s)
                        break;
                    if(end==n && temp!=s)
                        {flag=2;break;}
                }
            if(flag==1)
            {cout<<++i<<" "<<end<<"\n";i=n;}
            if(flag==2)
            {cout<<"-1";i=n; break;}
                    
        }
        
        
        
        
        
    }
	
	
	
	//code
	return 0;
}
