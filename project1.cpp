//40FB54C86566B9DDEAB902CC80E8CE85C1C62AAD
#include <iostream>
#include <string>
#include <getopt.h>
#include <vector>
#include <deque>
using namespace std;

struct Coordinate {
    uint32_t row = 0;
    uint32_t col = 0;
    char identity = '.'; 
    char check = 'n';
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
    uint32_t water_locations = 0;
    uint32_t land_locations = 0;
    uint32_t ashore = 0;
    bool sail_stack;
    bool search_stack;
    string hunt_order;
    char pathing;
    bool statistics; 


    public: // min
    Map(vector<vector<Coordinate>> &fullmap, Coordinate starting, uint32_t maximumr, 
    uint32_t maximumc, Coordinate treasureloc, bool erbose, bool sail_stac, bool search_stac, string order, char pathway, bool stati): map(fullmap), start_location(starting), treasure_location(treasureloc), 
    max_row(maximumr), max_col(maximumc), verbose(erbose), sail_stack(sail_stac), search_stack(search_stac), hunt_order(order), pathing(pathway), statistics(stati){
        uint32_t size_vec = max_col * max_row;
        path.resize(size_vec);
    }

    void Router(){
        sail_container.push_back(start_location); 
        while(!sail_container.empty()){ // check out of bounds
            if(treasure_found){
                break;
            }
            
            if(!sail_stack){
                sail_location = sail_container.front();
                sail_container.pop_front();
            } else {
                sail_location = sail_container.back();
                sail_container.pop_back();
            }
            water_locations++;
           
            if(hunt_order[0] == 'N'){
                North_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'E'){
                East_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'S'){
                South_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'W'){
                West_SailLocation();
                if(treasure_found){
                    break;
                }
            }
            if(hunt_order[1] == 'N'){
                North_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'E'){
                East_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'S'){
                South_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'W'){
                West_SailLocation();
                if(treasure_found){
                    break;
                }
            }
            if(hunt_order[2] == 'N'){
                North_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'E'){
                East_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'S'){
                South_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'W'){
                West_SailLocation();
                if(treasure_found){
                    break;
                }
            }
            if(hunt_order[3] == 'N'){
                North_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'E'){
                East_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'S'){
                South_SailLocation();
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'W'){
                West_SailLocation();
                if(treasure_found){
                    break;
                }
            }
        
        if(!search_container.empty()){
            
            if(!search_stack){
                search_location = search_container.front();
            } else {
                search_location = search_container.back();
            }
            if(verbose){
                cout << "Went ashore at: " << search_location.row << "," << search_location.col << "\n";
            }
            ashore++;
         }
         bool going = false; 

        while(!search_container.empty()){
            if(treasure_found){
                break;
            }
            if(!search_stack){
                search_location = search_container.front();
                search_container.pop_front();
            } else {
                search_location = search_container.back();
                search_container.pop_back();
            }
            land_locations++;
            if(hunt_order[0] == 'N'){
                North_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row - 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'E'){
                East_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col + 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'S'){
                South_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row + 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[0] == 'W'){
                West_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col - 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            }

            if(hunt_order[1] == 'N'){
                North_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row - 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'E'){
                East_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col + 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'S'){
                South_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row + 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[1] == 'W'){
                West_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col - 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            }
            if(hunt_order[2] == 'N'){
                North_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row - 1 << "," << search_location.col << ".\n";
                    
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'E'){
                East_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col + 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'S'){
                South_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row + 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[2] == 'W'){
                West_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col - 1<< ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            }
            if(hunt_order[3] == 'N'){
                North_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row - 1 << "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'E'){
                East_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col + 1<< ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'S'){
                South_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row + 1<< "," << search_location.col << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            } else if (hunt_order[3] == 'W'){
                West_SearchLocation();
                if(treasure_found && verbose){
                    cout << "Searching island... party found treasure at " << search_location.row << "," << search_location.col - 1 << ".\n";
                    break;
                }
                if(treasure_found){
                    break;
                }
            }
            going = true; 
            }
             if(!treasure_found && verbose && going){
                cout << "Searching island... party returned with no treasure." << "\n";
            }
            
        }
cout << "done " << endl;
    }

