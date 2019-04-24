#include<iostream>
#include<ctime>
#include<cstring>
#include <string>
#include<cstdlib>
#include<vector>
#include <algorithm>
#include<windows.h>
using namespace std;



class Multiplicator
{
public:
    unsigned long long int n1;
    unsigned long long int n2;
    unsigned long long int k ;
    vector <unsigned long long int> arr1;
    vector <unsigned long long int> arr2;

    Multiplicator(unsigned long long int k )
    {

        cout << "size of n1: " << k << endl;

        //cin >> k;

        n1 = generator(k);
        arr1 = turner(n1,k);

        cout <<"n1 = " << n1 << endl;
        cout << "size of n2: " << k;

        //cin >> k;

        n2 = generator(k);
        arr2 = turner(n2,k);

        cout <<endl << "n2 = " << n2 <<endl;
    }

    unsigned long long int pow (unsigned long long int a, unsigned long long int b)
    {
        unsigned long long int x = 1;

        for(int i = 0; i < b; i++)
        {
            x *= a;
        }

        return x;
    }

    unsigned long long int generator(unsigned long long int k)
    {
        unsigned long long int n = 0;
        n = ((rand() % ((pow(10,k-1))) + (pow(10,k-1))));
        return n;
    }

    vector<unsigned long long int> turner(unsigned long long int x, unsigned long long int k)
    {
        vector <unsigned long long int> arr;

        for(int i = 0; i < k; i++)
        {
            arr.insert(arr.begin(),x%10);
            x /= 10;
        }

        return arr;
    }

    vector<unsigned long long int> equaller(vector<unsigned long long int> x, vector<unsigned long long int> y)
    {
        int maxi = max(x.size(),y.size());
        int mini = min(x.size(),y.size());
        for(int i = 0; i < maxi - mini; i++)
        {
            y.insert(y.begin(),0);
        }
        return y;
    }

    void show_vector( vector<unsigned long long int>&a)
    {
        for (vector<unsigned long long int>::iterator it = a.begin() ; it!=a.end() ; ++it)
        cout<<*it;
    }



    unsigned long long int pillar( vector<unsigned long long int> x, vector<unsigned long long int> y )
    {
        unsigned long long int sum = 0;
        unsigned long long int flag = 0;
        unsigned long long int flag2 = 0;

        if(x.size() > y.size())
        {
            y = equaller(x,y);
        }
        else
        {
            x = equaller(y,x);
        }
        vector<unsigned long long int> bob(x.size());
        vector<unsigned long long int> dlc(x.size());


        for(int i = x.size()-1; i >= 0; i--)
        {
            for( int j = y.size()-1; j >= 0; j-- )
            {
                bob[i] = y[j] * x[i];
            }
        }

        return sum;
    }

    vector<unsigned long long int> dividerHalfOne (vector<unsigned long long int> x)
    {
        vector<unsigned long long int> arr;

        for(int i = 0; i < x.size()/2; i++)
        {
            arr.push_back(x[i]);
        }

        return arr;
    }

    vector<unsigned long long int> dividerHalfTwo (vector<unsigned long long int> x)
    {
        vector<unsigned long long int> arr;

            for(int i = x.size()/2; i < x.size(); i++)
            {
                arr.push_back(x[i]);
            }

        return arr;
    }

    unsigned long long int divideAndConquier (vector<unsigned long long int> x, vector<unsigned long long int> y)
    {
        if(x.size() == 1 && y.size() == 1)
        {
            return ((x[0])) * ((y[0]));
        }
        else
        {
            for(int i = 0; i < x.size()%2; i++)
            {
                x.insert(x.begin(),0);
                y.insert(y.begin(),0);
            }
          //  if(x.size() > y.size())
         //   {
              //  if(x.size()%2 == 0)
               // y = equaller(x,y);
             //   else
           //     {
         //           x.insert(x.begin(),0);
       //             y = equaller(x,y);
     //           }
   //         }
            //else
          //  {
        //        if(y.size()%2 == 0)
      //          x = equaller(y,x);
                //else
              //  {
            //        y.insert(y.begin(),0);
          //          x = equaller(y,x);
        //        }
          //  }
            vector<unsigned long long int> al = dividerHalfOne(x);
            vector<unsigned long long int> ar = dividerHalfTwo(x);
            vector<unsigned long long int> bl = dividerHalfOne(y);
            vector<unsigned long long int> br = dividerHalfTwo(y);

            unsigned long long int x1 =  divideAndConquier(al,bl);
            unsigned long long int x2 =  divideAndConquier(al,br);
            unsigned long long int x3 =  divideAndConquier(ar,bl);
            unsigned long long int x4 =  divideAndConquier(ar,br);

            return x1 * (pow(10,x.size())) + (x2 + x3) * (pow(10, x.size()/2)) + x4;
        }
    }
};



int main()
{
    srand( time(0) );
    for(int i = 2; i < 9; i++)
    {
    Multiplicator s(i);

    unsigned long long x;
    int time1 = clock();

    cout << s.pillar((s.arr1),(s.arr2)) << endl;

//    int time2 = clock();
    cout << "Pillar method required " << (float)(clock() - time1)/CLOCKS_PER_SEC << " seconds." << endl;

    int time2 = clock();

    cout << s.divideAndConquier((s.arr1),(s.arr2)) << endl;
//    time2 = clock();

    cout << "Divide and Coquier method required " <<(float)(clock() - time2)/CLOCKS_PER_SEC << " seconds." << endl;
    cout << endl << endl;
    }

    return 0;
}
