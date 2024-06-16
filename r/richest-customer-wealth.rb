# @param {Integer[][]} accounts
# @return {Integer}
def maximum_wealth(accounts)
  accounts.map(&:sum).max
end
