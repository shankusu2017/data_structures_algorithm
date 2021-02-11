#include "quick_sort.h"

/*
 * 自己写的快速排序算法
 */


//三要素 基准线， 逻辑，渐变
void quick_sort(int *start, int *tail, unsigned depth)
{
    addCallDepth(depth);
    addCalTimes();

    //part1:基准线
    if (start >= tail) {
        return;
    }

    //step2:逻辑和渐变

    //选择参考值
    int tmp = *start;
    int *i  = start;
    int *j  = tail;
    while(i < j) {
        //循环1
        for(; i < j; --j) {  //找到小于basic的数
            addCPUTimes();
            if (*j < tmp) {
                *i = *j;
                break;
            }
        }
        /* 循环1结束时：j分为两种情况
         * s1:找到了一个value<tmp的slot填入到了i指向的slot
         * s2:j和i重合了
         * 无论哪种情况[j+1, left] 区间的value都 >= tmp
         */


        //循环2
        for(; i < j; ++i) {
            addCPUTimes();
            if (*i > tmp) {
                *j = *i;
                break;
            }
        }
        /* 循环2结束时：i分为两种情况
         * s1:找到了一个value>tmp的slot填入到了j指向的slot
         * s2:i和j重合了
         * 无论哪种情况[left, i-1] 区间的value都 <= tmp
         */


        //此时，i指针指向的slot空闲，且[left,i-1]区域的值<=tmp
        //j指针指向的slot的值>tmp,且[j+1,right]预取的值>=tmp
        //返回循环入口时ij至少靠近了一步
    }
    addCPUTimes();
    *j = tmp;   //*i=tmp也一样

    // 渐变部分
    quick_sort(start, i - 1, depth + 1);
    quick_sort(j + 1, tail, depth + 1);
}

