#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate Chi-Square value
double chiSquareTest(const vector<double>& observed, const vector<double>& expected) {
    if (observed.size() != expected.size()) {
        cerr << "Error: Observed and expected frequencies must have the same size." << endl;
        return -1;
    }

    double chiSquare = 0.0;
    for (size_t i = 0; i < observed.size(); ++i) {
        if (expected[i] == 0) {
            cerr << "Error: Expected frequency at index " << i << " is zero." << endl;
            return -1;
        }
        chiSquare += pow(observed[i] - expected[i], 2) / expected[i];
    }
    return chiSquare;
}

int main() {
    size_t n;
    cout << "Enter the number of categories: ";
    cin >> n;

    vector<double> observed(n), expected(n);

    cout << "Enter the observed frequencies: \n";
    for (size_t i = 0; i < n; ++i) {
        cout << "Category " << i + 1 << ": ";
        cin >> observed[i];
    }

    cout << "Enter the expected frequencies: \n";
    for (size_t i = 0; i < n; ++i) {
        cout << "Category " << i + 1 << ": ";
        cin >> expected[i];
    }

    double chiSquare = chiSquareTest(observed, expected);
    if (chiSquare != -1) {
        cout << "\nChi-Square Test Statistic: " << chiSquare << endl;
    }

    return 0;
}
