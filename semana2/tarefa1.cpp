#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;

void ordenarCrescente(vector<int>& nums) {
	setlocale(LC_ALL, "Portuguese");
    for (int i = 0; i < nums.size(); i++) {
        int indice_menor = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[indice_menor]) {
                indice_menor = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[indice_menor];
        nums[indice_menor] = temp;
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    vector<int> nums;

    cout << "Digite 10 n�meros:" << endl;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << "N�meros na ordem que voc� digitou: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    ordenarCrescente(nums);

    cout << "\nN�meros ap�s a ordena��o crescente: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

