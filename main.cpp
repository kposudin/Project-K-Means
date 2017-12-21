//
//  main.cpp
//  k-means lib
//
//  Created by tin on 03.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//


#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
//#include "k-means.h"
#include "functions.hpp"
#include "classes.hpp"
#include "сlassifier.hpp"
using namespace std;
int v=0;


void my_dist(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount){
    cout << "123";
}

int main(){
    
    
    string a;
    centroid_vector cv;
    dp_vector dpv;
    int ch;
    
    
    cout << "FOR FILE INPUT TYPE 1 // FOR KEYBOARD INPUT TYPE 2"<< endl;
    cin >> ch;
    if (ch==1){
    file_input(cv,dpv);
    }
    else if (ch==2){
    input(cv, dpv);
    }
    else cout << "UNKNOWN COMMAND";
   
    
    return 0;
}
