//
//  classes.cpp
//  k-means lib
//
//  Created by tin on 10.05.17.
//  Copyright © 2017 yung blüd. All rights reserved.
//

#include "classes.hpp"
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
//centroid data

bool centroid::operator==(const centroid& right) {
        return coord == right.coord;
    }


//vector of the cluster centroids
centroid_vector::centroid_vector(){
        head=NULL;
        tail=NULL;
        c_amount=0;
        dim=0;
    };
centroid_vector::~centroid_vector(){
}
    
void centroid_vector::push (vector<double> newdata){
        centroid*temp=new centroid;
        temp->coord=newdata;
        c_amount+=1;
        temp->centroid_num=c_amount;
        if(head==NULL){
            temp->next=NULL;
            temp->prev=NULL;
            head=temp;
            tail=temp;
            
        }
        else{
            temp->next=NULL;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        
    }
    
    
centroid& centroid_vector::operator [](int index){
        centroid*temp1=head;
        int i;
        vector<int> p;
        p.insert(p.end(), 0);
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return *head;
            }
        }
        return *temp1;
    }
    
centroid centroid_vector::operator [](int index) const {
        centroid*temp1=head;
        int i;
        vector<int> p;
        p.insert(p.end(), 0);
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return *head;
            }
        }
        return *temp1;
    }
    





//data_point includes integer vector with attributes and pointer to the cluster that cointains this data_point.


//data_points vector

dp_vector::dp_vector(){
        head=NULL;
        tail=NULL;
    };
    
    
void dp_vector::push_start (vector<double> newdata){
        data_point*temp=new data_point;
        temp->data=newdata;
        if(head==NULL){ head=temp;
            tail=temp;
        }
        else{
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    
    
void dp_vector::push (vector<double> newdata){
        data_point*temp=new data_point;
        temp->data=newdata;
        if(head==NULL){
            temp->next=NULL;
            temp->prev=NULL;
            head=temp;
            tail=temp;
        }
        else{
            temp->next=NULL;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        
    }
    
    
    
    
data_point& dp_vector::operator [](int index){
        data_point*temp1=head;
        int i;
        vector<int> p;
        p.insert(p.end(), 0);
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return *head;
            }
        }
        return *temp1;
    }
    
data_point dp_vector::operator [](int index) const {
        data_point*temp1=head;
        int i;
        vector<int> p;
        p.insert(p.end(), 0);
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return *head;
            }
        }
        return *temp1;
    }
    
    
    
dp_vector::~dp_vector(){
        
    }
    
    



