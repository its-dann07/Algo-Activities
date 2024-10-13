#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//calculate distance between two points
double calculate_distance(double X1, double Y1, double X2, double Y2) {
    return std::sqrt(std::pow((X2 - X1), 2) + std::pow((Y2 - Y1), 2));
}

//calculate total distance between consecutive points
double calculate_total_distance(const vector<pair<double, double>>& points) {
    double totalDistance = 0.0;
    for (size_t i = 1; i < points.size(); ++i) {
        totalDistance += calculate_distance(points[i - 1].first, points[i - 1].second,
                                            points[i].first, points[i].second);
    }
    return totalDistance;
}

//calculate the sum of N natural numbers
int first_N_num_sum(int N) {
    return (N * (N + 1)) / 2;
}

int main() {
    int N;
    cout << "Enter the number (N) of delivery points: ";
    cin >> N;

    vector<pair<double, double>> points(N);
    cout << "Enter the coordinates of the points (x y):" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    const double total_distance = calculate_total_distance(points);
    const int natural_num_sum = first_N_num_sum(N);

    cout << "The total distance between points is: " << total_distance << endl;
    cout << "The sum of the first " << N << " Natural Numbers is: " << natural_num_sum << endl;

    return 0;
}

//The program determines the distance between 2 delivery points at each time. It also calculates the sum of the first N natural numbers.
//The software calculates the overall distance between a collection of delivery locations as well as the sum of the first N natural integers.
//First, a function that calculates the Euclidean distance between two locations is defined using the distance formula.
//An alternative function cycles over a vector of coordinates to get the distances between successive places.
//After checking about the number of delivery sites and their coordinates from the user, the main function computes distance and the sum of natural integers.
//Finally, the total distance and the sum of the first N natural numbers are displayed to the user.