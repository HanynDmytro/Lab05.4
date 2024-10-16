#include <iostream>
#include <cmath>
using namespace std;

double S0(const int K, const int N) {
    double s = 0;
    for (int i = K; i <= N; i++)
        s += ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0));
    return s;
}

double S1(const int K, const int N, const int i) {
    if (i > N)
        return 0;
    else
        return ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0)) + S1(K, N, i + 1);
}

double S2(const int K, const int N, const int i) {
    if (i < K)
        return 0;
    else
        return ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0)) + S2(K, N, i - 1);
}

double S3(const int K, const int N, const int i, double t) {
    t = t + ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0));
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

double S4(const int K, const int N, const int i, double t) {
    t = t + ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0));
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main() {
    int N;
    cout << "N = "; cin >> N;
    cout << "(iter) S0 = " << S0(1, N) << endl;
    cout << "(rec up ++) S1 = " << S1(1, N, 1) << endl;
    cout << "(rec up --) S2 = " << S2(1, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(1, N, 1, 0) << endl;
    cout << "(rec down --) S4 = " << S4(1, N, N, 0) << endl;
    return 0;
}
