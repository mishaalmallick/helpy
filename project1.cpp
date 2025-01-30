#include <iostream>
#include <string>
#include <getopt.h>
#include <vector>
#include <deque>
using namespace std;

struct Coordinate {
    uint32_t row;
    uint32_t col;
    char identity = '.'; 
    char path = '.';
    char Search_or_Not = 'N';
};

class Map {
    private:
    vector<vector<Coordinate>> map; 
    vector<char> path; 
    deque<Coordinate> sail_container;
    deque<Coordinate> search_container;
    Coordinate sail_location;
    Coordinate search_location; 
    Coordinate start_location; 
    Coordinate treasure_location;
    bool treasure_found = false; 
    uint32_t max_row;
    uint32_t max_col;
    uint32_t total_locations = 0;
    bool verbose;
    uint32_t water_locations = 0;
    uint32_t land_locations = 0;
    uint32_t ashore = 0;
    bool sail_stack;
    bool search_stack;
    string hunt_order;

    public:
    Map(vector<vector<Coordinate>> fullmap, Coordinate starting, uint32_t maximumr, 
    uint32_t maximumc, Coordinate treasureloc, bool erbose, bool sail_stac, bool search_stac, string order)
    : map(fullmap), start_location(starting), treasure_location(treasureloc), 
    max_row(maximumr), max_col(maximumc), verbose(erbose), sail_stack(sail_stac), search_stack(search_stac), hunt_order(order) {
        uint32_t size_vec = max_col * max_row;
        path.resize(size_vec);
    }

    void Router() {
        sail_container.push_back(start_location);    
        while (!sail_container.empty() && !treasure_found) { 
            sail_location = sail_stack ? sail_container.back() : sail_container.front();
            sail_stack ? sail_container.pop_back() : sail_container.pop_front();

            for (char direction : hunt_order) {
                if (direction == 'N') North_SailLocation();
                else if (direction == 'E') East_SailLocation();
                else if (direction == 'S') South_SailLocation();
                else if (direction == 'W') West_SailLocation();
            }
        }
    }

    void North_SailLocation() {
        if (sail_location.row > 0) {
            Coordinate &next = map[sail_location.row - 1][sail_location.col];
            if (next.identity != '#' && next.identity != '@' && next.identity != 'c') {
                next.path = 'N';
                next.identity = 'c';
                sail_container.push_back(next);
                water_locations++;
                if (next.identity == '$') treasure_found = true;
                total_locations++;
            }
        }
    }
    
    void South_SailLocation() {
        if (sail_location.row < max_row - 1) {
            Coordinate &next = map[sail_location.row + 1][sail_location.col];
            if (next.identity != '#' && next.identity != '@' && next.identity != 'c') {
                next.path = 'S';
                next.identity = 'c';
                sail_container.push_back(next);
                water_locations++;
                if (next.identity == '$') treasure_found = true;
                total_locations++;
            }
        }
    }
    
    void East_SailLocation() {
        if (sail_location.col < max_col - 1) {
            Coordinate &next = map[sail_location.row][sail_location.col + 1];
            if (next.identity != '#' && next.identity != '@' && next.identity != 'c') {
                next.path = 'E';
                next.identity = 'c';
                sail_container.push_back(next);
                water_locations++;
                if (next.identity == '$') treasure_found = true;
                total_locations++;
            }
        }
    }
    
    void West_SailLocation() {
        if (sail_location.col > 0) {
            Coordinate &next = map[sail_location.row][sail_location.col - 1];
            if (next.identity != '#' && next.identity != '@' && next.identity != 'c') {
                next.path = 'W';
                next.identity = 'c';
                sail_container.push_back(next);
                water_locations++;
                if (next.identity == '$') treasure_found = true;
                total_locations++;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    char map_or_list = ' ';
    Coordinate starting_location = {0, 0, '.', '.', '.'};
    Coordinate ending_location = {0, 0, '.', '.', '.'};
    vector<vector<Coordinate>> Full_Map;
    uint32_t maximum_number_rows = 0;
    bool v = false;
    bool ss = true;
    bool ms = false;
    bool statistics = false;
    bool path = false;
    string hunt_ordering = "";

    int opt;
    while ((opt = getopt(argc, argv, "hc:f:o:vsp:")) != -1) {
        switch (opt) {
            case 'v':
                v = true;
                break;
            case 's':
                statistics = true;
                break;
            case 'p':
                path = true;
                break;
            case 'o':
                hunt_ordering = optarg;
                break;
            default:
                return 1;
        }
    }
    string comment;
    while (getline(cin, comment) && !comment.empty());
    cin >> map_or_list;
    cin >> maximum_number_rows;
    Full_Map.resize(maximum_number_rows, vector<Coordinate>(maximum_number_rows));
    
    for (uint32_t i = 0; i < maximum_number_rows; ++i) {
        for (uint32_t j = 0; j < maximum_number_rows; ++j) {
            char identite;
            cin >> identite;
            Full_Map[i][j] = {i, j, identite};
            if (identite == '@') starting_location = Full_Map[i][j];
            if (identite == '$') ending_location = Full_Map[i][j];
        }
    }
    
    Map Game(Full_Map, starting_location, maximum_number_rows, maximum_number_rows, ending_location, v, ss, ms, hunt_ordering);
    Game.Router();
    Game.Backtracking();
       if(v || true){
        Game.Verbose();
    }
    if(statistics || true){
        Game.Stats_Print();
    }
    if(map_or_list == 'M' && path){
        Game.Treasure_Map_Print();
    }
    if(map_or_list == 'L' && path){
        Game.Coordinate_Location();
    }
    Game.Print_Results();
    return 0;
}
