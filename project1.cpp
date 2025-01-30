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
    bool treasure_found; 
    uint32_t max_row;
    uint32_t max_col;
    uint32_t total_locations;
    bool verbose;
    uint32_t water_locations;
    uint32_t land_locations;
    uint32_t ashore;
    bool sail_stack;
    bool search_stack;
    string hunt_order;


    public: // min
    Map(vector<vector<Coordinate>> fullmap, Coordinate starting, uint32_t maximumr, 
    uint32_t maximumc, Coordinate treasureloc, bool erbose, bool sail_stac, bool search_stac, string order): map(fullmap), start_location(starting), treasure_location(treasureloc), 
    max_row(maximumr), max_col(maximumc), verbose(erbose), sail_stack(sail_stac), search_stack(search_stac), hunt_order(order){
        uint32_t size_vec = max_col * max_row;
        path.resize(size_vec);
    }

    void Router(){
        sail_container.push_back(start_location);    
        while(!sail_container.empty() || !treasure_found){ // check out of bounds
            if(!sail_stack){
                sail_location = sail_container.front();
                sail_container.pop_front();
            } else {
                sail_location = sail_container.back();
                sail_container.pop_back();
            }
            if(hunt_order[0] == 'N'){
                North_SailLocation();
            } else if (hunt_order[0] == 'E'){
                East_SailLocation();
            } else if (hunt_order[0] == 'S'){
                South_SailLocation();
            } else if (hunt_order[0] == 'W'){
                West_SailLocation();
            }

            if(hunt_order[1] == 'N'){
                North_SailLocation();
            } else if (hunt_order[1] == 'E'){
                East_SailLocation();
            } else if (hunt_order[1] == 'S'){
                South_SailLocation();
            } else if (hunt_order[1] == 'W'){
                West_SailLocation();
            }
            if(hunt_order[2] == 'N'){
                North_SailLocation();
            } else if (hunt_order[2] == 'E'){
                East_SailLocation();
            } else if (hunt_order[2] == 'S'){
                South_SailLocation();
            } else if (hunt_order[2] == 'W'){
                West_SailLocation();
            }
            if(hunt_order[3] == 'N'){
                North_SailLocation();
            } else if (hunt_order[3] == 'E'){
                East_SailLocation();
            } else if (hunt_order[3] == 'S'){
                South_SailLocation();
            } else if (hunt_order[3] == 'W'){
                West_SailLocation();
            }

        while(!search_container.empty()){
            Coordinate save;
            if(!search_stack){
                save = search_container.front();
                search_container.pop_front();
            } else {
                save = search_container.back();
                search_container.pop_back();
                }
            if(hunt_order[0] == 'N'){
                North_SearchLocation();
            } else if (hunt_order[0] == 'E'){
                East_SearchLocation();
            } else if (hunt_order[0] == 'S'){
                South_SearchLocation();
            } else if (hunt_order[0] == 'W'){
                West_SearchLocation();
            }

            if(hunt_order[1] == 'N'){
                North_SearchLocation();
            } else if (hunt_order[1] == 'E'){
                East_SearchLocation();
            } else if (hunt_order[1] == 'S'){
                South_SearchLocation();
            } else if (hunt_order[1] == 'W'){
                West_SearchLocation();
            }
            if(hunt_order[2] == 'N'){
                North_SearchLocation();
            } else if (hunt_order[2] == 'E'){
                East_SearchLocation();
            } else if (hunt_order[2] == 'S'){
                South_SearchLocation();
            } else if (hunt_order[2] == 'W'){
                West_SearchLocation();
            }
            if(hunt_order[3] == 'N'){
                North_SearchLocation();
            } else if (hunt_order[3] == 'E'){
                East_SearchLocation();
            } else if (hunt_order[3] == 'S'){
                South_SearchLocation();
            } else if (hunt_order[3] == 'W'){
                West_SearchLocation();
            }
 
            }
        }
    }

    void North_SailLocation(){
        if(sail_location.row != 0){ 
            if(map[sail_location.row - 1][sail_location.col].identity != '#' 
             && map[sail_location.row - 1][sail_location.col].identity != '@'){ // north
                if(map[sail_location.row - 1][sail_location.col].identity != 'o' 
                || map[sail_location.row - 1][sail_location.col].identity != 'c' ){
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    map[sail_location.row - 1][sail_location.col].identity = 'c';
                    sail_container.push_back(map[sail_location.row - 1][sail_location.col]);
                    water_locations++;
                }
                if(map[sail_location.row - 1][sail_location.col].identity == 'o'){
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    map[sail_location.row - 1][sail_location.col].identity = 'c';
                    search_container.push_back(map[sail_location.row - 1][sail_location.col]);
                    land_locations++;
                }
                if(map[sail_location.row - 1][sail_location.col].identity == '$'){
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    treasure_found = true; 
                }
                total_locations++; 
            }   
        }
    }

    void South_SailLocation(){
        if(sail_location.row != max_row){
            if(map[sail_location.row + 1][sail_location.col].identity != '#'
            && map[sail_location.row + 1][sail_location.col].identity != '@'){ // south
                if(map[sail_location.row + 1][sail_location.col].identity != 'o' 
                || map[sail_location.row + 1][sail_location.col].identity != 'c' ){
                    map[sail_location.row + 1][sail_location.col].path = 'S';
                    map[sail_location.row + 1][sail_location.col].identity = 'c';
                    sail_container.push_back(map[sail_location.row + 1][sail_location.col]);
                    water_locations++;
                }
                if(map[sail_location.row + 1][sail_location.col].identity == 'o'){
                    map[sail_location.row + 1][sail_location.col].path = 'S';
                    map[sail_location.row + 1][sail_location.col].identity = 'c';
                    search_container.push_back(map[sail_location.row + 1][sail_location.col]);
                    land_locations++;
                }
                if(map[sail_location.row + 1][sail_location.col].identity == '$'){
                    map[sail_location.row + 1][sail_location.col].path = 'S';
                    treasure_found = true; 
                }
                total_locations++;
            }
        }
    }

    void East_SailLocation(){
        if(sail_location.col != max_col){
            if(map[sail_location.row][sail_location.col + 1].identity != '#' 
            && map[sail_location.row][sail_location.col + 1].identity != '@'){ // east 
                if(map[sail_location.row][sail_location.col + 1].identity != 'o' 
                || map[sail_location.row][sail_location.col + 1].identity != 'c' ){
                    map[sail_location.row][sail_location.col + 1].path = 'E';
                    map[sail_location.row][sail_location.col + 1].identity = 'c';
                    sail_container.push_back(map[sail_location.row][sail_location.col + 1]);
                    water_locations++;
                }
                if(map[sail_location.row][sail_location.col + 1].identity == 'o'){
                    map[sail_location.row][sail_location.col + 1].path = 'E';
                    map[sail_location.row][sail_location.col + 1].identity = 'c';
                    search_container.push_back(map[sail_location.row][sail_location.col + 1]);
                    land_locations++;
                }
                if(map[sail_location.row][sail_location.col + 1].identity == '$'){
                    map[sail_location.row][sail_location.col +  1].path = 'E';
                    treasure_found = true; 
                }
                total_locations++;
            }
        }
    }

    void West_SailLocation(){
        if(sail_location.col != 0){
            if(map[sail_location.row][sail_location.col - 1].identity != '#'
            && map[sail_location.row][sail_location.col - 1].identity != '@'){ // west 
                if(map[sail_location.row][sail_location.col - 1].identity != 'o' 
                || map[sail_location.row][sail_location.col - 1].identity != 'c' ){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    map[sail_location.row][sail_location.col - 1].identity = 'c';
                    sail_container.push_back(map[sail_location.row][sail_location.col - 1]);
                    water_locations++;
                }
                if(map[sail_location.row][sail_location.col - 1].identity == 'o'){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    map[sail_location.row][sail_location.col - 1].identity = 'c';
                    search_container.push_back(map[sail_location.row][sail_location.col - 1]);
                    land_locations++;
                }
                if(map[sail_location.row][sail_location.col - 1].identity == '$'){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    treasure_found = true; 
                }
                total_locations++;
            }
        }
    }

    void North_SearchLocation(){
        if(sail_location.row != 0){
            if(map[sail_location.row - 1][sail_location.col].identity != '#'){ // north
                if(map[sail_location.row - 1][sail_location.col].identity == 'o' && 
                map[sail_location.row - 1][sail_location.col].identity != 'c'){
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    map[sail_location.row - 1][sail_location.col].identity = 'c';
                    map[sail_location.row - 1][sail_location.col].Search_or_Not = 'S';
                    search_container.push_back(map[sail_location.row - 1][sail_location.col]);
                    land_locations++;
                    total_locations++; 
                }
                if(map[sail_location.row - 1][sail_location.col].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                }
                if(verbose){
                    cout << "Went ashore at " << sail_location.row << "," << sail_location.col << "\n";
                    if(treasure_found){
                        cout << "Searching island... party found treasure at " << sail_location.row - 1 << 
                        sail_location.col << "\n";
                    } else {
                        cout << "Searching island... party returned with no treasure." << "\n";
                    }

                }
            }
        }
    }

    void East_SearchLocation(){
        if(sail_location.col != max_col){
            if(map[sail_location.row][sail_location.col + 1].identity != '#'){ // east 
                if(map[sail_location.row][sail_location.col + 1].identity == 'o'
                && map[sail_location.row][sail_location.col + 1].identity != 'c'){
                    map[sail_location.row][sail_location.col + 1].path = 'E';
                    map[sail_location.row][sail_location.col + 1].identity = 'c';
                    map[sail_location.row][sail_location.col + 1].Search_or_Not = 'S';
                    search_container.push_back(map[sail_location.row][sail_location.col + 1]);
                    land_locations++;
                    total_locations++;
                }
                if(map[sail_location.row][sail_location.col + 1].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                }
                if(verbose){
                    cout << "Went ashore at " << sail_location.row << "," << sail_location.col + 1 << "\n";
                    if(treasure_found){
                        cout << "Searching island... party found treasure at " << sail_location.row << 
                        sail_location.col + 1 << "\n";
                    } else {
                        cout << "Searching island... party returned with no treasure." << "\n";
                    }

                }
            }
        }
    }

    void West_SearchLocation(){
        if(sail_location.col != 0){
            if(map[sail_location.row][sail_location.col - 1].identity != '#'){ // west 
                if(map[sail_location.row][sail_location.col - 1].identity == 'o'
                &&map[sail_location.row][sail_location.col - 1].identity != 'c'){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    map[sail_location.row][sail_location.col - 1].identity = 'c';
                    map[sail_location.row][sail_location.col - 1].Search_or_Not = 'S';
                    search_container.push_back(map[sail_location.row][sail_location.col - 1]);
                    land_locations++;
                    total_locations++;
                }
                if(map[sail_location.row][sail_location.col - 1].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                }
                if(verbose){
                    cout << "Went ashore at " << sail_location.row << "," << sail_location.col - 1 << "\n";
                    if(treasure_found){
                        cout << "Searching island... party found treasure at " << sail_location.row << 
                        sail_location.col - 1 << "\n";
                    } else {
                        cout << "Searching island... party returned with no treasure." << "\n";
                    }

                }
            }
        }
    }

    void South_SearchLocation(){
        if(sail_location.row != max_row){
            if(map[sail_location.row + 1][sail_location.col].identity != '#'){ // north
                if(map[sail_location.row + 1][sail_location.col].identity == 'o' && 
                map[sail_location.row + 1][sail_location.col].identity != 'c'){
                    map[sail_location.row + 1][sail_location.col].path = 'N';
                    map[sail_location.row + 1][sail_location.col].identity = 'c';
                    map[sail_location.row + 1][sail_location.col].Search_or_Not = 'S';
                    search_container.push_back(map[sail_location.row - 1][sail_location.col]);
                    land_locations++;
                    total_locations++;
                }
                if(map[sail_location.row + 1][sail_location.col].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                }
                if(verbose){
                    cout << "Went ashore at " << sail_location.row << "," << sail_location.col << "\n";
                    if(treasure_found){
                        cout << "Searching island... party found treasure at " << sail_location.row + 1 << 
                        sail_location.col << "\n";
                    } else {
                        cout << "Searching island... party returned with no treasure." << "\n";
                    }

                }
            }
        }
    }

    void Backtracking(){
        Coordinate backtracking_loc = sail_location; 
        path.push_back(sail_location.path);
        while(backtracking_loc.identity != '@'){
            if(backtracking_loc.path == 'N'){
                path.push_back(backtracking_loc.path);
                backtracking_loc = map[sail_location.row + 1][sail_location.col];
            }
            if(backtracking_loc.path == 'E'){
                path.push_back(backtracking_loc.path);
                backtracking_loc = map[sail_location.row][sail_location.col - 1];
            }
            if(backtracking_loc.path == 'S'){
                path.push_back(backtracking_loc.path);
                backtracking_loc = map[sail_location.row - 1][sail_location.col];
            }
            if(backtracking_loc.path == 'W'){
                path.push_back(backtracking_loc.path);
                backtracking_loc = map[sail_location.row][sail_location.col + 1];
            }
        }
    }

    void Coordinate_Location(){
        Coordinate backtracking_loc = sail_location; 
        vector<Coordinate> printing_out; 
        vector<Coordinate> printing_out_again;
        while(backtracking_loc.identity != '@'){
            if(backtracking_loc.path == 'N'){
                if(backtracking_loc.Search_or_Not == 'S'){
                    printing_out_again.push_back(backtracking_loc);
                }
                printing_out.push_back(backtracking_loc);
                backtracking_loc = map[sail_location.row + 1][sail_location.col];
            }
            if(backtracking_loc.path == 'E'){
                if(backtracking_loc.Search_or_Not == 'S'){
                    printing_out_again.push_back(backtracking_loc);
                }
                printing_out.push_back(backtracking_loc);
                backtracking_loc = map[sail_location.row][sail_location.col - 1];
            }
            if(backtracking_loc.path == 'S'){
                if(backtracking_loc.Search_or_Not == 'S'){
                    printing_out_again.push_back(backtracking_loc);
                }
                printing_out.push_back(backtracking_loc);
                backtracking_loc = map[sail_location.row - 1][sail_location.col];
            }
            if(backtracking_loc.path == 'W'){
                if(backtracking_loc.Search_or_Not == 'S'){
                    printing_out_again.push_back(backtracking_loc);
                }
                printing_out.push_back(backtracking_loc);
                backtracking_loc = map[sail_location.row][sail_location.col + 1];
            }
        }
        cout << "Sail:" << "\n";
        cout << start_location.row << "," << treasure_location.col << "\n";
        for(uint32_t i = 0; i < printing_out.size(); i++){
            cout << printing_out[i].row << "," << printing_out[i].col << "\n";
        }
        if(map[treasure_location.row][treasure_location.col].Search_or_Not != 'S'){
            cout << printing_out[treasure_location.row].row << "," << printing_out[treasure_location.col].col << "\n";
        }
        cout << "Search:" << "\n";
        for(uint32_t i = 0; i < printing_out.size(); i++){
            cout << printing_out_again[i].row << "," << printing_out_again[i].col << "\n";
        }
        if(map[treasure_location.row][treasure_location.col].Search_or_Not == 'S'){
            cout << printing_out_again[treasure_location.row].row << "," << printing_out_again[treasure_location.col].col << "\n";
        }

    }

    void Print_Results(){
        if(!treasure_found){
            cout << "No treasure found after investigating " << total_locations << " locations" << "\n";
        }
        if(treasure_found){
            cout << "Treasure found at " << treasure_location.row << "," << treasure_location.col << "with path length " 
            << path.size();
        }
    }

    void Verbose(){
        if(verbose)
        cout << "Treasure hunt started " << start_location.row << "," << start_location.col  << "\n";

    }

    void Stats_Print(){
        cout << "--- STATS ---" << "\n";
        cout << "Starting location: " << start_location.row << "," << start_location.col << "\n";
        cout << "Water locations investigated: " << water_locations << "\n";
        cout << "Land locations investigated: " << land_locations << "\n";
        cout << "Went ashore: " << ashore << "\n";
        cout << "Path length: " << path.size() << "\n";
        cout << "Treasure location: " << treasure_location.row << "," << treasure_location.col << "\n";
        cout << "--- STATS ---" << "\n";
    }

    void Treasure_Map_Print(){
        for(uint32_t i = 0; i < max_row; i++){
            for(uint32_t j = 0; j < max_col; j++){
                if(map[i][j].path == '.'){
                    cout << map[i][j].path;
                }
                if(0 < j && j < max_col && 0 < i && i < max_row){
                    if(map[i][j].path == 'N' || map[i][j].path == 'S'){
                        if(map[i][j - 1].path == 'E' || map[i][j - 1].path == 'W' ||
                        map[i][j + 1].path == 'E' || map[i][j + 1].path == 'W'){
                            cout << "+" << "\n";
                        }
                    } else {
                        if(map[i][j].path == 'N' && map[i][j].path == 'S'){
                            cout << "|" << "\n";
                        }
                    }
                } else {
                        if(map[i][j].path == 'N' && map[i][j].path == 'S'){
                            cout << "|" << "\n";
                        }
                }
                if(map[i][j].path == 'E' || map[i][j].path == 'W'){
                    cout << "-" << "\n";
                }

                
            }
        }
    } 

};


