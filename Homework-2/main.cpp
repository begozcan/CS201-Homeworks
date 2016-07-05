#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

int maximum( int a, int b, int c )
{
    int max = ( a < b ) ? b : a;
    return ( ( max < c ) ? c : max );
}

int cubicAlgo(int*& a, int size) {
    int maxSum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int thisSum = 0;

            for (int k = i; k <= j; k++) {
                thisSum += a[k];
            }

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int quadAlgo(int*& a, int size) {
    int maxSum = 0;

    for(int i = 0; i < size; i++) {
        int thisSum = 0;
        for(int j = i; j < size; j++) {
            thisSum += a[j];

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int recursiveAlgo(int*& a, int left, int right) {
    if (left == right) {
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    }

    int center = (left + right) / 2;
    int maxLeftSum = recursiveAlgo(a, left, center);
    int maxRightSum = recursiveAlgo(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return maximum(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int linAlgo(int*& a, int size) {
    int maxSum = 0, thisSum = 0;

    for (int i = 0; i < size; i++) {
        thisSum += a[i];

        if(thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }

    return maxSum;
}

int main() {
    int* a = new int[(int)(pow(2,30))];

   // Testing first algorithm with sizes varying from 1 to 8,192
   double duration1[14] = {0};

   cout << "Start testing the cubic algorithm" << endl;

   for (int i = 0; i < 14; i++) {
       // Record times for various sizes
       double duration;
       clock_t startTime = clock();
       cubicAlgo(a, (int)(pow(2,i)));
       duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
       duration1[i] = duration;
       cout << "Execution took " << duration << " milliseconds." << endl;
   }
   // Print out the stored durations
   cout << "duration1 = [ ";
   for (int j = 0; j < 14; j++) {
       cout << duration1[j] << " ";
   }
   cout << "];" << endl;

   cout << "End testing the cubic algorithm" << endl;

   // Testing second algorithm with sizes varying from 1 to 524,288
   double duration2[20] = {0};

   cout << "Start testing the quaratic algorithm" << endl;

   for (int k = 0; k < 20; k++) {
       // Record times for various sizes
       double duration;
       clock_t startTime = clock();
       quadAlgo(a, (int)(pow(2,k)));
       duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
       duration2[k] = duration;
       cout << "Execution took " << duration << " milliseconds." << endl;
   }
   // Print out the stored durations
   cout << "duration2 = [ ";
   for (int l = 0; l < 20; l++) {
       cout << duration2[l] << " ";
   }
   cout << "];" << endl;

   cout << "End testing the quadratic algorithm" << endl;

   // Testing third algorithm with sizes varying from 1 to 536,870,912
   double duration3[30] = {0};

   cout << "Start testing the recursive algorithm" << endl;

   for (int m = 0; m < 30; m++) {
       // Record times for various sizes
       double duration;
       clock_t startTime = clock();
       recursiveAlgo(a, 0, ((int) pow(2, m)) - 1);
       duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
       duration3[m] = duration;
       cout << "Execution took " << duration << " milliseconds." << endl;
   }
   // Print out the stored durations
   cout << "duration3 = [ ";
   for (int n = 0; n < 30; n++) {
       cout << duration3[n] << " ";
   }
   cout << "];" << endl;

   cout << "End testing the recursive algorithm" << endl;


    // Testing fourth algorithm with sizes varying from 1 to 1,073,741,824
    double duration4[31] = {0};

    cout << "Start testing the linear algorithm" << endl;

    for (int p = 0; p < 31; p++) {
        // Record times for various sizes
        double duration;
        clock_t startTime = clock();
        linAlgo(a, (int) pow(2, p));
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        duration4[p] = duration;
        cout << "Execution took " << duration << " milliseconds." << endl;
    }
    // Print out the stored durations
    cout << "duration4 = [ ";

    for (int q = 0; q < 31; q++) {
        cout << duration4[q] << " ";
    }
    cout << "];" << endl;

    cout << "End testing the linear algorithm" << endl;

    return 0;
}