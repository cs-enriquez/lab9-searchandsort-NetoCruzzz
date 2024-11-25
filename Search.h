#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> 
void printArray(flexibleType arr[],int size) {
    if (size <= 0)
        return;
    else
        cout << arr[0] << " ";
    printArray(arr + 1, size - 1);
}


// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end) {
    
    if (arr[start] == target)
        return arr[start] == target;
    else if (start >= end)
        return false;
    else
        return seqSearch(target, arr, start + 1, end);
}


// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {
    int left = 0; int mid;
    int right = n - 1;
    int pos = -1;
    bool found = false;
    while(!found&&left<=right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            pos = mid;
            found = true;
        }
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return found;
}



// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base case
    if(n<=0)
return false;
else if(n==1){return charray[0] == target || charray[1] == target;}
else if(charray[n]==target)
return true;
    //general case
else{ if(charray[n]<target)
charray+=(n/2);}
   return binSearchR(target,charray,n/2);
}


// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int x, int y) {
    double z = darray[x];
    darray[x] = darray[y];
    darray[y] = z;
}

int minFind(double darray[], int size, int currentIndex = 0, int minIndex = 0) {
    if (currentIndex == size) {
        return minIndex;
    }
    if (darray[currentIndex] < darray[minIndex]) {
        minIndex = currentIndex;
    }
    return minFind(darray, size, currentIndex + 1, minIndex);
}


void newSort(double darray[], int n) {
    if(n<=0)
return;
swap(darray,minFind(darray,n),0);
newSort(darray+1,n-1);
}
