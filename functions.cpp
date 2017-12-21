//
//  functions.cpp
//  k-means lib
//
//  Created by tin on 10.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//

#include "functions.hpp"
#include "сlassifier.hpp"


//int clust_sel;
//this function calculates all the possible distances from the cluster centroids to data_points using the Euclidean space and assigns every data_point to the nearest centroid.

void clust(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount){
    int i,j;
    double min_dis;
    double cur_dis=0;
    double cd_sq=0;
    for (i=0; i<dp_amount;i++){
        min_dis=INT_MAX;
        for (j=0; j<c_amount;j++){
            for(int k=0;k<dimensionality;k++){
                cd_sq+=(dpv[i].data[k]-cv[j].coord[k])*(dpv[i].data[k]-cv[j].coord[k]);
            }
            cur_dis=sqrt(cd_sq);
            cd_sq=0;
            if (cur_dis<min_dis){
                dpv[i].clust_bel=cv[j];
                min_dis=cur_dis;
            }
        }
    }
}

//this function calculates all the possible distances from the cluster centroids to data_points using the square of the Euclidean space and assigns every data_point to the nearest centroid.
void clust_sq(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount){
    int i,j;
    int min_dis;
    int cur_dis=0;
    int cd_sq=0;
    for (i=0; i<dp_amount;i++){
        min_dis=INT_MAX;
        for (j=0; j<c_amount;j++){
            for(int k=0;k<dimensionality;k++){
                cd_sq+=(dpv[i].data[k]-cv[j].coord[k])*(dpv[i].data[k]-cv[j].coord[k]);
            }
            cur_dis=cd_sq;
            cd_sq=0;
            if (cur_dis<min_dis){
                dpv[i].clust_bel=cv[j];
                min_dis=cur_dis;
            }
        }
    }
}




//this function calculates all the possible distances from the cluster centroids to data_points using the Taxicab geometry and assigns every data_point to the nearest centroid.
void clust_tg(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount){
    int i,j;
    double min_dis;
    double cur_dis=0;
    double cd_sq=0;
    double cup;
    for (i=0; i<dp_amount;i++){
        min_dis=__SIZEOF_DOUBLE__;
        for (j=0; j<c_amount;j++){
            for(int k=0;k<dimensionality;k++){
                cup=dpv[i].data[k]-cv[j].coord[k];
                if (cup>=0)
                cd_sq+=cup;
                else
                cd_sq+=-cup;
            }
            cur_dis=cd_sq;
            cd_sq=0;
            if (cur_dis<min_dis){
                dpv[i].clust_bel=cv[j];
                min_dis=cur_dis;
            }
        }
    }
}


//this function calculates all the possible distances from the cluster centroids to data_points using the Chebyshev distance and assigns every data_point to the nearest centroid.
void clust_cheb(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount){
    int i,j;
    int min_dis;
    int cur_dis=0;
    int cd_sq=0;
    double cup;
    for (i=0; i<dp_amount;i++){
        min_dis=INT_MAX;
        for (j=0; j<c_amount;j++){
            for(int k=0;k<dimensionality;k++){
                if (dpv[i].data[k]-cv[j].coord[k]>=0)
                    cup=dpv[i].data[k]-cv[j].coord[k];
                else
                    cup=-dpv[i].data[k]-cv[j].coord[k];
                if (cup>cd_sq)
                    cd_sq=cup;
            }
            cur_dis=cd_sq;
            cd_sq=0;
            if (cur_dis<min_dis){
                dpv[i].clust_bel=cv[j];
                min_dis=cur_dis;
            }
        }
    }
}

void clust_user(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount, void(*user_dist)(centroid_vector cv, int dp_amount, dp_vector dpv, int dimensionality, int c_amount)){
    user_dist(cv, dp_amount, dpv, dimensionality, c_amount);
    
}







//this function calculates average of the all points in every cluster and then replaces the coordinates of the current cluster with value found.
void cent_move(centroid_vector cv, dp_vector dpv, int dimensionality, int dp_amount){
    double n=0;
    for (int i=0;i<cv.c_amount;i++){
        
        vector<double> new_c(dimensionality);
        n=0;
        for (int j=0; j<dp_amount; j++){
            if (dpv[j].clust_bel==cv[i]){//if current data_point belongs to current centroid
                for (int k=0; k<dimensionality; k++){
                    new_c[k]+=dpv[j].data[k];
                }
                n+=1;
            }
        }
        for (int l=0;l<dimensionality;l++){
            new_c[l]=new_c[l]/n;
            cv[i].coord[l]=new_c[l];
        }
        new_c.clear();
        
    }
}