    void North_SailLocation(){
        if(sail_location.row != 0){ 
            /* cout << "North, Sail" << endl;
            cout << sail_location.row - 1 << sail_location.col << endl; */
            if(map[sail_location.row - 1][sail_location.col].identity == '$'){
                map[sail_location.row - 1][sail_location.col].path = 'N';
                treasure_found = true; 
            }
            if(map[sail_location.row - 1][sail_location.col].identity != '#' 
             && map[sail_location.row - 1][sail_location.col].identity != '@'){ // north
                if(map[sail_location.row - 1][sail_location.col].identity != 'o' 
                && map[sail_location.row - 1][sail_location.col].check != 'c' ){;
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    map[sail_location.row - 1][sail_location.col].check = 'c';
                    sail_container.push_back(map[sail_location.row - 1][sail_location.col]);
      
                
                }
                if(map[sail_location.row - 1][sail_location.col].identity == 'o' && 
                map[sail_location.row - 1][sail_location.col].check != 'c'){
                    map[sail_location.row - 1][sail_location.col].path = 'N';
                    map[sail_location.row - 1][sail_location.col].check = 'c';
                    search_container.push_back(map[sail_location.row - 1][sail_location.col]);
                   

                 
                }
                total_locations++; 
            }   
        }
    }

    void South_SailLocation(){
        if(sail_location.row != max_row - 1){
            // cout << "South, Sail" << endl;
            //cout << sail_location.row + 1 << sail_location.col << endl;
            if(map[sail_location.row + 1][sail_location.col].identity == '$'){
                map[sail_location.row + 1][sail_location.col].path = 'S';
                treasure_found = true; 
            }
            if(map[sail_location.row + 1][sail_location.col].identity != '#'
            && map[sail_location.row + 1][sail_location.col].identity != '@'){ // south
                if(map[sail_location.row + 1][sail_location.col].identity != 'o' 
                && map[sail_location.row + 1][sail_location.col].check != 'c'){
                    map[sail_location.row + 1][sail_location.col].path = 'S';
                    map[sail_location.row + 1][sail_location.col].check = 'c';
                    sail_container.push_back(map[sail_location.row + 1][sail_location.col]);
        
                    
                }
                if(map[sail_location.row + 1][sail_location.col].identity == 'o'
               && map[sail_location.row + 1][sail_location.col].check != 'c'){
                    map[sail_location.row + 1][sail_location.col].path = 'S';
                    map[sail_location.row + 1][sail_location.col].check = 'c';
                    search_container.push_back(map[sail_location.row + 1][sail_location.col]);
                  
         
                }
                total_locations++;
            }
        }
    }

    void East_SailLocation(){
        if(sail_location.col != max_col - 1){
             //  cout << "East, Sail" << endl;
           // cout << sail_location.row << sail_location.col + 1 << endl;
            if(map[sail_location.row][sail_location.col + 1].identity == '$'){
                map[sail_location.row][sail_location.col +  1].path = 'E';
                treasure_found = true; 
            }
            if(map[sail_location.row][sail_location.col + 1].identity != '#' 
            && map[sail_location.row][sail_location.col + 1].identity != '@'){ // east 
                if(map[sail_location.row][sail_location.col + 1].identity != 'o' 
                && map[sail_location.row][sail_location.col + 1].check != 'c' ){
                    map[sail_location.row][sail_location.col + 1].path = 'E';
                    map[sail_location.row][sail_location.col + 1].check = 'c';
                    sail_container.push_back(map[sail_location.row][sail_location.col + 1]);
           
                    
                }
                if(map[sail_location.row][sail_location.col + 1].identity == 'o'
                && map[sail_location.row][sail_location.col + 1].check != 'c' ){
                    map[sail_location.row][sail_location.col + 1].path = 'E';
                    map[sail_location.row][sail_location.col + 1].check = 'c';
                    search_container.push_back(map[sail_location.row][sail_location.col + 1]);
                    
         
                }
                total_locations++;
            }
        }
    }

