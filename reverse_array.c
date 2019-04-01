
int main() {
	
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
	    int n,temp,j;
	     scanf("%d",&n);
	    int a[n];
	    
	    for(int i=0;i<n; i++)
	        scanf("%d",&a[i]);
	   j=n-1;
	    for(int i=0; i<n;i++)
	        {
	                if(i>=j)
	                    break;
	            temp=a[i];
	            a[i]=a[j];
	            a[j]=temp;
	            j--;
	        }
	    
	    for(int i=0; i<n; i++)
	        printf("%d ", a[i]);
	    printf("\n");
	  }
	
	return 0;
}
