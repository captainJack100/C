#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Time
{
    int h;
    int m;
    int s;
    string name;
} Time;

class CompareTime
{
    public:
        bool operator()(Time& t1, Time& t2)
        {
            if(t1.h < t2.h) return true;
            if(t1.h == t2.h && t1.m < t2.m) return true;
            if(t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
        }
};

class Shape
{
    public:
        Shape(int a, int b, int c, string n):aa(a), bb(b), cc(c), name(n)
        {
        }
        string getName()
        {
            return name;
        }
    private:
        int aa;
        int bb;
        int cc;
        string name;
};

int main(void)
{
    priority_queue<Time, vector<Time>, CompareTime> pq;
    vector<Shape> vec;
    Time t[4] = { {3,2,40, "one"}, {3,2,26, "two"}, {5, 16, 13, "three"}, {5,15,20, "four"} };
    Shape tt[4] = {Shape(1,1,1,"one"), Shape(2,2,2,"two"), Shape(3,3,3,"three"), Shape(4,4,4,"four")};

    for(int i = 0; i < 4; i++)
    {
        pq.push(t[i]);
        vec.push_back(tt[i]);
    }

    while (!pq.empty())
    {
        cout << pq.top().name << endl;
        pq.pop();
    }

    while (!vec.empty())
    {
        cout << vec.back().getName() << endl;
        vec.pop_back();
    }

    return 0;
}