    void West_SailLocation(){
        if(sail_location.col != 0){
           //cout << "West, Sail" << endl;
          //  cout << sail_location.row  << sail_location.col - 1 << endl;

            if(map[sail_location.row][sail_location.col - 1].identity == '$'){
                map[sail_location.row][sail_location.col - 1].path = 'W';
                treasure_found = true; 
            }
            if(map[sail_location.row][sail_location.col - 1].identity != '#'
            && map[sail_location.row][sail_location.col - 1].identity != '@'){ // west 
                if(map[sail_location.row][sail_location.col - 1].identity != 'o' 
                && map[sail_location.row][sail_location.col - 1].check != 'c' ){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    map[sail_location.row][sail_location.col - 1].check = 'c';
                    sail_container.push_back(map[sail_location.row][sail_location.col - 1]);
         
                   
                }
                if(map[sail_location.row][sail_location.col - 1].identity == 'o'
                && map[sail_location.row][sail_location.col - 1].check != 'c' ){
                    map[sail_location.row][sail_location.col - 1].path = 'W';
                    map[sail_location.row][sail_location.col - 1].check = 'c';
                    search_container.push_back(map[sail_location.row][sail_location.col - 1]);
                   
  
                }
                total_locations++;
            }
        }
    }

    void North_SearchLocation(){
        if(search_location.row != 0){
           //       cout << "North, Search" << endl;
           // cout << search_location.row  - 1 << search_location.col << endl;
            if(map[search_location.row - 1][search_location.col].identity != '#'){ // north
                if(map[search_location.row - 1][search_location.col].identity == 'o' &&
                map[search_location.row - 1][search_location.col].check != 'c'){
                    map[search_location.row - 1][search_location.col].path = 'N';
                    map[search_location.row - 1][search_location.col].check = 'c';
                    map[search_location.row - 1][search_location.col].Search_or_Not = 'S';
                    search_container.push_back(map[search_location.row - 1][search_location.col]);
                 
                    total_locations++; 
            
                }
                if(map[search_location.row - 1][search_location.col].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                    treasure_location.Search_or_Not = 'S';
                }
            }
        }
    }

    void East_SearchLocation(){
        if(search_location.col != max_col - 1){
            //    cout << "East, Search" << endl;
          //  cout << search_location.row << search_location.col + 1 << endl;
            if(map[search_location.row][search_location.col + 1].identity != '#'){ // east 
                if(map[search_location.row][search_location.col + 1].identity == 'o'
                && map[search_location.row][search_location.col + 1].check != 'c'){
                    map[search_location.row][search_location.col + 1].path = 'E';
                    map[search_location.row][search_location.col + 1].check = 'c';
                    map[search_location.row][search_location.col + 1].Search_or_Not = 'S';
                    search_container.push_back(map[search_location.row][search_location.col + 1]);
                 
                    total_locations++;
             
                }
                if(map[search_location.row][search_location.col + 1].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                    treasure_location.Search_or_Not = 'S';
                }
            }
        }
    }

    void West_SearchLocation(){
       if(search_location.col != 0){
          // cout << "West, Search" << endl;
           // cout << search_location.row  << search_location.col - 1 << endl;
            if(map[search_location.row][search_location.col - 1].identity != '#'){ // west 
                if(map[search_location.row][search_location.col - 1].identity == 'o' &&
                map[search_location.row][search_location.col - 1].check != 'c'){
                    map[search_location.row][search_location.col - 1].path = 'W';
                    map[search_location.row][search_location.col - 1].check = 'c';
                    map[search_location.row][search_location.col - 1].Search_or_Not = 'S';
                    search_container.push_back(map[search_location.row][search_location.col - 1]);
               
                    total_locations++;
               
                }
                if(map[search_location.row][search_location.col - 1].identity == '$'){
                    sail_location = search_location;
                    treasure_found = true; 
                    treasure_location.Search_or_Not = 'S';
                }
            }
        }
    }

