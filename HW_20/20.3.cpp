#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

struct Point {
    int x,y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y,2));
}

vector<Point> readPoints(const string& filename) {
    ifstream f(filename);
    vector<Point> points;
    char ignore;
    int x,y;
    while (f >> ignore >> x >> ignore >> y >> ignore) {
        points.push_back({x, y});
    }

    return points;
}

map<double, vector<pair<Point, Point>>> createSegments(const vector<Point>& points) {
    map<double, vector<pair<Point, Point>>> segments;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double length = distance(points[i], points[j]);
            segments[length].push_back({points[i], points[j]});
        }
    }
    return segments;
}

void writeFile(const string& filename, const map<double, vector<pair<Point, Point>>>& segments) {
    ofstream f(filename);
    for (const auto& [length,pairs] : segments) {
        for (const auto& [p1,p2] : pairs) {
            f << "(" << p1.x << ", " << p1.y << ") - ("
                 << p2.x << ", " << p2.y << ") : "
                 << length << endl;
        }
    }
}


int main() {
    string inputFile = "B:/C++/HomeWork/HW_20/points.txt";
    string outputFile = "B:/C++/HomeWork/HW_20/sorted_segments.txt";

    // Читання точок з файлу
    vector<Point> points = readPoints(inputFile);

    // Створення відрізків і сортування за довжиною
    auto segments = createSegments(points);

    // Запис відсортованих відрізків у файл
    writeFile(outputFile, segments);

    cout << "Segments sorted by length and written to file." << endl;
    return 0;
}