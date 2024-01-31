void ShellSort(int* a,int n)
{
    int gap=n;
    while (gap > 1)
    {
        gap = gap / 2;
        for (int i = 0; i < n - gap; i++)
        {

            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (a[end] > tmp)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}