    void South_SearchLocation(){

        if(search_location.row != max_row - 1){
            //            cout << "South, Search" << endl;
           // cout << search_location.row + 1 << search_location.col << endl;
            if(map[search_location.row + 1][search_location.col].identity != '#'){ // north
                if(map[search_location.row + 1][search_location.col].identity == 'o'
                && map[search_location.row + 1][search_location.col].check != 'c'){
                    map[search_location.row + 1][search_location.col].path = 'N';
                    map[search_location.row + 1][search_location.col].check = 'c';
                    map[search_location.row + 1][search_location.col].Search_or_Not = 'S';
                    search_container.push_back(map[search_location.row + 1][search_location.col]);
               
                    total_locations++;
                   
                }
                if(map[search_location.row + 1][search_location.col].identity == '$'){
                    sail_location = search_location;
                    treasure_location.Search_or_Not = 'S';
                    treasure_found = true; 
                }

            }
        }
    }

    void Backtracking(){
        cout << "1" << endl;
        Coordinate backtracking_loc = sail_location; 
        cout << "2" << endl;
        path.push_back(sail_location.path);
        cout << "3" << endl;
        uint32_t count = 0;
        uint32_t count2 = 0; 
        uint32_t count3 = 0; 
        cout << "4" << endl;
        vector<Coordinate> searching;
        cout << "5" << endl;
        vector<Coordinate> sailing; 
        cout << "6" << endl;
        if(treasure_location.Search_or_Not == 'S'){
            searching.push_back(treasure_location);
            count3++;
        } else {
            sailing.push_back(treasure_location);
            count2++;
        }
        

        while(backtracking_loc.identity != '@'){
            if(backtracking_loc.path == 'N'){
                path.push_back(backtracking_loc.path);
                map[backtracking_loc.row][backtracking_loc.col].identity = '|';
                cout << " a " << endl;
                if(backtracking_loc.identity == 'o'){
                    searching.push_back(backtracking_loc);
                    count3++;
                    cout << " b " << endl;

                } else {
                    sailing.push_back(backtracking_loc);
                    count2++;
                    cout << " c " << endl;
                }
                backtracking_loc = map[backtracking_loc.row + 1][backtracking_loc.col];    
                cout << " d " << endl; 
                count++;
   
            }
            if(backtracking_loc.path == 'E'){
                path.push_back(backtracking_loc.path);
                map[backtracking_loc.row][backtracking_loc.col].identity = '-';
                cout << " e " << endl;
                if(backtracking_loc.identity == 'o'){
                    searching.push_back(backtracking_loc);
                    count3++;
                    cout << " f " << endl;
                } else {
                    sailing.push_back(backtracking_loc);
                    count2++;
                    cout << " g " << endl;
                }
                backtracking_loc = map[backtracking_loc.row][backtracking_loc.col - 1];           
                count++;
                cout << " h " << endl;
            }
            if(backtracking_loc.path == 'S'){
                path.push_back(backtracking_loc.path);
                map[backtracking_loc.row][backtracking_loc.col].identity = '|';
                cout << " i " << endl;
                if(backtracking_loc.identity == 'o'){
                    searching.push_back(backtracking_loc);
                    count3++;
                    cout << " j " << endl;
                } else {
                    sailing.push_back(backtracking_loc);
                    count2++;
                    cout << " k " << endl;
                }
                backtracking_loc = map[backtracking_loc.row - 1][backtracking_loc.col];  
                cout << " l " << endl;       
                count++;
            }
            if(backtracking_loc.path == 'W'){
                path.push_back(backtracking_loc.path);
                map[backtracking_loc.row][backtracking_loc.col].identity = '-';
                cout << " m " << endl;
                if(backtracking_loc.identity == 'o'){
                    searching.push_back(backtracking_loc);
                    cout << " n " << endl;
                    count3++;
                } else {
                    sailing.push_back(backtracking_loc);
                    cout << " o " << endl;
                    count2++;
                }
                backtracking_loc = map[backtracking_loc.row][backtracking_loc.col + 1];
                cout << " p " << endl;
                count++;
            }
        }
        path.resize(count);
cout << "done 2 " << endl;
        if(statistics){
            Stats_Print();
        }
        
       
            if(pathing == 'L'){
            cout << "Sail:" << "\n";
            cout << start_location.row << "," << start_location.col << "\n";

            
            
            for(uint32_t i = count2 - 1; i > 0; i--){
                cout << sailing[i].row << "," << sailing[i].col << "\n";
            }
            cout << sailing[0].row << "," << sailing[0].col << "\n";
            
            
            cout << "Search:" << "\n";
            for(uint32_t i = count3 - 1; i >0; i--){
                cout << searching[i].row << "," << searching[i].col << "\n";
            }
            if(!searching.empty()){
                cout << searching[0].row << "," << searching[0].col << "\n";
            }
        
            }
            if(pathing == 'M'){
                Treasure_Map_Print();
            }


    }


