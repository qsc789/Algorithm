void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int min = begin, max = begin;
        for (int i = begin; i <= end; i++)
        {
            if (a[i] < a[min])
            {
                min = i;
            }
            if (a[i] > a[max])
            {
                max = i;
            }
        }
        Swap(&a[begin], &a[min]);
        if (max == begin)
        {
            max = min;
        }
        Swap(&a[max], &a[end]);

        begin++;
        end--;
    }

}