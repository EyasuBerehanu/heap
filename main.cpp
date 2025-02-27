#include <iostream>
#include <fstream>  
#include <bits/stdc++.h>

using namespace std;

void heap(int num[], int& size, int value);
void print(int num[], int size, int index, int level);
void filess();

void heap(int num[], int& size, int value) //change this or change the other one
{
    num[size] = value;
    size++;

    int i = size - 1;
    while (i != 0 && num[(i - 1) / 2] < num[i]) {
        swap(num[i], num[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void print(int num[], int size, int index, int level) //https://www.youtube.com/watch?v=xhkSiIeTKQo
{
    if (index >= size) {
        return;
    }

    print(num, size, 2 * index + 2, level + 1);
    cout << string(level * 4, ' ') << num[index] << endl;
    print(num, size, 2 * index + 1, level + 1);
}

void filess() {
    
}

int main()
{
    int num[100];  
    int size = 0;  

    cout << "Choose method:" << endl;
    cout << "1 for files" << endl;
    cout << "2 for input" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        
    } else if (choice == 2) {
        cout << "Enter Numbers Here" << endl;
        while (true) {
            int value;
            if (cin >> value) {
                heap(num, size, value);  

                for (int i = size / 2 - 1; i >= 0; --i) {
                    int largest = i; 
                    int left = 2 * i + 1; 
                    int right = 2 * i + 2;

                    if (left < size && num[left] > num[largest]) {
                        largest = left;
                    }
                    if (right < size && num[right] > num[largest]) {
                        largest = right;
                    }

                    if (largest != i) {
                        swap(num[i], num[largest]);
                    }
                }

                cout << "---------------------------------" << endl;
                print(num, size, 0, 0);  
            } else {
                break; 
            }
        }
    } else {
        return 0;  
    }

    cout << endl;
    print(num, size, 0, 0);  

    return 0;
}
