/**
 * This example shows how to split and join priority queues.
 */

#include <functional>
#include <iostream>
#include <cassert>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace pb_ds;
using namespace pb_ds;

int
main()
{
    // Two priority queue objects.
    pb_ds::priority_queue<int> even_p, odd_p;

    // First we insert some values: even ones into even_p, and odd ones
    // into odd_p.
    for (size_t i = 0; i < 10; ++i)
    {
        even_p.push(2*  i);
        odd_p.push(2*  i + 1);
    }

    // Check that each one contains the appropriate 10 values.
    assert(even_p.size() == 10);
    assert(even_p.top() == 18);

    // Print out the values.
    cout << "Initial values in even priority queue:" << endl;
    pb_ds::priority_queue<int>::const_iterator it;
    for (it = even_p.begin(); it != even_p.end(); ++it)
        cout <<* it << endl;

    assert(odd_p.size() == 10);
    assert(odd_p.top() == 19);

    // Print out the values.
    cout << "Initial values in odd priority queue:" << endl;
    for (it = odd_p.begin(); it != odd_p.end(); ++it)
        cout <<* it << endl;

    // Now join the queues.
    even_p.join(odd_p);

    // Check that each one contains the appropriate values.

    assert(even_p.size() == 20);
    assert(even_p.top() == 19);

    // Print out the values.
    cout << "After-join values in even priority queue:" << endl;
    for (it = even_p.begin(); it != even_p.end(); ++it)
        cout <<* it << endl;

    assert(odd_p.size() == 0);

    // Print out the values.
    cout << "After-join values in odd priority queue:" << endl;
    for (it = odd_p.begin(); it != odd_p.end(); ++it)
        cout <<* it << endl;

    // Now split the queues.
    even_p.split(bind2nd(modulus<int>(), 2), odd_p);

    // Check that each one contains the appropriate 10 values.

    assert(even_p.size() == 10);
    assert(even_p.top() == 18);

    // Print out the values.
    cout << "After-split values in even priority queue:" << endl;
    for (it = even_p.begin(); it != even_p.end(); ++it)
        cout <<* it << endl;

    assert(odd_p.size() == 10);
    assert(odd_p.top() == 19);

    // Print out the values.
    cout << "After-split values in odd priority queue:" << endl;
    for (it = odd_p.begin(); it != odd_p.end(); ++it)
        cout <<* it << endl;

    return 0;
}

