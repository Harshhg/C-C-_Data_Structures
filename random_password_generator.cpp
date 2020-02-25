#include <iostream>
#include<cstdlib>
using namespace std;

int main() 
{
    int length = 20;
    string pass="";
    srand(time(0));
    for(int i=0; i<length; i++)
    {
        int lower = 1;
        int upper = 3;
        // 1 - number , 2 - alphabets small,  3 - alphabets Large
        int set = (rand() % (upper - lower + 1)) + lower;  
        
        if(set==1)  //choose random number
        {
            int l_num = 1;
            int u_num = 9;
            int temp_num = (rand() % (u_num - l_num + 1)) + l_num;
            pass+=to_string(temp_num);
        }
        else if(set==2) //choose random alphabet small
        {
            int l_alpha = 97;
            int u_alpha = 122;
            int temp_alpha = (rand() % (u_alpha - l_alpha + 1)) + l_alpha;
            char c = temp_alpha;
            pass+=c;
        }
        else  //choose random alphabet Large
        {
            int l_alpha = 65;
            int u_alpha = 90;
            int temp_alpha = (rand() % (u_alpha - l_alpha + 1)) + l_alpha;
            char c = temp_alpha;
            pass+=c;
        }
    }
    cout<<pass;
	return 0;
}
