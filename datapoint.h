//
// Created by legok on 4/25/2023.
//

#ifndef DSAPROJECT3_DATAPOINT_H
#define DSAPROJECT3_DATAPOINT_H

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

#endif //DSAPROJECT3_DATAPOINT_H

struct datapoint
{
    //datapoint structure to hold the information from a line in the election data file
    int year;               //year of election
    string stateFull;       //full name of the state
    string state;           //abbreviation of the state  <- USE THIS FOR SORTING NAME
    string county;          //county name
    int countyNum;          //county number?? not sure "county_fips"
    string office;          //office the candidate is running for
    string candidate;       //name of the candidate
    string party;           //party name, will be parsed into DEM, REP, and OTHER for ease of use
    int numVotes;           //number of votes the candidate recieved from the county
    int totalVotes;         //total number of votes in the entire county
    int version;            //version
    string mode;            //mode

    //extra details that would be useful to calculate
    double voteRate;        //this will be calucated by voteRate = (double)numVotes / (double)totalVotes;

    void display()
    {
        cout << "year: " << year << " state: " << state << " county: " << county << " countyNum: " << countyNum << " office: " << office << endl
        << "candidate: " << candidate << " party: " << party << " numVotes: " << numVotes << " totalVotes: " << totalVotes << " voteRate: " << setprecision(5) << voteRate << endl;
    }
};