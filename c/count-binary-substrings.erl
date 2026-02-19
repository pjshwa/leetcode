-spec count_binary_substrings(S :: unicode:unicode_binary()) -> integer().
count_binary_substrings(S) ->
  Counts = group_counts(S),
  sum_neighbor_mins(Counts).

group_counts(<<>>) ->
  [];
group_counts(<<C, Rest/binary>>) ->
  group_counts(Rest, C, 1, []).

group_counts(<<>>, _Prev, Count, Acc) ->
  lists:reverse([Count | Acc]);
group_counts(<<C, Rest/binary>>, Prev, Count, Acc) when C =:= Prev ->
  group_counts(Rest, Prev, Count + 1, Acc);
group_counts(<<C, Rest/binary>>, _Prev, Count, Acc) ->
  group_counts(Rest, C, 1, [Count | Acc]).

sum_neighbor_mins([]) ->
  0;
sum_neighbor_mins([_]) ->
  0;
sum_neighbor_mins([A, B | Rest]) ->
  erlang:min(A, B) + sum_neighbor_mins([B | Rest]).
