#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Spiral{
private:
    int** spiral;
    int center;
    int length;
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
        //Set all spots to zero
        //jk I'm done with this day for now, wish I chose a different language for this
        //Now to fill in the spiral
        int value = 1;
        spiral[center][center] = value;
        if(length > 1){
            for(int ring = 1;value < (length - 1) * (length - 1);ring++){
                //RIGHT
                for(int i = 0;i < ring * 2;i++){
                    spiral[center + ring][center + i - (ring -  1)] = value;
                    value++;
                }
                //UP
                for(int i = 0;i < ring * 2;i++){
                    spiral[center - i + (ring -  1)][center + ring] = value;
                    value++;
                }
                //LEFT
                for(int i = 0;i < ring * 2;i++){
                    spiral[center - ring][center - i + (ring -  1)] = value;
                    value++;
                }
                //DOWN
                for(int i = 0;i < ring * 2;i++){
                    spiral[center + i - (ring -  1)][center - ring] = value;
                    value++;
                }
            }
        }
    }


};

int main(){
    Spiral ayy = Spiral(265149);
    return 0;
}
