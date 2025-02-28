//https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps /
#include <iostream>
#include <fstream>  
#include <bits/stdc++.h>

using namespace std;

void heap(int num[], int& size, int value);
void print(int table[], int pos, int depth, int size);
void filess();

void heap(int num[], int& size, int value)
{
    num[size] = value;
    size++;
    int i = size - 1;
    
    while (i != 0 && num[(i - 1) / 2] < num[i]) {
        swap(num[i], num[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

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
}

int main()
{
    int num[100];  
    int size = 0;  
    int choice;
    
    cout << "Choose method:" << endl;
    cout << "1 for files" << endl;
    cout << "2 for input" << endl;
    
    cin >> choice;

    if (choice == 1) {
        filess(num, size);
    } else if (choice == 2) {
        cout << "Enter Numbers Here" << endl;
        while (true) {
            int value;
            
            if (cin >> value) {
                heap(num, size, value);  
                cout << "---------------------------------" << endl;
                print(num, 0, 0, size);  
            } else {
                break; 
            }
        }
    } else {
        return 0;  
    }

    cout << endl;
    print(num, 0, 0, size);  

    return 0;
}
