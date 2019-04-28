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
        n = rand() % 10 + 1;
        bob.push_back(n);
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

    vector<int> equaller(vector<int> x, vector<int> y)
    {
        int maxi = max(x.size(),y.size());
        int mini = min(x.size(),y.size());
        for(int i = 0; i < maxi - mini; i++)
        {
            y.insert(y.begin(),0);
        }
        return y;
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
            y = equaller(x,y);
        }
        else
        {
            x = equaller(y,x);
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
        x = equaller(x,y);
        y = equaller(x,y);
        x.insert(x.begin(), 0);
        y.insert(y.begin(), 0);
        vector<int> bob (x.size());

        for(int i = x.size(); i > 0; i--)
        {
            bob[i] = x[i] + y[i];

            if(bob[i] > 9)
            {
                bob[i-1] ++;
                bob[i] %= 10;
            }
        }

        if(bob[0] == 0)
            bob.erase(bob.begin());
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
            vector<int> al = dividerHalfOne(x);
            vector<int> ar = dividerHalfTwo(x);
            vector<int> bl = dividerHalfOne(y);
            vector<int> br = dividerHalfTwo(y);

            vector <int> x1 =  divideAndConquier(al,bl);
            vector <int> x2 =  divideAndConquier(al,br);
            vector <int> x3 =  divideAndConquier(ar,bl);
            vector <int> x4 =  divideAndConquier(ar,br);
            for(int i = 0; i < x.size(); i++)
            {
                x1.push_back(0);
            }

            vector <int> x2plusx3;

            x2plusx3 = addition(x2,x3);

            for(int i = 0; i < x.size()/2; i++)
            {
                x2plusx3.push_back(0);
            }

            vector <int> sum;

            sum = addition(x1,x2plusx3);
            sum = addition(sum,x4);


            return sum;
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
