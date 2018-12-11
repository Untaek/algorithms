#include <iostream>
#include <algorithm>

using namespace std;
void merge(int arr[], int l, int m, int h)
{
  int *temp = new int[h - l];
  fill(temp, temp + h - l, 0);

  int l_index = l;
  int h_index = m + 1;
  int i = 0;

  while (i <= h - l)
  {
    if (l_index <= m && (h_index > h || arr[l_index] <= arr[h_index]))
    {
      temp[i] = arr[l_index];
      l_index++;
    }
    else
    {
      temp[i] = arr[h_index];
      h_index++;
    }
    i++;
  }

  for (int i = l; i < h + 1; i++)
  {
    arr[i] = temp[i - l];
  }

  delete[] temp;
}

void merge_sort(int arr[], int l, int h)
{
  if (l >= h)
  {
    return;
  }

  int mid = (l + h) / 2;

  merge_sort(arr, l, mid);
  merge_sort(arr, mid + 1, h);
  merge(arr, l, mid, h);
}

int main()
{
  int arr[8] = {7, 5, 4, 9, 2, 3, 1, 6};

  cout << "before ";
  for (int i = 0; i < 8; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;

  merge_sort(arr, 0, 7);

  cout << "after ";
  for (int i = 0; i < 8; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;
}