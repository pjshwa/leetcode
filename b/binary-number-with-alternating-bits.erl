has_alternating_bits(N) when is_integer(N), N >= 0 ->
    has_alt(N, -1).

has_alt(0, _) ->
    true;
has_alt(N, PrevBit) ->
    Bit = N band 1,
    case Bit =:= PrevBit of
        true  -> false;
        false -> has_alt(N bsr 1, Bit)
    end.
