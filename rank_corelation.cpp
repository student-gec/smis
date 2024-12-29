#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<int> calculateRanks(const vector<double>& data) {
    vector<pair<double, int> > valueIndex;
    for (int i = 0; i < data.size(); i++) {
        valueIndex.push_back({data[i], i});
    }
    
    sort(valueIndex.begin(), valueIndex.end());
    
    vector<int> ranks(data.size());
    for (int i = 0; i < valueIndex.size(); i++) {
        ranks[valueIndex[i].second] = i + 1; // Assign rank
    }
    
    return ranks;
}

double spearmanRankCorrelation(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size()) {
        throw invalid_argument("Vectors x and y must be of the same length.");
    }

    int n = x.size();
    
    vector<int> rankX = calculateRanks(x);
    vector<int> rankY = calculateRanks(y);

    double dSquaredSum = 0;
    for (int i = 0; i < n; i++) {
        double d = rankX[i] - rankY[i];
        dSquaredSum += d * d;
    }

    return 1 - (6 * dSquaredSum) / (n * (n * n - 1));
}

int main() {
    int n;
    
    cout << "Enter the number of elements in the datasets: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the elements of the first dataset (x): ";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Enter the elements of the second dataset (y): ";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    try {
        double correlation = spearmanRankCorrelation(x, y);
        cout << "Spearman's Rank Correlation Coefficient: " << correlation << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
