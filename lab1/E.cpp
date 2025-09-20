#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> boris;
    queue<int> nurik;

    for (int i = 0; i < 5; i++)
    {
        int pusa;
        cin >> pusa;
        boris.push(pusa);
    }

    for (int i = 0; i < 5; i++)
    {
        int pusa;
        cin >> pusa;
        nurik.push(pusa);
    }

    int moves = 0;
    const int max_move = 1000000;

    while (!boris.empty() && !nurik.empty() && moves < max_move)
    {
        int b = boris.front();
        boris.pop();
        int n = nurik.front();
        nurik.pop();

        bool borwin = false;

        if (b == 0 && n == 9)
        {
            borwin = true;
        }
        else if (b == 9 && n == 0)
        {
            borwin = false;
        }
        else if (b > n)
        {
            borwin = true;
        }
        else
        {
            borwin = false;
        }

        if (borwin)
        {
            boris.push(b);
            boris.push(n);
        }
        else
        {
            nurik.push(b);
            nurik.push(n);
        }

        moves++;
    }

    if (moves >= max_move)
    {
        cout << "blin nichya";
    }
    else if (boris.empty())
    {
        cout << "Nursik " << moves;
    }
    else
    {
        cout << "Boris " << moves;
    }
}
