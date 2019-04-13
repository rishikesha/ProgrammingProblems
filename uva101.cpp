#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Piles {
    private:
        vector<vector<int>> pile;
        vector<int> x,y;

        void resetPosition(int n) {
            int xx = x[n], yy = y[n];
            for (int i = 1; pile[n][i] >= 0; i++) {
                x[pile[n][i]] = pile[n][i];
                y[pile[n][i]] = 0;
                pile[n][i] = -1;
            }
        }
    

    public:
        Piles(int n) {
            x.resize(n, 0);
            y.resize(n, 0);
            for(int i = 0; i< n; i++) {
                pile.push_back(vector<int>(n+1,-1));
                pile[i][0]= i;
                x[i] = i;
            }
        }
        void processCommand(string command, int from, string where, int to) {
            if (command == "move" and where == "onto") {
                resetPosition(from);
                resetPosition(to);
                pile[to][0] = to;
                pile[to][1] = from;
            } else if (command == "move" and where == "over") {
                resetPosition(from);
                int i = 0;
                while(pile[to][i] >= 0) i++;
                pile[to][i] = from;
            } else if(command == "pile" and where == "onto") {
                resetPosition(to);
                for (int i = 0; pile[from][i] >= 0; i++) {
                    pile[to][i+1] = pile[from][i];
                }
                resetPosition(from);
            } else if (command == "pile" and where == "over") {
                int i = 0;
                for(; pile[to][i] >= 0; i++);
                for (int j = 0; pile[from][j] >= 0; j++) {
                    pile[to][i+j] = pile[from][j];
                }
                resetPosition(from);
            }
        }

        void printResult(){
            for (int i = 0; i < pile.size(); i++) {
                cout << i <<":";
                for(int j = 0; pile[i][j] >= 0; j++) {
                    cout << " " << pile[i][j];
                }
                cout << "\n";
            }
        }


};


int main() {
    string s;
    int n;
    getline(cin,s);
    istringstream iss(s);
    iss >> n;

    Piles pile(n);

    while(true) {
        getline(cin,s);
        iss = istringstream(s);
        cout << "debug " << s << "\n";

        string command, from, where, to;
        iss >> command;
        if (command == "quit") {
            break;
        }

        iss >> from >> where >> to;


        pile.processCommand(command, stoi(from), where, stoi(to));
    }

    pile.printResult();
}
