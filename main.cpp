#include <iostream>
#include <vector>//for using resizeable arrays
#include <fstream>//for reading from files and writing files
#include <sstream>//for manipulating the strings
#include <string>//for handling of characters
#include <ctime>//library handling date and time

using namespace std;

struct Team {
    string name;
    string town;
    string stadium;
};

struct Match{ // structure of how the fixtures are going to be
    Team home;// Team can be playing at their home ground
    Team away;//Team can be playing away
    int leg; // 1 or 2
    string time; // it can be played in afternoon or evening
    string weekend; // "weekend #1", "weekend #2", and so on.
    string day;//Saturday or Sunday
};














