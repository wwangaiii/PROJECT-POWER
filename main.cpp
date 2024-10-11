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
void loadTeams(const string& filename, vector<Team>& teams) {
    ifstream file("Downloads/teams_csvFile - teams_csvFile.csv");// this is where the code reads data from the files
    string line;




 while (getline(file, line)) {
        stringstream ss(line);
        Team team;
        getline(ss, team.name, ',');
        getline(ss, team.town, ',');
        getline(ss, team.stadium);
        teams.push_back(team);
    }

void generateFixtures(const vector<Team>& teams, vector<Match>& fixtures) {
    int totalTeams = teams.size();
    int totalWeekends = (totalTeams - 1) * 2; // Each team plays every other team twice










