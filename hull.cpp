#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

bool direction(Point pi, Point pj, Point pk){
    Point p, q;
    p.x = pk.x - pi.x;
    p.y = pk.y - pi.y;
    q.x = pj.x - pi.x;
    q.y = pj.y - pi.y;
    bool ans = ((p.x * q.y - p.y * q.x) < 0) ? true : false;
    return ans;
}

void convexHull(Point points[], int n) {
    if(n<3){
        cout<<"At least 3 points are required to form a convex hull"<<endl;
    }
    vector<Point> hull;
    int left = 0;
    for (int i=1; i<n; i++)
        if (points[i].x < points[left].x)
            left = i;
    int p = left, q;
    do{
        hull.push_back(points[p]);
        q = (p+1)%n;
        for(int i=0; i<n; i++){
            if(direction(points[p], points[i], points[q])){
                q = i;
            }
        }
        p = q;
    }while(p != left);
    cout<<"\nPoints in the Convex Hull"<<endl;
    for(int i=0; i<hull.size(); i++){
        cout<<hull[i].x<<","<< hull[i].y<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number of distinct points to form convex hull : ";
    cin>>n;
    Point points[n];
    cout<<"Enter the co-ordinates of the points"<<endl;
    for(int i=0; i<n; i++){
        cin>>points[i].x>>points[i].y;
    }
    convexHull(points, n);
    return 0;
}