#include "quick_sort.h"

/*
 * 其它人的算法
 */

//快速排序算法(从小到大)
//arr:需要排序的数组，begin:需要排序的区间左边界，end:需要排序的区间的右边界
void quick_sort20(int *arr,int begin,int end, unsigned depth)
{
    addCallDepth(depth);
    addCalTimes();

    if (begin >= end)
        return;

    //如果区间不只一个数
    int temp = arr[begin]; //将区间的第一个数作为基准数
    int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
    int j = end; //从右到左进行查找时的“指针”，指示当前右位置
    //不重复遍历
    while(i < j)
    {
        //当右边的数大于基准数时，略过，继续向左查找
        //不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
        while(i<j && arr[j] > temp) {
            addCPUTimes();
            j--;
        }
        //将右边小于等于基准元素的数填入右边相应位置
        arr[i] = arr[j];


        //当左边的数小于等于基准数时，略过，继续向右查找
        //(重复的基准元素集合到左区间)
        //不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
        while(i<j && arr[i] <= temp) {
            addCPUTimes();
            i++;
        }
        //将左边大于基准元素的数填入左边相应位置
        arr[j] = arr[i];
    }
    //将基准元素填入相应位置
    arr[i] = temp;
    addCPUTimes();

    //此时的i即为基准元素的位置
    //对基准元素的左边子区间进行相似的快速排序
    quick_sort20(arr,begin,i-1, ++depth);
    //对基准元素的右边子区间进行相似的快速排序
    quick_sort20(arr,i+1,end, ++depth);
}

void quick_sort21(int *a, int left, int right, unsigned depth)
{
    addCallDepth(depth);
    addCalTimes();

    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }

    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
            /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            addCPUTimes();
            j--;/*向前寻找*/
        }

        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/

        while(i < j && key >= a[i])
            /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            addCPUTimes();
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    quick_sort21(a, left, i - 1, depth + 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    quick_sort21(a, i + 1, right, depth + 1);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}

