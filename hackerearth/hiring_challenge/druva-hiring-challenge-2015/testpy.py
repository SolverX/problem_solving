
T = long(raw_input())
while (T != 0):
    T = T - 1
    N = long(raw_input())
    N = N - 1
    tmp,num=N,N
    cnt = 0
    while ( tmp > 0 ):
        if ( (tmp&1)==0 ):
            num = num | (1<<cnt)
        tmp = tmp >> 1
        cnt = cnt + 1
    cnt = cnt -1;
    number = num >> 1
    number = number + 1
    if (num != 0 ):
        N = (N-number+1) << 1;
    else:
        N = 1
    print num,N