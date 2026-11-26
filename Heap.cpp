
#include <iostream>
using namespace std;

int heap[100];
int n = 0;

// Insert element
void insert(int value) {
    n++;
    int i = n;
    heap[i] = value;

    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// Delete root element
void deleteRoot() {
    if (n == 0) {
        cout << "Heap is empty\n";
        return;
    }

    heap[1] = heap[n];
    n--;

    int i = 1;

    while (2 * i <= n) {
        int largest = 2 * i;

        if (largest + 1 <= n &&
            heap[largest + 1] > heap[largest]) {
            largest++;
        }

        if (heap[i] < heap[largest]) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

// Display heap
void display() {
    cout << "Heap elements: ";
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }
    } while (choice != 4);

    return 0;
}
