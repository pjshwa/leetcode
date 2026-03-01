-spec min_partitions(N :: unicode:unicode_binary()) -> integer().
min_partitions(N) ->
  max_digit(N, 0).

max_digit(<<>>, Max) ->
  Max;
max_digit(<<Digit, Rest/binary>>, Max) ->
  Value = Digit - $0,
  NewMax = if Value > Max -> Value; true -> Max end,
  max_digit(Rest, NewMax).
