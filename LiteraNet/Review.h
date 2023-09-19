#include <iostream>
#include <string>
using namespace std;

class Review {
	string resumen;
public:
	Review(string resumen) { this->resumen = resumen; }
	Review(){}
	void getReview() {
		cout << resumen << endl;
	}
};