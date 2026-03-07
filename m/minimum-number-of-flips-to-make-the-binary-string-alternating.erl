-spec min_flips(S :: unicode:unicode_binary()) -> integer().
min_flips(S) ->
  Bits = binary_to_list(S),
  N = byte_size(S),
  Sum = initial_sum(Bits, 0, 0),
  Ans = erlang:min(Sum, N - Sum),
  case N band 1 of
    0 ->
      Ans;
    1 ->
      rotate(Bits, 0, N, Sum, Ans)
  end.

initial_sum([], _Idx, Acc) ->
  Acc;
initial_sum([Ch | Rest], Idx, Acc) ->
  Bit = Ch - $0,
  Mismatch = Bit bxor (Idx band 1),
  initial_sum(Rest, Idx + 1, Acc + Mismatch).

rotate([], _Idx, _N, _Sum, Ans) ->
  Ans;
rotate([Ch | Rest], Idx, N, Sum, Ans) ->
  Bit = Ch - $0,
  Removed = Bit bxor (Idx band 1),
  Added = Bit bxor ((Idx + 1) band 1),
  NewSum = Sum - Removed + Added,
  NewAns = erlang:min(Ans, erlang:min(NewSum, N - NewSum)),
  rotate(Rest, Idx + 1, N, NewSum, NewAns).
