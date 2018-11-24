/*
 * main.cpp
 *
 *  Created on: 2018. 11. 18.
 *      Author: han
 */

#include "hw11.h"
#include "const.cpp"

double* F_0(double& VD);
double* F_1(double* f0);

int main(int argc, char *argv[]){
	double *f0, *f1, VD = atof(argv[1]), Vi = 0;
	ofstream file_f0, file_f1;

	file_f0.open("f0.txt");
	file_f1.open("f1.txt");

	for(int i = 0; i < VN; i++){

		f0 = F_0(Vi);
		f1 = F_1(f0);

		for(int i=0; i<N; i++) file_f0 << (Length/(N-1))*i << ", " << Vi << ", " << f0[i] << endl;
		for(int i=0; i<N-1; i++) file_f1 << (Length/(N-1))*(i+0.5) << ", " << Vi << ", " << f1[i] << endl;

		Vi += VD / (VN-1);

	}
	file_f0.close();
	file_f1.close();

	return 0;

}

double* F_0(double& VD){
	LA s(N);
	double *V = new double[N];
	double *b = new double[N];

	double c1, c2;

	const double Vt = VD/(interface1 - interface2);
	const double fs = sqrt(2*pi)/(1+exp(q*H/(k_B*T)));
	const double fd = sqrt(2*pi)/(1+exp(q*(H+VD)/(k_B*T)));

	for(int i=0; i < N; i++)
		if(i<=interface1) V[i] = 0;
		else if(i > interface1 && i <= interface2) V[i] = (double)(i-interface1) * Vt;
		else V[i] = VD;

	for(int i=0; i < N; i++)
		if(i == 0 || i == N-1) s(i,i) = 1.0;
		else
		{
			c1 = H + 0.5*(V[i]+V[i-1]);
			c2 = H + 0.5*(V[i]+V[i+1]);
			s(i,i-1) = c1; s(i,i) = -c1-c2; s(i,i+1) = c2;
		}

	for(int i=0; i < N; i++)
		if(i == 0) b[i] = fs;
		else if(i == N-1) b[i] = fd;
		else b[i] = 0;

	return s/b;
}

double *F_1(double *f0){
	double *f1 = new double[N-1];
	for(int i = 0; i < N-1; i++) f1[i] = -(velocity_ave*tau*Gamma_011perC_1)/(Length/(N-1))*(f0[i+1]-f0[i]);
	return f1;
}



