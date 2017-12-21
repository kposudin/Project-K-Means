//
//  сlassifier.cpp
//  k-means lib
//
//  Created by tin on 10.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//

#include "сlassifier.hpp"
#include "classes.hpp"
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>
using namespace std;
void classify(vector<double> a, centroid_vector cv){
    int j;
    int min_dis;
    int cur_dis=0;
    int cd_sq=0;
    int cb=-1;
    min_dis=INT_MAX;
    for (j=0; j<cv.c_amount;j++){
        for(int k=0;k<cv.dim;k++){
            cd_sq+=(a[k]-cv[j].coord[k])*(a[k]-cv[j].coord[k]);
        }
        cur_dis=cd_sq;
        cd_sq=0;
        if (cur_dis<min_dis){
            cb=j;
            min_dis=cur_dis;
        }
    }
    cout << "YOUR DATA POINT BELONGS TO " << cb+1 << " CLUSTER" << endl;
};
