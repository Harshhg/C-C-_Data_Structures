#include <stdio.h>

int main() {
	//code

	int tc; //number of test cases
	scanf("%d",&tc); //inputing test cases
	while(tc--)
	{
	    int n; //number of arrays elements
	    scanf("%d",&n); //inputting array elements
	    int ar[n],temp;
	    for(int i=0;i<n; i++)
	        scanf("%d",&ar[i]);
	    int d; //number of times to rotate the array;
	    scanf("%d",&d);
	    while(d--)
	    {
	        int i=0;
	        temp= ar[i];
	        for(i=0;i<n-1;i++)
	        {
	           ar[i]=ar[i+1];
	        }
	        ar[i]=temp;
	    }

	
	for(int i=0; i<n;i++)
	    printf("%d ",ar[i]);
	 printf("\n");
	}
	
	
	return 0;
}
