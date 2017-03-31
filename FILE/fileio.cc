#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file;
	ofstream file1;
	
	file.open("a.txt");
	file1.open("b.txt");	

	while(!file.eof()) {
	char k = file.get();
	file1 << k;
	}
			
	file1.close();
	file.close();
	return 0;
}

