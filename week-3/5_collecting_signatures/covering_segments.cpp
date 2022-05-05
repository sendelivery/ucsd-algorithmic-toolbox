#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool segment_compare(Segment const& lhs, Segment const& rhs) {
  if(lhs.end < rhs.end)
    return 1;
  else
    return 0;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  std::sort(segments.begin(), segments.end(), segment_compare);
  
  while (segments.size() > 0) {
    int min_end = segments[0].end;
    while(segments.size() > 0) {
      if(segments[0].start <= min_end)
        segments.erase(segments.begin());
      else 
        break;
    }
    points.push_back(min_end);
  }

  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

// n number of segments 1 <= n <= 100
// each segment has a start (a) and a finish (b) 0 <= a <= b <= 10^9
// output number of lines and then which coordinate the lines are drawn