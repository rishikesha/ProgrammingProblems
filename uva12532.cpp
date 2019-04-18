#include<vector>
#include<iostream>
#include<string>
#include<sstream>


using namespace std;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class SegmentTree {
    private:
        vector<int> st;
        int sz;

        int left(int i) { return (i<<1);}
        int right(int i) {return 1|(i<<1);}

        void build(int p, int L, int R, vector<int>& v) {
            if(L==R) {
                st[p] = sgn(v[L]);
            } else {
                build(left(p), L, (L+R)/2, v);
                build(right(p), (L+R)/2 +1,R, v);
                st[p] = st[left(p)] * st[right(p)];
            }
        }

        void update(int p, int L, int R, int i, int val) {
            if (L == i and R == i)
                st[p] = sgn(val);
            else { 
                if ( i <= (L+R)/2) 
                    update(left(p), L, (L+R)/2, i, val);
                else 
                    update(right(p), (L+R)/2 + 1, R, i, val);

                st[p] = st[left(p)] * st[right(p)];
            }
        }

        int inspect(int p, int L, int R, int first, int last) {
            if (last < L or first > R)
                return 1;

            if (first <= L and R <= last)
                return st[p];

            int l = inspect(left(p), L, (L+R)/2, first, last);
            int r = inspect(right(p), (L+R)/2 + 1, R, first, last);
            return l*r;
        }


    public:

        SegmentTree(vector<int>& v) : sz(v.size()){
            st.resize(4*sz);
            build(1, 0, sz-1, v);
        }

        void update(int i, int val) {
            update(1,0,sz-1, i-1, val);
        }

        int inspect(int first, int last) {
            return inspect(1, 0, sz-1, first-1, last-1);
        }
};


int main() {
    string s;
    while(getline(cin,s), s.length()) {
        istringstream iss(s);
        vector<int> v;
        int n, k;
        iss >> n >> k;
        getline(cin, s);
        iss = istringstream(s);
        for(int i=0; i< n; i++) {
            int tmp; iss >> tmp;
            v.push_back(tmp);
        }

        SegmentTree st(v);

        for (int i = 0; i < k ; i++) {
            getline(cin,s); iss = istringstream(s);
            char c; int ft, sd, r ;
            iss >> c >> ft >> sd;
            switch(c) {
                case 'P': 
                    r = st.inspect(ft,sd);
                    if(r>0) 
                        cout<<"+"; 
                    else if(r<0) 
                        cout <<"-";
                    else 
                        cout <<"0";
                    break;
                case 'C':
                    st.update(ft,sd);
                    break;
            }

        }
        cout << "\n";
    }
}
