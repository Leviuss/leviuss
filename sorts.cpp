#include <iostream>
#include <vector>
//#include "linked list by LEO header.h"
#include <string>
#include <ctime>
#include <fstream>
#include <random>
#include <iostream>
using namespace std;


template <typename T>
vector<T> countingSort(vector<T>& a, vector<T>& b, T k)
{
    vector <T> c(k);
    for(int i = 0; i < k; i++)
    {
        c[i] = 0;
    }

    for(int j = 0; j < a.size(); j++)
    {
        c[a[j]] = c[a[j]] + 1;
    }

    for( int i = 1; i < k; i++ )
    {
        c[i] += c[i - 1];
    }

    for(int j = a.size()-1; j >= 0; j--)
    {
        b[c[a[j]]] = a[j];
        c[a[j]] --;
    }
    return b;
}



template <typename T>
void insertionSort(vector<T>& a)
{
	if (a.size() < 2)
    {
        return;
    }
	else
	{
		for (int i = 1; i < a.size(); i++)
		{
			T save = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > save)
			{
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = save;
		}
	}
}

template <typename D>
void quickSort(vector<D>& a, int left, int right)
{
	int mid = (left + right + 1) / 2;
	D pivot = a[mid];

	int i = left, j = right;
	while (i < j)
	{

		while (a[i] <= pivot && i < mid)
		{
			i++;
		}
		while (a[j] > pivot && j > mid)
		{
			j--;
		}
		if (i <= j)
        {
			D save = a[i];
			a[i] = a[j];
			a[j] = save;
			i++;
			j--;


		};
		if (left < j)
			quickSort(a, left, j);

		if (i < right)
			quickSort(a, i, right);

	}
}




int main()
{
    srand(time(0));
    ofstream file1;
    file1.open("quickSortTime.txt");
    file1 << "integers" << '\n';
    for(int i = 10; i < 120;i += 20)
    {
        vector<int> arr;
        for(int j = 0; j < i; j++)
        {
            arr.push_back(rand()%10);
        }
        int time1 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time2 = clock();
        ///////////
        arr.clear();
        for(int j = 0; j < i; j++)
        {
            arr.push_back(rand()%10);
        }
        int time3 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time4 = clock();
        /////////
        ///////////
        arr.clear();
        for(int j = 0; j < i; j++)
        {
            arr.push_back(rand()%10);
        }
        int time5 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time6 = clock();
        /////////
        file1 << i << " " << ((float)((time2 - time1))/CLOCKS_PER_SEC + (float)((time4 - time3))/CLOCKS_PER_SEC + (float)((time6 - time5))/CLOCKS_PER_SEC )/ 3<< '\n';
        arr.clear();
    }

    file1 << "strings" << '\n';

    for(int i = 10; i < 120;i += 20)
    {
        vector<char> arr;
        for(int j = 0; j < i; j++)
        {
            arr.push_back((rand()%'z' + 'a'));
        }
        int time1 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time2 = clock();
        ///////////////
        arr.clear();
        for(int j = 0; j < i; j++)
        {
            arr.push_back(rand()%'z' + 'a');
        }
        int time3 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time4 = clock();
        ///////////////
        ///////////////
        arr.clear();
        for(int j = 0; j < i; j++)
        {
            arr.push_back(rand()%'z' + 'a');
        }
        int time5 = clock();
        cout << 11;
        quickSort( arr, 0 , arr.size() - 1 );
        int time6 = clock();
        ///////////////
        file1 << i << " " << ((float)(time2 - time1)/CLOCKS_PER_SEC  + (float)((time4 - time3))/CLOCKS_PER_SEC + (float)((time6 - time5))/CLOCKS_PER_SEC )/ 3<< '\n';
        arr.clear();
    }
    //////////////////////////////////////
    ofstream file2;
    file2.open("insertionSortTime.txt");
    file2 << "integers" << '\n';
    for(int i = 10; i < 1000;i += 20)
    {
        vector<int> arr2;
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%10);
        }
        int time1 = clock();
        cout << 11;
        insertionSort( arr2 );
        int time2 = clock();
        ////////////////////
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%10);
        }
        int time3 = clock();
        cout << 11;
        insertionSort(arr2);
        int time4 = clock();
        /////////
        ////////////////////
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%10);
        }
        int time5 = clock();
        cout << 11;
        insertionSort(arr2);
        int time6 = clock();
        /////////
        file2 << i << " " << ((float)(time2 - time1)/CLOCKS_PER_SEC  + (float)(time4 - time3)/CLOCKS_PER_SEC + (float)(time6 - time5)/CLOCKS_PER_SEC) /3<< '\n';
        arr2.clear();

    }

    file2 << "strings" << '\n';

    for(int i = 10; i < 300;i += 20)
    {
        vector<int> arr2;
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%'z' + 'a');
        }
        int time1 = clock();
        cout << 11;
        insertionSort( arr2 );
        int time2 = clock();
        ////////////////////
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%'z' + 'a');
        }
        int time3 = clock();
        cout << 11;
        insertionSort(arr2);
        int time4 = clock();
        /////////
        ////////////////////
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr2.push_back(rand()%'z' + 'a');
        }
        int time5 = clock();
        cout << 11;
        insertionSort(arr2);
        int time6 = clock();
        /////////
        file2 << i << " " << ((float)(time2 - time1)/CLOCKS_PER_SEC  + (float)(time4 - time3)/CLOCKS_PER_SEC + (float)(time6 - time5)/CLOCKS_PER_SEC) /3<< '\n';
        arr2.clear();
    }


