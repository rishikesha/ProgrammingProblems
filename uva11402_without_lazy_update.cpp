/* Rishikesh
 * UVA 11402
 * Lazy updates have to be implemented otherwise TLE
 */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>

using namespace std;

class SegmentTree {
    private:
        vector<int> st, v;
        int sz;

        int left(int i) { return (i << 1);}
        int right(int i) { return 1 + (i << 1);}

        void build(int p, int L, int R) {
            if ( L==R)
                st[p] = v[L]; // count the number of 1
            else {
                build(left(p), L, (L+R)/2);
                build(right(p), (L+R)/2 + 1, R);
                st[p] = st[left(p)] + st[right(p)];
            }
        }

        void update(int p, int L, int R, int i, int newpirate) {
            if (L== i and R == i) {
                st[p] = newpirate;
                v[i] = newpirate;
            }
            else {
                if (i <= (L+R)/2)
                    update(left(p), L, (L+R)/2, i, newpirate);
                else
                    update(right(p), (L+R)/2+1, R, i, newpirate);

                st[p] = st[left(p)] + st[right(p)];
            }
        }

        int query(int p, int L, int R, int i, int j) {
            if (L > j or R < i)
                return 0;
            if (i <= L and j>=R)
                return st[p];

            return query(left(p), L, (L+R)/2, i, j) +
                query(right(p), (L+R)/2 + 1, R, i, j);
        }

    public:
        SegmentTree(string pirates) {
            for(char c : pirates) {
                v.push_back(c == '0'? 0 : 1);
            }
            sz = pirates.length();
            st.resize(4*sz);
            build(1,0, sz-1);
        }

        void update(int newpirate, int i) {
            update(1, 0, sz - 1, i, newpirate);
        }
        void update(int newpirate, int first, int last) {
            for (int i = first; i<= last; i++)
                if (v[i] != newpirate) {
                    update(newpirate,i);
                }
        }

        void invert(int first, int last) {
            for (int i = first; i <= last; i++) {
                update(1-v[i], i);
            }
        }

        int query(int i, int j) {
            return query(1, 0, sz-1, i, j);

        }
};

int main() {
    int ncases;
    cin >> ncases;
    for(int caseno=1; caseno <= ncases; caseno++) {
        string pirates="", s;
        printf("Case %d:\n", caseno);
        int m;
        cin >>  m;
        while (m--) {
            int t;
            cin >> t;
            cin >> s;
            while (t--) {
                pirates += s;
            }
        }

        // Initialize segmenttree
        SegmentTree st(pirates);


        //process queries
        int nqueries, qu=0;
        cin >> nqueries;
        while (nqueries--) {
            int fst, lst;
            char cs;
            cin >> cs >> fst >> lst;
            switch(cs) {
                case 'F':
                    st.update(1,fst,lst);
                    break;
                case 'E':
                    st.update(0,fst,lst);
                    break;
                case 'I':
                    st.invert(fst, lst);
                    break;
                case 'S':
                    printf("Q%d: %d\n", ++qu, st.query(fst, lst));
                    break;
            }

        }
    }
    return 0;
}

