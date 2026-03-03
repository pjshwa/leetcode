-spec find_kth_bit(N :: integer(), K :: integer()) -> char().
find_kth_bit(N, K) ->
  case kth_bit(N, K) of
    0 -> $0;
    1 -> $1
  end.

kth_bit(1, _K) ->
  0;
kth_bit(N, K) ->
  Mid = 1 bsl (N - 1),
  if
    K =:= Mid ->
      1;
    K < Mid ->
      kth_bit(N - 1, K);
    true ->
      1 - kth_bit(N - 1, (1 bsl N) - K)
  end.
