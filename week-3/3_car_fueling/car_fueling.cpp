#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    if(tank >= dist) return 0;
    
    int location    =   tank, 
        cur_stop    =   0,
        total_stops =   0;

    while(location < dist) { 
        if(stops[0] > location) return -1; 
        ++total_stops; 
        while(stops.size() > 0 && stops[0] <= location) {
            cur_stop = stops[0]; 
            stops.erase(stops.begin()); 
        }
        location = cur_stop + tank; 
        if(stops.empty()) break; 
    }

    if(dist > location) return -1; 

    return total_stops; 
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
