// BoxPlot.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>
using namespace std;
void boxInfo(const vector<double>& array, int e)
{
    vector<double> arrayCopy(array);
    double k = 1.5,
        min,
        Iq,
        median,
        mean,
        stddev,
        Uq,
        max;
    vector<double> out;
    sort(arrayCopy.begin(), arrayCopy.end());
    cout.setf(ios::scientific);
    cout.precision(e);

    Iq = arrayCopy[0.25 * arrayCopy.size()];
    Uq = arrayCopy[0.75 * arrayCopy.size()];

    min = Iq - k * (Uq - Iq);
    max = Uq + k * (Uq - Iq);

    if (arrayCopy.size() % 2) median = arrayCopy[arrayCopy.size() / 2];
    else median = (arrayCopy[arrayCopy.size() / 2] + arrayCopy[arrayCopy.size() / 2 + 1]) / 2;

    mean = accumulate(array.begin(), array.end(), 0.0) / array.size();

    stddev = 0;
    for (auto i : array) stddev += (i - mean) * (i - mean);
    stddev /= (array.size()-1);
    stddev = sqrt(stddev);

    for (auto i : arrayCopy)
    {
        if (i < min || i > max) out.push_back(i);
    }


    cout << "min:\t" << min << endl;
    cout << "lq:\t" << Iq << endl;
    cout << "median:\t" << median << endl;
    cout << "mean:\t" << mean << endl;
    cout << "stddev:\t" << stddev << endl;
    cout << "uq:\t" << Iq << endl;
    cout << "max:\t" << max << endl;
    cout << "out:\t";
    for (int i = 0; i < out.size(); cout << out[i++] << " ");
    cout << endl;
    cout << mean <<"  " << median <<"  " << stddev << endl;
 
}

int main()
{
    vector<double> x = { 0.0855298042e+00,1.4513241053e+00,1.3237277269e+00,1.0128350258e+00,1.4122089148e+00,6.5826654434e-01,2.0795986652e+00,1.0230206251e+00,1.4231411219e+00,1.1091691256e+00,1.7714337111e+00,1.3986129761e+00,1.0640757084e+00,1.4216910601e+00,1.2402026653e+00 };
    boxInfo(x, 2);

}

