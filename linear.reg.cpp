#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class holder{

  public:

    int vals[125] = {};
		int error[125] = {};

    void executeEquation(int t1[], int t1x[], int extent, int real[]){

      for(int i = 0; i<extent; i++){
        for(int j = 0; j<5; j++){
          int tempval = 0;
          tempval = t1[i] + t1x[i]*j;
          vals[(i*5)+j] = tempval;
					error[(i*5) + j] = vals[(i*5)+j] - real[j];
					error[(i*5) + j] = error[(i*5) + j] * error[(i*5) + j];
        }
      }

    }

};

int main(){

  int equations_t1[25] = {};
  int equations_t1x[25] = {};
  int counter = 0;

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      equations_t1[counter] = i;
      equations_t1x[counter] = j;
			counter++;
    }
  }

  for(int i=0; i<25; i++){
    cout << to_string(equations_t1[i]) + ", ";
    cout << to_string(equations_t1x[i]) + "\n";
  }

  int realVals[5] = {};
	int error[25] = {};

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

	holder holder;
	holder.executeEquation(equations_t1, equations_t1x, 25, realVals);

  for(int i=0; i<125; i = i + 5){
    holder.error[i] = holder.error[i] + holder.error[i + 1] + holder.error[i + 2] + holder.error[i + 3] + holder.error[i + 4];
		error[i/5] = holder.error[i];
	}

	for(int i=0; i<125; i++){
    cout << "value (" << i % 5 << ", "  << holder.vals[i] << ")" << endl;
  }
	for(int i=0; i<25; i++){
    cout << error[i] << endl;
	}
	int min = error[0];
	int minPos = 0;
	
	for(int i = 0; i<25; i++){
    if(error[i] < min){
      min = error[i];
			minPos = i;
		}
	}

	cout << min << " at index " << minPos << " of errorList is the lowest error:" << endl;

  cout << equations_t1[minPos] << "x + " << equations_t1x[minPos] << endl;

  return 0;

}
