#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

// Function to calculate the mean of the data
double calculateMean(const vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Function to calculate the median of the data
double calculateMedian(vector<double> data) {
    sort(data.begin(), data.end());
    size_t n = data.size();
    if (n % 2 == 0) {
        return (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
        return data[n / 2];
    }
}

// Function to calculate the mode of the data
vector<double> calculateMode(const vector<double>& data) {
    unordered_map<double, int> frequency;
    for (double value : data) {
        frequency[value]++;
    }

    int maxFrequency = 0;
    for (const auto& pair : frequency) {
        maxFrequency = max(maxFrequency, pair.second);
    }

    vector<double> modes;
    for (const auto& pair : frequency) {
        if (pair.second == maxFrequency) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}

int main() {
    size_t n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> data(n);
    cout << "Enter the data points: \n";
    for (size_t i = 0; i < n; ++i) {
        cout << "Data point " << i + 1 << ": ";
        cin >> data[i];
    }

    double mean = calculateMean(data);
    double median = calculateMedian(data);
    vector<double> mode = calculateMode(data);

    cout << "\nMean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: ";
    if (mode.size() == data.size()) {
        cout << "No mode (all values appear equally)." << endl;
    } else {
        for (double value : mode) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
