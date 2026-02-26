-spec num_steps(S :: unicode:unicode_binary()) -> integer().
num_steps(S) ->
  num_steps_rev(lists:reverse(to_list(S))).

num_steps_rev("1") ->
  0;
num_steps_rev([$0 | T]) ->
  num_steps_rev(T) + 1;
num_steps_rev(S) ->
  num_steps_rev(add_one_rev(S)) + 1.

add_one_rev([]) ->
  "1";
add_one_rev([$0 | T]) ->
  [$1 | T];
add_one_rev([$1 | T]) ->
  [$0 | add_one_rev(T)].

to_list(S) when is_binary(S) ->
  binary_to_list(S);
to_list(S) ->
  S.
