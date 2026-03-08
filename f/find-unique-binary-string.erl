-spec find_different_binary_string(Nums :: [unicode:unicode_binary()]) -> unicode:unicode_binary().
find_different_binary_string(Nums) ->
  N = length(Nums),
  Ints = [list_to_integer(binary_to_list(Bin), 2) || Bin <- Nums],
  Missing = hd(lists:seq(0, N) -- Ints),
  Bin = integer_to_binary(Missing, 2),
  Pad = N - byte_size(Bin),
  if
    Pad > 0 ->
      list_to_binary([lists:duplicate(Pad, $0), Bin]);
    true ->
      Bin
  end.
