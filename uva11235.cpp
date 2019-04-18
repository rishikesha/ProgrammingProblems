#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
struct Node {
    int maxfreq; //max freq in this interval
    int beginlen; // len of beginning seq
    int traillen; // len of trailing seq
    int beginint;
    int trailint;
    Node (int mf, int bl, int tl, int bc, int tc ) : maxfreq(mf), beginlen(bl), traillen(tl),
    beginint(bc), trailint(tc){}
    Node() {
        Node(0,0,0,' ',' ');
    }

    bool operator ==(Node other) {
        return maxfreq == other.maxfreq and beginlen == other.beginlen 
            and traillen == other.traillen and trailint == other.trailint
            and beginint == other.beginint;
    }
};

Node invalid = Node(0,0,0,' ', ' ');

class SegmentTree {
    private:
        vector<Node> st;
        vector<int> v;
        int vsize;

        int left(int n) {return n << 1;}
        int right(int n) {return (n << 1) + 1;}

        void build(int p, int L, int R) {
            if (L==R) {
                st[p] = Node(1,1,1, v[L], v[R]);
            } else {
                int lp = left(p), rp = right(p);
                build(lp, L, (L+R)/2);
                build(rp, (L+R)/2+1, R);

                int bl, tl; // length of beginning and trailling int
                int mf = max(st[lp].maxfreq, st[rp].maxfreq);
                if (v[(L+R)/2] == v[(L+R)/2 + 1])
                    mf = max(mf, st[lp].traillen + st[rp].beginlen);

                tl = st[rp].traillen;
                if (v[(L+R)/2] == v[R]) {
                    tl += st[lp].traillen;
                } 

                bl = st[lp].beginlen;
                if (v[(L+R)/2+1] == v[L] ) {
                    bl += st[rp].beginlen;
                } 

                st[p] = Node(mf, bl, tl, v[L], v[R]);
            }
        }

        Node query(int p, int i, int j, int L, int R) {
            if (i > R or j < L)
                return invalid;
            if (L >= i and R<=j)
                return st[p];

            Node n1 = query(left(p), i, j, L, (L+R)/2);
            Node n2 = query(right(p), i, j,(L+R)/2+1, R);
            if (n1 == invalid)
                return n2;
            if (n2 == invalid)
                return n1;

            auto n = join(n1, n2);
            return n;
        }

        Node join(Node n1, Node n2) {

            int mf= max(n1.maxfreq, n2.maxfreq);
            int beginint = n1.beginint;
            int trailint = n2.trailint;
            int beginlen = n1.beginlen;
            int traillen = n2.traillen;

            if (n1.trailint == n2.beginint)
                mf = max(mf, n1.traillen + n2.beginlen);

            if (n1.beginint == n2.beginint)
                beginlen += n2.beginlen;

            if (n2.trailint == n1.trailint)
                traillen += n1.traillen;

            return Node(mf, beginlen, traillen, beginint, trailint);
        

        }

    public:
        SegmentTree (vector<int> &v_)  {
            v = std::move(v_);
            vsize = v.size();
            st.resize(4*vsize);
            build(1, 0, vsize-1);
        }

        int query (int i, int j) {
            return query(1, i-1, j-1, 0, vsize-1).maxfreq;
        }


};

int main() {
    vector<int> v;
    int n, q;
    while(cin>> n, n != 0) {
        v.clear();
        cin >> q;
        for(int i =0; i< n; i++) {
            int t; cin >> t;
            v.push_back(t);
        }

        SegmentTree sg(v);

        for(int i = 0; i < q; i++) {
            int lend, rend; cin >> lend >> rend;
            cout << sg.query(lend, rend) << "\n";;
        }
    }
}
