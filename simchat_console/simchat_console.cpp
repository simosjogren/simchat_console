// simchat_console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Connection.h"
#include <ctime>

using namespace std;

string getDatafromUser(string description) {
    string to_return;
    cout << description << ": ";
    getline(cin, to_return);
    return to_return;
}

void Refresher() {
    // So function understands what a second means.
    using namespace literals::chrono_literals;
    while (true) {
        // Toiminta
        this_thread::sleep_for(1s);   
    }
}

int main()
{
    std::cout << "Hello World!\n";
    string ip = getDatafromUser("IP");
    string port = getDatafromUser("Port");
    string username = getDatafromUser("Username");

    system("CLS");

    Connection current_connection(ip, port, username);
    current_connection.ConnectIP();
    
    // Lets create the updater thread.
    thread updater(Refresher);
    

    updater.join();


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