    void Print_Results(){
        if(!treasure_found){
            cout << "No treasure found after investigating " << water_locations + land_locations + 1 << " locations" << "\n";
        }
        if(treasure_found){
            cout << "Treasure found at " << treasure_location.row << "," << treasure_location.col << " with path length " 
            << path.size() + 1 << ".\n";
        }
    }

    void Verbose(){
        cout << "Treasure hunt started at: " << start_location.row << "," << start_location.col  << "\n";
    }

    void Stats_Print(){
        cout << "--- STATS ---" << "\n";
        cout << "Starting location: " << start_location.row << "," << start_location.col << "\n";
        cout << "Water locations investigated: " << water_locations << "\n";
        cout << "Land locations investigated: " << land_locations + 1 << "\n";
        cout << "Went ashore: " << ashore << "\n";
        cout << "Path length: " << path.size() + 1 << "\n";
        cout << "Treasure location: " << treasure_location.row << "," << treasure_location.col << "\n";
        cout << "--- STATS ---" << "\n";
    }

    void Print_Map(){
        for(uint32_t i = 0; i < max_row; i++){
            for (uint32_t j = 0; j < max_col; j++){
                cout << map[i][j].identity;
            }
            cout << endl;
        }
    }

    void Treasure_Map_Print(){
        for(uint32_t i = 0; i < max_row; i++){
            for (uint32_t j = 0; j < max_col; j++){

                if(map[i][j].identity == '$'){
                    cout << 'X';
                } else {
                    if(i != 0){
                        if((map[i - 1][j].identity == '|' && map[i][j].identity == '-')
                        ||(map[i - 1][j].identity == '+' && map[i][j].identity == '-')){
                          map[i][j].identity = '+';  
                        }
                    }
                    if(i != max_row - 1){
                        if((map[i + 1][j].identity == '|' && map[i][j].identity == '-')
                        || (map[i + 1][j].identity == '+' && map[i][j].identity == '-')){
                            map[i][j].identity = '+';
                        }
                    }
                    if(j != 0){
                        if((map[i][j].identity == '|'&& map[i][j + 1].identity == '-' )||
                        (map[i][j].identity == '|'&& map[i][j + 1].identity == '$')){
                            map[i][j].identity = '+';
                        }
                    } 
                    if(j != max_col){
                        if((map[i][j].identity == '|'&& map[i][j - 1].identity == '-' )||
                        (map[i][j].identity == '|'&& map[i][j - 1].identity == '$') ){
                            map[i][j].identity = '+';
                        }
                    }
                    cout << map[i][j].identity;
                }
                
            }
            cout << endl;
        }
    } 

};


