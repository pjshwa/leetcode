-spec check_ones_segment(S :: unicode:unicode_binary()) -> boolean().
check_ones_segment(S) ->
  all_ones(trim_ends(S)).

trim_ends(S) ->
  trim_right_zeros(trim_left_zeros(S)).

trim_left_zeros(<<$0, Rest/binary>>) ->
  trim_left_zeros(Rest);
trim_left_zeros(S) ->
  S.

trim_right_zeros(<<>>) ->
  <<>>;
trim_right_zeros(S) when is_binary(S) ->
  case binary:last(S) of
    $0 ->
      trim_right_zeros(binary:part(S, 0, byte_size(S) - 1));
    _ ->
      S
  end;
trim_right_zeros(S) ->
  S.

all_ones(<<>>) ->
  true;
all_ones(<<$1, Rest/binary>>) ->
  all_ones(Rest);
all_ones(_) ->
  false.
