# Insertion sort

```python
def insertion_sort(a):
    n = len(a)
    for i in range(1, n):
        j = i
        while j > 0 and a[j] < a[j - 1]:
            a[j - 1], a[j] = a[j], a[j - 1]
            j -= 1

a = [5, 1, 3, 2, 1, 4]
insertion_sort(a)
print(a)
```
$O(n^2)$

# Divide and conquer

Разделение задач на подзадачи

# Слияние отсортированных массивов

```python
def merge(a, b):
    n = len(a)
    m = len(b)
    i, j = 0, 0
    result = []
    while i < n and j < m:
        if a[i] < b[j]:
            result.append(a[i])
            i += 1
        else:
            result.append(b[j])
            j += 1
    result += a[i:]
    result += b[j:]
    return result

a = [2, 5, 7, 33, 456, 6554]
b = [-4, 5, 33, 45]
print(merge(a, b))
```

$O(n + m)$

# Merge sort

```python
def merge_sort(arr):
    n = len(arr)
    if n == 1:
        return arr
    left = merge_sort(arr[:n//2])
    right = merge_sort(arr[n//2:])
    return merge(left, right)


n = 10
arr = list(range(n))
random.shuffle(arr)
arr = merge_sort(arr)
print(arr)
```
$O(n\log n)$

# Quick sort

```python
import random


def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[random.randint(0, len(arr)-1)] 
    
    left = quick_sort([x for x in arr if x < pivot])
    center = [x for x in arr if x == pivot]
    right = quick_sort([x for x in arr if x > pivot])
    
    return left + center + right 
    
data = [1,2,1,2,1,3,4,5,6]
print(data)
print(quick_sort(data))
```

# Theorem

Не существует алгоритма который сортирует массив используя только сравнение двух элементов быстрее чем $\Theta(\log n)$

### Доказательство

Пусть есть массив $A = \{a_1, a_2, \dots a_n\}$. Всего перестановок массива $n!$

Ну а дальше очев 

минимальная высота бинарного дерева с $n$ листьями - $\log n$

$\log n! = \Theta(n \cdot \log n)$
