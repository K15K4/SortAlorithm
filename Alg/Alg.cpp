#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

static void GnomeSort(int* data, int count) {
    for (int i = 1; i < count; ) {
        if (data[i - 1] <= data[i])
            ++i;
        else {
            int tmp = data[i];
            data[i] = data[i - 1];
            data[i - 1] = tmp;
            --i;
            if (i == 0)
                i = 1;
        }
    }
}


// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;

        // Compare all elements with current gap
        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}

void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;

        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted.
        if (!swapped)
            break;

        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}



int main()
{
    srand(time(NULL));

    int qua = 100000;
    int* alg_array = new int[qua];
    for (int i = 0; i < qua; i++)
    {
        alg_array[i] = rand();
    }
    auto start = chrono::steady_clock::now();
    GnomeSort(alg_array, qua);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    for (int i = 0; i < 50; i++)
    {
        cout << alg_array[i] << "    ";
    }
    delete[] alg_array;
}
