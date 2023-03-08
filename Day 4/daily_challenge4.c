#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maxBanana(int* piles, int pilesSize){
    int max = piles[0];
    for(int i = 1; i < pilesSize; i++){
        if(piles[i]>max) max = piles[i];
    }
    return max;
}
long long hoursRequired(int* piles, int pilesSize, int speed){
    long long count = 0;
    long double num;
    for(int i=0;i<pilesSize;i++){
        num = (int)ceil((long double)piles[i]/speed);
        count += num;
    }
    return count;
}
int binarySearch(int* piles, int pilesSize, int h, int start, int end){
    int speed = start + (end-start)/2;
    if(start<end){
        if(hoursRequired(piles, pilesSize, speed) > h){
            return binarySearch(piles, pilesSize, h, speed+1, end);
        }
        else return binarySearch(piles, pilesSize, h, start, speed-1);
    }
    return end;
}
int minEatingSpeed(int* piles, int pilesSize, int h){
    int max = maxBanana(piles, pilesSize);
    int speed = binarySearch(piles, pilesSize, h, 1, max);
    return speed+1;
}
int main(){
    int piles[] = {805306368,805306368,805306368};
    int pilesSize = 3;
    int h = 1000000000;
    int speed = minEatingSpeed(piles, pilesSize, h);
    printf("%d", speed);
    return 0;
}