#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 1000;

void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectSort(int arr[], int size);
void insertionSort(int arr[], int size);
void compareSorts(int arr[], int size);

int main() {
    int choice, arr[SIZE];
    
    do {
        cout << "Menu Inicial" << endl;
        cout << "1 - Continuar" << endl;
        cout << "2 - Sair" << endl;
        cout << "Escolha: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                fillArray(arr, SIZE);
                
                do {
                    cout << "\nMenu de Opções" << endl;
                    cout << "1 - Bubble Sort" << endl;
                    cout << "2 - Select Sort" << endl;
                    cout << "3 - Insertion Sort" << endl;
                    cout << "4 - Comparação" << endl;
                    cout << "5 - Sair" << endl;
                    cout << "Escolha: ";
                    cin >> choice;
                    
                    switch(choice) {
                        case 1:
                            bubbleSort(arr, SIZE);
                            cout << "\nBubble Sort aplicado:" << endl;
                            printArray(arr, SIZE);
                            break;
                        case 2:
                            selectSort(arr, SIZE);
                            cout << "\nSelect Sort aplicado:" << endl;
                            printArray(arr, SIZE);
                            break;
                        case 3:
                            insertionSort(arr, SIZE);
                            cout << "\nInsertion Sort aplicado:" << endl;
                            printArray(arr, SIZE);
                            break;
                        case 4:
                            compareSorts(arr, SIZE);
                            break;
                        case 5:
                            cout << "\nSaindo do Programa" << endl;
                            break;
                        default:
                            cout << "\nOpção Inválida" << endl;
                    }
                    
                } while(choice != 5);
                
                break;
            case 2:
                cout << "\nSaindo do Programa" << endl;
                break;
            default:
                cout << "\nOpção Inválida" << endl;
        }
        
    } while(choice != 2);
    
    return 0;
}

void fillArray(int arr[], int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand() % 1001;
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    int temp;
    bool swapped;
    
    for(int i=0; i<size-1; i++) {
        swapped = false;
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void selectSort(int arr[], int size) {
    int temp, minIndex;
    
    for(int i=0; i<size-1; i++) {
        minIndex = i;
        for(int j=i+1; j<size; j++) {
                            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) {
    int temp, j;
    
    for(int i=1; i<size; i++) {
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void compareSorts(int arr[], int size) {
    int tempArr[SIZE];
    clock_t start, end;
    double bubbleTime, selectTime, insertionTime;
    
    // Bubble Sort
    for(int i=0; i<size; i++) {
        tempArr[i] = arr[i];
    }
    start = clock();
    bubbleSort(tempArr, size);
    end = clock();
    bubbleTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Select Sort
    for(int i=0; i<size; i++) {
        tempArr[i] = arr[i];
    }
    start = clock();
    selectSort(tempArr, size);
    end = clock();
    selectTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Insertion Sort
    for(int i=0; i<size; i++) {
        tempArr[i] = arr[i];
    }
    start = clock();
    insertionSort(tempArr, size);
    end = clock();
    insertionTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    cout << "\nTempo de Execução:" << endl;
    cout << "Bubble Sort: " << bubbleTime << " segundos" << endl;
    cout << "Select Sort: " << selectTime << " segundos" << endl;
    cout << "Insertion Sort: " << insertionTime << " segundos" << endl;
}


