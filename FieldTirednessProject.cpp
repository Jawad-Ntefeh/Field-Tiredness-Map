#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    int sizeX, sizeY, currentYear=-1, plantingCount, startX, startY, endX,endY;

    std::string file;
    std::cin >> file;

    std::ifstream inputFile;
    inputFile.open(file);

    inputFile >> sizeX;
    inputFile >> sizeY;

    int **tirednessMap = (int **) malloc(sizeX * sizeof(int *));
    int **newtirednessMap = (int **) malloc(sizeX * sizeof(int *));
    for (int n = 0; n < sizeX; n++) {
        tirednessMap[n] = (int *) malloc(sizeY * sizeof(int));
        newtirednessMap[n] = (int *) malloc(sizeY * sizeof(int));
    }

    tirednessMap = (int**)calloc(sizeX, sizeof(int*));
    for (int n = 0; n < sizeX; n++) {
        tirednessMap[n] = (int*)calloc(sizeY, sizeof(int));
    }


    if(sizeX <= 40 || 40 <= sizeY) {

        while(currentYear!=2017) {

            newtirednessMap = (int**)calloc(sizeX, sizeof(int*));
            for (int n = 0; n < sizeX; n++) {
                newtirednessMap[n] = (int*)calloc(sizeY, sizeof(int));
            }

            inputFile >> currentYear;
            inputFile >> plantingCount;

            for (int plant = 0; plant < plantingCount; plant++) {
                inputFile >> startX >> startY >> endX >> endY;

                for (int m = startX; m <= endX; m++) {
                    for (int n = startY; n <= endY; n++) {
                        if (newtirednessMap[m][n] != 1) {
                            newtirednessMap[m][n]++;
                        }
                    }
                }
            }

            for (int m=0; m < sizeX; m++) {
                for (int n = 0; n < sizeY; n++){
                    tirednessMap[m][n] += newtirednessMap[m][n];

                    if (tirednessMap[m][n] != 0 && newtirednessMap[m][n] == 0) {
                        tirednessMap[m][n]--;
                    }
                }
            }

        }

        for (int n = 0; n < sizeY ; n++){
            for(int m = 0; m < sizeX; m++){
                std::cout << tirednessMap[m][n] << " ";
            }
            std::cout << "\n";
        }

    }
    inputFile.close();
    free(tirednessMap);
    free(newtirednessMap);
    return 0;
}