#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


#include "BinaryTree.hpp"
using namespace ariel;
using namespace std;


BinaryTree<int> tree_of_ints1;
BinaryTree<string> tree_of_strings2;
BinaryTree<double> tree_of_ints3;
BinaryTree<int> tree_of_ints4;
BinaryTree<string> tree_of_strings5;

void fill_trees(){
    tree_of_ints1.add_root(1)
    .add_left(1, 2)      
    .add_right(1, 3)
    .add_left(3, 4);

    tree_of_strings2.add_root("N")
    .add_left("N", "O")
    .add_right("N", "A");
    
    tree_of_ints3.add_root(5)
    .add_left(5, 6.5)
    .add_left(6.5, 7.6)
    .add_left(7.6, 9)
    .add_right(6.5, 8);

    tree_of_ints4.add_root(23)
    .add_left(23, 24)
    .add_left(24, 25)
    .add_left(25, 26)
    .add_left(26, 27);

    tree_of_strings5.add_root("hey")
    .add_left("hey", "whats")
    .add_right("hey", "up");

}

TEST_CASE("check inorder"){
    fill_trees();
    stringstream ss("",ios_base::app | ios_base::out);
    string s;

    for (auto it=tree_of_ints1.begin_inorder(); it!=tree_of_ints1.end_inorder(); ++it) {
        ss << (*it) << " " ;
    }  
    s = ss.str();
    
    CHECK_EQ(s, "2 1 4 3 ");
    ss.str(std::string() );
    ss.clear(); 

    for (auto it=tree_of_strings2.begin_inorder(); it!=tree_of_strings2.end_inorder(); ++it) {
        ss << (*it) << " " ;
    }
    s = ss.str();  
    
    CHECK_EQ(s, "O N A ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_ints3.begin_inorder(); it!=tree_of_ints3.end_inorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    
    CHECK_EQ(s, "9 7.6 6.5 8 5 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_ints4.begin_inorder(); it!=tree_of_ints4.end_inorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 

    CHECK_EQ(s, "27 26 25 24 23 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_strings5.begin_inorder(); it!=tree_of_strings5.end_inorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "whats hey up ");
    

}


TEST_CASE("check preorder"){
    fill_trees();
    stringstream ss("",ios_base::app | ios_base::out);
    string s;

    for (auto it=tree_of_ints1.begin_preorder(); it!=tree_of_ints1.end_preorder(); ++it) {
        ss << (*it) << " " ;
    }  
    s = ss.str();
    CHECK_EQ(s, "1 2 3 4 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_strings2.begin_preorder(); it!=tree_of_strings2.end_preorder(); ++it) {
        ss << (*it) << " " ;
    }
    s = ss.str();  
    CHECK_EQ(s, "N O A ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_ints3.begin_preorder(); it!=tree_of_ints3.end_preorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "5 6.5 7.6 9 8 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_ints4.begin_preorder(); it!=tree_of_ints4.end_preorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "23 24 25 26 27 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_strings5.begin_preorder(); it!=tree_of_strings5.end_preorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "hey whats up ");


    
}

TEST_CASE("check postorder"){
    fill_trees();
    stringstream ss("",ios_base::app | ios_base::out);
    string s;

    for (auto it=tree_of_ints1.begin_postorder(); it!=tree_of_ints1.end_postorder(); ++it) {
        ss << (*it) << " " ;
    }  
    s = ss.str();
    CHECK_EQ(s, "2 4 3 1 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_strings2.begin_postorder(); it!=tree_of_strings2.end_postorder(); ++it) {
        ss << (*it) << " " ;
    }
    s = ss.str();  
    CHECK_EQ(s, "O A N ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_ints3.begin_postorder(); it!=tree_of_ints3.end_postorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "9 7.6 8 6.5 5 ");
    ss.str(std::string());
    ss.clear();

    for (auto it=tree_of_ints4.begin_postorder(); it!=tree_of_ints4.end_postorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "27 26 25 24 23 ");
    ss.str(std::string() );
    ss.clear();

    for (auto it=tree_of_strings5.begin_postorder(); it!=tree_of_strings5.end_postorder(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "whats up hey ");
    
}

TEST_CASE("check default iterator(inorder)"){
    fill_trees();
    stringstream ss("",ios_base::app | ios_base::out);
    string s;

    for (auto it=tree_of_ints1.begin(); it!=tree_of_ints1.end(); ++it) {
        ss << (*it) << " " ;
    }  
    s = ss.str();
    
    CHECK_EQ(s, "2 1 4 3 ");
    ss.str(std::string());
    ss.clear(); 

    for (auto it=tree_of_strings2.begin(); it!=tree_of_strings2.end(); ++it) {
        ss << (*it) << " " ;
    }
    s = ss.str();  
    
    CHECK_EQ(s, "O N A ");
    ss.str(std::string());
    ss.clear();

    for (auto it=tree_of_ints3.begin(); it!=tree_of_ints3.end(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    
    CHECK_EQ(s, "9 7.6 6.5 8 5 ");
    ss.str(std::string());
    ss.clear();

    for (auto it=tree_of_ints4.begin(); it!=tree_of_ints4.end(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 

    CHECK_EQ(s, "27 26 25 24 23 ");
    ss.str(std::string());
    ss.clear();

    for (auto it=tree_of_strings5.begin(); it!=tree_of_strings5.end(); ++it) {
        ss << (*it) << " " ;
    } 
    s = ss.str(); 
    CHECK_EQ(s, "whats hey up ");
    
    
}