void print_help() {
    cout << "Usage: program [options]\n";
}

int main(int argc, char* argv[]){ 
    
    vector<vector<Coordinate>> FullMap;
    bool verbose = false; 
    bool captain_sq = true;
    bool firstmate_sq = false;
    string hunt_order = "NESW";
    bool statistics = false; 
    char show_path = ' '; 
    char map_or_list = ' ';
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
                exit(1);
            case 'c':
                if(string(optarg) == "QUEUE"){
                    captain_sq = false;
                } else if (string(optarg) != "STACK"){
                    cerr << "  Invalid argument is: " << optarg << endl;
                    exit(1);
                }
                break;
            case 'f':
                if(string(optarg) == "STACK"){
                    firstmate_sq = true; 
                } else if(string(optarg) != "QUEUE"){
                    cerr << "  Invalid argument is: " << optarg << endl;
                    exit(1);
                }
                break;
            case 'o':
                if(string(optarg).size() != 4){
                cerr << "  Invalid argument is: " << optarg << endl;
                exit(1);
                }
                    for(int i = 0; i < 4; i++){
                        if(optarg[i] != 'N' && optarg[i] != 'E' && optarg[i] != 'S' && optarg[i] != 'W'){   
                            cerr << "  Invalid argument is: " << optarg << endl;
                            exit(1);
                        }
                    }
                    hunt_order = optarg;
                
            
                break;
            case 'v':
                verbose = true; 
                break;
            case 's':
                statistics = true; 
                break;
            case 'p': 
                if(string(optarg)[0] == 'M' || string(optarg)[0] == 'L'){
                    show_path = string(optarg)[0]; 
                } else {
                    cerr << "  Invalid argument is: " << optarg << endl;
                    exit(1);
                }
                break;
            default:
                print_help();
             
            
        }

    };
    uint32_t N; 
    string comments;
    while(getline(cin, comments)) {
        if(comments[0] == 'M'){
            map_or_list = 'M';
            break;
        }
        if(comments[0] == 'L'){
            map_or_list = 'L';
            break;
        }
    }

    cin >> N; 
    FullMap.resize(N);

    
    for (uint32_t i = 0; i < N; ++i) {
        FullMap[i].resize(N);
    }
        uint32_t row_num = 0;
        uint32_t col_num = 0;
        char character; 
        Coordinate submit = {0, 0, '.', ' ', 'N'}; 
        Coordinate starting = {0, 0, '.', ' ', 'N'};
        Coordinate ending = {0, 0, '.', ' ', 'N'};
        if(map_or_list == 'M'){
           
            while(cin >> character){
                if(character != '\n'){
                submit.row = row_num;
                submit.col = col_num;
                submit.identity = character; 
                FullMap[row_num][col_num] = submit; 
                if(character == '@'){
                    starting = submit;
                }
                if(character == '$'){
                    ending = submit;
                }
                col_num++;
                if(col_num == N){
                    col_num = 0;
                    row_num++;
                }
            }
            }
        }
        if(map_or_list == 'L'){
            while(cin >> row_num >> col_num >> character){
            submit.row = row_num;
            submit.col = col_num;
            submit.identity = character; 
            
            FullMap[row_num][col_num] = submit; 
            
            if(character == '@'){
                starting = submit;
            }
            if(character == '$'){
                ending = submit;
            }
            }



            for (uint32_t i = 0; i < N; i++){
                for(uint32_t j = 0; j<N; j++){
                    FullMap[i][j].row = i;
                    FullMap[i][j].col =j;
            }
        } }

        Map Game = Map(FullMap, starting, N, N, ending, verbose, captain_sq, firstmate_sq, hunt_order, show_path, statistics);
        
        if(verbose){
            Game.Verbose();
        }
       
        Game.Router();
        Game.Backtracking();   
        Game.Print_Results();



    return 0; 

}
