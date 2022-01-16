#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

float real_vals[11];

void questions(){
	for(int i=0; i<11; i++){
		cout << "Please Insert the Y Value for X = " << i << ": " << endl;
		cin >> real_vals[i];
	}
}

float  return_reg_equation_vals(float m, float b, float reg_vals[11], int iVal){
	for(int i = 0; i<11; i++){
		reg_vals[i] = (m * i) + b;
	}
	return reg_vals[iVal];
}

void findEquationDriver(float learning_rate){
	float m_coefficient = 0;
	float b_coefficient = 0;
	float reg_vals[11];
	float errorVal = 0;
	for(int i = 0; i<11; i++){
		float regRunner = return_reg_equation_vals(m_coefficient, b_coefficient, reg_vals, i);
		cout <<  regRunner << endl;
		reg_vals[i] = regRunner;
		errorVal = ((reg_vals[i]-real_vals[i])*(reg_vals[i]-real_vals[i])) + errorVal;
		cout << errorVal << endl;
	}
}

int main(){
	questions();
	findEquationDriver(0.5);
	return 0;
}