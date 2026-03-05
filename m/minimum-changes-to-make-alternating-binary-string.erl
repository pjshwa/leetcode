-spec min_operations(S :: unicode:unicode_binary()) -> integer().
min_operations(S) ->
  min(rec(S, 0), rec(S, 1)).

rec(<<>>, _T) ->
  0;
rec(<<Head, Rest/binary>>, T) ->
  case Head =:= T + $0 of
    true -> rec(Rest, 1 - T);
    false -> rec(Rest, 1 - T) + 1
  end.
