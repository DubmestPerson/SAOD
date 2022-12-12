#include <iostream>
#include <vector>
#include <list>
#include <chrono>
using namespace std;

int main()
{
    //list <int> l;
    //int N = 200;
    //int M = 300;
    //for (int i = 0; i < N; i++)
    //    l.push_back(i);

    //int k = 0;
    //auto start = chrono::steady_clock::now();
    //for (int i = 0; i < M; i++)
    //{
    //    l.push_front(i);
    //    k++;
    //    l.pop_front();
    //    k++;
    //}
    //auto stop = chrono::steady_clock::now();
    //cout << k << endl;
    //auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    //cout << N << "\t";
    //cout << dt << endl;
    //for (int i = 0; i < 36; i++)
    //{
    //    N += 50;
    //    cout << N << "\t";
    //    int mindt = 1000;
    //    for (int j = 0; j < 10; j++)
    //    {
    //        auto start = chrono::steady_clock::now();
    //        for (int i = 0; i < M; i++)
    //        {
    //            l.push_front(i);
    //            k++;
    //            l.pop_front();
    //            k++;
    //        }
    //        auto stop = chrono::steady_clock::now();
    //        auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    //        if (dt < mindt) mindt = dt;
    //    }
    //    cout << mindt << endl;
    //    for (int i = 0; i < 50; i++)
    //        l.push_back(l.back()+1);
    //}
    //cout << l.size() << endl;


    vector <int> v;
    int N = 200;
    int M = 200;
    for (int i = 0; i < N; i++)
        v.push_back(i);

    int k = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < M; i++)
    {
        v.insert(v.begin(), i);
        k++;
        v.erase(v.begin());
        k++;
    }
    auto stop = chrono::steady_clock::now();
    cout << k << endl;
    auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << N << "\t";
    cout << dt << endl;
    for (int i = 0; i < 4; i++)
    {
        N += 200;
        cout << N << "\t";
        int mindt = 1000;
        for (int j = 0; j < 10; j++)
        {
            auto start = chrono::steady_clock::now();
            for (int i = 0; i < M; i++)
            {
                v.insert(v.begin(), i);
                k++;
                v.erase(v.begin());
                k++;
            }
            auto stop = chrono::steady_clock::now();
            auto dt = chrono::duration_cast<chrono::microseconds>(stop - start).count();
            if (dt < mindt) mindt = dt;
        }
        cout << mindt << endl;
        for (int i = 0; i < 200; i++)
            v.push_back(v.back() + 1);
    }
    cout << v.size() << endl;
}