# Логарифмическая сложность

## Функция Логарифмическая
$$x = \log_{b} (a)$$

$$a^b = x$$

### Свойства логарифма

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