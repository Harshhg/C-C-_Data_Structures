#include <stdio.h>
int main() {
	int tc; //number of test cases
	scanf("%d",&tc); //inputing test cases
	while(tc--)
	{
	    int n; //number of arrays elements
	    scanf("%d",&n); //inputting array elements
	    int d; //number of times to rotate the array;
	    scanf("%d",&d);
	    int ar[n],temp;
	    for(int i=0;i<n; i++)
	        scanf("%d",&ar[i]);
	    int b[n];
	    //Actual login begins..
	    for(int i=0;i<n;i++)
	       {
	           if(d>=n)
	           	 d-=n; 
	            b[i]=ar[d++];
	         }
	    // Logic ends...
	for(int i=0; i<n;i++)
	    printf("%d ",b[i]);
    printf("\n");
	}
	return 0;
}
