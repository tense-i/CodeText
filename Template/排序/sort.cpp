#include <bits/stdc++.h>
using namespace std;
const int N(1e3);
// 归并排序
int arr[N], temp[N];
void mergesort(int *q, int l, int r)
{
  if (l >= r)
    return;
  int mid = (l + r) >> 1;
  mergesort(q, l, mid), mergesort(q, mid + 1, r);
  int i = l, j = mid + 1;
  int k = 0;
  while (i <= mid && j <= r)
  {
    if (q[i] <= q[j])
      temp[k++] = q[i++];
    else
      temp[k++] = q[j++];
  }
  while (i <= mid)
    temp[k++] = q[i++];
  while (j <= r)
    temp[k++] = q[j++];
  for (int i = l, j = 0; i <= r; i++)
    q[i] = temp[j++];
}

// 插入排序
void insertsort(int a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int t = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] < t)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = t;
  }
}

// 希尔排序
void shell_sort(int a[], int n)
{
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int t = arr[i];
      int j = i - gap;
      while (j >= 0 && arr[j] > t)
      {
        arr[j + gap] = arr[j];
        j -= gap;
      }
      arr[j + gap] = t;
    }
  }
}
// 堆排序
void heapify(int arr[], int n, int i)
{
  int largest = i;   // 初始化最大元素为当前节点
  int l = 2 * i + 1; // 左子节点的索引
  int r = 2 * i + 2; // 右子节点的索引
  // 如果左子节点比最大元素大，则更新最大元素
  if (l < n && arr[l] > arr[largest])
  {
    largest = l;
  }
  // 如果右子节点比最大元素大，则更新最大元素
  if (r < n && arr[r] > arr[largest])
  {
    largest = r;
  }
  // 如果最大元素不是当前节点，则交换它们，并递归地调整堆
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  // 建立最大堆（从最后一个非叶节点开始）
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }

  // 依次取出堆顶元素，交换到数组末尾，并逐渐缩小堆的大小
  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int a[] = {1, 0, -2, 1, 2, 11, 2, 3, 55, 4};
  // insertsort(a,10);
  shell_sort(a, 10);
  for (int i = 0; i < 10; i++)
  {
    cout << a[i] << ' ';
  }
  return 0;
}