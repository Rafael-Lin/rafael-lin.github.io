#include "stdafx.h"
#include "Greedy.h"
#include "string"
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<math.h>

#include<iostream>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stack>

using namespace std;

int candy(vector<int> &ratings) {
/**********************************************************************************
*
* There are N children standing in a line. Each child is assigned a rating value.
*
* You are giving candies to these children subjected to the following requirements:
*
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
*
* What is the minimum candies you must give?
*
*
**********************************************************************************/

/*
 *    The soluiton is O(2n) run-time complexity
 *
 *    For example:
 *
 *        ratings[] = { 5, 6, 7, 4, 1, 2, 3, 2, 1, 7 }
 *
 *    1) Go through the ratings from left to right.
 *
 *       Find the each increasing sub-array, giving the minimal candy
 *
 *        ratings[] = { 5, 6, 7,   4,   1, 2, 3,   2,   1, 7 }
 *                      ------>    ->   ------>    ->   --->
 *          candy[] = { 1, 2, 3,   1,   1, 2, 3,   1,   1, 2 }
 *
 *    2) Go through the raings from right to left.
 *
 *             ratings[] = { 5,   6,   7, 4, 1,   2,   3, 2, 1,   7 }
 *                           <-   <-   <------    <-   <------    <-
 *          prev_candy[] = { 1,   2,   3, 1, 1,   2,   3, 1, 1,   2 }
 *                                        +1              +1
 *               candy[] = { 1,   2,   3, 2, 1,   2,   3, 2, 1,   2 }
 *
 *    3) total candy is 19
 *
 */

    vector<int> candyCnt(ratings.size()) ;
    //allocate candies, considering the minimal rating on the left
    candyCnt[0] = 1;
    for(int i = 1; i < ratings.size(); i++){
        candyCnt[i] = ratings[i] > ratings[i-1] ? candyCnt[i-1]+1 : 1;
    }
    //print(candyCnt);
    //modify the allocation, considering the minimal rating on the right
    int totalCandy = candyCnt[ratings.size()-1];
    for(int i = ratings.size()-2; i >= 0; i--){
        candyCnt[i] = (ratings[i] > ratings[i+1] && candyCnt[i+1]+1 > candyCnt[i]) ? candyCnt[i+1]+1 : candyCnt[i];
        //count total candies by the way
        totalCandy += candyCnt[i];
    }
    //print(candyCnt);
    return totalCandy;
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  /**********************************************************************************
  *
  * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
  *
  * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
  * its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
  *
  * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
  *
  * Note:
  * The solution is guaranteed to be unique.
  *
  *
  **********************************************************************************/
  /**********************************************************************************
  *
  * There are N gas stations along a circular route, where the amount of
  * gas at station i is gas[i].
  *
  * You have a car with an unlimited gas tank and it costs cost[i] of gas
  * to travel from station i to its next station (i+1). You begin the
  * journey with an empty tank at one of the gas stations.
  *
  * Return the starting gas station's index if you can travel around the
  * circuit once, otherwise return -1.
  *
  * Note: The solution is guaranteed to be unique.
  *
  *
  **********************************************************************************/
  int current = 0; int start = gas.size(); //start from the end to
  beginning int total = 0;

  do {
    if (total + gas[current] - cost[current] >= 0) {
      total +=
        (gas[current] - cost[current]); current++; // can go from current to
      current + 1
    }
    else{
      start--; //not enough gas, try to start the one
      before origin start point.total += (gas[start] - cost[start]);
    }
  } while (current != start);

  return total >= 0 ? start % gas.size() : -1;
}

