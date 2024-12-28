# Логарифмическая сложность

## Логарифмическая Функция
$$x = \log_{b} (a)$$

$$a^b = x$$

### Свойства логарифма

$$\log_{q}(a \cdot b) = \log_{q}(a) + \log_{q}(b)$$


$$\log_{q}(\frac{a}{b}) = \log_{q}(a) − \log_{q}(b)$$

$$\log_{q}(a^n) = n \cdot \log_{q}(a)$$

$$\log_{q}(a) = \frac{\log_{r}(a)}{\log_{r}(q)}$$

$$\log_{10}(a) = \log_{2}(a) \log_{2}(10) = \frac{1}{\log_{2}(10)} \log_{2}(a) \approx 0.4978 \cdot \log_{2}(a)$$

$$\log_{10}(n) = \Theta(\log(n))$$


## Быстрое возведение

сложность $O(\log n)$

```python
def fast_pow(a, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return fast_pow(a * a, n // 2)
    else:
        return a * fast_pow(a, n - 1)
```

## Бинарный поиск

сложность $O(\log(n))$

```python
def bin_search(arr, x):
    '''
    Если x in arr, то max i: arr[i] = x
    Если x not in arr, то max i: arr[i] < x
    Если x < arr, то -1
    '''

    left = -1
    right = len(arr)

    while right > left + 1:
        mid = (left + right) // 2
        # print(left, mid, right, arr[mid])
        if x < arr[mid]:
            right = mid
        else:
            left = mid
    return left


def insert_in_arr(arr, x):
    pos = bin_search(arr, x)
    print(arr[:pos+1], [x], arr[pos+1:])
    return arr[:pos+1] + [x] + arr[pos+1:]


arr = [1,1,3,3,5,5]
insert_in_arr(arr,6)
```

## Поиск по ответу

```python
def min_true(f):
    '''
    Пусть f(x) -- неубывающая функция со значениями {False, True}
    Найдем минимальное n, такое что f(n) == True
    '''
    right = 2
    while not f(right):
        right *=2
    left = 0
    while right > left + 1:
        mid = (left + right) // 2
        if f(mid):
            right = mid
        else:
            left = mid
    return right

```
## Целая часть корня

```python
def f(x, n):
   return x*x > n

n = 8
m = min_true(lambda x: f(x,n))
print(f"{m} -- это минимальное целое число, которого {m}*{m} > {n}")
print(f"Целая часть корня из {n} равна {m-1}")
```

## Диплломы

```python
def f(x, w, h, n):
   return (x//w)*(x//h) >= n

w, h, n = map(int,input().split())
print(min_true(lambda x: f(x,w, h, n)))
```

## Логарифм и полином

$$\log(n)=o(n)$$

$$(log(n))^{1000} = o(n^{0.001})$$

$$n = o(n \cdot \log(n))$$

$$n \cdot \log(n) = o(n^2)$$
```