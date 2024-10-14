#include <iostream>
#include <vector>
using namespace std;
// Intersection of two sorted arrays
int intersection(vector<int> a, vector<int> b)
{
    if (a.size() == 0 || b.size() == 0)
    {
        return 0;
    }
    vector<int> answer = {};
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {

        if (a[i] == b[j])
        {
            if (answer.size() == 0 || answer.back() != a[i])
            {
                answer.push_back(a[i]);
            }
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++; // if b is bigger than a , a should be incremented
        }
        else
        {
            j++;
        }
    }
    for (int i : answer)
    {
        cout << i << "  ";
    }
    return 0;
}
// union of two sorted arrays
int Union(vector<int> a, vector<int> b)
{
    int i = 0;
    int j = 0;
    vector<int> ans = {};
    while (i < a.size() && j < b.size())

    {

        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        if (a[i] < b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
                i++;
            }
        }
        else if (a[i] > b[j])
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
                j++;
            }
        }
    }
    while (i < a.size())
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }
    while (j < b.size())
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

