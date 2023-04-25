//
// Created by legok on 4/21/2023.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <fstream>
#include "quicksort.h"
#include "mergesort.h"
#include "datapoint.h"
using namespace std;

//parseFile function to parse the entirety of the electionDataTest.csv
void parseFile(list<datapoint> &data, string fName)
{
    //create file stream to read the file, and open the requested file name
    ifstream inFile;
    inFile.open(fName, ios::in);
    string line;                            //line to hold each read in line of data
    vector<string> dataPoints;              //vector of strings to hold each line

    //remove the first line from the file, since it contains the label
    getline(inFile, line);

    do
    {
        //get the line in the file
        getline(inFile, line);

        //make sure the line exists as to not push back an empty line
        if(!inFile)
        {
            break;
        }

        //push back the line to the dataPoints vector
        dataPoints.push_back(line);

    }while(inFile.eof());

    //output each line read in to verify lines were read in. this is for debug only.
    for(int i = 0; i < dataPoints.size(); i++)
    {
        cout << dataPoints[i] << endl;
    }

    //parse each line that was previously grabbed
    for(auto itr = dataPoints.begin(); itr != dataPoints.end(); itr++)
    {
        stringstream separate(*itr);    //string stream to handle the inputs
        string temp;                        //string to temporarily hold the component
        vector<string> components;          //holds the separated components of each line
        datapoint tempPoint;

        while(getline(separate, temp, ','))
        {
            components.push_back(temp);           //push the component into the list of components
        }

        //iterate through the components to add them to the data
        auto it = components.begin();

        //set each component of the datapoint, iterating through each time.
        tempPoint.year = stoi(*it++);
        tempPoint.stateFull = *it++;
        tempPoint.state = *it++;
        tempPoint.county = *it++;
        tempPoint.countyNum = stoi(*it++);
        tempPoint.office = *it++;
        tempPoint.candidate = *it++;
        tempPoint.party = *it++;
        tempPoint.numVotes = stoi(*it++);
        tempPoint.totalVotes = stoi(*it++);
        tempPoint.version = stoi(*it++);
        tempPoint.mode = *it;

        //calculate extra components
        tempPoint.voteRate = (double)tempPoint.numVotes / (double)tempPoint.totalVotes;

        //push back the completed datapoint into the list
        data.push_back(tempPoint);
    }
}

//test comment
int main()
{
    //insert new line so that format looks nicer.
    cout << endl;
    //list to hold the entirety of the datapoints, parsed and entered using parseFile()
    list<datapoint> data;

    //load and parse the file into the datapoint list.
    //file must be put in cmake-build-debug folder in order to be recognized for some reason, not sure why.
    parseFile(data, "electionDataTest.csv");



    cout << endl << "successful run" << endl;
    return 0;
}