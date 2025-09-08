#include<iostream>
#include<ctime>
using namespace std;

int main()
{
  int guess;
  int gussing=5;
  int num;
  srand(time(0));
  guess=rand()%10;

  printf("Try to Gussing number from [0,9]\n");

  for(int i=0;i<gussing;i++)
  {
    cout << "Gussing " << i+1 << " : " << endl;
    cin >> num;
    if(guess > num)
    {
      cout << "too low\n";
    }else if(guess < num)
    {
      cout << "too high\n";
    }else{
      cout << "True\n";
      i=gussing;
    }
  }
}
