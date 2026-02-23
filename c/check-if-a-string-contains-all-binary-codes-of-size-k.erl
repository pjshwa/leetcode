-spec has_all_codes(S :: unicode:unicode_binary(), K :: integer()) -> boolean().
has_all_codes(_S, K) when K =< 0 ->
  true;
has_all_codes(S, K) ->
  N = byte_size(S),
  Need = 1 bsl K,
  if
    K > N ->
      false;
    N - K + 1 < Need ->
      false;
    true ->
      Mask = Need - 1,
      <<Prefix:K/binary, Rest/binary>> = S,
      Code0 = init_code(Prefix),
      Visited0 = 1 bsl Code0,
      slide(Rest, Mask, Need, Code0, Visited0, 1)
  end.

slide(<<>>, _Mask, Need, _Code, _Visited, Count) ->
  Count =:= Need;
slide(<<C, Rest/binary>>, Mask, Need, Code, Visited, Count) ->
  Bit = bit(C),
  Code1 = ((Code bsl 1) band Mask) bor Bit,
  Flag = 1 bsl Code1,
  case (Visited band Flag) of
    0 ->
      Count1 = Count + 1,
      if
        Count1 =:= Need ->
          true;
        true ->
          slide(Rest, Mask, Need, Code1, Visited bor Flag, Count1)
      end;
    _ ->
      slide(Rest, Mask, Need, Code1, Visited, Count)
  end.

init_code(Bin) ->
  init_code(Bin, 0).

init_code(<<>>, Acc) ->
  Acc;
init_code(<<C, Rest/binary>>, Acc) ->
  init_code(Rest, (Acc bsl 1) bor bit(C)).

bit($1) ->
  1;
bit(_) ->
  0.
