#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

double real_vals[11];

void questions(){
	for(int i=0; i<11; i++){
		cout << "Please Insert the Y Value for X = " << i << ": " << endl;
		cin >> real_vals[i];
	}
}

double  return_reg_equation_vals(double m, double b, double reg_vals[11], int iVal){
	for(int i = 0; i<11; i++){
		reg_vals[i] = (m * i) + b;
	}
	return reg_vals[iVal];
}

double m_coefficient = 0;
double b_coefficient = 0;
double errorPrev = numeric_limits<double>::infinity();
double prevm = 0;

void findEquationDriver(double learning_rate){
	double reg_vals[11];
	double errorVal = 0;
	for(int i = 0; i<11; i++){
		double regRunner = return_reg_equation_vals(m_coefficient, b_coefficient, reg_vals, i);
		cout <<  regRunner << endl;
		reg_vals[i] = regRunner;
	}
	for(int i = 0; i<11; i++){
		errorVal = (reg_vals[i]-real_vals[i]) + errorVal;
		cout << errorVal << endl;
	}
	if((abs(errorVal)<=abs(errorPrev)) && abs(errorVal)>0.0001){
		m_coefficient = m_coefficient - (errorVal * (1.00/11.00) * learning_rate);
		cout << m_coefficient << endl;
		errorPrev = errorVal;
		prevm = m_coefficient;
		findEquationDriver(0.01);
	}
	else{
		cout << prevm << "x + " << b_coefficient << endl;
	}
}

int main(){
	questions();
	findEquationDriver(0.1);
	return 0;
}