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

//todo
//display the graph
void displayGraph()
{

}

//todo
//display text
void displayText()
{

}

//todo
//get average of a type
double getAverage(list<datapoint> data, string mode)
{
    return 0;
}

//todo
//search for a value and return the address
int searchValue(list<datapoint> data, string mode, string value)
{
    return 0;
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

    //  main program running, function decides which function of the program should be run.
    //  0 - Display Graph
    //  1 - Sort using Merge Sort
    //  2 - Sort using Quick Sort
    //  3 - Display the average for an attribute
    //  4 - Find a specific data point and display its attributes
    //  5 - Compare two specific data points
    //  6 - Display counties that have DEM & REP percentages of nearly equal value
    //  7 - Display counties that are mostly DEM or REP percentage only
    int function = 0;
    string mode = "";
    string value = "";
    //the search parameters. valid options are all-caps only.
    //YEAR STATE COUNTY COUNTYNUM OFFICE CANDIDATE PARTY NUMVOTES TOTALVOTES VOTERATE

    while(function >= 0 && function <= 7)
    {
        //todo
        //replace this with a button click when the UI is completed
        //get the chosen function.
        cout << " Which function should be run?" << endl;
        cout << " 0 - Display Graph" << endl;
        cout << " 1 - Sort using Merge Sort" << endl;
        cout << " 2 - Sort using Quick Sort" << endl;
        cout << " 3 - Display the average for an attribute" << endl;
        cout << " 4 - Find a specific data point and display its attributes" << endl;
        cout << " 5 - Compare two specific data points" << endl;
        cout << " 6 - Display counties that have DEM & REP percentages of nearly equal value" << endl;
        cout << " 7 - Display counties that are mostly DEM or REP percentage only" << endl;
        cout << "-1 - Exit the program" << endl;
        cin >> function;

        if(function == 0)
        {
            cout << "Displaying graph." << endl;
            //todo
            displayGraph();
        }
        else if(function == 1)
        {
            cout << "Merge sorting..." << endl;
            cout << "Sort by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            //todo
            mergeSort(data, mode);
            //todo
            displayGraph();
        }
        else if(function == 2)
        {
            cout << "Quick sorting..." << endl;
            cout << "Sort by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            //todo
            quickSort(data, mode);
            //todo
            displayGraph();
        }
        else if(function == 3)
        {
            cout << "Tallying average..." << endl;
            cout << "Search by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            //todo
            getAverage(data, mode);
            //todo
            displayText();
        }
        else if(function == 4)
        {
            cout << "Finding data point..." << endl;
            cout << "Search by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            cout << "What value?" << endl;
            cin >> value;

            //todo
            searchValue(data, mode, value);
            //todo
            displayText();
        }
        else if(function == 5)
        {
            int item1 = 0, item2 = 0;

            cout << "Finding data points..." << endl;
            cout << "Search by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            cout << "What value?" << endl;
            cin >> value;

            //todo
            item1 = searchValue(data, mode, value);

            cout << "Search by?" << endl;
            cout << "YEAR" << endl;
            cout << "STATE" << endl;
            cout << "COUNTY" << endl;
            cout << "COUNTYNUM" << endl;
            cout << "OFFICE" << endl;
            cout << "CANDIDATE" << endl;
            cout << "PARTY" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

            cout << "What value?" << endl;
            cin >> value;

            //todo
            item2 = searchValue(data, mode, value);

            //todo
            displayText();
        }
        else if(function == 6)
        {

        }
        else if(function == 7)
        {

        }
        else if(function == -1)
        {
            break;
        }



    }

    cout << endl << "successful run" << endl;
    return 0;
}