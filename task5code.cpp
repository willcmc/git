#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;

     cout << "Enter a positive number: ";                           //edit for first commit, adding comment #1
     cin >> num;

     n = num;                                                       //edit for the third commit, adding comment #3

     do
     {
         digit = num % 10;                                          //edit for the fifth commit, adding comment #5
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (n == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
