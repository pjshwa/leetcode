object Solution {
    def concatenatedBinary(n: Int): Int = {
        val MOD = 1_000_000_007L
        var (ans, p, i) = (0L, 1L, 1L)
        while (i <= n) {
            if ((i & (i - 1)) == 0) p = (p * 2) % MOD
            ans = ((ans * p) + i) % MOD
            i += 1
        }
        ans.toInt
    }
}
