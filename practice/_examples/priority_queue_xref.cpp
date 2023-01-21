/**
 * This example shows how to cross-reference priority queues
 * and other containers. I.e., using an associative container to
 * map keys to entries in a priority queue, and using the priority
 * queue to map entries to the associative container. The combination
 * can be used for fast operations involving both priorities and
 * arbitrary keys.
 *
 * The most useful examples of this technique are usually from the
 * field of graph algorithms (where erasing or modifying an arbitrary
 * entry of a priority queue is sometimes necessary), but a full-blown
 * example would be too long. Instead, this example shows a very simple
 * version of Dijkstra's
 */

#include <iostream>
#include <cassert>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace pb_ds;
using namespace pb_ds;

// A priority queue of integers, which supports fast pushes,
// duplicated-int avoidance, and arbitrary-int erases.
class mapped_priority_queue
        {
        public:

            // Pushes an int into the container. If the key is already in, this
            // is a no-op.
            void
            push(const int& r_str);

            // Returns a const reference to the largest int in the container.
            const int
            top() const
            {
                assert(!empty());
                return m_pq.top();
            }

            // Erases the largest int in the container.
            void
            pop();

            // Erases an arbitrary int. If the int is not in the container, this
            // is a no-op, and the return value is false.
            bool
            erase(const int& r_str);

            bool
            empty() const
            { return m_pq.empty(); }

            size_t
            size() const
            { return m_pq.size(); }

        private:
            // A priority queue of strings.
            typedef pb_ds::priority_queue< int> pq_t;

            // A hash-table mapping strings to point_iterators inside the
            // priority queue.
            typedef cc_hash_table< int, pq_t::point_iterator> map_t;

            pq_t m_pq;
            map_t m_map;
        };

void
mapped_priority_queue::
push(const int& r_str)
{
    // First check if the int is already in the container. If so, just return.
    if (m_map.find(r_str) != m_map.end())
        return;

    // Push the int into the priority queue, and store a point_iterator to it.
    pq_t::point_iterator pq_it = m_pq.push(r_str);

    try
    {
        // Now make the map associate the int to the point_iterator.
        m_map[r_str] = pq_it;
    }
    catch(...)
    {
        // If the above failed, we need to remove the int from the
        // priority queue as well.
        m_pq.erase(pq_it);
        throw;
    }
}

void
mapped_priority_queue::
pop()
{
    assert(!empty());

    // Erase the int from the map.
    m_map.erase(m_pq.top());

    // ...then from the priority queue.
    m_pq.pop();
}

bool
mapped_priority_queue::
erase(const int& r_str)
{
    map_t::point_iterator map_it = m_map.find(r_str);

    // If the int is not in the map, this is a no-op.
    if (map_it == m_map.end())
        return false;

    // Otherwise, we erase it from the priority queue.
    m_pq.erase(map_it->second);

    // ...then from the map.
    m_map.erase(r_str);

    return true;
}

int main()
{
    // Push some values into the container object.
    mapped_priority_queue m;
    m.push(1);
    m.push(2);

    // The following four operations are no-ops: 2 and 1 are already in
    // the container.
    m.push(2);
    m.push(2);
    m.push(2);
    m.push(1);

    m.push(10);
    m.push(11);
    m.push(12);

    // The size should be 5, since m contains the set {1, 2, 10, 11, 12}.
    assert(m.size() == 5);

    // The largest value should be 12.
    assert(m.top() == 12);

    // Now erase some values.

    // Erasing 1 actually erases a value.
    assert(m.erase(1));

    // ...but erasing 1 again is a no-op.
    assert(!m.erase(1));

    // The size should be 5, since m contains the set {2, 10, 11, 12}.
    assert(m.size() == 4);

    // Now print the values in the container.
    while (!m.empty())
    {
        cout << m.top() << endl;
        m.pop();
    }

    return 0;
}

