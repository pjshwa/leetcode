-spec count_prime_set_bits(Left :: integer(), Right :: integer()) -> integer().
count_prime_set_bits(Left, Right) ->
  count_prime_set_bits(Left, Right, 0).

count_prime_set_bits(N, Right, Acc) when N > Right ->
  Acc;
count_prime_set_bits(N, Right, Acc) ->
  Bits = count_set_bits(N),
  NewAcc = case is_prime(Bits) of
    true -> Acc + 1;
    false -> Acc
  end,
  count_prime_set_bits(N + 1, Right, NewAcc).

count_set_bits(0) ->
  0;
count_set_bits(N) ->
  (N band 1) + count_set_bits(N bsr 1).

is_prime(N) when N =< 1 ->
  false;
is_prime(2) ->
  true;
is_prime(N) when N rem 2 =:= 0 ->
  false;
is_prime(N) ->
  is_prime(N, 3).

is_prime(N, D) when D * D > N ->
  true;
is_prime(N, D) ->
  case N rem D of
    0 -> false;
    _ -> is_prime(N, D + 2)
  end.
