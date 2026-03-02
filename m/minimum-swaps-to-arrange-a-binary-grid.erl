-spec min_swaps(Grid :: [[integer()]]) -> integer().
min_swaps(Grid) ->
  N = length(Grid),
  TrailingZeros = [count_trailing_zeros(Row) || Row <- Grid],
  min_swaps(0, N, TrailingZeros, 0).

min_swaps(N, N, _TrailingZeros, Ans) ->
  Ans;
min_swaps(TargetRow, N, TrailingZeros, Ans) ->
  Need = N - 1 - TargetRow,
  {Prefix, Rest} = lists:split(TargetRow, TrailingZeros),
  case find_first_valid(Rest, Need, 0) of
    not_found ->
      -1;
    {ok, RelIdx} ->
      {Before, [Chosen | After]} = lists:split(RelIdx, Rest),
      UpdatedTrailingZeros = Prefix ++ [Chosen | Before ++ After],
      min_swaps(TargetRow + 1, N, UpdatedTrailingZeros, Ans + RelIdx)
  end.

find_first_valid([], _Need, _Idx) ->
  not_found;
find_first_valid([H | _T], Need, Idx) when H >= Need ->
  {ok, Idx};
find_first_valid([_H | T], Need, Idx) ->
  find_first_valid(T, Need, Idx + 1).

count_trailing_zeros(Row) ->
  count_trailing_zeros_from_right(lists:reverse(Row), 0).

count_trailing_zeros_from_right([0 | T], Acc) ->
  count_trailing_zeros_from_right(T, Acc + 1);
count_trailing_zeros_from_right([_H | _T], Acc) ->
  Acc;
count_trailing_zeros_from_right([], Acc) ->
  Acc.
