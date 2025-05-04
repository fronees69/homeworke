#include <iostream>

void vstavka(int*& arr1, int& size1, int* arr2, int size2) {
    int newSize = size1 + size2;
    int* tempArr = new int[newSize];
    for (int i = 0; i < size1; ++i) 
    {
        tempArr[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) 
    {
        tempArr[size1 + i] = arr2[i];
    }
    int newnewSize = 0;
    for (int i = 0; i < newSize; ++i) 
    {
        bool isDuplicate = false;
        for (int j = 0; j < newnewSize; ++j) 
        {
            if (tempArr[i] == tempArr[j]) 
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) 
        {
            tempArr[newnewSize++] = tempArr[i];
        }
    }

    delete[] arr1;
    arr1 = new int[newnewSize];

    for (int i = 0; i < newnewSize; ++i) 
    {
        arr1[i] = tempArr[i];
    }

    size1 = newnewSize;
    delete[] tempArr;
}

int main() 
{
    int size1 = 6;
    int* arr1 = new int[size1] {1, 3, 5, 3, 9, 15};
    int size2 = 5;
    int* arr2 = new int[size1] { 78, 6, 7, 4, 5 }; // сюда надо писать значение для добавления

    vstavka(arr1, size1, arr2, size2);

    std::cout << "rezult: ";
    for (int i = 0; i < size1; ++i) 
    {
        std::cout << arr1[i] << " ";
    }

    delete[] arr1; 
    return 0;
}
