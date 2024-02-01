
int GetMiddle(int* a, int left,int right)
{
    int mid = (left + right) >> 1;
    if (a[left] < a[mid])
    {
        if (a[mid] < a[right])
        {
            return mid;
        }
        else if (a[left] > a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (a[mid] > a[right])
        {
            return  mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}
void QuickSort(int* a, int left,int right)
{
    if (left >= right)
    {
        return;
    }
    int index = GetMiddle(a, left, right);
    Swap(&a[left], &a[index]);
    int begin = left, end = right;
    int pivot = begin;
    int key = a[begin];

    while (begin < end)
    {
        while (begin<end&&a[end] >= key) {
            end--;
        }
        a[pivot] = a[end];
        pivot = end;
        while (begin<end&&a[begin] <= key)
        {
            begin++;
        }
        a[pivot] = a[begin];
        pivot = begin;
    }

    pivot = begin;
    a[pivot] = key;
    QuickSort(a, left, pivot - 1);
    QuickSort(a, pivot+1, right);
}