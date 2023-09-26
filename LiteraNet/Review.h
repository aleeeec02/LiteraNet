#pragma once
#include <iostream>
#include <string>
using namespace std;

class Review {
	string resumen;
public:
	Review(string resumen) { this->resumen = resumen; }
	Review(){}
	void  addReview(string resumen) {
		this->resumen = resumen;
	};
	string getReview() {
		return this->resumen;
	};
	void showReview() {
		cout << this->resumen<<endl;
	}
};