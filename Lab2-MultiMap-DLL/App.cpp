#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"

using namespace std;


int main() {


	testAll();
    cout << "Shorts ok!" << endl;
	testAllExtended();
	cout << "Extended ok!" << endl;
	system("pause");

}
