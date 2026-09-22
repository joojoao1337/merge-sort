#include <iostream>
#include <vector>

// Combina dois subvetores ordenados em um único subvetor ordenado
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria vetores temporários para armazenar os dados divididos
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copia os dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Combina os vetores temporários de volta no vetor original
    int i = 0; // Índice inicial do primeiro subvetor
    int j = 0; // Índice inicial do segundo subvetor
    int k = left; // Índice inicial do subvetor combinado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal que implementa o Merge Sort recursivamente
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Caso base: 1 ou 0 elementos
    }
    
    int mid = left + (right - left) / 2; // Previne estouro de memória (overflow) para índices grandes

    // Ordena a primeira e a segunda metade
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combina as metades ordenadas
    merge(arr, left, mid, right);
}

// Função utilitária para imprimir o vetor
void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    
    std::cout << "Original array: ";
    printVector(data);

    // Executa o Merge Sort
    mergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    printVector(data);
    
    return 0;
}
