#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
    string input = "157	564	120	495	194	520	510	618	244	443	471	473	612	149	506	138 1469 670 47	604	1500 238 1304 1426 54 749 1218 1409	60 51 1436 598 578 184	2760	3057	994	167	2149	191	2913	2404	213	1025	1815	588	2421	3138 935	850	726	155	178	170	275	791	1028	75	781	138	176	621	773	688 212	977	297	645	229	194	207	640	804	509	833	726	197	825	242	743 131	43	324	319	64	376	231	146	382	162	464	314	178	353	123	446 551	121	127	155	1197	288	1412	1285	557	137	145	1651	1549	1217	681	1649 1723	1789	5525	4890	3368	188	3369	4842	3259	2502	4825	163	146	2941	126	5594 311	2420	185	211	2659	2568	2461	231	2599	1369	821	506	2227	180	220	1372 197	4490	141	249	3615	3314	789	4407	169	352	4383	5070	5173	3115	132	3513 4228	2875	3717	504	114	2679	165	3568	3002	116	756	151	4027	261	4813	2760 651	3194	2975	2591	1019	835	3007	248	3028	1382	282	3242	296	270	3224	3304 1858	1650	1720	1848	95	313	500	1776	207	1186	72	259	281	1620	79	77 3841	3217	440	3481	3643	940	3794	4536	1994	4040	3527	202	193	1961	230	217 2837	2747	2856	426	72	78	2361	96	2784	2780	98	2041	2444	1267	2167	2480 411	178	4263	4690	3653	162	3201	4702	3129	2685	3716	147	3790	4888	79	165 ";
    //string input = "5 9 2 8 9 4 7 3 3 8 6 5 2 7 9 4 ";
    int rowSize = 16; //16 for true input
    int colSize = 16; //16 for true input
    int arr[rowSize][colSize];
    int r = 0;//Row location for the following loop
    int c = 0;//Col
    string currNum = "";
    //Input string -> 2D array
    for(int i = 0;i < input.size();i++){
        //If its a tab/space/non number, add num to array accordingly
        if(input.at(i) != '0'&&input.at(i) != '1'&&input.at(i) != '2'&&input.at(i) != '3'&&input.at(i) != '4'&&input.at(i) != '5'&&input.at(i) != '6'&&input.at(i) != '7'&&input.at(i) != '8'&&input.at(i) != '9'){
            arr[r][c] = atoi(currNum.c_str());
            currNum = "";
            r++;
            if(r == rowSize){
                r = 0;
                c++;
            }
        }
        else{
            currNum += input.at(i);
        }
    }
    //DAY 2 PART 1: CHECKSUM
    int big;
    int small;
    int sum = 0;
    //Column Iteration: Adds difference of max and min values in each row
    for(int i = 0;i < colSize;i++){
        big = 0;
        small = 9999999;
        //Row Iteration: Determines max and min values in the row
        for(int j = 0;j < rowSize;j++){
            if(arr[j][i] < small)
                small = arr[j][i];
            if(arr[j][i] > big)
                big = arr[j][i];
        }
        sum += (big - small);
    }
    cout << sum << "\n";
    //DAY 2 PART 2: DIVIDE SUM
    sum = 0;
    int divVal;
    //Column Iteration
    for(int i = 0;i < colSize;i++){
        divVal = 0;
        //Row Iteration: For figuring out the numerator of divVal
        for(int j = 0;j < rowSize;j++){
            //2nd Row Iteration: For figuring out the denominator of divVal
            for(int k = 0;k < rowSize;k++){
                //If they are divisible and not by itself, set divVal to said division and quit searching for divVal
                if(arr[j][i] % arr[k][i] == 0 && j != k){
                    divVal = (arr[j][i] / arr[k][i]);
                    break;
                }
            }
            if(divVal != 0)
                break;
        }
        sum += divVal;
    }
    cout << sum;

    return 0;
}