////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////
    ofstream file3;
    file3.open("countingSortTime.txt");
    file3 << "integers" << '\n';
    for(int i = 10; i < 10000;i += 20)
    {
        vector<int> arr1;
        vector<int> arr2;
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%100);
            arr2.push_back(rand()%100);
        }
        int time1 = clock();
        cout << 2;
        arr1 = countingSort( arr1,arr2,101 );
        int time2 = clock();
        ////////////////////
        arr1.clear();
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%100);
            arr2.push_back(rand()%100);
        }
        int time3 = clock();
        cout << 22;
        arr1 = countingSort( arr1,arr2,101 );
        int time4 = clock();
        /////////
        ////////////////////
        arr1.clear();
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%100);
            arr2.push_back(rand()%100);
        }
        int time5 = clock();
        cout << 22;
        arr1 = countingSort( arr1,arr2,101 );
        int time6 = clock();
        /////////
        file3 << i << " " << ((float)(time2 - time1)/CLOCKS_PER_SEC  + (float)(time4 - time3)/CLOCKS_PER_SEC + (float)(time6 - time5)/CLOCKS_PER_SEC) /3<< '\n';
        arr2.clear();
        arr1.clear();

    }

  /*  file3 << "strings" << '\n';

    for(int i = 10; i < 300;i += 20)
    {
        vector<char> arr2;
        vector<char> arr1;
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%'z' + 'a');
            arr2.push_back(rand()%'z' + 'a');
        }
        int time1 = clock();
        cout << 22;
        arr1 = countingSort(arr1,arr2,'A');
        int time2 = clock();
        ////////////////////
        arr1.clear();
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%'z' + 'a');
            arr2.push_back(rand()%'z' + 'a');
        }
        int time3 = clock();
        cout << 22;
        arr1 = countingSort(arr1,arr2,'A');
        int time4 = clock();
        /////////
        ////////////////////
        arr1.clear();
        arr2.clear();
        for(int j = 0; j < i; j++)
        {
            arr1.push_back(rand()%'z' + 'a');
            arr2.push_back(rand()%'z' + 'a');
        }
        int time5 = clock();
        cout << 22;
        arr1 = countingSort(arr1,arr2,'A');
        int time6 = clock();
        /////////
        ////////////////////
        arr1.clear();
        arr2.clear();
        /////////
        file2 << i << " " << ((float)(time2 - time1)/CLOCKS_PER_SEC  + (float)(time4 - time3)/CLOCKS_PER_SEC + (float)(time6 - time5)/CLOCKS_PER_SEC) /3<< '\n';
    }*/





	return 0;
}
