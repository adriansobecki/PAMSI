
template<typename T>
void merge(T* data, int l, int m, int r);

template<typename T>
void merge_sort(T* data, int l, int r)
{
    if (r > l)
    {
        int m = (l + r) / 2;
        merge_sort(data, l, m);
        merge_sort(data, m + 1, r);
        merge(data, l, m, r);
    }
}

template<typename T>
void merge(T* data, int l, int m, int r)
{

    T* tab;
    tab = (T*)malloc(sizeof(T) * (r - l + 1));
    int i = l;
    int k = m + 1;
    int z = 0;


    while (i <= m && k <= r)
        {
            if (data[i] < data[k])
            {
                tab[z] = data[i];
                ++i;
            }
            else
            {
                tab[z] = data[k];
                ++k;
            }
            ++z;
        }

    if (i <= m)
    {
        while (i <= m)
        {
            tab[z] = data[i];
            ++i;
            ++z;
        }
    }
    else
    {
        while (k <= r)
        {

            tab[z] = data[k];
            ++k;
            ++z;
        }
    }

    k = l;   
    i = 0;   
    while (k <= r)  
    {  
        data[k] = tab[i];      
        ++k;     
        ++i;   
    }
    free(tab);
}