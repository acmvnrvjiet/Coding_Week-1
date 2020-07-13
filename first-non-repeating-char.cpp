/*Topic: Strings
https://practice.geeksforgeeks.org/problems/non-repeating-character/0

Solution:
Given a string, find the first non-repeating character in it.
For example, given string is "abcdabsc".
the first non-repeating character is 'd'.
The approach to the sol:
Let us first calculate the count of occurence of each charater in the string
'a'-2
'b'-2
'c'-2
'd'-1
's'-1
Though there are two characters which are non repeating, the first non-repeating charater in the string will be 'd'

We can create a count array to store the occurences of each charater.
Let the index of 'a' - 0, 'b' - 1, 'c' - 2 and so on..
The ASCII values of 'a' - 97, 'b' - 98, 'c' - 99 and so on..
Subtract the ASCII value of the charater with 97 to get the index.
For example, if the character is 'c' : the index value can be obtained by 99-97=3.(ASCII val of 'c' - ASCII val of 'a')
Traverse through the string. If the count of any character is 1, then break the loop and print the charcter.
*/

//cpp solution:
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s; cin>>s;
	int len=s.length();	
	int a[26]={0}; //Count array to store the occurences. Initialise the array to 0
	
	for(int i=0;i<len;i++)
	{
		a[s[i]-97]++;
		//To convert the character to its index value and increment the count of the occurence of character. 
	}
	int i=0;
	for(i=0;i<len;i++)
	{
		if(a[s[i]-'a']==1)
		{
			cout<<s[i];
			break;
		}
	} 

	if(i==len)
		cout<<-1;
}


//Solution given by: Shreya Pola
