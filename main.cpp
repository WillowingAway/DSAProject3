//
// Created by legok on 4/21/2023.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "quicksort.h"
#include "mergesort.h"
//#include "datapoint.h"
using namespace std;

//parseFile function to parse the entirety of the electionDataTest.csv
void parseFile(vector<datapoint> &data, string fName)
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
            components.push_back(temp);           //push the component into the vector of components
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

        if(*it == "DEMOCRAT")
        {
            tempPoint.party = "DEM";
        }
        else if(*it == "REPUBLICAN")
        {
            tempPoint.party = "REP";
        }
        else
        {
            tempPoint.party = "OTHER";
        }
        it++;
        tempPoint.numVotes = stoi(*it++);
        tempPoint.totalVotes = stoi(*it++);
        tempPoint.version = stoi(*it++);
        tempPoint.mode = *it;

        //calculate extra components
        tempPoint.voteRate = (double)tempPoint.numVotes / (double)tempPoint.totalVotes;

        //push back the completed datapoint into the vector
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

//get average of a type
double getAverage(vector<datapoint> data, string mode)
{
    double sum = 0, average = 0;
    //modes YEAR COUNTYNUM NUMVOTES TOTALVOTES VOTERATE
    if(mode == "YEAR")
    {
        for(int i = 0; i < data.size(); i++)
        {
            sum += data[i].year;
        }

        average = (double) sum / (double) data.size();
    }
    else if(mode == "COUNTYNUM")
    {
        for(int i = 0; i < data.size(); i++)
        {
            sum += data[i].countyNum;
        }

        average = (double) sum / (double) data.size();
    }
    else if(mode == "NUMVOTES")
    {
        for(int i = 0; i < data.size(); i++)
        {
            sum += data[i].numVotes;
        }

        average = (double) sum / (double) data.size();
    }
    else if(mode == "TOTALVOTES")
    {
        for(int i = 0; i < data.size(); i++)
        {
            sum += data[i].totalVotes;
        }

        average = (double) sum / (double) data.size();
    }
    else if(mode == "VOTERATE")
    {
        for(int i = 0; i < data.size(); i++)
        {
            sum += data[i].voteRate;
        }

        average = (double) sum / (double) data.size();
    }

    return average;
}

//search for a value and return the address
int searchValue(vector<datapoint> data, string mode, string value)
{
    int address = 0;
    //modes YEAR STATE COUNTY COUNTYNUM OFFICE CANDIDATE PARTY NUMVOTES TOTALVOTES VOTERATE

    if(mode == "YEAR")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].year == stoi(value))
            {
                address = i;
            }
        }
    }
    else if(mode == "STATE")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].state == value)
            {
                address = i;
            }
        }
    }
    else if(mode == "COUNTY")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].county == value)
            {
                address = i;
            }
        }
    }
    else if(mode == "COUNTYNUM")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].countyNum == stoi(value))
            {
                address = i;
            }
        }
    }
    else if(mode == "OFFICE")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].office == value)
            {
                address = i;
            }
        }
    }
    else if(mode == "CANDIDATE")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].candidate == value)
            {
                address = i;
            }
        }
    }
    else if(mode == "PARTY")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].party == value)
            {
                address = i;
            }
        }
    }
    else if(mode == "NUMVOTES")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].numVotes == stoi(value))
            {
                address = i;
            }
        }
    }
    else if(mode == "TOTALVOTES")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].totalVotes == stoi(value))
            {
                address = i;
            }
        }
    }
    else if(mode == "VOTERATE")
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].voteRate == stoi(value))
            {
                address = i;
            }
        }
    }

    return address;
}

//todo
//return a vector of counties with very close DEM & REP voting percentages within 10%?
void findCloseCounties(vector<datapoint> data, vector<datapoint> &result)
{

}

//todo
//return a vector of counties with very extreme DEM & REP voting percentages over 60%?
void findExtremeCounties(vector<datapoint> data, vector<datapoint> &result)
{

}

//test comment
int main()
{
    //insert new line so that format looks nicer.
    cout << endl;
    //vector to hold the entirety of the datapoints, parsed and entered using parseFile()
    vector<datapoint> data;

    //load and parse the file into the datapoint vector.
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
            //mergeSort(data, mode);
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
            cout << "COUNTYNUM" << endl;
            cout << "NUMVOTES" << endl;
            cout << "TOTALVOTES" << endl;
            cout << "VOTERATE" << endl;
            cin >> mode;

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

            item2 = searchValue(data, mode, value);

            //todo
            displayText();
        }
        else if(function == 6)
        {
            cout << "Displaying close DEP & REP counties..." << endl;
            vector<datapoint> result;

            findCloseCounties(data, result);

            //todo
            displayGraph();
        }
        else if(function == 7)
        {
            cout << "Displaying extreme counties..." << endl;
            vector<datapoint> result;

            findExtremeCounties(data, result);

            //todo
            displayGraph();
        }
        else
        {
            cout << "Exiting program..." << endl;
            break;
        }
    }

    cout << endl << "successful run" << endl;
    return 0;
}