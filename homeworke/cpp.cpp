#include <iostream>
using namespace std;

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
    cout << "write size of arr1: " << endl;
    int size1 = 0;
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "Enter elements arr1: ";
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }
    cout << "write size of arr2: " << endl;
    int size2 = 0;
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "Enter elements arr2: ";
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }
    vstavka(arr1, size1, arr2, size2);

    std::cout << "rezult: ";
    for (int i = 0; i < size1; ++i)
    {
        std::cout << arr1[i] << " ";
    }

    delete[] arr1;
    return 0;
}
