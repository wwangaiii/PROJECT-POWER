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
    ifstream file("C:/Users/barak/Downloads/teams_csvFile - teams_csvFile.csv");// this is where the code reads data from the files
    

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
    int totalTeams = teams.size();// Stores the total number of teams
    int totalWeekends = (totalTeams - 1) * 2; // Each team plays every other team twice
//Create fixtures for each team
for(int leg=1;i<=2;leg++){// Two legs for each team(HOME AND AWAY)
   for (int i = 0; i < totalTeams; i++) {//Iterates through each team as a potential home team. 
     for(int j=i+1;j<totalTeams;j++){// Iterates through each team after the current home team, ensuring that each pair of teams is matched only once per leg.
Match match;//creating the object(Match)
match.home=teams[i];//setting the home teams as "i"
match.away=teams[j];//setting away teams as "j"
match.leg=leg;//assigning current leg(EITHER 1 OR 2)
match.time=(rand()%2==0) ? "afternoon":"evening";;//randomly assigning the time
match.weekend="weekend="+to_string((i+j+leg)%totalWeekends+1);
match.day=(rand()%2==) ? "Saturday":"Sunday";//randomly assigning the day
fixtures.push_back(match);
}
}
}
 // Writing the fixtures to a CSV file
    ofstream file("ABC.premier.league.fixtures.csv");
    file << "Home Team,Away Team,Leg,Time,Weekend, Day\n";

    for (const auto& match : fixtures) {
        file << match.home.name << ", "
             << match.away.name << ", "
             << match.leg << ", "
             << match.time << ", "
             <<match.day << ", "
             << match.weekend << "\n";

        cout << match.home.name << " VS " << match.away.name//output formula
             << "  |  Leg: " << match.leg
             << "  |  Time: " << match.time
             << "  |  " << match.weekend
             << "  |  Day: "<<match.day << endl;
    }

    file.close();
}

int main() {

    vector<Team> teams;
    loadTeams ("teams_csvFile.csv",teams); //Load teams from CSV file 
    vector<Match> fixtures;
    generateFixtures(teams, fixtures);

return 0;
}









