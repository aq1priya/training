#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <string.h>
#include <unistd.h>
#include <mutex>

using namespace std;

string s = "";

void producer(string mystr) {
    thread :: id my_id = this_thread :: get_id();
    cout << "producer: " << my_id << ": started" << endl;
    sleep(1);
    cout << "producer: " << my_id << ": " << mystr << endl;
    s = mystr;
}

void consumer() {
    thread :: id my_id = this_thread :: get_id();
    cout << "consumer: " << my_id << ": started " << endl;
    while (s == "") sleep(1);
    cout << "consumer: " << my_id << ": " << s << endl;
}

int main() {
    string mystr;
    cout << "Enter the input string: ";
    cin >> mystr;    

    thread t1(producer, mystr);          
    thread t2(consumer);         
   
    t1.join();                
    t2.join();               
    return 0;
}

