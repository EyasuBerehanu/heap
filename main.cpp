<<<<<<< HEAD
//https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
=======
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767
#include <iostream>
#include <fstream>  
#include <bits/stdc++.h>

using namespace std;

void heap(int num[], int& size, int value);
<<<<<<< HEAD
void print(int table[], int pos, int depth, int size);
void filess(int num[], int& size);

void heap(int num[], int& size, int value)
{
    num[size] = value;
    size++;
    int i = size - 1;
    
=======
void print(int num[], int size, int index, int level);
void filess();

void heap(int num[], int& size, int value) //change this or change the other one
{
    num[size] = value;
    size++;

    int i = size - 1;
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767
    while (i != 0 && num[(i - 1) / 2] < num[i]) {
        swap(num[i], num[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

<<<<<<< HEAD
void print(int table[], int pos, int depth, int size) {
    if (pos >= size){
       return; 
    } 

    if (pos * 2 + 1 < size) {
        print(table, pos * 2 + 1, depth + 1, size);
    }

    for (int a = 0; a < depth; a++) {
        cout << "   "; 
    }
    cout << table[pos] << endl;

    if (pos * 2 + 2 < size) { 
        print(table, pos * 2 + 2, depth + 1, size);
    }
}

void filess(int num[], int& size) {
    ifstream file("numbers.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }
    int value;
    while (file >> value) {
        if (value >= 1 && value <= 1000) {
            heap(num, size, value);
        }
    }
    file.close();
    cout << "File input complete." << endl;
=======
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
    
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767
}

int main()
{
    int num[100];  
    int size = 0;  
<<<<<<< HEAD
    int choice;
    
    cout << "Choose method:" << endl;
    cout << "1 for files" << endl;
    cout << "2 for input" << endl;
    
    cin >> choice;

    if (choice == 1) {
        filess(num, size);
=======

    cout << "Choose method:" << endl;
    cout << "1 for files" << endl;
    cout << "2 for input" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767
    } else if (choice == 2) {
        cout << "Enter Numbers Here" << endl;
        while (true) {
            int value;
<<<<<<< HEAD
            
            if (cin >> value) {
                heap(num, size, value);  
                cout << "---------------------------------" << endl;
                print(num, 0, 0, size);  
=======
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
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767
            } else {
                break; 
            }
        }
    } else {
        return 0;  
    }

    cout << endl;
<<<<<<< HEAD
    print(num, 0, 0, size);  
=======
    print(num, size, 0, 0);  
>>>>>>> 8bf66d7e636c6231a407db677889de5cd20d1767

    return 0;
}
