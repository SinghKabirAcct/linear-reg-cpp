#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

double real_vals[11];
double learnRate;
double accuracyVar;

void questions(){
	for(int i=0; i<11; i++){
		cout << "Please Insert the Y Value for X = " << i << ": " << endl;
		cin >> real_vals[i];
	}
	cout << "What learning rate do you want to apply? (reccommended around 0.01-0.1)" << endl;
	cin >> learnRate;
	cout << "What level of accuracy? (Range: 1-inf, reccommended above 20, lower is better)" << endl;
	cin >> (accuracyVar);
	accuracyVar = accuracyVar/100000000;

}

double  return_reg_equation_vals(double m, double b, double reg_vals[11], int iVal){
	for(int i = 0; i<11; i++){
		reg_vals[i] = (m * i) + b;
	}
	return reg_vals[iVal];
}

double m_coefficient = 0;
double b_coefficient = 0;
double errorPrevM = numeric_limits<double>::infinity();
double errorPrevB = numeric_limits<double>::infinity();
double prevm = 0;
double prevb = 0;

void findEquationDriver(double learning_rate, double accVar){
	double reg_vals[11];
	double errorValM = 0;
	double errorValB = 0;
	for(int i = 0; i<11; i++){
		double regRunner = return_reg_equation_vals(m_coefficient, b_coefficient, reg_vals, i);
		reg_vals[i] = regRunner;
	}
	for(int i = 0; i<11; i++){
		errorValM = ((reg_vals[i]-real_vals[i])*i) + errorValM;
		errorValB = ((reg_vals[i]-real_vals[i])) + errorValB;
	}
	if((abs(errorValB)>accVar) || (abs(errorValM)>accVar)){
		if((abs(errorValM)<=abs(errorPrevM)) && abs(errorValM)>accVar){
			m_coefficient = m_coefficient - (errorValM * (1.00/11.00) * learning_rate);
		}
		if((abs(errorValB)<=abs(errorPrevB)) && abs(errorValB)>accVar){
			b_coefficient = b_coefficient - (errorValB * (1.00/11.00) * learning_rate);
		}
		errorPrevM = errorValM;
		errorPrevB = errorValB;
		prevm = m_coefficient;
		prevb = b_coefficient;
		findEquationDriver(learnRate, accVar);
	}
	else{
		cout << prevm << "x + " << b_coefficient << endl;
	}
}

int main(){
	questions();
	findEquationDriver(learnRate, accuracyVar);
	return 0;
}