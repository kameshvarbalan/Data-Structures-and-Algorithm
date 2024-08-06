#include <iostream>
using namespace std;

struct Point{
    int x,y;
};

bool on_segment(Point pi, Point pj, Point pk){
    if(min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y)){
        return true;
    }
    return false;
}

int direction(Point pi, Point pj, Point pk){
    Point p, q;
    p.x = pk.x - pi.x;
    p.y = pk.y - pi.y;
    q.x = pj.x - pi.x;
    q.y = pj.y - pi.y;
    return (p.x*q.y - p.y*q.x);
}

void intersect(Point p1, Point p2, Point p3, Point p4){
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) && ((d3<0 && d4>0) || (d3>0 && d4<0))){
        cout<<"Line 1 and Line 2 intersect each other"<<endl;
    }
    else if(d1==0 && d2==0 && (on_segment(p3,p4,p1) || on_segment(p3,p4,p2))){
        cout<<"Line 1 and Line 2 are collinear and Line 1 lies on Line 2"<<endl;
    }
    else if(d3==0 && d4==0 && (on_segment(p1,p2,p3) || on_segment(p1,p2,p4))){
        cout<<"Line 1 and Line 2 are collinear and Line 2 lies on Line 1"<<endl;
    }
    else if((d1==0 && d2==0) || (d3==0 && d4==0)){
        cout<<"Line 1 and Line 2 are collinear but do not lie on each other"<<endl;
    }
    else if(d1==0 && on_segment(p3,p4,p1)){
        cout<<"Point 1 lies on Line 2 and they intersect"<<endl;
    }
    else if(d2==0 && on_segment(p3,p4,p2)){
        cout<<"Point 2 lies on Line 2 and they intersect"<<endl;
    }
    else if(d3==0 && on_segment(p1,p2,p3)){
        cout<<"Point 3 lies on Line 1 and they intersect"<<endl;
    }
    else if(d4==0 && on_segment(p1,p2,p4)){
        cout<<"Point 4 lies on Line 1 and they intersect"<<endl;
    }
    else{
        cout<<"Line 1 and Line 2 do not intersect each other"<<endl;
    }
}

int main(){
    Point p1, p2, p3, p4;
    cout<<"Enter (x,y) co-ordinate for point 1 on line 1 : ";
    cin>>p1.x>>p1.y;
    cout<<"Enter (x,y) co-ordinate for point 2 on line 1 : ";
    cin>>p2.x>>p2.y;
    cout<<"Enter (x,y) co-ordinate for point 3 on line 2 : ";
    cin>>p3.x>>p3.y;
    cout<<"Enter (x,y) co-ordinate for point 4 on line 2 : ";
    cin>>p4.x>>p4.y;
    cout<<"\n";
    intersect(p1, p2, p3, p4);
    return 0;
}