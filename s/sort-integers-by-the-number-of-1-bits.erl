-spec sort_by_bits(Arr :: [integer()]) -> [integer()].
sort_by_bits(Arr) ->
  lists:sort(
    fun(A, B) ->
      CountA = count_ones(A),
      CountB = count_ones(B),
      (CountA < CountB) orelse (CountA =:= CountB andalso A =< B)
    end,
    Arr
  ).

count_ones(0) ->
  0;
count_ones(N) ->
  (N band 1) + count_ones(N bsr 1).