// this function prints the results of the culsterization
void print_result(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv){
    for (int i=0; i<c_amount; i++){
        cout << "CLUSTER " << i+1 << " DATA POINTS:" << endl;
        for (int j=0; j<dp_amount; j++){
            if (dpv[j].clust_bel.centroid_num==cv[i].centroid_num){
                cout << "DATA POINT " << j+1 << endl;
            }
        }
    }
}





void kmeans_clust (int iter_amount, centroid_vector cv, dp_vector dpv, int dimensionality, int c_amount, int dp_amount){
    int ch;
    cout <<"1 TO USE THE EUCLIDEAN SPACE // 2 TO USE THE SQUARE OF THE EUCLIDEAN SPACE // 3 TO USE THE TAXICAB GEOMETRY // 4 TO USE THE CHEBYSHEV DISTANCE" << endl;
    cin >> ch;
    if (ch==1)
        for (int i=0; i<iter_amount; i++){
            
            clust(cv,dp_amount,dpv,dimensionality,c_amount);
            cent_move(cv, dpv, dimensionality, dp_amount);
        }
    else if (ch==2)
        for (int i=0; i<iter_amount; i++){
            
            clust_sq(cv,dp_amount,dpv,dimensionality,c_amount);
            cent_move(cv, dpv, dimensionality, dp_amount);
        }
    else if (ch==3)
        for (int i=0; i<iter_amount; i++){
            
            clust_tg(cv,dp_amount,dpv,dimensionality,c_amount);
            cent_move(cv, dpv, dimensionality, dp_amount);
        }
    else if (ch==4)
        for (int i=0; i<iter_amount; i++){
            
            clust_cheb(cv,dp_amount,dpv,dimensionality,c_amount);
            cent_move(cv, dpv, dimensionality, dp_amount);
        }
    else cout << "UNKNOWN COMMAND" << endl;
    cout << "1 TO SAVE CLUSTERS COORDS TO FILE" << endl;
    cin >> ch;
    if (ch==1)
    centroid_to_file(cv, c_amount, dimensionality);
}



void file_result (int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv){
    ofstream fres;
    fres.open("clusterization results.txt");
    
    for (int i=0; i<c_amount; i++){
        fres << "CLUSTER " << i+1 << " DATA POINTS:" << endl;
        for (int j=0; j<dp_amount; j++){
            if (dpv[j].clust_bel.centroid_num==cv[i].centroid_num){
                fres << "DATA POINT " << j+1 << endl;
            }
        }
    }
    fres.close();
    
}


//functions that shows all the data points that belongs to the cluster number i
void cluster_i_result(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv, int i){
    
    cout << "CLUSTER " << i << " DATA POINTS:" << endl;
    for (int j=0; j<dp_amount; j++){
        if (dpv[j].clust_bel==cv[i-1]){
            cout << "DATA POINT " << j+1 << endl;
        }
    }
    
}

//functions that writes all the data points that belongs to the cluster number i to the file "cluster i results"
void cluster_i_file_result (int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv, int i){
    ofstream cres;
    cres.open("cluster i results.txt");
    
    
    cres << "CLUSTER " << i << " DATA POINTS:" << endl;
    for (int j=0; j<dp_amount; j++){
        if (dpv[j].clust_bel==cv[i-1]){
            cres << "DATA POINT " << j+1 << endl;
        }
    }
    cres.close();
}


void c_i_s(int c_amount, int dp_amount, dp_vector dpv, centroid_vector cv){
    int ch,c;
    cout << "1 TO SHOW CLUSTER I COORDINATES // 2 TO OUTPUT CLUSTER I COORDINATES TO FILE" << endl;
    cin >> ch;
    if (ch==1){
        cout << endl << "ENTER CLUSTER NUMBER TO SHOW ITS DATA POINTS" << endl;
        cin >> c;
        cluster_i_result (c_amount, dp_amount, dpv, cv,c);
    }
    if (ch==2){
        cout << endl << "ENTER CLUSTER NUMBER TO SHOW ITS DATA POINTS" << endl;
        cin >> c;
        cluster_i_file_result (c_amount, dp_amount, dpv, cv,c);
    }
}


