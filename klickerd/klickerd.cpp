#include <iostream>
#include <Windows.h>
#include <vector>
#include <utility>
#include <thread>
#include<conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    vector<pair<int, int>> got;
    vector<pair<int, int>>v;
    POINT curs;
    int cont = 0;
    char input;
    vector<int>counter;
    cout << "Press <L> to write points, <Z> to do and, <O> to do , and <Q> to exit." << endl;

    while (true)
    {
        if (_kbhit())
        {
            input = _getch();

            if (input == 'L' || input == 'l')
            {
                v.clear(), got.clear();
                cout << "Recording points. Press <C> to stop recording or <0> to cancel" << endl;
                while (true)
                {
                    if (_kbhit())
                    {
                        input = _getch();
                        if (input == 'C' || input == 'c')
                            break;
                        else if (input == '0')
                        {
                            got.clear();
                            cout << "Registration cancelled." << endl;
                            break;
                        }
                    }

                    GetCursorPos(&curs);
                    got.push_back(make_pair(curs.y, curs.x));
                    this_thread::sleep_for(chrono::milliseconds(40));
                    if (input == 'V' || input == 'v') {
                        v.push_back(make_pair(curs.y, curs.x));
                        this_thread::sleep_for(chrono::milliseconds(40));

                    }
                    ;
                }
            }
            else if (input == 'Z' || input == 'z')
            {

                for (const auto& point : got)
                {
                    SetCursorPos(point.second, point.first);
                    this_thread::sleep_for(chrono::milliseconds(22));
                }
            }
            else if (input == 'O' || input == 'o')
            {

                int j = 0;
                int i = 0;
                int push = 0;
                while (i < got.size())
                {
                    push = 0;
                    SetCursorPos(got[i].second, got[i].first);
                    this_thread::sleep_for(chrono::milliseconds(22));

                    if (v[j].first == got[i].first && v[j].second == got[i].second && push < v.size())
                    {
                        this_thread::sleep_for(chrono::milliseconds(22));
                        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, v[j].second, v[j].first, 0, 0);
                        ++j;
                    }

                    ++i;
                }
            }
            else if (input == 'Q' || input == 'q')
            {
                break;
            }
        }
    }

    return 0;
}
