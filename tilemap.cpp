#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream tileMapFile ("./tilemap.txt");

            string line;
            int x = 0;
            int y = 0;
            vector< vector<int> > tiles;
            
            while (getline(tileMapFile, line)) {
                size_t pos = 0;
                string token;
                vector<int> tile_x;
                int count = 0;
                while ((pos = line.find(" ")) != string::npos) {
                    
                    token = line.substr(0, pos);
                    int tile = stoi(token);
                    tile_x.push_back(tile);
                    // cout << tile_x.at(count) << " ";
                    line.erase(0, pos + 1);
                    count += 1;
                }
                // cout << endl;
                tiles.push_back(tile_x);
                
            }
            for (int i = 0; i < tiles.size(); i++) {
                for (int j = 0; j < tiles[i].size(); j++) {
                    cout << tiles[i][j] << " ";
                }
                cout << endl;
            }

}