#include <iostream>
#include <algorithm>
using namespace std;

typedef struct t_max
{
  int low;
  int high;
  int sum;
} Max;

Max create_max(int l, int h, int s)
{
  Max max;
  max.low = l;
  max.high = h;
  max.sum = s;
  return max;
}

Max find_cross_max(int p[], int l, int h)
{
  int sum = 0;
  int left_max = 0;
  int right_max = 0;
  int mid = (l + h) / 2;
  int left = mid;
  int right = mid + 1;

  for (int i = mid; i > 0; i--)
  {
    sum += p[i];
    if (left_max < sum)
    {
      left_max = sum;
      left = i;
    }
  }

  sum = 0;

  for (int i = mid + 1; i < h; i++)
  {
    sum += p[i];
    if (right_max < sum)
    {
      right_max = sum;
      right = i;
    }
  }

  return create_max(left, right, left_max + right_max);
}
Max find_max(int p[], int l, int h)
{
  int current_max = 0;
  int global_max = 0;
  int low = l;
  int high = h;

  for (int i = 0; i < h; i++)
  {
    current_max += p[i];

    if (current_max < 0)
    {
      low = i + 1;
      current_max = 0;
    }
    if (global_max < current_max)
    {
      global_max = current_max;
      high = i;
    }
  }

  return create_max(low, high, global_max);
}

int main()
{
  int p[17] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
  int pm[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

  Max max = find_max(pm, 0, 15);

  cout << max.low << endl;
  cout << max.high << endl;
  cout << max.sum << endl;
}