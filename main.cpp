#include <iostream>
using namespace std;

// function to print array
void print_array(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int get_max_element(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// function to counting sort
// digit is represented by exp
void counting_sort(int array[], int size, int exp) {
    int output[size];
    int i, count[10] = {0};

    // store count of occurrence
    for (i = 0; i < size; ++i) {
        count[(array[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0 ; --i) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; ++i) {
        array[i] = output[i];
    }
}

// function to sort array by radix sort algorithm
void radix_sort(int array[], int size) {
    int max = get_max_element(array, size);

    // counting sort for every digit
    for (int exp = 1; max/exp > 0; exp *= 10) {
        counting_sort(array, size, exp);
    }
}

int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Given array: ";
    print_array(array, size);

    radix_sort(array, size);

    cout << "Sorted array: ";
    print_array(array, size);

    return 0;
}
