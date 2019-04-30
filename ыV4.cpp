#include<iostream>
#include<ctime>
#include<cstring>
#include <string>
#include<cstdlib>
#include<vector>
#include <algorithm>
#include<windows.h>
using namespace std;

vector<int> operator * ( vector<int> a,int x)
{
    for(int i = 0; i < x; i++)
    {
        a.push_back(0);
    }
    return a;
}

class Multiplicator
{
public:
    int n1;
    int n2;
    int k ;
    vector <int> arr1;
    vector <int> arr2;

    Multiplicator(int k )
    {

        cout << "size of n1: " << k << endl;

        //cin >> k;

        arr1 = generator(k);

        cout <<"n1 = ";
        show_vector(arr1);
        cout << endl;
        cout << "size of n2: " << k;

        //cin >> k;

        arr2 = generator(k);

        cout <<endl << "n2 = ";
        show_vector(arr1);
        cout << endl;
    }

    int pow (int a, int b)
    {
        int x = 1;

        for(int i = 0; i < b; i++)
        {
            x *= a;
        }

        return x;
    }

    vector<int> generator(int k)
    {
        vector<int> bob;
        int n;

        for(int i = 0; i < k; i++)
        {
            n = rand() % 9 + 1;
            bob.push_back(n);
        }
        return bob;
    }

    vector<int> turner(int x, int k)
    {
        vector <int> arr;

        for(int i = 0; i < k; i++)
        {
            arr.insert(arr.begin(),x%10);
            x /= 10;
        }

        return arr;
    }

    vector<int> equaller(vector<int> x, int y)
    {
        for(int i = 0; i < y - x.size() +1; i++)
        {
            x.insert(x.begin(),0);
        }
        return x;
    }

    void show_vector( vector<int> &a)
    {
        for (vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
            cout<<*it;
    }



    int pillar( vector<int> x, vector<int> y )
    {
        int sum = 0;
        int temp = 0;
        int flag = 0;
        int flag2 = 0;

        if(x.size() > y.size())
        {
            y = equaller(y,x.size());
        }
        else
        {
            x = equaller(x,y.size());
        }
        vector<int> bob(x.size());
        vector<int> dlc(x.size());


        for(int i = x.size()-1; i >= 0; i--)
        {
            for( int j = y.size()-1; j >= 0; j-- )
            {
                bob[j] += y[j] * x[i];
                //       if
            }
        }

        return sum;
    }

    vector<int> addition (vector<int> x, vector<int> y)
    {
        x = equaller(x,y.size());
        y = equaller(y,x.size());

        vector<int> bob;

        for(int i = x.size(); i > 0; i--)
        {
            bob.insert(bob.begin(),0);
            bob[0] = x[i] + y[i];

            if(bob[0] > 9)
            {
                bob.insert(bob.begin(),0);
                bob[1] %= 10;
                bob[0] ++;
            }
        }

        if(bob[0] == 0)
            bob.erase(bob.end());
        show_vector(bob);
        cout << endl;
        return bob;
    }

    vector <int> multiplication (vector <int> x, vector <int> y)
    {
        vector <int> bob(2);

        bob[1] = x[0] * y[0];

        if(bob[1] > 9)
        {
            bob[0] = bob[1] / 10;
            bob[1] %= 10;
        }
        else
        {
            bob.erase(bob.begin());
        }
        return bob;
    }



    vector<int> dividerHalfOne (vector<int> x)
    {
        vector<int> arr;

        for(int i = 0; i < x.size()/2; i++)
        {
            arr.push_back(x[i]);
        }

        return arr;
    }

    vector<int> dividerHalfTwo (vector<int> x)
    {
        vector<int> arr;

        for(int i = x.size()/2; i < x.size(); i++)
        {
            arr.push_back(x[i]);
        }

        return arr;
    }


    vector <int> divideAndConquier (vector<int> x, vector<int> y)
    {
        if(x.size() == 1 && y.size() == 1)
        {
            return multiplication(x,y);
        }
        else
        {
            for(int i = 0; i < x.size()%2; i++)
            {
                x.insert(x.begin(),0);
                y.insert(y.begin(),0);
            }
            vector<int> al = dividerHalfOne(x);
            vector<int> ar = dividerHalfTwo(x);
            vector<int> bl = dividerHalfOne(y);
            vector<int> br = dividerHalfTwo(y);

            vector <int> x1 =  divideAndConquier(al,bl);
            vector <int> x2 =  divideAndConquier(al,br);
            vector <int> x3 =  divideAndConquier(ar,bl);
            vector <int> x4 =  divideAndConquier(ar,br);

            for (auto k:addition(x3,x4))
                cout<<k<<endl;


            vector <int> qqq  = addition (addition( x1 * x.size(), addition(x3,x4) * (x.size()/2) ), x4);
            int q  = 2;

            return addition (addition( x1 * x.size(), addition(x3,x4) * (x.size()/2) ), x4);
        }
    }
};



int main()
{
    srand( time(0) );
    for(int i = 2; i < 9; i++)
    {
        Multiplicator s(i);

        int x;
        int time1 = clock();

        cout << s.pillar((s.arr1),(s.arr2)) << endl;

//    int time2 = clock();
        cout << "Pillar method required " << (float)(clock() - time1)/CLOCKS_PER_SEC << " seconds." << endl;

        int time2 = clock();
        vector <int> bob;

        bob = s.divideAndConquier(s.arr1,s.arr2);

        s.show_vector(bob);

        //s.show_vector(s.divideAndConquier((s.arr1),(s.arr2)));
        cout << endl;
//    time2 = clock();

        cout << "Divide and Coquier method required " <<(float)(clock() - time2)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << endl << endl;
    }

    return 0;
}
