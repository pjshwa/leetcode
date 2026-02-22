-spec binary_gap(N :: integer()) -> integer().
binary_gap(N) ->
  Bits = integer_to_list(N, 2),
  scan(Bits, 0, none, 0).

scan([], _Idx, _LastOneIdx, Best) ->
  Best;
scan([H | T], Idx, LastOneIdx, Best) when H =:= $1 ->
  NewBest =
    case LastOneIdx of
      none -> Best;
      PrevIdx -> max(Best, Idx - PrevIdx)
    end,
  scan(T, Idx + 1, Idx, NewBest);
scan([_H | T], Idx, LastOneIdx, Best) ->
  scan(T, Idx + 1, LastOneIdx, Best).
