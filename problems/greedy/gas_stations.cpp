#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {

    unsigned long int n = gas.size();

    int validStartIdx = 0;
    while( validStartIdx < n && gas[validStartIdx] < cost[validStartIdx] ){
        validStartIdx++;
    }

    // No elem can reach its next
    if( validStartIdx == n )
        return -1;

    int currentGas = gas[validStartIdx] - cost[validStartIdx];
    int startIdx = validStartIdx;
    int endIdx = validStartIdx + 1;

    while( startIdx < n ){


        if( currentGas + gas[endIdx%n] >= cost[endIdx%n] ){

            // Gas is positive - Valid station reached

            if( ( endIdx + 1 )%n == startIdx )
                return startIdx;

            currentGas += gas[endIdx%n];
            currentGas -= cost[endIdx%n];
            endIdx++;

        } else {

            // pick next startIdx, post endIdx
            int nextStartIdx = endIdx;
            while( nextStartIdx < n && gas[nextStartIdx] < cost[nextStartIdx] ){
                nextStartIdx++;
            }

            if( nextStartIdx >= n )
                return -1;

            startIdx = nextStartIdx;
            currentGas = gas[startIdx] - cost[startIdx];
            endIdx = startIdx + 1;
        }
    }

    return -1;
}

int main() {

//    vector<int> gas = { 1, 2 };
//    vector<int> cost = { 2, 1 };
//    cout<<"Ans: "<<canCompleteCircuit( gas, cost )<<endl;         // 1

//    vector<int> gas1 = { 369, 72, 760, 967, 98, 963, 260, 7, 959, 186, 85, 948, 328, 136, 601, 832, 547 };
//    vector<int> cost1 = { 960, 85, 747, 341, 402, 446, 438, 413, 307, 406, 501, 666, 973, 378, 648, 65, 414 };
//    cout<<"Ans: "<<canCompleteCircuit( gas1, cost1 )<<endl;           // -1

    vector<int> gas2 = { 204, 918, 18, 17, 35, 739, 913, 14, 76, 555, 333, 535, 653, 667, 52, 987, 422, 553, 599, 765, 494, 298, 16, 285, 272, 485, 989, 627, 422, 399, 258, 959, 475, 983, 535, 699, 663, 152, 606, 406, 173, 671, 559, 594, 531, 824, 898, 884, 491, 193, 315, 652, 799, 979, 890, 916, 331, 77, 650, 996, 367, 86, 767, 542, 858, 796, 264, 64, 513, 955, 669, 694, 382, 711, 710, 962, 854, 784, 299, 606, 655, 517, 376, 764, 998, 244, 896, 725, 218, 663, 965, 660, 803, 881, 482, 505, 336, 279 };
    vector<int> cost2 = { 273, 790, 131, 367, 914, 140, 727, 41, 628, 594, 725, 289, 205, 496, 290, 743, 363, 412, 644, 232, 173, 8, 787, 673, 798, 938, 510, 832, 495, 866, 628, 184, 654, 296, 734, 587, 142, 350, 870, 583, 825, 511, 184, 770, 173, 486, 41, 681, 82, 532, 570, 71, 934, 56, 524, 432, 307, 796, 622, 640, 705, 498, 109, 519, 616, 875, 895, 244, 688, 283, 49, 946, 313, 717, 819, 427, 845, 514, 809, 422, 233, 753, 176, 35, 76, 968, 836, 876, 551, 398, 12, 151, 910, 606, 932, 580, 795, 187 };
    cout<<"Ans: "<<canCompleteCircuit( gas2, cost2 )<<endl;           // 31

    return 0;
}