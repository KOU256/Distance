#include<iostream>
#include<cmath>
#include"distance.hpp"

using namespace std;

int main() {
	Distance dis;
	double logitude, latitude;

	for (int i = 0; i < 2; i++) {
		cout << i + 1 << "ñ?????????gx???ogx???H" << endl;
		cout << "??gx:";
		cin >> latitude;
		cout << "?ogx:";
		cin >> logitude;
		dis.getCoordinate(logitude, latitude, i);
	}

	cout << dis.calculateDistance() << "m" << endl;
	
	return 0;
}