//
//  functions.hpp
//  k-means lib
//
//  Created by tin on 10.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp
#include "classes.hpp"
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>

void clust(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount);
void clust_sq(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount);
void clust_tg(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount);
void clust_cheb(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount);
void clust_user(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount, void(*user_dist)(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount));
void cent_move(centroid_vector cv, dp_vector dpv, int dimensionality, int dp_amount);
void print_result(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv);
void kmeans_clust (int iter_amount, centroid_vector cv, dp_vector dpv, int dimensionality, int c_amount, int dp_amount);
void file_result (int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv);
void cluster_i_result(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv, int i);
void cluster_i_file_result (int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv, int i);
void c_i_s(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv);
void input(centroid_vector cv, dp_vector dpv);
void file_input(centroid_vector cv, dp_vector dpv);
void centroid_to_file(centroid_vector cv, int c_amount, int dimensionality);
void classif (centroid_vector cv);
#endif /* functions_hpp */
