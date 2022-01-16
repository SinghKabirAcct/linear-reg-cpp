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

float m_coefficient = 0;
float b_coefficient = 0;
float errorPrev = numeric_limits<float>::infinity();

void findEquationDriver(float learning_rate){
	float reg_vals[11];
	float errorVal = 0;
	for(int i = 0; i<11; i++){
		float regRunner = return_reg_equation_vals(m_coefficient, b_coefficient, reg_vals, i);
		cout <<  regRunner << endl;
		reg_vals[i] = regRunner;
	}
	for(int i = 0; i<11; i++){
		errorVal = (reg_vals[i]-real_vals[i]) + errorVal;
		cout << errorVal << endl;
	}
	m_coefficient = m_coefficient - (errorVal * (1/11) * learning_rate);
	if(errorPrev != 0){
		cout << m_coefficient << endl;
	}
	else{
		cout << m_coefficient << "x + " << b_coefficient << endl;
	}
}

int main(){
	questions();
	findEquationDriver(0.5);
	return 0;
}