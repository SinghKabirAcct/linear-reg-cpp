#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class holder{

  public:

    float vals[1000] = {};
		float error[1000] = {};

    void executeEquation(float t1[], float t1x[], int extent, float real[]){

      for(int i = 0; i<extent; i++){
        for(int j = 0; j<10; j++){
          float tempval = 0;
          tempval = t1[i] + t1x[i]*j;
          vals[(i*10)+j] = tempval;
					error[(i*10) + j] = vals[(i*10)+j] - real[j];
					error[(i*10) + j] = error[(i*10) + j] * error[(i*10) + j];
        }
      }

    }

};

int main(){

  float equations_t1[100] = {};
  float equations_t1x[100] = {};
  int counter = 0;

  for(double i=0; i<5; i = i + 0.5){
    for(double j=0; j<5; j = j + 0.5){
      equations_t1[counter] = i;
      equations_t1x[counter] = j;
			counter++;
    }
  }

  float realVals[10] = {};
	int error[100] = {};

	cout << "Welcome to the Claire linear regression tool made with C++ by Kabir Singh!" << endl;
	cout << "Please Input the Y value for X = 0" << endl;
	cin >> realVals[0];
	cout << "Please Input the Y value for X = 1" << endl;
	cin >> realVals[1];
	cout << "Please Input the Y value for X = 2" << endl;
	cin >> realVals[2];
	cout << "Please Input the Y value for X = 3" << endl;
	cin >> realVals[3];
	cout << "Please Input the Y vale for X = 4" << endl;
	cin >> realVals[4];
  cout << "Please Input the Y value for X = 5" << endl;
  cin >> realVals[5];
  cout << "Please Input the Y value for X = 6" << endl;
  cin >> realVals[6];
  cout << "Please Inpute the Y value for X = 7" << endl;
	cin >> realVals[7];
  cout << "Please Input the Y value for X = 8" << endl;
	cin >> realVals[8];
	cout << "Please Input the Y value for X = 9" << endl;
	cin >> realVals[9];

	holder holder;
	holder.executeEquation(equations_t1, equations_t1x, 100, realVals);

  for(int i=0; i<1000; i = i + 10){
    holder.error[i] = holder.error[i] + holder.error[i + 1] + holder.error[i + 2] + holder.error[i + 3] + holder.error[i + 4] + holder.error[i + 5] + holder.error[i + 6]
		+ holder.error[i + 7] + holder.error[i + 8] + holder.error[i + 9];
		error[i/10] = holder.error[i];
	}

	int min = error[0];
	int minPos = 0;
	
	for(int i = 0; i<100; i++){
    if(error[i] < min){
      min = error[i];
			minPos = i;
		}
	}

	cout << min << " at index " << minPos << " of errorList is the lowest error:" << endl;

  cout << equations_t1[minPos] << "x + " << equations_t1x[minPos] << endl;
  return 0;

}
