#include <iostream>
#include <list>
#include <iterator>
#include <utility>

using namespace std;
list < pair <int,int> >::iterator it,it_1;

void print(list < pair <int,int> > lst)
{
    for (it = lst.begin(); it != lst.end(); it++)
    {
        it_1 = it;
        it_1++;
        cout << "(" << (*it).second << ")" << "x^" << (*it).first;
        if((it_1) != lst.end())
            cout << " + ";
    }
}

pair <int,int> operator * (int n, pair <int,int> p)
{
    p.second = p.second*n;
    return p;
}

list < pair <int,int> > operator * (list < pair <int,int> > lst, int a)
{
    for (it = lst.begin(); it != lst.end(); it++)
    {
        *it = a*(*it);
    }
    return lst;
}

list < pair <int,int> > operator * (list < pair <int,int> > lst, pair <int,int> p)
{
    for (it = lst.begin(); it != lst.end(); it++)
    {
        (*it).first = (*it).first + p.first;
    }
    lst = lst * p.second;
    return lst;
}

list < pair <int,int> > operator + (list < pair <int,int> > lst1, list < pair <int,int> > lst2)
{
    list < pair <int,int> > lst3;
    it = lst1.begin();
    it_1 = lst2.begin();

    while(it != lst1.end() && it_1 != lst2.end())
    {
        if ((*it).first > (*it_1).first)
        {
            lst3.push_back(*it);
            it++;
        }

        if ((*it).first < (*it_1).first)
        {
            lst3.push_back(*it_1);
            it_1++;
        }

        if ((*it).first == (*it_1).first)
        {
            (*it).second = (*it).second + (*it_1).second;
            lst3.push_back(*it);
            it++;
            it_1++;
        }
    }

    while (it != lst1.end())
    {
        lst3.push_back(*it);
        it++;
    }

    while (it_1 != lst2.end())
    {
        lst3.push_back(*it_1);
        it_1++;
    }
    return lst3;
}

list < pair <int,int> > operator - (list < pair <int,int> > lst1, list < pair <int,int> > lst2)
{
    lst2 = lst2*(-1);
    lst1 = lst1 + lst2;
    return lst1;
}

int main()
{
    int i,j;
    cout << "Nomer: " << endl;
    cin >> j;
    pair <int,int> p;
    pair <int,int> p1;
    list < pair <int,int> > T[10];
    list < pair <int,int> > T1, T2, T3;

    p.first = 0;
    p.second = 1 ;

    p1.first = 1;
    p1.second = 2;

    T[0].push_front(p);
    T1.push_front(p);

    p.first = 1;
    p.second = 1;

    T[1].push_front(p);
    T2.push_front(p);

    for(i = 2; i < 10; i++)
    {
        T[i] = T[i-1]*p1 - T[i-2];
    }

    for(i = 0; i < 10; i++)
    {
        print(T[i]);
        cout << endl;
    }

    for (i = 2; i < j+1; i++)
    {
        T3 = T2*p1 - T1;
        T1 = T2;
        T2 = T3;
    }

    cout << endl;

    if (j == 0) print(T[0]);
    if (j == 1) print(T[1]);
    if (j > 1) print(T3);

    return 0;
}
