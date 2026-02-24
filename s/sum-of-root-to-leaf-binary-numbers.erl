%% Definition for a binary tree node.
%%
%% -record(tree_node, {val = 0 :: integer(),
%%                     left = null  :: 'null' | #tree_node{},
%%                     right = null :: 'null' | #tree_node{}}).

-spec sum_root_to_leaf(Root :: #tree_node{} | null) -> integer().
sum_root_to_leaf(Root) ->
  case Root of
    null -> 0;
    _ -> sum_root_to_leaf(<<>>, Root)
  end.

sum_root_to_leaf(Bits, #tree_node{val = Val, left = Left, right = Right}) ->
  NextBits = <<Bits/binary, (Val + $0)>>,
  case {Left, Right} of
    {null, null} ->
      binary_to_integer(NextBits, 2);
    _ ->
      LeftSum =
        case Left of
          null -> 0;
          _ -> sum_root_to_leaf(NextBits, Left)
        end,
      RightSum =
        case Right of
          null -> 0;
          _ -> sum_root_to_leaf(NextBits, Right)
        end,
      LeftSum + RightSum
  end.
