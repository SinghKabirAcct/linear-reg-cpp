#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

float real_vals[10];

void questions(){
	for(int i=0; i<11; i++){
		cout << "Please Insert the Y Value for X = " << i << ": " << endl;
		cin >> real_vals[i];
	}
}


int main(){
	questions();
	return 0;
}