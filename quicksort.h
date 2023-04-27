//
// Created by legok on 4/21/2023.
//

#ifndef DSAPROJECT3_QUICKSORT_H
#define DSAPROJECT3_QUICKSORT_H

#include "datapoint.h"
#include <string>
#include <vector>
using namespace std;

#endif //DSAPROJECT3_QUICKSORT_H

int qsPartition(vector<datapoint> &vec, int start, int end, string mode)
{
    datapoint pivotPoint = vec[start];
    int count = 0;

    //find the right point for the pivot
    for(int i = start + 1; i <= end; i++)
    {
        if(mode == "YEAR")
        {
            if(vec[i].state <= pivotPoint.state)
            {
                count++;
            }
        }
        else if(mode == "STATE")
        {
            if(vec[i].state.substr(0, 3) <= pivotPoint.state.substr(0, 3))
            {
                count++;
            }
        }
        else if(mode == "COUNTY")
        {
            if(vec[i].county.substr(0, 3) <= pivotPoint.county.substr(0, 3))
            {
                count++;
            }
        }
        else if(mode == "COUNTYNUM")
        {
            if(vec[i].countyNum <= pivotPoint.countyNum)
            {
                count++;
            }
        }
        else if(mode == "OFFICE")
        {
            if(vec[i].office.substr(0, 3) <= pivotPoint.office.substr(0, 3))
            {
                count++;
            }
        }
        else if(mode == "CANDIDATE")
        {
            if(vec[i].candidate.substr(0, 3) <= pivotPoint.candidate.substr(0, 3))
            {
                count++;
            }
        }
        else if(mode == "PARTY")
        {
            if(vec[i].party.substr(0, 3) <= pivotPoint.party.substr(0, 3))
            {
                count++;
            }
        }
        else if(mode == "NUMVOTES")
        {
            if(vec[i].numVotes <= pivotPoint.numVotes)
            {
                count++;
            }
        }
        else if(mode == "TOTALVOTES")
        {
            if(vec[i].totalVotes <= pivotPoint.totalVotes)
            {
                count++;
            }
        }
        else if(mode == "VOTERATE")
        {
            if(vec[i].voteRate <= pivotPoint.voteRate)
            {
                count++;
            }
        }
    }

    //swap the pivot with where it should be
    int pivotID = 0;
    pivotID = start + count;
    //cout << pivotID << endl;
    swap(vec[pivotID], vec[start]);
    int st = start;
    int ed = end;
    //move start and end closer together

    while(st < pivotID && ed > pivotID)
    {
        //adjust st
        if(mode == "YEAR")
        {
            while(vec[st].state <= pivotPoint.state)
            {
                st++;
            }
        }
        else if(mode == "STATE")
        {
            while(vec[st].state.substr(0, 3) <= pivotPoint.state.substr(0, 3))
            {
                st++;
            }
        }
        else if(mode == "COUNTY")
        {
            while(vec[st].county.substr(0, 3) <= pivotPoint.county.substr(0, 3))
            {
                st++;
            }
        }
        else if(mode == "COUNTYNUM")
        {
            while(vec[st].countyNum <= pivotPoint.countyNum)
            {
                st++;
            }
        }
        else if(mode == "OFFICE")
        {
            while(vec[st].office.substr(0, 3) <= pivotPoint.office.substr(0, 3))
            {
                st++;
            }
        }
        else if(mode == "CANDIDATE")
        {
            while(vec[st].candidate.substr(0, 3) <= pivotPoint.candidate.substr(0, 3))
            {
                st++;
            }
        }
        else if(mode == "PARTY")
        {
            while(vec[st].party.substr(0, 3) <= pivotPoint.party.substr(0, 3))
            {
                st++;
            }
        }
        else if(mode == "NUMVOTES")
        {
            while(vec[st].numVotes <= pivotPoint.numVotes)
            {
                st++;
            }
        }
        else if(mode == "TOTALVOTES")
        {
            while(vec[st].totalVotes <= pivotPoint.totalVotes)
            {
                st++;
            }
        }
        else if(mode == "VOTERATE")
        {
            while(vec[st].voteRate <= pivotPoint.voteRate)
            {
                st++;
            }
        }

        //adjust ed
        if(mode == "YEAR")
        {
            while(vec[ed].state > pivotPoint.state)
            {
                ed--;
            }
        }
        else if(mode == "STATE")
        {
            while(vec[ed].state.substr(0, 3) > pivotPoint.state.substr(0, 3))
            {
                ed--;
            }
        }
        else if(mode == "COUNTY")
        {
            while(vec[ed].county.substr(0, 3) > pivotPoint.county.substr(0, 3))
            {
                ed--;
            }
        }
        else if(mode == "COUNTYNUM")
        {
            while(vec[ed].countyNum > pivotPoint.countyNum)
            {
                ed--;
            }
        }
        else if(mode == "OFFICE")
        {
            while(vec[ed].office.substr(0, 3) > pivotPoint.office.substr(0, 3))
            {
                ed--;
            }
        }
        else if(mode == "CANDIDATE")
        {
            while(vec[ed].candidate.substr(0, 3) > pivotPoint.candidate.substr(0, 3))
            {
                ed--;
            }
        }
        else if(mode == "PARTY")
        {
            while(vec[ed].party.substr(0, 3) > pivotPoint.party.substr(0, 3))
            {
                ed--;
            }
        }
        else if(mode == "NUMVOTES")
        {
            while(vec[ed].numVotes > pivotPoint.numVotes)
            {
                ed--;
            }
        }
        else if(mode == "TOTALVOTES")
        {
            while(vec[ed].totalVotes > pivotPoint.totalVotes)
            {
                ed--;
            }
        }
        else if(mode == "VOTERATE")
        {
            while(vec[ed].voteRate > pivotPoint.voteRate)
            {
                ed--;
            }
        }

        if((st < pivotID) && (ed > pivotID))
        {
            //cout << pivotID << endl;
            //cout << "swapping " << st << " and " << ed << endl;
            swap(vec[st++], vec[ed--]);
        }

    }

    return pivotID;
}

void quickSort(vector<datapoint> &data, int start, int end, string mode)
{
    //base case handling
    if(start >= end)
    {
        return;
    }
    else
    {
        //sort the pivot, and both sides of the pivot point
        int partition = 1;
        partition = qsPartition(data, start, end, mode);
        quickSort(data, start, partition - 1, mode);
        quickSort(data, partition + 1, end, mode);
    }
}