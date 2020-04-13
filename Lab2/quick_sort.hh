
#pragma once

template<typename T>
int quick(T* data, int l, int m, int r);

template<typename T>
void change(T* data, int i, int k);

template<typename T>
void quick_sort(T* data, int l, int r)
{
    if (r > l)
    {
        int m = (l + r) / 2;
        m=quick(data, l, m, r);
        quick_sort(data, l, m - 1);
        quick_sort(data, m + 1, r);
    }
}


template<typename T>
int quick(T* data, int l, int m, int r)
{
    int i = l+1;
    int k = r;
    int pivot = data[m];
    change(data, l, m);
    while (1)
    {
        while (data[i] < pivot && i<r)
        {
            i++;
        }
        while (data[k] > pivot)
        {
            k--;
        }
        if (i >= k)
        {
            change(data, l, k);
            return k;
        }
        else
        {
            change(data, i, k);
            k--;
            i++;
        }
    }

}

template<typename T>
void change(T* data, int i, int k)
{
    int q;
    q = data[i];
    data[i] = data[k];
    data[k] = q;
}