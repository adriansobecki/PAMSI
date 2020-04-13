using namespace std;
#include <math.h>
#include "quick_sort.hh"

template<typename T>
void insertion_sort(T* data, int l, int r);

template<typename T>
void intro_sort(T* data, int l, int r, int how_deep);

template<typename T>
void heap_sort(T* data, int l, int r);

template<typename T>
void repair(T* data, int i);

template<typename T>
void repair2(T* tab, int i, int r);

template<typename T>
void introspective_sort(T* data, int l, int r)
{
	int length = r - l + 1;
	intro_sort(data, l, r, (int) floor(2 * log2(length)));
	insertion_sort(data, l, r);
}

template<typename T>
void intro_sort(T* data, int l, int r, int how_deep)
{

	if (how_deep <= 0)
	{
		heap_sort(data, l, r);
	}
	else
	{
		int m = quick(data, l, (l + r) / 2, r);
		if (m - l > 16)
			intro_sort(data, l, m - 1, how_deep - 1);
		if (r - m > 16)
			intro_sort(data, m + 1, r, how_deep - 1);
	}
}



template<typename T>
void insertion_sort(T* data, int l, int r)
{
	int i, j;
	T element;
	for (i = l+1;i <= r;i++)
	{
		element = data[i];
		j = i - 1;
		while (j >= l && element < data[j])
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = element;
	}
}


template<typename T>
void heap_sort(T* data, int l, int r)
{
	int i;
	T* tab;
	T element;
	tab = (T*)malloc(sizeof(T) * (r - l + 1));
	tab[0] = data[l];
	i = 1;
	while(i+l <= r)
	{
		tab[i] = data[l+i];
		if (tab[i] > tab[((i + 1) / 2) - 1])
			repair(tab, i);
		i++;
	}
	i--;
	while (r >= l)
	{
		data[r] = tab[0];
		element = tab[i];
		tab[i] = tab[0];
		tab[0] = element;
		r--;
		i--;
		repair2(tab, 0, i);
	}
	
	free(tab);
}

template<typename T>
void repair(T* tab, int i)
{
	T element = tab[i];
	tab[i] = tab[((i + 1) / 2) - 1];
	tab[((i + 1) / 2) - 1] = element;
	i = ((i + 1) / 2) - 1;
	if (i>0 && tab[i] > tab[((i + 1) / 2) - 1])
		repair(tab, i);
}

template<typename T>
void repair2(T* tab, int i, int r)
{
	T element;
	if ((i+1)*2 <= r)
	{
		if (tab[((i + 1) * 2)-1] > tab[((i + 1) * 2)])
		{
			element = tab[((i + 1) * 2)-1];
			if (tab[i] < element)
			{
				tab[((i + 1) * 2)-1] = tab[i];
				tab[i] = element;
			}
			repair2(tab, ((i + 1) * 2)-1, r);
		}
		else
		{
			element = tab[((i + 1) * 2)];
			if (tab[i] < element)
			{
				tab[((i + 1) * 2)] = tab[i];
				tab[i] = element;
			}
			repair2(tab, ((i + 1) * 2), r);
		}

	}
	else if (((i + 1) * 2)-1 == r)
	{
		element = tab[((i + 1) * 2) - 1];
		if (tab[i] < element)
		{
			tab[((i + 1) * 2) - 1] = tab[i];
			tab[i] = element;
		}
	}
	
}