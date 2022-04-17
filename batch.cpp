#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("batch.inp");
    ofstream output("batch.out");

    if (!input) {
        cout << "file not found" << endl;
        return 0;
    }
    else {
        cout << "file read" << endl;
    }

    int N;
    int cn;
    input >> N;

    int cpu_rest = 70;
    int prog_exit = 229;

    for (int i = 0; i < N; i++) {
        int index = 0;

        while (1) {
            input >> cn;

            if (cn == -1) {
                break;
            }
            else {
                if (index % 2 == 1) {
                    cpu_rest += cn;
                }
                prog_exit += cn;
            }
            index++;
        }
    }

    output << cpu_rest << " " << prog_exit;

    input.close();
    output.close();
    return 0;
}