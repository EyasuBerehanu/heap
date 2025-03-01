//Eyasu Berehanu
//2/28/2025
//Heap program which orginzes numbers using max heap
//Sourcs: https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/
//https://www.geeksforgeeks.org/heap-sort/#heap-sort-algorithm
//https://cplusplus.com/doc/tutorial/files/
//print from Mr.Galbrith
#include <iostream>   
#include <fstream>   
#include <bits/stdc++.h>

using namespace std;

void heap(int num[], int& size, int value); 
void print(int table[], int pos, int depth, int size); 
void filess(int num[], int& size); 
void remove(int num[], int& size);
void removeAll(int num[], int& size);

void heap(int num[], int& size, int value) // this inserts value into the max heap
{
    num[size] = value; // inserts value at the end
    size++; 
    int i = size - 1; 

    while (i != 0 && num[(i - 1) / 2] < num[i]) { // moves inserted number up swaping with parent if greater
        swap(num[i], num[(i - 1) / 2]); 
        i = (i - 1) / 2; 
    }
}

void print(int table[], int pos, int depth, int size) { //prints heap in a sideways tree way for visual
    if (pos >= size) { // i had to add this cuz if i didnt a pesky little 1 would pop up after i did all removed
        return; 
    }
    
    if (pos * 2 + 1 < size) { //print right side of tree first using recurstion
        print(table, pos * 2 + 1, depth + 1, size);
    }

    for (int a = 0; a < depth; a++) { //spacing for visuals
        cout << "   "; 
    }
    cout << table[pos] << endl;

    if (pos * 2 + 2 < size) {  //print left side of tree  using recurstion
        print(table, pos * 2 + 2, depth + 1, size);
    }
}

void filess(int num[], int& size) { //reads numbers from a file and inserts into heap
    ifstream file("numbers.txt"); 
    if (!file) {
        return; 
    }
    int value;
    while (file >> value) { // intersts to heap and makes sure its one at time
        if (value >= 1 && value <= 1000) { // the 1 to 1000 range like it says in intructions
            heap(num, size, value); 
        }
    }
    file.close(); 
}

void remove(int num[], int& size) { //reomves root or max number from the heap
    if (size <= 0) {
        return; 
    }

    //cout << "Removed " << num[0] << endl; // Display the removed element
    num[0] = num[size - 1]; // replaces root with last num and shrinks the heap using 
    size--; 

    int i = 0; 
    while (i * 2 + 1 < size) { 
        int largest = i;
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 

        if (left < size && num[left] > num[largest]) { //finds the largest root from left and right
            largest = left;
        }

        if (right < size && num[right] > num[largest]) { //finds the largest root from left and right
            largest = right;
        }

        if (largest != i) { //swaps and contiueies and breaks if everything meets the rules
            swap(num[i], num[largest]); 
            i = largest; 
        } else {
            break; 
        }
    }
}


void removeAll(int num[], int& size) { //this removes all nums from heap
    cout << "All Removed" << endl;

    while (size > 0) {
        remove(num, size); // this keeps removing until empty 
    }
    

}

int main()
{
    int num[100]; 
    int size = 0; 
    int choice;

    cout << "Choose:" << endl;
    cout << "1 for files" << endl;
    cout << "2 for input" << endl;
    cin >> choice;

    if (choice == 1) {
        filess(num, size); // reeads from file
        print(num, 0, 0, size);
        
        int removeChoice;
    while (true) {
        
        cout << "Choose option for removal" << endl; //the player chooses removal option
        cout << "type 1 to remove one element" << endl;
        cout << "type 2 to remove all elements" << endl;

        cin >> removeChoice;

        if (removeChoice == 1) {
            remove(num, size); //remove top num
            cout << "---------------------------------------" << endl;
            print(num, 0, 0, size); // then displays heap after removal
            cout << "---------------------------------------" << endl;
            cout << "Removed " << num[0] + 1 << endl; // says the one that got removed
        
            
        } else if (removeChoice == 2) {
            removeAll(num, size); //removes all elements
            break;
            
        } else {
            break; 
        
        }
    }
    } else if (choice == 2) { //basically added this section so i could do the same thing with files as imput now cuz i miss read lol
        cout << "Enter Numbers and type delete to remove max or deleteall to delete all" << endl;
        while (true) {
            char input[10];
            cin >> input;
            if (strcmp(input, "delete") == 0) { ///deletes max root if you type delete
                remove(num, size);
                cout << "---------------------------------" << endl;
                print(num, 0, 0, size);
                 cout << "---------------------------------" << endl;
                 
            } else if (strcmp(input, "deleteall") == 0) { //deletes all if you type deleteall
                removeAll(num, size);
                cout << "---------------------------------" << endl;
                print(num, 0, 0, size);
                cout << "---------------------------------" << endl;
            
            } else { //this will contuie to let the numbers you put be added to the heap but now i had to us atoi cut the inputs arnt for nums they have to be turned to ints now
                int value = atoi(input); 
                heap(num, size, value);
                cout << "---------------------------------" << endl;
                print(num, 0, 0, size);
                cout << "---------------------------------------" << endl;
            
            }
        }
    } else {
        return 0; 
    }

    print(num, 0, 0, size);

    return 0; 
}

