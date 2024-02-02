void _MergeSort(int* a, int left,int right,int* tmp)
{
    if (left >= right)
    {
        return ;
    }
    int mid = (left + right) >> 1;
    _MergeSort(a, left, mid, tmp);
    _MergeSort(a, mid + 1, right, tmp);
    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int index = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
        {
            tmp[index++] = a[begin1++];
        }
        else
        {
            tmp[index++] = a[begin2++];

        }
    }
    while (begin1 <= end1)
    {
        tmp[index++] = a[begin1++];

    }
    while (begin2 <= end2)
    {
        tmp[index++] = a[begin2++];
    }
    //拷贝回去
    for (int i = left; i <= right; i++)
    {
        a[i] = tmp[i];
    }
}
void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    _MergeSort(a, 0, n - 1, tmp);
    free(tmp);
}