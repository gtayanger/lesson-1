#include <iostream>
#include <exception>

using namespace std;

template<typename T>
class Stack
{
private:
    T* buffer;
    int max_size;
    int next_pos;

public:
    Stack(int max_size)
    {
        if (max_size <= 0)
            throw exception("invalid size");
        buffer = new T[max_size];
        this->max_size = max_size;
        next_pos = 0;
    }

    ~Stack()
    {
        delete[] buffer;
    }

    bool Push(T n)
    {
        if (next_pos >= max_size)
        {
            return false;
        }
        else
        {
            buffer[next_pos] = n;
            next_pos++;
            return true;
        }
    }

    bool Pop(T* ret)
    {
        if (next_pos <= 0)
        {
            return false;
        }
        else
        {
            next_pos--;
            *ret = buffer[next_pos];
            return true;
        }
    }

    int Size()
    {
        return next_pos;
    }
};

int main()
{
    Stack<int> int_stack(10);

    for (int i = 0; i < 20; i++)
        int_stack.Push(i);

    for (int i = 0; i < 20; i++)
    {
        int ret;
        int_stack.Pop(&ret);
        cout << ret << endl;
    }

    Stack<double> double_stack(10);

    for (int i = 0; i < 20; i++)
        double_stack.Push(i * 1.123);

    for (int i = 0; i < 20; i++)
    {
        double ret;
        double_stack.Pop(&ret);
        cout << ret << endl;
    }

    return 0;
}
