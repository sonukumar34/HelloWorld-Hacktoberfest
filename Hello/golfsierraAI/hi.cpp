#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binary(int l, int e, int *a, int k)
{
    while (l <= e)
    {
        int m = l + (e - l) / 2;
        if (a[m] == k)
            return m;
        if (a[m] > k)
            return binary(l, m - 1, a, k);
        if (a[m] < k)
            return binary(m + 1, e, a, k);
    }
    return -1;
}
int linearsearch(int *a, int n, int k)
{
    int ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    srand(time(0));
    double rtimebinary, rtimelinear;
    clock_t startbinary, endbinary, startlinear, endlinear, timelinear, timebinary;
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int a[n];
    for (int i = 0; i <= n; i++)
    {
        a[i] = rand() % n;
    }
    startbinary = clock();
    binary(0, n, a, k);
    endbinary = clock();
    startlinear = clock();
    linearsearch(a, n, k);
    endlinear = clock();
    timebinary = abs(startbinary - endbinary);
    timelinear = abs(startlinear - endlinear);
    rtimebinary = ((double)timebinary) / CLOCKS_PER_SEC;
    rtimelinear = ((double)timelinear) / CLOCKS_PER_SEC;
    printf("Time taken Binary: %f Sec\n", rtimebinary);
    printf("Time taken Linear : %f Sec\n", rtimelinear);
    return 0;
}