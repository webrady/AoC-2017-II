#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Spiral{
private:
    int** spiral;
    int center;
    int length;
    int targetX;
    int targetY;

    void isTarget(int target,int value,int x,int y){
        if(target == value){
            targetX = x;
            targetY = y;
        }
    }
public:
    Spiral(){
    }
    Spiral(int target){
        //Generates the 2d array
        for(int i = 1;true;i+=2){
            if((i * i) >= target){
                //makes the ixi array
                length = i + 1;
                spiral = new int*[length];
                for(int j = 0;j < length;j++){
                    spiral[j] = new int[length];
                }
                //center calc
                center = ((length - 1) / 2);
                break;
            }
        }
        //Now to fill in the spiral
        int value = 1;
        spiral[center][center] = value++;
        if(length > 1){
            for(int ring = 1;value < (length - 1) * (length - 1);ring++){
                //OUT OF BOUNDS YOU FAGGOT DRAW THE SHIT OUT
                //RIGHT
                for(int i = 0;i < ring * 2;i++){
                    spiral[center + ring][center + i - (ring -  1)] = value;
                    this->isTarget(target,value,center + ring,center + i - (ring -  1));
                    value++;
                }
                //UP
                for(int i = 0;i < ring * 2;i++){
                    spiral[center - i + (ring -  1)][center + ring] = value;
                    this->isTarget(target,value,center - i + (ring -  1),center + ring);
                    value++;
                }
                //LEFT
                for(int i = 0;i < ring * 2;i++){
                    spiral[center - ring][center - i + (ring -  1)] = value;
                    this->isTarget(target,value,center - ring,center + i + (ring -  1));
                    value++;
                }
                //DOWN
                for(int i = 0;i < ring * 2;i++){
                    spiral[center + i - (ring -  1)][center - ring] = value;
                    this->isTarget(target,value,center + i - (ring -  1),center - ring);
                    value++;
                }
            }
        }
    }

    int getDist(){
        return abs(center - targetX) + abs(center - targetY);
    }
};

int main(){
    Spiral ayy = Spiral(265149);
    cout << ayy.getDist();
    return 0;
}
