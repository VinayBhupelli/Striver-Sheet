#include <bits/stdc++.h>
using namespace std;

// arr1 has extra space in it store the array two elements in it
// way 1:
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v(m + n);
        int i = 0, j = 0;
        int k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                v[k++] = nums1[i++];
            else
                v[k++] = nums2[j++];
        }
        while (i < m)
        {
            v[k++] = nums1[i++];
        }
        while (j < n)
        {
            v[k++] = nums2[j++];
        }
        for (int i = 0; i < v.size(); i++)
        {
            nums1[i] = v[i];
        }
    }
};
// way 2:
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

// if arr1 dont have extra space
void merge(long long arr1[], long long arr2[], int n, int m)
{

    // Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // case 1: left in arr1[]
            // and right in arr2[]:
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1)
            break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}