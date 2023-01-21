// TODO
#include <bits/stdc++.h>

using namespace std;

struct Sensor;
struct Segment;

struct Segment {
    int x;
    Sensor *below;
    explicit Segment(int x, Sensor *below = nullptr) : x(x), below(below) {}
};
struct Sensor {
    int t=0, x1, x2, y;
    map<int, Segment*> segments;
    Sensor(int x1, int x2, int y) : x1(x1), x2(x2), y(y) {}
};
struct Drop {
    int x, y, id;
    Sensor *below = nullptr;
    Drop(int x, int y, int id) : x(x), y(y), id(id) {}
};

pair<Segment*, Sensor*> get(Drop* drop, Sensor* sensor) {
//    if (sensor->segments.upper_bound(drop->x) == sensor->segments.begin()) {
//        cout << drop->x << " " << sensor->x1 << endl;
//        cout << sensor->y << " " << sensor->segments.size() << endl;
//        cout << sensor->segments.begin()->first << endl;
//        exit(1);
//    }
    // cout << sensor->x1 << " " << sensor->x2 << ", " << flush;
    // assert(sensor->segments.upper_bound(drop->x) != sensor->segments.begin());
    Segment* segment = prev(sensor->segments.upper_bound(drop->x))->second;
    if (sensor->t == 0 || sensor->t == drop->y - sensor->y) return {segment, sensor};
    auto below = get(drop, segment->below);
    // segment->below = below.second;
    return below;
}

void process(Drop* drop) {
    // cout << drop->x << " " << drop->y << ": ";
    auto[segment, sensor] = get(drop, drop->below);
    // cout << endl;
    if (sensor->y != 0) sensor->t = drop->y - sensor->y;
    drop->y = sensor->y;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int d, s;
    cin >> d >> s;
    struct endpoint_type {
        int x, y, type;
        Drop* drop; Sensor* sensor;
        endpoint_type(int x, int y, int type, Drop* drop, Sensor* sensor) : x(x), y(y), type(type), drop(drop), sensor(sensor) {}
    };
    vector<endpoint_type> endpoints;

    vector<Drop*> drops;
    for (int i = 0; i < d; i++) {
        int x, y; cin >> x >> y;
        drops.push_back(new Drop(x, y, i));
        endpoints.emplace_back(x, y, 1, drops[i], nullptr);
    }

    for (int i = 0; i < s; i++) {
        int x1, x2, y; cin >> x1 >> x2 >> y;
        auto sensor = new Sensor(x1, x2, y);
        endpoints.emplace_back(x1, y, 0, nullptr, sensor);
        endpoints.emplace_back(x2, y, 2, nullptr, sensor);
    }

    sort(endpoints.begin(), endpoints.end(), [] (const endpoint_type& a, const endpoint_type& b) {
        if (a.x == b.x) {
            // process begins, then drops, then ends?
            return a.type < b.type;
            // if (a.y == b.y) return !(bool)a.type;
            // return a.y < b.y;
        }
        return a.x < b.x;
    });

    auto bottom = new Sensor(0, 1000000010, 0);
    bottom->segments[0] = new Segment(0);
    map<int, Sensor*> m = {{0, bottom}};
    for (auto endpoint: endpoints) {
        auto[x,y,type,drop,sensor] = endpoint;
        // cout << x << " " << y << " " << type << endl;
        if (type==0) {
            auto it = m.insert({y, sensor}).first;
            assert(it != m.begin());
            sensor->segments[x] = new Segment(x, prev(it)->second);
        } else if (type==1) {
            assert(m.upper_bound(y) != m.begin());
            drop->below = prev(m.upper_bound(y))->second;
        } else if (type==2) {
            auto it = m.find(y);
            assert(it != m.end());
            if (next(it) != m.end())
                next(it)->second->segments[x+1] = new Segment(x+1, prev(it)->second);
            m.erase(y);
        }
    }

    // cout << "hi" << endl;
    sort(drops.begin(), drops.end(), [] (const Drop* a, const Drop* b) {
        return a->y < b->y;
    });
    for (auto drop: drops) process(drop);
    sort(drops.begin(), drops.end(), [] (const Drop* a, const Drop* b) {
        return a->id < b->id;
    });
    for (auto drop: drops) cout << drop->y << "\n";
}