# How fast?
ARG_5  : MAX=8, AVG=5

ARG_100: MAX=689, AVG=636

ARG_500: MAX=4920, AVG=4778

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
