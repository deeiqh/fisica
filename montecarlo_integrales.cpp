#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

	using namespace std;

	// user defined function below
	float f(float x, float y) {
		return pow(x,2) + pow(y, 2);
	}

	int main() {
		int count = 0;
		float total = 0, inBox = 0;

		fstream arch;
		arch.open("d_dentro.txt", fstream::out);
		fstream arch2;
		arch2.open("d_fuera.txt", fstream::out);

		float xmin = 0, xmax = 1, ymin = 0, ymax = 1, zmin = 0, zmax=2;

		for (count = 0; count < 100000; count++) {
			float u1 = (float)rand() / (float)RAND_MAX;
			float u2 = (float)rand() / (float)RAND_MAX;
			float u3 = ((float)rand() / (float)RAND_MAX)*2;

			float xcoord = ((xmax - xmin)*u1) + xmin;
			float ycoord = ((ymax - ymin)*u2) + ymin;
			float zcoord =u3;
			float val = f(xcoord, ycoord);

			total++;

			if (zcoord <= val) {
				arch << xcoord << "\t" << ycoord << '\t' << zcoord << '\n';
				inBox++;
			}
			else {
				arch2 << xcoord << "\t" << ycoord << '\t' << zcoord << '\n';
			}
		}

		float density = inBox / total;

		arch.close();
		arch2.close();

		cout <<density << '\n';

		return 0;
	}


