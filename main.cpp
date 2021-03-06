#include <iostream>
#include <algorithm>
using namespace std;

typedef struct heap
{
  int size;
  int *data;
} Heap;

void init_heap(Heap &heap, int size)
{
  heap.size = 0;
  heap.data = new int[size + 1];
}

void clear_heap(Heap &heap)
{
  delete[] heap.data;
}

void put_heap_item(Heap &heap, int item)
{
  heap.data[heap.size + 1] = item;
  for (int i = heap.size + 1; i > 1; i /= 2)
  {
    if (heap.data[i / 2] < item)
    {
      heap.data[i] = heap.data[i / 2];
    }
    else
    {
      heap.data[i / 2] = item;
      break;
    }
  }
}

void build_max_heap(Heap &heap, int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    put_heap_item(heap, arr[i]);
  }
}

void heap_sort(int arr[], int size)
{
  Heap heap;
  init_heap(heap, size);
  build_max_heap(heap, arr, size);

  for (int i = size; i > 0; i++)
  {
    arr[i] = heap.data[i];
  }

  clear_heap(heap);
}
