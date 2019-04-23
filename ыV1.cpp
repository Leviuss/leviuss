#include<iostream>
#include<ctime>
#include<cstring>
#include <string>
#include<cstdlib>
#include<vector>
#include <algorithm>
using namespace std;



class Multiplicator
{
public:
    long long int n1;
    long long int n2;
    vector <long long int> arr1;
    vector <long long int> arr2;

    Multiplicator()
    {
        long long int k = 13;

      //  cout << "enter size of n1: ";

        //cin >> k;

        n1 = generator(k);
        arr1 = turner(n1,k);

        cout <<"n1 = " << n1 <<endl;
        //cout << "enter size of n2: ";

     //   cin >> k;

        n2 = generator(k);
        arr2 = turner(n2,k);

        cout <<"n2 = " << n2 <<endl;
    }

    long long int pow (long long int a, long long int b)
    {
        long long int x = 1;

        for(int i = 0; i < b; i++)
        {
            x *= a;
        }

        return x;
    }

    long long int generator(long long int k)
    {
        long long int n = 0;
        n = ((rand() % ((pow(10,k-1))) + (pow(10,k-1))));
        return n;
    }

    vector<long long int> turner(long long int x, long long int k)
    {
        vector <long long int> arr;

        for(int i = 0; i < k; i++)
        {
            arr.insert(arr.begin(),x%10);
            x/=10;
        }

        return arr;
    }

    vector<long long int> equaller(vector<long long int> x, vector<long long int> y)
    {
        for(int i = 0; i < x.size() - y.size(); i++)
        {
            y.insert(y.begin(),0);
        }
        return y;
    }

    void show_vector( vector<long long int>&a)
    {
        for (vector<long long int>::iterator it = a.begin() ; it!=a.end() ; ++it)
        cout<<*it;
    }


    long long int pillar( vector<long long int> x, vector<long long int> y )
    {
        long long int bob = 0;
        long long int sum = 0;
        long long int flag = 0;
        long long int flag2 = 0;

        if(x.size() > y.size())
        {
            y = equaller(x,y);
        }
        else
        {
            x = equaller(y,x);
        }


        for(int i = x.size()-1; i >= 0; i--)
        {
            for( int j = y.size()-1; j >= 0; j-- )
            {
                bob += (y[j])  * (x[i]) * int(pow(10,x.size()-j-1));
               // cout << y[j] << " * " << x[j] << " * " << int(pow(10,x.size()-j-1)) << " = " << bob << "    ";
            }
           // cout << endl;
            sum += bob * int(pow(10,flag2));
            bob = 0;
            flag2 ++;
        }

        return sum;
    }

    vector<long long int> dividerHalfOne (vector<long long int> x)
    {
        vector<long long int> arr;

        for(int i = 0; i < x.size()/2; i++)
        {
            arr.push_back(x[i]);
        }

        return arr;
    }

    vector<long long int> dividerHalfTwo (vector<long long int> x)
    {
        vector<long long int> arr;

        if(x.size() % 2 == 0)
            for(int i = x.size()/2; i < x.size(); i++)
            {
                arr.push_back(x[i]);
            }
        else
            for(int i = x.size()/2; i < x.size(); i++)
            {
                arr.push_back(x[i]);
            }

        return arr;
    }

    long long int divideAndConquier (vector<long long int> x, vector<long long int> y)
    {
        if(x.size() == 1 && y.size() == 1)
        {
            return ((x[0])) * ((y[0]));
        }
        else
        {
            if(x.size() > y.size())
            {
                if(x.size()%2 == 0)
                y = equaller(x,y);
                else
                {
                    x.insert(x.begin(),0);
                    y = equaller(x,y);
                }
            }
            else
            {
                if(y.size()%2 == 0)
                x = equaller(y,x);
                else
                {
                    y.insert(y.begin(),0);
                    x = equaller(y,x);
                }
            }
            vector<long long int> al = dividerHalfOne(x);
            vector<long long int> ar = dividerHalfTwo(x);
            vector<long long int> bl = dividerHalfOne(y);
            vector<long long int> br = dividerHalfTwo(y);

            long long int x1 =  divideAndConquier(al,bl);
            long long int x2 =  divideAndConquier(al,br);
            long long int x3 =  divideAndConquier(ar,bl);
            long long int x4 =  divideAndConquier(ar,br);

            return x1 * (pow(10,x.size())) + (x2 + x3) * (pow(10, x.size()/2)) + x4;
        }
    }
};



int main()
{
    srand( time(0) );

    Multiplicator s;
    int time1 = clock();

    cout << s.pillar((s.arr1),(s.arr2)) << endl;

    int time2 = clock();

    cout << "Pillar method required " << (float)(time2 - time1) / CLOCKS_PER_SEC << " seconds." << endl;

    time1 = clock();

    cout << s.divideAndConquier((s.arr1),(s.arr2)) << endl;

    time2 = clock();

    cout << "Divide and Coquier method required " << (float)(time2 - time1) / CLOCKS_PER_SEC << " seconds.";

    return 0;
}
