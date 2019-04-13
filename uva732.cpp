/* Rishikesh
 * UVA 732: Anagrams by stack
 */

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
vector<string> transform(stack<char> st, string source, string target, string seq) {
    if (st.size() + source.length() != target.length()) {
        return vector<string>();
    }

    vector<string> answer;

    if (target.length() == 0)
        return {seq};

    if (source.length()) {
        st.push(source[0]);
        vector<string> t = transform(st, source.substr(1), target, seq + " i");
        answer.insert(answer.end(), t.begin(), t.end());
        st.pop();
    }

    if (not st.empty() and st.top() == target[0]) {
        st.pop();
        vector<string> t = transform(st, source, target.substr(1), seq + " o");
        answer.insert(answer.end(), t.begin(), t.end());
    }

    return answer;
}

int main() {
    string source, target;
    while(getline(cin, source), source.length()) {
        getline(cin, target);
        vector<string> v = transform(stack<char>(), source, target, "");
        cout << "[\n";
        for (auto s : v) 
            cout << s.substr(1) << "\n";
        cout << "]\n";
    }
}
