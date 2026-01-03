using namespace std;
#include "std_lib_facilities.h"

int main() {
    // random 4-digit secret between 0–9

    int p = randint(10);
    int l = randint(10);
    int m = randint(10);
    int n = randint(10);
    vector<int> answer = {p, l, m, n};

    cout << "Mastermind (4 numbers 0 to 9). Enter 4 integers (EOF to quit)\n";

    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        vector<int> guess = {a, b, c, d};

        // mark matched positions 
        vector<int> usedAnswer(4, 0);
        vector<int> usedGuess(4, 0);

        int reds = 0;
        int whites = 0;

        // 1. Count reds (exact matches)
        for (int i = 0; i < 4; ++i) {
            if (guess[i] == answer[i]) {
                ++reds;
                usedAnswer[i] = 1;
                usedGuess[i] = 1;
            }
        }

        // 2. Count whites (correct number, wrong position)
        for (int i = 0; i < 4; ++i) {
            if (usedGuess[i]) continue;
            for (int j = 0; j < 4; ++j) {
                if (!usedAnswer[j] && guess[i] == answer[j]) {
                    ++whites;
                    usedAnswer[j] = 1;
                    break;
                }
            }
        }

        cout << "reds: " << reds << "  whites: " << whites << '\n';
        cout << "Enter next guess (4 ints):\n";
    }

    cout << "Goodbye!\n";
    return 0;
}
