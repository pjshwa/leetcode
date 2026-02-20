-spec make_largest_special(S :: unicode:unicode_binary()) -> unicode:unicode_binary().
make_largest_special(S) ->
  largest_special(S).

largest_special(<<>>) ->
  <<>>;
largest_special(S) ->
  Chunks = split_special_chunks(S),
  Normalized = [normalize_chunk(Chunk) || Chunk <- Chunks],
  Sorted = lists:sort(fun compare_chunks/2, Normalized),
  iolist_to_binary(Sorted).

normalize_chunk(Chunk) ->
  Size = byte_size(Chunk),
  case Size of
    0 ->
      <<>>;
    2 ->
      <<$1, $0>>;
    _ ->
      Inner = binary:part(Chunk, 1, Size - 2),
      InnerLargest = largest_special(Inner),
      <<$1, InnerLargest/binary, $0>>
  end.

split_special_chunks(S) ->
  split_special_chunks(S, 0, [], []).

split_special_chunks(<<>>, 0, [], AccRev) ->
  lists:reverse(AccRev);
split_special_chunks(<<C, Rest/binary>>, Balance, CurrRev, AccRev) ->
  NewBalance =
    case C of
      $1 -> Balance + 1;
      $0 -> Balance - 1
    end,
  NewCurrRev = [C | CurrRev],
  case NewBalance of
    0 ->
      Chunk = list_to_binary(lists:reverse(NewCurrRev)),
      split_special_chunks(Rest, 0, [], [Chunk | AccRev]);
    _ ->
      split_special_chunks(Rest, NewBalance, NewCurrRev, AccRev)
  end.

compare_chunks(A, B) ->
  AOnes = leading_ones(A),
  BOnes = leading_ones(B),
  case AOnes =:= BOnes of
    true -> A > B;
    false -> AOnes > BOnes
  end.

leading_ones(Bin) ->
  leading_ones(Bin, 0).

leading_ones(<<$1, Rest/binary>>, Count) ->
  leading_ones(Rest, Count + 1);
leading_ones(_, Count) ->
  Count.
