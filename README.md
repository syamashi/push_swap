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
