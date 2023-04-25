//
// Created by Thomas Prettyman on 4/21/23.
//
#pragma once

#include <vector>

// code for mergeSort and merge adapted from Sorting lecture slides

template <typename T>
void mergeSort(std::vector<T>& vec, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

template <typename T>
void merge(std::vector<T>& vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<T> X(n1);
    std::vector<T> Y(n2);

    for(int i = 0; i < n1; i++)
        X[i] = vec[left + i];
    for(int j = 0; j < n2; j++)
        Y[j] = vec[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(X[i] <= Y[j])
        {
            vec[k] = X[i];
            i++;
        }
        else
        {
            vec[k] = Y[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        vec[k] = X[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        vec[k] = Y[j];
        j++;
        k++;
    }
}