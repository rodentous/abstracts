# Основы
- **Функциональное программирование** — ВСЕ это функция
- **Лямбда** — анонимная функция

### Синтакс
$\lambda\ argument\ .\ body$ \
принимает **только один** аргумент

### Пример
$\lambda x.x$
```python
def lambda(x):
    return x
```


&nbsp;
# Каррирование

### Функция возвращает функцию
$\lambda x.\lambda y.x$

### Вызов
$(\ (\lambda x.\lambda y.x)a\ )b$
- где **a, b, ...** - аргументы **x, y**

### Карри (синтаксический сахар)
$$((\lambda x)y)z \Leftrightarrow \lambda xyz$$


&nbsp;
# Логические операторы (комбинаторы)

$True = \lambda xy.x$
- возвращает первый аргумент
```python
def true(x, y)
    return x
```
---

$False = \lambda xy.y$
- возвращает второй аргумент
```python
def false(x, y)
    return y
```
---

$Not = \lambda b.b \ False \ True$
- где **b** это **True / False**
```python
def not(b):
    return b(false, true)
```
---

$And = \lambda xy.xy(False)$
- где **x, y** это **True / False**
```python
def and(x, y):
    if x:
        return y
    return false
```
```python
def and(x, y):
    return x(y, x)
```

---

$Or = \lambda xy.x(True)y$
- где **x, y** это **True / False**
```python
def and(x, y):
    if x:
        return true
    return y
```


&nbsp;
# Нумералы черча

Каждое натуральное число задается количеством итераций

- $\bar{0} = \lambda fx.x$

- $\bar{1} = \lambda fx.fx$

- $\bar{2} = \lambda fx.f(fx)$

- $\bar{3} = \lambda fx.f(f(fx))$

- $\bar{n} = \lambda fx.f(f(\dots (f(fx))\dots)) = f^n(x)$

### Функции
применяем к нумералу **f** еще раз чтобы получить следующий нумерал
- $Succ = \lambda nfx.\ f(nfx)$
---
применяем **Succ()** **m** раз
- $Add = \lambda mn.m\ Succ(n)$
---
применяем **Add(n)** **m** раз
- $Mlt = \lambda mn.m\ Add(n)\ \bar{0}$ \
или применяем **n m** раз
- $Mlt = \lambda mn.\lambda fx.m(nf)x$


&nbsp;
# Пары

$Pair = \lambda xyb.bxy$
- где **x, y** - аргументы
- **b** - True/False (первый/второй элемент)

### Аксессоры
$First = \lambda p.p(True)$

$Second = \lambda p.p(False)$
- где p - пара (без третьего аргумента)

---
### Пример

$$First(Pair\ \bar{5}\ \bar{7}) \rightarrow \bar{5}$$

### Синтаксический сахар:
$$(x, y) \Leftrightarrow Pair\ x\ y$$


&nbsp;
# Циклы

$(i, S_i)$
- где **i** - индекс
- **S~i~** - значение/состояние

$$(0, S_0) \rightarrow (1, S_1) \rightarrow \dots \rightarrow (n, S_n)$$

**i** от нуля до **n + 1**

---

$For = \lambda n S_0 f.Second(n(\ \lambda p.(Succ(First\ p),\ f(First\ p)(Second\ p))) \ (0, S_0))$

- $For(0, S_0) f=S_0$

- $For(n+1,S_0)f = fn(For(n, S_0) f)$


&nbsp;
# Вычитание

$Pred = \lambda n.For(n, \bar{0})True$
- возвращаем последний индекс цикла от **n** (**n-1**)
- на S~0~ плевать (пусть будет 0)

---

$Sub = \lambda mn.nPred(m)$


&nbsp;
# Рекурсия

$\lambda f.\phi(f) \Rightarrow \phi(\phi(\phi(\phi(\phi(\phi(...))))))$

$f = \phi(f)$

$f$ - неподвижная точка $\phi$

$Y\phi = f = \phi(Y\phi)$

$Y = \lambda\phi.(\lambda f_0.\phi(f_0f_0))(\lambda f_0.\phi(f_0f_0))$

$Y\phi = (\lambda f_0.\phi(f_0f_0))(\lambda f_0.\phi(f_0f_0))$

$\phi(\lambda f_0.\phi(f_0f_0))(\lambda f_0.\phi(f_0f_0))$

$\phi(Y\phi)$

---
**Факториал:** $fact = Y(f.\lambda n.IF(IsZero\ n) \bar{1}(f(n - 1))$


&nbsp;
# Система типов