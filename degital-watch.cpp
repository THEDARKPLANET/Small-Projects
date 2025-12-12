#include <iostream> // to use cin and cout 
#include <cstdlib>  //this lib in windows called <windows.h> to use system function
#include <unistd.h> // incuding sleep function in Linux
using namespace std; // needen't to wtite std::string , std::cout , etc.

int main()
{
    //variabls
    int hours=0;
    int minits=0;
    int secend=0;

    // take input from user 
    cout << "Hours : ";
    cin >> hours;
    cout << "Minits : ";
    cin >> minits;
    cout << "Secends : ";
    cin >> secend;

    while(true)
    {
        // set minits counter
        if(secend>59)
        {
            minits++;
            secend = 0;
        }
        // set hours counter
        if(minits>59)
        {
            hours++;
            minits = 0;
        }
        // set day counter
        if(hours>23)
        {
            hours = 0;
        }
        cout << hours << ":" << minits << ":" << secend << endl; // show watch
        // increase secend to set the watch 
        secend++;
        sleep(1); // sleep function in windows with capital s Sleep()
        system("clear");  // on windows system("cls");
    }
}
