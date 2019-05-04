#include<iostream>
#include<ctime>
#include<cstring>
#include<fstream>
#include <string>
#include<cstdlib>
#include<vector>
#include <algorithm>
#include<windows.h>
using namespace std;

vector<int> mult ( vector<int> a,int x)
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
        show_vector(arr2);
        cout << endl;
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



    vector<int> equaller(vector<int> x, int y)
    {
        int fuck = x.size();
        for(int i = 0; i < y - fuck; i++)
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



    vector<int> pillar( vector<int> x, vector<int> y )
    {
        y = equaller(y,x.size());
        x = equaller(x,y.size());

        int n1 = x.size();
        int n2 = y.size();

        vector<int> res(n1 + n2 + 1, 0);

        int i_n1 = 0;
        int i_n2 = 0;

        for (int i = x.size()-1; i >= 0; i--)
        {
            int carry = 0;

            n1 = x[i];
            i_n2 = 0;

            for (int j = y.size()-1; j >= 0; j--)
            {
                n2 = y[j];

                int sum = n1*n2 + res[i_n1 + i_n2] + carry;
                carry = sum/10;

                res[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }

            if (carry > 0)
                res[i_n1 + i_n2] += carry;

            i_n1++;
        }

        int i = res.size() - 1;

        while ( i >= 0 && res[i] == 0)
        {
            i--;
        }

       reverse(&res[0], &res[res.size() - 1 ]);
       res.erase(res.end()-1);


        return res;
    }

    vector<int> addition (vector<int> x, vector<int> y)
    {
        x = equaller(x,y.size());
        y = equaller(y,x.size());

        vector<int> bob;
        bob.insert(bob.begin(),0);
        //cout << "arr1 = ";
        //show_vector(x);
        //cout << endl << "arr2 = ";
        //show_vector(y);
        //cout << endl;

        for(int i = x.size()-1; i >= 0; i--)
        {
            bob[0] += x[i] + y[i];
          //  cout << x[i] << " + " << y[i] << " = ";
           // cout << bob[0] << endl;

            bob.insert(bob.begin(),0);

            bob[0] += bob[1]/10;
            bob[1] %= 10;
        }
        if(bob[0] == 0)
            bob.erase(bob.begin());
        return bob;
    }

    vector<int> substraction(vector<int> x, vector<int> y)
    {
        x = equaller(x,y.size());
        y = equaller(y,x.size());

        vector<int> bob;
        bob.insert(bob.begin(),0);
        //cout << "arr1 = ";
        //show_vector(x);
        //cout << endl << "arr2 = ";
        //show_vector(y);
        //cout << endl;

        for(int i = x.size()-1; i >= 0; i--)
        {
            bob[0] += x[i] - y[i];
          //  cout << x[i] << " + " << y[i] << " = ";
           // cout << bob[0] << endl;

            bob.insert(bob.begin(),0);

            if(bob[1] < 0)
            {
                bob[0] --;
                bob[1] += 10;
            }
        }
        if(bob[0] == 0)
            bob.erase(bob.begin());
        return bob;
    }

    vector <int> multiplication (vector <int> x, vector <int> y)
    {
        vector <int> bob(2);
        int a = x[0] * y[0];

        bob[1] = (a) % 10;
        bob[0] = a / 10;

        if(bob[1] == 0)
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

            vector <int> mult1 = mult(x1,x.size());
            //show_vector(mult1); cout << " mult1 " << endl; // OK

            vector <int> x2PLUSx3 = addition(x2,x3);
            //show_vector(x2PLUSx3); cout << " x2+x3 " << endl; // OK

            vector <int> mult2 = mult(x2PLUSx3,x.size()/2);
            //show_vector(mult2); cout << " mult2 " << endl; // OK

            //cout << "Check ,ult1 and mult2: ";
            //show_vector(mult1);
            //cout <<" ";
            //show_vector(mult2);
            //cout << endl;

            vector <int> add1 = addition(mult1,mult2);
            //show_vector(add1); cout << " add1 " << endl; // FUCKING SHIT

            vector <int> add2 = addition(add1,x4);
            //show_vector(add2); cout << " add2" << endl;

            return add2;
        }
    }

    /*vector <int> karazuba (vector<int> x, vector<int> y)
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
            vector <int> x2 =  divideAndConquier(addition(al,ar),addition(br,bl));
            vector <int> x3 =  divideAndConquier(ar,br);

            vector <int> mult1 = mult(x1,x.size());
            show_vector(mult1); cout << " mult1 " << endl;

            vector <int> x2MINUSx1 = substraction(x2,x1);
            show_vector(x2MINUSx1); cout << " x2-x1 " << endl;

            vector<int> x2x1MINUSx3 = substraction(x2MINUSx1,x3);
            show_vector(x2x1MINUSx3); cout << " x2x1 - X3 " << endl;

            vector <int> mult2 = mult(x2x1MINUSx3,x.size()/2);
            show_vector(mult2); cout << " mult2 " << endl; // OK

            //cout << "Check ,ult1 and mult2: ";
            //show_vector(mult1);
            //cout <<" ";
            //show_vector(mult2);
            //cout << endl;

            vector <int> add1 = addition(mult1,mult2);
            show_vector(add1); cout << " add1 " << endl; // FUCKING SHIT

            vector <int> add2 = addition(add1,x3);
            show_vector(add2); cout << " add2" << endl;

            return add2;
        }
    }
    */
};