void input(centroid_vector cv, dp_vector dpv){
    double n;
    int dimensionality, dp_amount, c_amount, iter_amount;
    cout << "ENTER AMOUNT OF ATTRIBUTES" << endl;
    cin >> dimensionality;
    cv.dim=dimensionality;
    cout << "ENTER AMOUNT OF DATA POINTS" << endl;
    cin >> dp_amount;
    cout << "ENTER AMOUNT OF CLUSTERS" << endl;
    cin >> c_amount;
    cout << "ENTER AMOUNT OF ITERATIONS" << endl;
    cin >> iter_amount;
    vector<double> new_c;
    new_c.reserve(dimensionality);
    for (int i=0; i<c_amount; i++){
        cout << "ENTER CLUSTER " << i+1 << " COORDINATES" << endl;
        for (int j=0; j<dimensionality;j++){
            cin >> n;
            new_c.push_back(n);
        }
        cout << endl;
        cv.push(new_c);
        new_c.clear();
    }
    
    for (int i=0; i<dp_amount; i++){
        cout << "ENTER DATA POINT " << i+1 << " ATTRIBUTES" << endl;
        for (int j=0; j<dimensionality; j++){
            cin >> n;
            new_c.push_back(n);
        }
        cout << endl;
        dpv.push(new_c);
        new_c.clear();
        
    }
    kmeans_clust(iter_amount,cv,dpv,dimensionality,c_amount,dp_amount);
    int ch;
    cout << "1 TO WRITE THE RESULTS TO CONSOLE // 2 TO WRITE THE RESULTS TO FILE" << endl;
    cin >> ch;
    if (ch==1)
        print_result(c_amount, dp_amount, dpv, cv);
    else if (ch==2)
        file_result(c_amount, dp_amount, dpv, cv);
    else cout << "UNKNOWN COMMAND";
    c_i_s(c_amount,dp_amount,dpv,cv);
    cout << "1 TO CLASSIFY ADDITIONAL DATA POINT" << endl;
    cin >> ch;
    if (ch==1)
    {
        classif(cv);
    }
    
    
}


void file_input(centroid_vector cv, dp_vector dpv){
    string a;
    int dimensionality, dp_amount, c_amount, iter_amount;
    double n;
    ifstream fin("in.txt");
    
    //AMOUNT OF ATTRIBUTES
    fin >> a;
    dimensionality = stoi(a);
    cv.dim=dimensionality;
    //AMOUNT OF DATA POINTS
    fin >> a;
    dp_amount=stoi(a);
    //AMOUNT OF CLUSTERS
    fin >> a;
    c_amount=stoi(a);
    //AMOUNT OF ITERATIONS"
    fin >> a;
    iter_amount=stoi(a);
    
    
    
    vector<double> new_c;
    new_c.reserve(dimensionality);
    for (int i=0; i<c_amount; i++){
        //cout << "ENTER CLUSTER " << i+1 << " COORDINATES" << endl;
        for (int j=0; j<dimensionality;j++){
            fin >> a;
            n = stod(a);
            new_c.push_back(n);
        }
        //cout << endl;
        cv.push(new_c);
        new_c.clear();
    }
    
    for (int i=0; i<dp_amount; i++){
        //cout << "ENTER DATA POINT " << i+1 << " ATTRIBUTES" << endl;
        for (int j=0; j<dimensionality; j++){
            fin >> a;
            n=stoi(a);
            new_c.push_back(n);
        }
        //cout << endl;
        dpv.push(new_c);
        new_c.clear();
        
        
    }
    fin.close();
    kmeans_clust(iter_amount,cv,dpv,dimensionality,c_amount,dp_amount);
    int ch;
    cout << "1 FOR OUTPUT TO FILE // 2 FOR OUTPUT TO CONSOLE" << endl;
    cin >> ch;
    if (ch==2){
        print_result(c_amount, dp_amount, dpv, cv);
    }
    else if (ch==1){
        file_result(c_amount, dp_amount, dpv, cv);
    }
    c_i_s(c_amount,dp_amount,dpv,cv);
    cout << "1 TO CLASSIFY ADDITIONAL DATA POINT" << endl;
    cin >> ch;
    if (ch==1)
    {
        classif(cv);
    }
    
}

void centroid_to_file(centroid_vector cv, int c_amount, int dimensionality){
    ofstream cres;
    cres.open("clusters.txt");
    for (int j=0; j<c_amount; j++){
        for (int i=0; i<dimensionality; i++){
            cres << cv[j].coord[i] << endl;
        }
    }
    cres.close();
}
void classif(centroid_vector cv){
    vector<double> dp1;
    double cup;
    cout << "INPUT DATA POINT ATTRIBUTES" << endl;
    for (int i=0; i<cv.dim; i++){
        cin >> cup;
        dp1.push_back(cup);
    }
    
    classify(dp1, cv);
};
