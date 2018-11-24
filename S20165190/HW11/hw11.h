/*
 * functioncall.h
 *
 *  Created on: 2018. 11. 18.
 *      Author: han
 */

#ifndef HW11_H_
#define HW11_H_


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class LA {
	private:
		int size;
		double *arr;

	public:
		LA(int N){
			arr = new double[N*N];
			for (int i = 0; i < N; i++) for(int j = 0; j < N; j++) *(arr+N*i+j) = 0;
			size = N;
		}

		int operator= (LA B);
		int operator= (double* B);
		void setMat(int x, int y, double phi);
		double* getP(void);
		double getMat(int x, int y);
		double getSize(void);
		LA operator- ();
		LA operator- (LA &B);
		LA operator+ (LA &B);
		double& operator() (int x, int y);
		double* operator/ (double *vector);

};


#endif /* HW11_H_ */
