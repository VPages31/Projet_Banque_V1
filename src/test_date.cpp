#include "date.h"

main()
{
CLEAR;
	Date D(22,02,2016);
	Date D1(23,02,2016);
	Date D2(22,03,2016);
	Date D3(22,02,2017);
	Date D4(21,02,2016);
	Date D5(22,01,2016);
	Date D6(22,02,2015);
	Date D7(22,02,2016);

	if (D < D1)
		cout << "true" << endl;
	else 
		cout << "false"<< endl;
	if (D < D2)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
	if (D < D3)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
	if (D < D4)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
	if (D < D5)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
	if (D < D6)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
	if (D < D7)
		cout << "true"<< endl;
	else 
		cout << "false"<< endl;
CLEAR;
}
