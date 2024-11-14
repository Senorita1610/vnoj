#include <bits/stdc++.h>

using ld = long double;
const ld eps = 1e-9;
using namespace std;

struct point {
    ld x, y;
    point operator-(const point& p) { return { x-p.x, y-p.y }; };
    bool operator%(const point& p) { return x*p.y - p.x*y > 0; }
};

int main() {
    int tc;
    std::cin>>tc;
    while(tc--){
        int x1, x2, x3, y1, y2, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
        int A = 2*(x1-x2), B = 2*(y1-y2), C = 2*(x1-x3), D = 2*(y1-y3);
        int E = x1*x1 - x2*x2 + y1*y1 - y2*y2, F = x1*x1 - x3*x3 + y1*y1 - y3*y3;
    
        ld cy = (A*F - C*E)/ld(A*D-B*C), cx = (D*E - B*F)/ld(A*D-B*C);
        ld r = std::sqrt(x1*x1 - 2*x1*cx + cx*cx + y1*y1 - 2*y1*cy + cy*cy);
    
        point c { cx, cy };
        point v1 = { x1-cx, y1-cy }; 
        point v2 = { x2-cx, y2-cy }; 
        point v3 = { x3-cx, y3-cy }; 
        auto z1 = v1%v3, z2 = v1%v2, z3 = v3%v2, z4 = v1%v2;
        bool inside = v1%v3 == v1%v2 && v3%v2 == v1%v2;
        point pts[4] = { { cx, cy+r }, { cx, cy-r }, { cx-r, cy }, { cx+r, cy } };
        point m { std::min(x1, x2), std::min(y1, y2) }, M { std::max(x1, x2), std::max(y1, y2) };
    
        for(int i = 0; i < 4; i++) {
            if((v1%(pts[i]-c) == v1%v2 && (pts[i]-c)%v2 == v1%v2) == inside) {
                m.x = std::min(m.x, pts[i].x);
                m.y = std::min(m.y, pts[i].y);
                M.x = std::max(M.x, pts[i].x);
                M.y = std::max(M.y, pts[i].y);
            }
        }
        auto W = std::ceil(M.x-eps)-std::floor(m.x+eps), H = (std::ceil(M.y-eps)-std::floor(m.y+eps));
        std::cout << int(W)*int(H)<<endl;
    }
}

