//
// Created by edy on 2023/2/28.
//

#include "数组.h"
#include <iostream>

using namespace std;

//https://www.bilibili.com/video/BV1et411b73Z?p=46&vd_source=58578d9079a40172707d03802e994791
/**
 * 找数组中最大值
 */
string findMax();

/**
 * 数组逆序
 */
void reverse();

int main() {
//    cout << "最重的是: " + findMax() << endl;
    reverse();
    return 0;
}

/*
 * 数组特点：
 * >放在一块连续的内存空间
 * >数组汇总每个元素都是相同的数据类型
 *
 * 一维数组案例：五只小猪称体重
 * 在一个数组中记录五只小猪的体重，如int arr[5] = {300,350,200,400,240};
 * 找出并打印最重的小猪的体重，
 */

string findMax() {
    int arr[5] = {300, 550, 200, 400, 240};
    int max = 0;
//    for (const auto &item : arr){
//        if (item>max)
//            max=item;
//    }
    for (int i = 0; i < 5; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return to_string(max);
}

void reverse() {
    int arr[] = {1, 3, 2, 5, 4};
    for (int i: arr) {
        cout << i << "、";
    }
    cout << endl;
    int start = 0, end = sizeof(arr) / sizeof(arr[0]) - 1;
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for (int i: arr) {
        cout << i << "、";
    }
}