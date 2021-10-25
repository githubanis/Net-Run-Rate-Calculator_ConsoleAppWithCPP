#include<bits/stdc++.h>
using namespace std;

std::vector<string> teams;
std::vector<vector<float>> totalRuns(12), totalRunsOfOpponent(12), totalOvers(12), totalOversOfOpponent(12);
std::vector<float> netRunRate(12);
std::string temp, t;
int noOfTeams, temp1, temp2;

void ShowOptions(int x) {
    for(int i=0; i<noOfTeams; i++) {
        if(i == x)
            continue;
        cout<<"Press "<<i + 1<<" for team "<<teams[i]<<endl;
    }
}
void TakeInput() {
    cin>>t;
    for(int i=0; i<noOfTeams; i++) {        
        getline(cin, temp);
        teams.push_back(temp);        
    }
    teams[0] = t;
}
void ShowInitialMassege() {
    cout<<"--------> This console app is all about <---------"<<endl;
    cout<<"------------> Net Run Rate Calculator <-----------"<<endl;
    cout<<"How many teams in the group: "<<endl;
}
void InvalidInputMassege(int num) {
    cout<<"Your Input is not right, please try again.."<<endl;
    cout<<"You must choose options between 1 to "<<num<<endl;
}
bool Invalid(int temp) {
    if(temp > noOfTeams || temp < 1) {
        InvalidInputMassege(noOfTeams);
        return true;
    }
    return false;
}
void SaveMatchScores(int x, int y, float rx, float ox, float ry, float oy) {

    totalRuns[x].push_back(rx);
    totalRunsOfOpponent[x].push_back(ry);

    totalRuns[y].push_back(ry);
    totalRunsOfOpponent[y].push_back(rx);

    totalOvers[x].push_back(ox);
    totalOversOfOpponent[x].push_back(oy);

    totalOvers[y].push_back(oy);
    totalOversOfOpponent[y].push_back(ox);

    float netRunRateForX = 0.0, netRunRateForY = 0.0; 
    float totalRunsForX = 0.0, totalRunsForY = 0.0;
    float totalRunsForOpponentX = 0.0, totalRunsForOpponentY = 0.0;
    float totalOversForX = 0.0, totalOversForY = 0.0;
    float totalOversForOpponentX = 0.0, totalOversForOpponentY = 0.0;
    
    for(int i = 0 ; i < totalRuns[x].size() ; i++) {
        totalRunsForX += totalRuns[x][i];
        totalRunsForOpponentX += totalRunsOfOpponent[x][i];
        totalOversForX += totalOvers[x][i];
        totalOversForOpponentX += totalOversOfOpponent[x][i];
    }
    for(int i = 0 ; i < totalRuns[y].size() ; i++) {
        totalRunsForY += totalRuns[y][i];
        totalRunsForOpponentY += totalRunsOfOpponent[y][i];
        totalOversForY += totalOvers[y][i];
        totalOversForOpponentY += totalOversOfOpponent[y][i];
    }
    netRunRateForX = (totalRunsForX / totalOversForX) - (totalRunsForOpponentX / totalOversForOpponentX);
    netRunRateForY = (totalRunsForY / totalOversForY) - (totalRunsForOpponentY / totalOversForOpponentY);

    netRunRate[x] = netRunRateForX;
    netRunRate[y] = netRunRateForY;

    
}
void ShowNetRunRate() {
    for(int i=0; i< noOfTeams; i++) {
        cout<<"Net Run Rate for "<<teams[i]<<" is: "<<netRunRate[i]<<endl;
    }
    
}

int main()
{
    ShowInitialMassege();
    cin>>noOfTeams;
    cout<<"There will be exactly "<<((noOfTeams * (noOfTeams - 1)) / 2)<<" match in the group if every team played 1 match with others. \nEnter team names in the group: "<<endl;
    TakeInput();
    ShowOptions(-1);
    cin>>temp1;
    while(Invalid(temp1)) {
        cin>>temp1;
    }      
    for(int i=0; i< ((noOfTeams * (noOfTeams - 1)) / 2); i++) {
        cout<<"\t----> Match no. "<<i + 1<<" <----"<<endl;
        if(i > 0) {
            ShowOptions(-1);
            cin>>temp1;
            while(Invalid(temp1)) {
                cin>>temp1;
            }      
        }
        cout<<"Enter Scores of "<<teams[temp1 - 1]<<": "<<endl;
        float rx, ox, ry, oy;
        cin>>rx;
        cout<<"Enter total over played by "<<teams[temp1 - 1]<<": "<<endl;
        cin>>ox;
        cout<<"\t----> Select opponent <----"<<endl;
        ShowOptions(temp1 - 1);
        cin>>temp2;
        while(Invalid(temp2)) {
            cin>>temp2;
        }   
        cout<<"\tEnter Scores of "<<teams[temp2 - 1]<<": "<<endl;
        cin>>ry;
        cout<<"\tEnter total over played by "<<teams[temp2 - 1]<<": "<<endl;
        cin>>oy;
        SaveMatchScores(temp1 - 1, temp2 - 1, rx, ox, ry, oy);
        ShowNetRunRate();
    }
    
	return 0;
}