int main()
{
    srand( time(0) );
    int k;
    cout << "Enter number of digits: ";
    cin >> k;
    vector<pair<double,double> > period(k);
    for(int i = 2; i < period.size(); i += 18)
    {
        Multiplicator s(i);

        int x;
        int time1 = clock();
        vector<int> alice;
        alice = s.pillar(s.arr1, s.arr2);
        s.show_vector(alice);

     //   cout << endl;

        int time2 = clock();
        period[i].first = ((double)(time2 - time1)/CLOCKS_PER_SEC );
       // cout << "Pillar method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << endl;
        vector <int> bob;
        time1 = clock();
        bob = s.divideAndConquier(s.arr1,s.arr2);
        time2 = clock();
        s.show_vector(bob);
        period[i].second = ((double)(time2 - time1)/CLOCKS_PER_SEC );
        cout << endl;
        //s.show_vector(s.divideAndConquier((s.arr1),(s.arr2)));
        //cout << endl;
//    time2 = clock();

       // cout << "Divide and Coquier method required " <<(float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;

       /* time1 = clock();
        vector<int> charly;
        charly = s.karazuba(s.arr1, s.arr2);
        s.show_vector(charly);
        cout << endl;

        time2 = clock();
        cout << "Karazuba method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;
        */
    }
    ofstream file;
    file.open("time1.txt");
    vector<pair<double,double> > period2(k);

    for(int i = 2; i < period.size(); i+= 18)
    {
        cout << i <<" " << period[i].first << " " << period[i].second << endl;
        file << i << " " << period[i].first << " " << period[i].second << '\n';
    }
    file.close();


    for(int i = 2; i < period2.size(); i += 18)
    {
        Multiplicator s(i);

        int x;
int        time1 = clock();
vector<int>        alice = s.pillar(s.arr1, s.arr2);
        s.show_vector(alice);

     //   cout << endl;

        int  time2 = clock();
        period2[i].first = ((double)(time2 - time1)/CLOCKS_PER_SEC );
       // cout << "Pillar method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << endl;
        time1 = clock();
   vector<int>     bob = s.divideAndConquier(s.arr1,s.arr2);
        time2 = clock();
        s.show_vector(bob);
        period2[i].second = ((double)(time2 - time1)/CLOCKS_PER_SEC );
        cout << endl;
        //s.show_vector(s.divideAndConquier((s.arr1),(s.arr2)));
        //cout << endl;
//    time2 = clock();

       // cout << "Divide and Coquier method required " <<(float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;

       /* time1 = clock();
        vector<int> charly;
        charly = s.karazuba(s.arr1, s.arr2);
        s.show_vector(charly);
        cout << endl;

        time2 = clock();
        cout << "Karazuba method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;
        */
    }
    ofstream file2;
    file2.open("time2.txt");
    vector<pair<double,double> > period3(k);

    for(int i = 2; i < period2.size(); i+= 18)
    {
        cout << i <<" " << period2[i].first << " " << period2[i].second << endl;
        file2 << i << " " << period2[i].first << " " << period2[i].second << '\n';
    }
    file2.close();





    for(int i = 2; i < period3.size(); i += 18)
    {
        Multiplicator s(i);

        int x;
int        time1 = clock();
vector<int>        alice = s.pillar(s.arr1, s.arr2);
        s.show_vector(alice);

     //   cout << endl;

        int  time2 = clock();
        period3[i].first = ((double)(time2 - time1)/CLOCKS_PER_SEC );
       // cout << "Pillar method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl;
        cout << endl;
        time1 = clock();
   vector<int>     bob = s.divideAndConquier(s.arr1,s.arr2);
        time2 = clock();
        s.show_vector(bob);
        period3[i].second = ((double)(time2 - time1)/CLOCKS_PER_SEC );
        cout << endl;
        //s.show_vector(s.divideAndConquier((s.arr1),(s.arr2)));
        //cout << endl;
//    time2 = clock();

       // cout << "Divide and Coquier method required " <<(float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;

       /* time1 = clock();
        vector<int> charly;
        charly = s.karazuba(s.arr1, s.arr2);
        s.show_vector(charly);
        cout << endl;

        time2 = clock();
        cout << "Karazuba method required " << (float)(time2 - time1)/CLOCKS_PER_SEC << " seconds." << endl << endl << endl;
        */
    }
    ofstream file3;
    file3.open("time3.txt");

    for(int i = 2; i < period3.size(); i+= 18)
    {
        cout << i <<" " << period3[i].first << " " << period3[i].second << endl;
        file3 << i << " " << period3[i].first << " " << period3[i].second << '\n';
    }
    file3.close();






    return 0;
}
