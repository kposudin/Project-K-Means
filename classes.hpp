//
//  classes.hpp
//  k-means lib
//
//  Created by tin on 10.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//

#ifndef classes_hpp
#define classes_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
//#include "functions.hpp"
using namespace std;

struct centroid{
    vector<double> coord;
    int centroid_num;
    centroid*next;
    centroid*prev;
    bool operator==(const centroid& right);
};
struct centroid_vector{
    centroid*head;
    centroid*tail;
    int c_amount;
    int dim;
    centroid_vector();
    void push (vector<double> newdata);
    centroid& operator [](int index);
    centroid operator [](int index) const;
    ~centroid_vector();
};
struct data_point{
    vector<double> data;
    centroid clust_bel;
    data_point*next;
    data_point*prev;
    
    
};
struct dp_vector {
    data_point*head;
    data_point*tail;
    dp_vector();
    void push_start (vector<double> newdata);
    void push (vector<double> newdata);
    data_point& operator [](int index);
    data_point operator [](int index) const;
    ~dp_vector();
};

#endif /* classes_hpp */
