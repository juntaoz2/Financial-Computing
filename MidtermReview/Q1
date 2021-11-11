#include <iostream>

using namespace std;

bool MySwapSum(int *ptr1, int *ptr2, int &result) {
    result = *ptr1 + *ptr2;
    if (*ptr1 != *ptr2) {
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        return true;}
    else
        
        return false;
}


int main(void) {
    int x1 = 1, y1 = 2, x2 = 3, y2 = 3;
    int result = 0;
    if (MySwapSum(&x1, &y1, result))
        cout << "x1 is not equal to y1,"<< " So swapped, the sum = " << result << endl;
    else
        cout << "x1 is equal to y1,"<< " No swap, the sum = " << result << endl;
    if (MySwapSum(&x2, &y2, result))
        cout << "x2 is not equal to y2,"<< " So swapped, the sum = " << result << endl;
    else
        cout << "x2 is equal to y2," << " No swap, the sum = " << result << endl;
    return 0;
}

/*
x1 is not equal to y1, So swapped, the sum = 3
x2 is equal to y2, No swap, the sum = 6
Press any key to continue . . .
*/
