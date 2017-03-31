#include <iostream>       // std::cout
#include <thread>         // std::thread
 
using namespace std;

void foo() {
    thread :: id my_id = this_thread :: get_id();
    cout << "ID :" << my_id;
}

void bar() {
    thread :: id my_id = this_thread :: get_id();
    cout << "ID :" << my_id;
   
}
int main() {
    thread first (foo);          // spawn new thread that calls foo()
    thread second (bar);         // spawn new thread that calls bar(0)
    std::cout << "main, foo and bar now execute concurrently...\n";
   // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes
    std::cout << "foo and bar completed.\n";
    return 0;
}
