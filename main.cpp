#include <iostream>
using namespace std;

class BinarySearch{
public:

    int sortedArray[10];

    // Essential variables for binary search
    int low = 0;
    int high = 9;
    int mid = (low + high) / 2;

    // Variable for insertion sort
    int key;

    // Constructor for insertion sort
    // Takes an unsorted array at the time of object creation and sorts it using insertionSort
    BinarySearch(int arr[10]){
        for(int i = 1; i < 10; i++){
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }

        for(int i = 0; i < 10; i++){
            sortedArray[i] = arr[i];
        }
    }

    // Prints the sorted array
    void printArray(){
        cout << "{ ";
        for(int i = 0; i < 10; i++){
            cout << sortedArray[i] << ", ";
        }
        cout << "}\n";
    }

    // Searches for a value and prints the index number of the sorted array
    void binarySearch(int searchValue){
        bool flag = 0;
        while(low <= high){

            if(sortedArray[mid] == searchValue){
                cout << "index number of the value you are looking for is " << mid;
                flag = 1;
                break;
            }

            else if(sortedArray[mid] < searchValue){
                low = mid + 1;
                mid = (low + high) / 2;
            }

            else{
                high = mid - 1;
                mid = (low + high) / 2;
            }
        }
        if(flag == 0){
            cout << "The value you are looking for is not exist";
        }
    }

};

int main()
{
    // Essential variables for binarySearch
    int unsortedArray[10];
    int len = sizeof(unsortedArray)/sizeof(unsortedArray[0]); // Calculate and store the length of the array
    int lookingFor;

    // User input for unsorted array
    for(int i = 0; i < len; i++){
        cin >> unsortedArray[i];
    }

    // Create an object for BinarySearch class
    BinarySearch obj(unsortedArray);


    cout << "The array after insertionSort\n";
    obj.printArray(); // Call the printArray method

    cout << "Give the value you are looking for = ";
    cin >> lookingFor;

    obj.binarySearch(lookingFor); // Call the binarySearch method

    return 0;
}
