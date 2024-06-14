// number guessing game
#include<iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

int main()
{
    int number,guess,nguesses=1;

    srand(time(0));
    number=rand();
  
    do
    {
        cout<<"guess the number\n";
        cin>>guess;
        if (number > guess)
        {
            cout<<"The number you've guessed is low, the actual number is higher than this!!\n";
        }
        else if (number < guess)
        {
            cout<<"The number you've guessed is high, the actual number is lower than this!!\n";
        }
        else 
        {
            cout<<"you guessed it right in "<<nguesses<<" attempt";
            if (nguesses !=1){
                cout<<"s\n";
            }
        }
        nguesses++;
    } while (number != guess);
    return 0;
}