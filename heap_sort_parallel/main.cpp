// C++ program for implementation of Heap Sort

#pragma clang diagnostic push
#pragma ide diagnostic ignored "openmp-use-default-none"

#include <iostream>
#include <omp.h>

using namespace std;

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i)
{
    int largest = i;        // Initialize largest as root
    int l = 2*i + 1;        // left = 2*i + 1
    int r = 2*i + 2;        // right = 2*i + 2
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest);
    }
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end 
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap 
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
*/

// Driver program 
int main()
{

    // NORMAL COMPUTING

    double start_time = omp_get_wtime();
    int sizeOfArray = 1000000;
    int arr[sizeOfArray];
    srand((unsigned) time(0));
    int threadsNum = omp_get_num_threads();

    for (int i=0; i<sizeOfArray; i+=threadsNum) {
        arr[i] = (rand() % 100) + 1;
        // cout << arr[i] << endl;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    double end_time = omp_get_wtime();
    double calc_time = end_time - start_time;
    cout << "1) Calculation time for normal computing: " << calc_time << " seconds." << endl;



    // PARALLEL COMPUTING
    double start_time2 = omp_get_wtime();
    #pragma omp parallel
    {
        int sizeOfArray = 1000000;
        int arr[sizeOfArray];
        srand((unsigned) time(0));
        int threadsNum = omp_get_num_threads();

        for (int i=0; i<sizeOfArray; i+=threadsNum) {
            arr[i] = (rand() % 100) + 1;
            // cout << arr[i] << endl;
        }

        int n = sizeof(arr) / sizeof(arr[0]);
        heapSort(arr, n);
        //cout << "Sorted array is \n";
        //printArray(arr, n);
    }

    double end_time2 = omp_get_wtime();
    double calc_time2 = end_time2 - start_time2;
    cout << "2) Calculation time for parallel computing: " << calc_time2 << " seconds." << endl;

    double ratio = calc_time / calc_time2;

    cout << "3) Parallel computing is " << ratio << " times faster." << endl;








}
