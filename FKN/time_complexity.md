# Временная сложность алгоритмов

**Асимптотика** - оценка поведения функции

Качество работы алгоритма:
- временная сложность;
- память;


## О-нотация, символы Ландау
- О-большое: $f(n) = O(g(n))\Leftrightarrow \exists C > 0, n_0 \  : \  \forall n > n_0 \ \ \  f(n) \leq Cg(n)$
- о-малое: $f(n) = o(g(n)) \Leftrightarrow \exists \epsilon > 0, n_0: \forall n > n_0 \frac{f(n)}{g(n)} < \epsilon$
- $\Theta$-большое: $f(n) = \Theta(g(n)) \Leftrightarrow \begin{cases}f(n) = O(g(n)) \\ g(n) = O(f(n))\end{cases}$


## Доказательство утверждений

- $10 \leq C\times1 \Rightarrow 10 = O(1)$

- $10 \leq 10 \times n^{12}, n_0 = 1 \Rightarrow 10 = O(n^{12})$

- $n^2 + n + 1 = o(n^3)$:
   
$$\frac{n^2 + n + 1}{n^3} < \epsilon$$
$$\epsilon n^3 -n^2 - n - 1 > 0, \epsilon = 4$$


- $n + 10 = \Theta(n)$

$$
\begin{cases}

n + 10 = O(n)\\

n = O(10 + n)

\end{cases}
$$
   
$$n + 10 \leq 11n$$