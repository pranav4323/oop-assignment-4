#include <iostream>
using namespace std;

class de
{
private:
    int x;

public:
    de()
    {
        x = 0;
        cout << "\nConstructor!";
    }
    void set()
    {
        cout << "\nvalue :";
        cin >> x;
    }
    void put()
    {
        cout << "\nValue : " << x;
    }
    ~de()
    {
        cout << "\nDestructor !";
    }
};

class op
{
private:
    int x;

public:
    void set()
    {
        cout << " value :";
        cin >> x;
    }
    op operator+(op &o)
    {
        op temp;
        temp.x = x + o.x;
        return temp;
    }
    void put()
    {
        cout << "\nValue: " << x;
    }
};

void fun(int x)
{
    cout << "\n function of 1 parameter : " << x;
}
void fun(int x, int y)
{
    cout << "\n function of 2 parameter  : " << x << " " << y;
}

class f
{
private:
    int temp;

public:
    void set()
    {
        cout << "\n value :";
        cin >> temp;
    }
    void put()
    {
        cout << "\nValue: " << temp;
    }
    friend void swap(f &x, f &y);
};
void swap(f &a, f &b)
{
    int temp;
    temp = a.temp;
    a.temp = b.temp;
    b.temp = temp;
}

class y
{
protected:
    int x;

public:
    y()
    {
        x = 5;
    }
    virtual void set() = 0;
};
class A : virtual public y
{
protected:
    int a;

public:
    void set()
    {
        cout << "\n value :";
        cin >> a;
    }
    void get()
    {
        cout << "\nAdded Value : " << (a + a);
    }
};
class B : virtual public y
{
protected:
    int y;

public:
    void set()
    {
        cout << "\nEnter value :";
        cin >> y;
    }
    void get()
    {
        cout << "\nAdded Value at Object: " << (y + x);
    }
};
class C : public A, public B
{
protected:
    int ch;

public:
    void set()
    {
        cout << "\nEnter 3 values :";
        cin >> x >> y >> ch;
    }
    void get()
    {
        cout << "\nAdded Value : " << (x + y + ch + x);
    }
};

template <class T>
class Template
{
private:
    T x, y;

public:
    void set()
    {
        cout << "\n two values :";
        cin >> x >> y;
    }
    void get()
    {
        cout << "\nAdded Value : " << (x + y);
    }
};

void division()
{
    int x, y;
    cout << "\nnumerator :";
    cin >> x;
    cout << "\n denominator :";
    cin >> y;
    try
    {
        if (y == 0)
            throw 'A';
        else
            cout << "\nResult : " << (x / y);
    }
    catch (char k)
    {
        cout << "\n not possible, if denominator is 0";
    }
}

int main()
{
    int ch, x;
    while (1)
    {

        cout << "\n1.class,objects,constructors and destructors";
        cout << "\n2. adding of 2 objects using operator overloading";
        cout << "\n3. function overloading";
        cout << "\n4. swaping private data of 2 objects by friend function";
        cout << "\n5. inheritance,virtual base class,virtual functions";
        cout << "\n6. adding 2 int and float variables by template class";
        cout << "\n7. Division of integers using exception handling";
        cout << "\n8.Cancel";
        cout << "\n choice: ";
        cin >> ch;
        if (ch == 1)
        {
            de o;
            o.set();
            o.put();
        }
        else if (ch == 2)
        {
            op o1, o2, o3;
            cout << "\n Object 1:";
            o1.set();
            cout << "\n Object 2:";
            o2.set();
            o3 = o1 + o2;
            cout << "\n Object 3:";
            o3.put();
        }
        else if (ch == 3)
        {
            fun(4);
            fun(3, 5);
        }
        else if (ch == 4)
        {
            f f1, f2;
            cout << "\nObject 1:";
            f1.set();
            cout << "\nObject 2:";
            f2.set();
            swap(f1, f2);
            cout << "\nAfter swaping:";
            cout << "\nObject 1:";
            f1.put();
            cout << "\nObject 2:";
            f2.put();
        }
        else if (ch == 5)
        {
            A a1;
            B b1;
            C c1;
            cout << "\nObject of A:";
            a1.set();
            a1.get();
            cout << "\nObject of B:";
            b1.set();
            b1.get();
            cout << "\nObject of C:";
            c1.set();
            c1.get();
        }
        else if (ch == 6)
        {
            Template<int> t1;
            Template<float> fl1;
            cout << "\nInteger Variables:";
            t1.set();
            t1.get();
            cout << "\nFloat Variables:";
            fl1.set();
            fl1.get();
        }
        else if (ch == 7)
        {
            division();
        }
        else if (ch == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\nTRY AGAIN!";
        }
    }
    return 0;
}
