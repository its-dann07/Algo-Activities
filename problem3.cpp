#include <iostream>
using namespace std;

// Recursive function
void tower_of_hanoi(int n, char source, char dest, char buff) {
    if (n == 1) {
        cout << "Your package has departed from " << source << " to " << dest << endl;
        return;
    }

    // Moves n-1 packages from source to buffer
    tower_of_hanoi(n - 1, source, buff, dest);

    // Move the nth package from source to destination
    cout << "Your package has departed " << n << " from " << source << " to " << dest << endl;

    // Moves n-1 packages from buffer to destination
    tower_of_hanoi(n - 1, buff, dest, source);
}
//printing
int main() {
    int N;
    cout<<" \tTOWER OF HANOI\n";
    cout << "Enter the number of packages: ";
    cin >> N;
    cout << "Number of times to move " << N << " packages:" << endl;
    tower_of_hanoi(N, 'A', 'C', 'B');

    //print total number of moves
    int total_moves = (1 << N) - 1; // 2^N - 1
    cout << "Total number of moves required: " << total_moves << endl;

    return 0;
}

//In this problem 3, we are using a recursion to further analyze how many times does an 'N' package takes to arrive on its destination.
//In line 5-19, we can see that we take 3 parameters, which are: the number of packages to be transported(n), source, destination, and the buffer.
// The base case of our function is n = 1, which prints the motion of the package.
// Else, it will recursively moves n - 1 from the source to the buffer.
// It moves the nth packages from the source to destination and then recursively moves the n - 1 package from buffer and transporting it into its destination.
// This process repeats until all packages has been moved to the destined location.

//In the last part, we print all the results of the recursion and how the process was done
//We get the total of the movement made by the package until it reaches its destination.
// Time Complexity: O 2(n)