void print_help() {
    cout << "Usage: program [options]\n";
    cout << "  --help, -h           Print help message and exit\n";
    cout << "  --captain, -c        Set captain container (QUEUE|STACK)\n";
    cout << "  --first-mate, -f     Set first mate container (QUEUE|STACK)\n";
    cout << "  --hunt-order, -o     Set hunt order (N, E, S, W)\n";
    cout << "  --verbose, -v        Enable verbose mode\n";
    cout << "  --stats, -s          Display statistics\n";
    cout << "  --show-path, -p      Display treasure map or list of locations\n";
}

int main(int argc, char* argv[]){
    char map_or_list = ' ';
    Coordinate starting_location = {0, 0, '.', '.', '.'};
    Coordinate ending_location = {0, 0, '.', '.', '.'};
    vector<vector<Coordinate>> Full_Map;
    uint32_t maximum_number_rows;
    bool v; 
    bool ss = true;
    bool ms = false;
    bool statistics;
    bool path; 
    string hunt_ordering = "";
    int opt;
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"captain", required_argument, 0, 'c'},
        {"first-mate", required_argument, 0, 'f'},
        {"hunt-order", required_argument, 0, 'o'},
        {"verbose", no_argument, 0, 'v'},
        {"stats", no_argument, 0, 's'},
        {"show-path", required_argument, 0, 'p'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "hc:f:o:vsp:", long_options, nullptr)) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'c':
                cout << "Captain container: " << optarg << endl;
                if(string(optarg) == "QUEUE"){
                    ss = false;
                }
                break;
            case 'f':
                cout << "First mate container: " << optarg << endl;
                if(string(optarg) == "STACK"){
                    ms = true; 
                }
                break;
            case 'o':
                cout << "Hunt order: " << optarg << endl;
                hunt_ordering = optarg;
                break;
            case 'v':
                cout << "Verbose mode enabled" << endl;
                v = true; 
                break;
            case 's':
                cout << "Displaying statistics" << endl;
                statistics = true; 
                break;
            case 'p':
                cout << "Show path mode: " << optarg << endl;
                path = true; 
                break;
            default:
                print_help();
                return 1;
        }
    }
 
    cin >> map_or_list;
    while(map_or_list != 'M' && map_or_list != 'L'){
    if(map_or_list == '#'){
        string comment;
        getline(cin, comment);
        cin >> map_or_list;
    }
    }
    cout << map_or_list << endl;
    if(map_or_list == 'M'){
        char identite;
        uint32_t row_count = 0;
        uint32_t col_count = 0;
        Coordinate submit;
        cin >> maximum_number_rows;
        while(cin >> identite){
            submit.row = row_count;
            submit.col = col_count;
            cout << row_count << col_count << endl;
            submit.identity = identite;
            cout << identite << endl;
            Full_Map[row_count][col_count] = submit;
            if(submit.identity == '@'){
                starting_location = submit;
            }
            if(submit.identity == '$'){
                ending_location = submit;
            }
            col_count++;
            if(col_count == maximum_number_rows){
                col_count = 0; 
                row_count++;
            }
        }
    }
    if(map_or_list == 'L'){
        uint32_t maximum_number_rows;
        uint32_t row_num;
        uint32_t col_num;
        char identite;
        Coordinate submit;
        cin >> maximum_number_rows;
        while(cin >> row_num){
            cin >> col_num;
            cin >> identite;
            submit.row = row_num;
            submit.col = col_num;
            Full_Map[row_num][col_num] = submit;
            if(submit.identity == '@'){
                starting_location = submit;
            }
            if(submit.identity == '$'){
                ending_location = submit;
            }
        }
    }
    
    Map Game = Map(Full_Map, starting_location, maximum_number_rows, maximum_number_rows, ending_location,
    v, ss, ms, hunt_ordering);
    if(statistics && path) { cout << "yay" << "\n"; }
    cout << starting_location.row << starting_location.col << "\n";
    return 0; 

}



