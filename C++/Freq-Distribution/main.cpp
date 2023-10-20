#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma") // if the machine use intel
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


vector<int> getNum(string raw)
{
    vector<int> numbers;
    int number = 0;

    for (char c : raw) {
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        } else {
            numbers.push_back(number);
            number = 0;
        }
    }

    return numbers;
}

void showNum(vector<int> num)
{
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
        if(((i+1)%10==0) || (i == num.size()-1 && (i+1)%10!=0)) cout << "  \n";
    }
    cout << "  \n";
}

void swap(vector<int>& num, int a, int b) {
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}

int partition(vector<int>& num, int low, int high) {
    int pivot = num[high]; 
    int i = (low - 1);    

    for (int j = low; j <= high - 1; j++) {
        if (num[j] <= pivot) {
            i++; 
            swap(num, i, j);
        }
    }
    swap(num, i + 1, high);
    return (i + 1);
}

void quickSort(vector<int>& num, int low, int high) {
    if (low < high) {
        int pi = partition(num, low, high);

        quickSort(num, low, pi - 1);
        quickSort(num, pi + 1, high);
    }
}

void makeTable(vector<int>& numbers, double width) {
    cout << "| Data Range | Median | Frequency |  \n";
    cout << "| :--------: | :----: | :-------: |  \n";
    int pos = 0, temp1 = numbers[0], temp2, freq;
    double median;
    while(true) {
        if(pos != numbers.size()) {
            freq = 0;
            temp2 = temp1 + (static_cast<int>(ceil(width)) - 1);
            median = (static_cast<double>(temp1+temp2))/2;
            while(true) {
                if(pos != numbers.size()) {
                    if(numbers[pos] <= temp2) {
                        freq++;
                        pos++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            cout << "| " << temp1 << "-" << temp2 << " | " << median << " | " << freq << " |  \n";
            temp1 = temp2 + 1;
        } else {
            break;
        }
    }
}

int main() 
{
    #ifndef input_data
    freopen("input.in", "r", stdin);
    freopen("output.md", "w", stdout);
    #endif

    fast_cin();
    string raw_data;
    getline(cin, raw_data);

    cout << "Raw data:  \n";
    vector<int> numbers = getNum(raw_data);
    showNum(numbers);
    
    cout << "Sorted data:  \n";
    quickSort(numbers, 0, numbers.size()-1);
    showNum(numbers);

    cout << "n = " << numbers.size() << "  \n";
    cout << "Range = " << numbers[numbers.size()-1] << " - " << numbers[0] << " = " << numbers[numbers.size()-1]-numbers[0] << "  \n";
    cout << "Number of Classes = 1 + 3.322 * log10(" << numbers.size() << ") = " << 1 + 3.322 * (log(numbers.size())/log(10)) << "  \n";
    double width = (static_cast<double>(numbers[numbers.size()-1]-numbers[0]))/(1 + 3.322 * (log((static_cast<double>(numbers.size())))/log(10)));
    cout << "Width = " << numbers[numbers.size()-1]-numbers[0] << "/" << 1 + 3.322 * (log(numbers.size())/log(10)) << " = " << width << " ~ " << ceil(width) << "  \n";
    cout << endl;

    makeTable(numbers, width);

    return 0;
}