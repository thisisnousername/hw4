/*
author: markus
  date: 15-11-18
*/

#include <fstream>
#include <string>
//#include <iostream>

using namespace std;

void read(double* const p, const int N, const string fname){
	ifstream in(fname.c_str());
	for(int i=0; i<N; i++)
		in >> p[i];
	in.close();
}

void filter(double* const p, const int N){
	double a = p[N-1];
	double b;
	double c = p[0];

	for(int i=0; i<N-1; i++){
		b = p[i];
		p[i] = (a+b+p[i+1])/3;
		a=b;
	}
	p[N-1] = (p[N-1]+a+c)/3;
}

void write(const double* const p, const int N, const string nfname){
	ofstream out(nfname.c_str());
	for(int i=0; i<N; i++)
		out << p[i] << endl;
	out.close();
}

int main(){
	const int N = 237;
	const string fname = "noisy.txt";
	const string nfname = "filtered.txt";
	double* p = new double[N];

	read(p, N, fname);

	//for(int i=0; i<N; i++)
	//	cout << p[i] << endl;

	//for(int i=0; i<100; i++)
	filter(p, N);

	//for(int i=0; i<N; i++)
	//	cout << p[i] << " filtered" << endl;

	write(p, N, nfname);

	delete[] p;

	return 0;
}
