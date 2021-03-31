![キャプチャ](https://user-images.githubusercontent.com/60595852/113107518-ff131380-923e-11eb-8293-961afa00865c.JPG)

# How fast?
ARG_5  : MAX=8, AVG=5

ARG_100: MAX=680, AVG=626

ARG_500: MAX=4878, AVG=4732
(2000 trials)

# How sort?
less7: all_sort

over6: quick_sort and a little optimisation.

# usage

1. only guacamole + bash works.

2. -vc option visualizes

```./push_swap -vc 100 10 0```

```./checker -vc 100 10 0```

```ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker -vc $ARG```

# Main point?
```
void	sort_over6(t_dlst *a, t_dlst *b, t_ps *ps)
{
	long	size;

	half_set(a, b, ps);
	while (ps->awant != ps->size)
	{
		b_settle_top(a, b, ps);
		while ((size = dlst_size(b)) > SORTSIZE)
			b_quick_sort(a, b, ps, size);
		if (size)
			allsort(a, b, ps, size);
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
			allsort(a, b, ps, size);
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}
```
When 100args,
```
1. halfset, A[50~99], B[0~49]
2. b_quick_sort, A[25~49 + 50~99], B[0~24]
3. b_quick_sort, A[12~24 + 25~49 + 50~99], B[0~11]
4. b_quick_sort, A[6~11 + 12~24 + 25~49 + 50~99], B[0~5]
5. b_quick_sort, A[4~5 + 6~11 + 12~24 + 25~49 + 50~99], B[0~3]
6. allsort, A[0123 + 4~5 + 6~11 + 12~24 + 25~49 + 50~99], B[-]
7. allsort, A[0123 + 45 + 6~11 + 12~24 + 25~49 + 50~99], B[-]
8. a_quick_sort, A[0123 + 45 + 12~24 + 25~49 + 50~99], B[6~11]
9. a_quick_sort, A[0123 + 45 + 9~11 + 12~24 + 25~49 + 50~99], B[6~8]
10. a_quick_sort, A[0123 + 45 + 678 + 91011 + 12~24 + 25~49 + 50~99], B[-]
... 
11. a_quick_sort, A[0...49 + 50~99], B[-]
12. b_quick_sort, A[0...49], B[50~99]
13. b_quick_sort, A[76~99 + 0...49], B[50~75]
...
```
