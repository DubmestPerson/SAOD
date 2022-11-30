#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>

size_t naive(const std::string& str, const std::string& sub)
{
    size_t n = str.size(), m = sub.size(), j = 0;
    for (size_t i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (str[i + j] != sub[j])
                break;
        }
        if (j == m)
            return i;
    }
    return std::string::npos;
}


void kmp_table(const std::string& sub, int* T) {
    int lsub = sub.length();

    T[0] = -1;
    T[1] = 0;

    int pos = 2;
    int cnd = 0;

    while (pos < lsub) {
        if (sub[pos - 1] == sub[cnd]) {
            cnd = cnd + 1;
            T[pos] = cnd;
            pos = pos + 1;
        }
        else if (cnd > 0)
            cnd = T[cnd];
        else {
            T[pos] = 0;
            pos = pos + 1;
        }
    }
}

size_t kmp(const std::string& str, const std::string& sub)
{
    int lstr = str.length();
    int lsub = sub.length();

    int* T = new int[lsub];
    kmp_table(sub, T);

    int m = 0;
    int i = 0;

    while (m + i < lstr) {
        if (sub[i] == str[m + i]) {
            i = i + 1;
            if (i == lsub) {
                delete[] T;
                return m;
            }
        }
        else {
            m = m + i - T[i];
            if (T[i] > -1)
                i = T[i];
            else
                i = 0;
        }
    }
    delete[] T;
    return std::string::npos;
}

#define ALPHABET_SIZE (1 << CHAR_BIT)

static void compute_prefix(const char* str, size_t size, int* result) {
    result[0] = 0;

    int k = 0;
    for (size_t q = 1; q < size; q++) {
        while (k > 0 && str[k] != str[q])
            k = result[k - 1];

        if (str[k] == str[q])
            k++;
        result[q] = k;
    }
}

static void prepare_badcharacter_heuristic(const char* str, size_t size,
    int result[ALPHABET_SIZE]) {
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
        result[i] = -1;

    for (size_t i = 0; i < size; i++)
        result[(size_t)str[i]] = i;
}

void prepare_goodsuffix_heuristic(const char* normal, size_t size, int* result) {
    std::string sreversed(normal);
    reverse(sreversed.begin(), sreversed.end());

    int* prefix_normal = new int [size];
    int* prefix_reversed = new int [size];
    compute_prefix(normal, size, prefix_normal);
    compute_prefix(sreversed.data(), size, prefix_reversed);

    for(size_t i = 0; i <= size; i++) {
        result[i] = size - prefix_normal[size - 1];
    }

    for(size_t i = 0; i < size; i++) {
        const int j = size - prefix_reversed[i];
        const int k = i - prefix_reversed[i] + 1;

        if(result[j] > k)
            result[j] = k;
    }
    delete[] prefix_normal;
    delete[] prefix_reversed;
}

size_t bm(const std::string& str, const std::string& sub)
{
    int haystack_len = str.length();
    int needle_len = sub.length();

    int badcharacter[ALPHABET_SIZE];
    int* goodsuffix = new int[needle_len + 1];
    prepare_badcharacter_heuristic(sub.data(), needle_len, badcharacter);
    prepare_goodsuffix_heuristic(sub.data(), needle_len, goodsuffix);

    size_t s = 0;
    while (s <= (haystack_len - needle_len)) {
        size_t j = needle_len;
        while (j > 0 && sub[j - 1] == str[s + j - 1])
            j--;

        if (j > 0) {
            int k = badcharacter[(size_t)str[s + j - 1]];
            int m;
            if (k < (int)j && (m = j - k - 1) > goodsuffix[j])
                s += m;
            else
                s += goodsuffix[j];
        }
        else {
            delete[] goodsuffix;
            return s;
        }
    }
    delete[] goodsuffix;

    return std::string::npos;
}

int main()
{
    using namespace std;

    string str, sub = "was born in a small town called Sceptre";
    ifstream fin("engwiki_ascii.txt", ios::binary);
    if (!fin.is_open())
    {
        cout << "not open!" << endl;
        return 0;
    }
    str.append((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

    size_t n = 10;
    std::vector<size_t> times(n), indx(n);

    cout << "\nstd::find\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = str.find(sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }

    cout << "\nnaive\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = naive(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    cout << "\nKMP\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = kmp(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
    cout << "\nBM\n";
    for (size_t i = 0; i < n; i++)
    {
        auto time_one = chrono::high_resolution_clock::now();
        auto index = bm(str, sub);
        if (index == std::string::npos)
            std::cout << "not found\n";
        else
            indx[i] = index;
        auto time_two = chrono::high_resolution_clock::now();
        times[i] = chrono::duration_cast<chrono::microseconds>(time_two - time_one).count();
    }
    for (size_t i = 0; i < n; i++)
    {
        cout << indx[i] << '\t' << times[i] << endl;
    }
}